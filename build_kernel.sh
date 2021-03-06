#!/bin/sh
# Build Script: Javilonas, 14-12-2013
# Javilonas <admin@lonasdigital.com>

echo "#################### Eliminando Restos ####################"
if [ -e boot.img ]; then
	rm boot.img
fi

if [ -e compile.log ]; then
	rm compile.log
fi

if [ -e ramdisk.cpio ]; then
	rm ramdisk.cpio
fi

if [ -e ramdisk.cpio.xz ]; then
	rm ramdisk.cpio.gz
fi

if [ -e ramdisk.cpio.xz ]; then
	rm ramdisk.cpio.xz
fi

make clean

echo "#################### Preparando Entorno ####################"

export KERNELDIR=`readlink -f .`
export RAMFS_SOURCE=`readlink -f $KERNELDIR/ramdisk`
export USE_SEC_FIPS_MODE=true

echo "kerneldir = $KERNELDIR"
echo "ramfs_source = $RAMFS_SOURCE"

if [ "${1}" != "" ];then
  export KERNELDIR=`readlink -f ${1}`
fi

TOOLCHAIN="/home/lonas/android/omni/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.7/bin/arm-linux-androideabi-"
TOOLCHAIN_PATCH="/home/lonas/android/omni/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.7/bin"
ROOTFS_PATH="/home/lonas/Kernel_Lonas/Lonas_KL-GT-I9300/ramdisk"
RAMFS_TMP="/home/lonas/Kernel_Lonas/tmp/ramfs-source-sgs3"

CONFIG_LOCALVERSION="Lonas_KL-5.2"
export KBUILD_BUILD_VERSION="1"

echo "ramfs_tmp = $RAMFS_TMP"

echo "#################### Eliminando build anterior ####################"
make ARCH=arm CROSS_COMPILE=$TOOLCHAIN -j`grep 'processor' /proc/cpuinfo | wc -l` mrproper

find -name '*.ko' -exec rm -rf {} \;
rm -rf $KERNELDIR/arch/arm/boot/zImage

echo "#################### Make defconfig ####################"
make lonas_defconfig

make -j`grep 'processor' /proc/cpuinfo | wc -l` ARCH=arm CROSS_COMPILE=$TOOLCHAIN || exit -1

mkdir -p $KERNELDIR/ramdisk/lib/modules
find -name '*.ko' -exec cp -av {} $KERNELDIR/ramdisk/lib/modules/ \;
$TOOLCHAIN_PATCH/arm-linux-androideabi-strip --strip-unneeded $KERNELDIR/ramdisk/lib/modules/*.ko

echo "#################### Build Ramdisk ####################"
rm -f $KERNELDIR/releasetools/tar/$CONFIG_LOCALVERSION-$KBUILD_BUILD_VERSION.tar
rm -f $KERNELDIR/releasetools/zip/$CONFIG_LOCALVERSION-$KBUILD_BUILD_VERSION.zip
cp -f $KERNELDIR/arch/arm/boot/zImage .

rm -rf $RAMFS_TMP
rm -rf $RAMFS_TMP.cpio
rm -rf $RAMFS_TMP.cpio.gz
rm -rf $RAMFS_TMP.cpio.xz
rm -rf $KERNELDIR/*.cpio
rm -rf $KERNELDIR/*.cpio.gz
rm -rf $KERNELDIR/*.cpio.xz
cd $ROOTFS_PATH
cp -ax $ROOTFS_PATH $RAMFS_TMP
find $RAMFS_TMP -name .git -exec rm -rf {} \;
find $RAMFS_TMP -name EMPTY_DIRECTORY -exec rm -rf {} \;
find $RAMFS_TMP -name .EMPTY_DIRECTORY -exec rm -rf {} \;
rm -rf $RAMFS_TMP/tmp/*
rm -rf $RAMFS_TMP/.hg

cd $RAMFS_TMP
find | fakeroot cpio -H newc -o > $RAMFS_TMP.cpio 2>/dev/null
ls -lh $RAMFS_TMP.cpio
xz --check=crc32 $BCJ --lzma2=$LZMA2OPTS,dict=8MiB $RAMFS_TMP.cpio
cd -

echo "#################### Compilar Kernel ####################"
cd $KERNELDIR
nice -n 10 make -j4 ARCH=arm CROSS_COMPILE=$TOOLCHAIN zImage || exit 1

echo "#################### Generar boot.img ####################"
./mkbootimg --kernel zImage --ramdisk $RAMFS_TMP.cpio.xz --board smdk4x12 --base 0x10000000 --pagesize 2048 --ramdiskaddr 0x11000000 -o $KERNELDIR/boot.img

echo "#################### Preparando flasheables ####################"

cp boot.img $KERNELDIR/releasetools/zip
cp boot.img $KERNELDIR/releasetools/tar

cd $KERNELDIR
cd releasetools/zip
zip -0 -r $CONFIG_LOCALVERSION-$KBUILD_BUILD_VERSION.zip *
cd ..
cd tar
tar cf $CONFIG_LOCALVERSION-$KBUILD_BUILD_VERSION.tar boot.img && ls -lh $CONFIG_LOCALVERSION-$KBUILD_BUILD_VERSION.tar

echo "#################### Eliminando restos ####################"

rm $KERNELDIR/releasetools/zip/boot.img
rm $KERNELDIR/releasetools/tar/boot.img
rm $KERNELDIR/boot.img
rm $KERNELDIR/zImage
rm -rf /home/lonas/Kernel_Lonas/tmp/ramfs-source-sgs3
rm /home/lonas/Kernel_Lonas/tmp/ramfs-source-sgs3.cpio.xz
echo "#################### Terminado ####################"
