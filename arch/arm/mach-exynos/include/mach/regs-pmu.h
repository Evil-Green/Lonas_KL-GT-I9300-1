/* linux/arch/arm/mach-exynos/include/mach/regs-pmu.h
 *
 * Copyright (c) 2010-2011 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * EXYNOS4 - Power management unit definition
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __ASM_ARCH_REGS_PMU_H
#define __ASM_ARCH_REGS_PMU_H __FILE__

#include <mach/map.h>

#define S5P_PMUREG(x)				(S5P_VA_PMU + (x))

#include "regs-pmu-4210.h"
#include "regs-pmu-4212.h"

#define S5P_CENTRAL_SEQ_CONFIGURATION		S5P_PMUREG(0x0200)

#define S5P_CENTRAL_LOWPWR_CFG			(1 << 16)

#define S5P_CENTRAL_SEQ_OPTION			S5P_PMUREG(0x0208)

#define S5P_USE_STANDBY_WFI0			(1 << 16)
#define S5P_USE_STANDBY_WFI1			(1 << 17)
#define S5P_USE_STANDBYWFI_ISP_ARM		(1 << 18)
#define S5P_USE_STANDBY_WFE0			(1 << 24)
#define S5P_USE_STANDBY_WFE1			(1 << 25)
#define S5P_USE_STANDBYWFE_ISP_ARM		(1 << 26)
#define S5P_USE_MASK				((0x3 << 16) | (0x3 << 24))

#define S5P_SWRESET				S5P_PMUREG(0x0400)

#define S5P_WAKEUP_STAT				S5P_PMUREG(0x0600)
#define	S5P_WAKEUP_STAT_SYSTIMER		(1 << 14)
#define S5P_WAKEUP_STAT_AUDIO			(1 << 13)
#define S5P_WAKEUP_STAT_MMC3			(1 << 12)
#define S5P_WAKEUP_STAT_MMC2			(1 << 11)
#define S5P_WAKEUP_STAT_RTCTICK			(1 << 2)
#define S5P_WAKEUP_STAT_RTCALARM		(1 << 1)
#define S5P_WAKEUP_STAT_EINT			(1 << 0)

#define S5P_EINT_WAKEUP_MASK			S5P_PMUREG(0x0604)
#define S5P_WAKEUP_MASK				S5P_PMUREG(0x0608)

#if defined(CONFIG_CPU_EXYNOS4212) || defined(CONFIG_CPU_EXYNOS4412)
#define S5P_WAKEUP_MASK_BIT                    0x3FFFFFF
#else
#define S5P_WAKEUP_MASK_BIT                    0xFFFF
#endif

#define S5P_HDMI_PHY_CONTROL			S5P_PMUREG(0x0700)
#define S5P_HDMI_PHY_ENABLE			(1 << 0)

#define S5P_DAC_CONTROL				S5P_PMUREG(0x70C)
#define S5P_DAC_ENABLE				(1)
#define S5P_DAC_DISABLE				(0)

#define S5P_DAC_PHY_CONTROL			S5P_PMUREG(0x070C)
#define S5P_DAC_PHY_ENABLE			(1 << 0)
#define S5P_DAC_DISABLE				(0)

#define S5P_MIPI_DPHY_CONTROL(n)		S5P_PMUREG(0x0710 + (n) * 4)
#define S5P_MIPI_DPHY_ENABLE			(1 << 0)
#define S5P_MIPI_DPHY_SRESETN			(1 << 1)
#define S5P_MIPI_DPHY_MRESETN			(1 << 2)

#define S5P_DPTX_PHY_CONTROL			S5P_PMUREG(0x720)
#define S5P_DPTX_PHY_ENABLE			(1 << 0)

#define S5P_INFORM0				S5P_PMUREG(0x0800)
#define S5P_INFORM1				S5P_PMUREG(0x0804)
#define S5P_INFORM2				S5P_PMUREG(0x0808)
#define S5P_INFORM3				S5P_PMUREG(0x080C)
#define S5P_INFORM4				S5P_PMUREG(0x0810)
#define S5P_INFORM5				S5P_PMUREG(0x0814)
#define S5P_INFORM6				S5P_PMUREG(0x0818)
#define S5P_INFORM7				S5P_PMUREG(0x081C)

#define S5P_PMU_DEBUG				S5P_PMUREG(0x0A00)
#define S5P_PMU_CLKOUT_SEL_SHIFT		(8)
#define S5P_CLKOUT_DISABLE			(0x1 << 0)

#define S5P_ARM_CORE0_SYS			S5P_PMUREG(0x1000)
#define S5P_DIS_IRQ_ARM_CORE0_LOCAL_SYS		S5P_PMUREG(0x1004)
#define S5P_DIS_IRQ_ARM_CORE0_CENTRAL_SYS	S5P_PMUREG(0x1008)
#define S5P_ARM_CORE1_SYS			S5P_PMUREG(0x1010)
#define S5P_DIS_IRQ_ARM_CORE1_LOCAL_SYS		S5P_PMUREG(0x1014)
#define S5P_DIS_IRQ_ARM_CORE1_CENTRAL_SYS	S5P_PMUREG(0x1018)
#define S5P_ARM_COMMON_SYS			S5P_PMUREG(0x1080)
#define S5P_ARM_L2_0_SYS			S5P_PMUREG(0x10C0)
#define S5P_ARM_L2_1_SYS			S5P_PMUREG(0x10C4)
#define S5P_CMU_ACLKSTOP_SYS			S5P_PMUREG(0x1100)
#define S5P_CMU_SCLKSTOP_SYS			S5P_PMUREG(0x1104)
#define S5P_CMU_RESET_SYS			S5P_PMUREG(0x110C)
#define S5P_APLL_SYSCLK_SYS			S5P_PMUREG(0x1120)
#define S5P_MPLL_SYSCLK_SYS			S5P_PMUREG(0x1124)
#define S5P_VPLL_SYSCLK_SYS			S5P_PMUREG(0x1128)
#define S5P_EPLL_SYSCLK_SYS			S5P_PMUREG(0x112C)
#define S5P_CMU_CLKSTOP_GPS_ALIVE_SYS		S5P_PMUREG(0x1138)
#define S5P_CMU_RESET_GPSALIVE_SYS		S5P_PMUREG(0x113C)
#define S5P_CMU_CLKSTOP_CAM_SYS			S5P_PMUREG(0x1140)
#define S5P_CMU_CLKSTOP_TV_SYS			S5P_PMUREG(0x1144)
#define S5P_CMU_CLKSTOP_MFC_SYS			S5P_PMUREG(0x1148)
#define S5P_CMU_CLKSTOP_G3D_SYS			S5P_PMUREG(0x114C)
#define S5P_CMU_CLKSTOP_LCD0_SYS		S5P_PMUREG(0x1150)
#define S5P_CMU_CLKSTOP_MAUDIO_SYS		S5P_PMUREG(0x1158)
#define S5P_CMU_CLKSTOP_GPS_SYS			S5P_PMUREG(0x115C)
#define S5P_CMU_RESET_CAM_SYS			S5P_PMUREG(0x1160)
#define S5P_CMU_RESET_TV_SYS			S5P_PMUREG(0x1164)
#define S5P_CMU_RESET_MFC_SYS			S5P_PMUREG(0x1168)
#define S5P_CMU_RESET_G3D_SYS			S5P_PMUREG(0x116C)
#define S5P_CMU_RESET_LCD0_SYS			S5P_PMUREG(0x1170)
#define S5P_CMU_RESET_MAUDIO_SYS		S5P_PMUREG(0x1178)
#define S5P_CMU_RESET_GPS_SYS			S5P_PMUREG(0x117C)
#define S5P_TOP_BUS_SYS				S5P_PMUREG(0x1180)
#define S5P_TOP_RETENTION_SYS			S5P_PMUREG(0x1184)
#define S5P_TOP_PWR_SYS				S5P_PMUREG(0x1188)
#define S5P_LOGIC_RESET_SYS			S5P_PMUREG(0x11A0)
#define S5P_ONENAND_MEM_SYS			S5P_PMUREG(0x11C0)
#define S5P_G2D_ACP_MEM_SYS			S5P_PMUREG(0x11C8)
#define S5P_USBOTG_MEM_SYS			S5P_PMUREG(0x11CC)
#define S5P_SDMMC_MEM_SYS			S5P_PMUREG(0x11D0)
#define S5P_CSSYS_MEM_SYS			S5P_PMUREG(0x11D4)
#define S5P_SECSS_MEM_SYS			S5P_PMUREG(0x11D8)
#define S5P_PAD_RETENTION_DRAM_SYS		S5P_PMUREG(0x1200)
#define S5P_PAD_RETENTION_MAUDIO_SYS		S5P_PMUREG(0x1204)
#define S5P_PAD_RETENTION_GPIO_SYS		S5P_PMUREG(0x1220)
#define S5P_PAD_RETENTION_UART_SYS		S5P_PMUREG(0x1224)
#define S5P_PAD_RETENTION_MMCA_SYS		S5P_PMUREG(0x1228)
#define S5P_PAD_RETENTION_MMCB_SYS		S5P_PMUREG(0x122C)
#define S5P_PAD_RETENTION_EBIA_SYS		S5P_PMUREG(0x1230)
#define S5P_PAD_RETENTION_EBIB_SYS		S5P_PMUREG(0x1234)
#define S5P_PAD_ISOLATION_SYS			S5P_PMUREG(0x1240)
#define S5P_PAD_ALV_SEL_SYS			S5P_PMUREG(0x1260)
#define S5P_XUSBXTI_SYS				S5P_PMUREG(0x1280)
#define S5P_XXTI_SYS				S5P_PMUREG(0x1284)
#define S5P_EXT_REGULATOR_SYS			S5P_PMUREG(0x12C0)
#define S5P_GPIO_MODE_SYS			S5P_PMUREG(0x1300)
#define S5P_GPIO_MODE_MAUDIO_SYS		S5P_PMUREG(0x1340)
#define S5P_CAM_SYS				S5P_PMUREG(0x1380)
#define S5P_TV_SYS				S5P_PMUREG(0x1384)
#define S5P_MFC_SYS				S5P_PMUREG(0x1388)
#define S5P_G3D_SYS				S5P_PMUREG(0x138C)
#define S5P_LCD0_SYS				S5P_PMUREG(0x1390)
#define S5P_LCD1_SYS				S5P_PMUREG(0x1394)
#define S5P_MAUDIO_SYS				S5P_PMUREG(0x1398)
#define S5P_GPS_SYS				S5P_PMUREG(0x139C)
#define S5P_GPS_ALIVE_SYS			S5P_PMUREG(0x13A0)

#define S5P_ARM_CORE0_CONFIGURATION		S5P_PMUREG(0x2000)
#define S5P_ARM_CORE0_STATUS			S5P_PMUREG(0x2004)
#define S5P_ARM_CORE0_OPTION			S5P_PMUREG(0x2008)

#define S5P_ARM_CORE_OPTION(_nr)		(S5P_ARM_CORE0_OPTION + ((_nr) * 0x80))
#define S5P_ARM_CORE_STATUS(_nr)		(S5P_ARM_CORE0_STATUS + ((_nr) * 0x80))
#define S5P_ARM_CORE_CONFIGURATION(_nr)		(S5P_ARM_CORE0_CONFIGURATION + ((_nr) * 0x80))

#define S5P_CORE_OPTION_DIS			(1 << 8)

#define S5P_ARM_COMMON_OPTION			S5P_PMUREG(0x2408)
#define S5P_CAM_OPTION				S5P_PMUREG(0x3C08)
#define S5P_TV_OPTION				S5P_PMUREG(0x3C28)
#define S5P_MFC_OPTION				S5P_PMUREG(0x3C48)
#define S5P_G3D_OPTION				S5P_PMUREG(0x3C68)
#define S5P_LCD0_OPTION				S5P_PMUREG(0x3C88)
#define S5P_LCD1_OPTION				S5P_PMUREG(0x3CA8)
#define S5P_MAUDIO_OPTION			S5P_PMUREG(0x3CC8)
#define S5P_GPS_OPTION				S5P_PMUREG(0x3CE8)
#define S5P_GPS_ALIVE_OPTION			S5P_PMUREG(0x3D08)

#define S5P_PAD_RET_MAUDIO_OPTION		S5P_PMUREG(0x3028)
#define S5P_PAD_RET_GPIO_OPTION			S5P_PMUREG(0x3108)
#define S5P_PAD_RET_UART_OPTION			S5P_PMUREG(0x3128)
#define S5P_PAD_RET_MMCA_OPTION			S5P_PMUREG(0x3148)
#define S5P_PAD_RET_MMCB_OPTION			S5P_PMUREG(0x3168)
#define S5P_PAD_RET_EBIA_OPTION			S5P_PMUREG(0x3188)
#define S5P_PAD_RET_EBIB_OPTION			S5P_PMUREG(0x31A8)

#define S5P_PAD_RETENTION_GPIO_COREBLK_SYS_OPTION		S5P_PMUREG(0x31E8)

#define S5P_XXTI_CONFIGURATION			S5P_PMUREG(0x3420)
#define S5P_XXTI_STATUS				S5P_PMUREG(0x3424)

#define S5P_PMU_CAM_CONF			S5P_PMUREG(0x3C00)
#define S5P_PMU_TV_CONF				S5P_PMUREG(0x3C20)
#define S5P_PMU_MFC_CONF			S5P_PMUREG(0x3C40)
#define S5P_PMU_G3D_CONF			S5P_PMUREG(0x3C60)
#define S5P_PMU_LCD0_CONF			S5P_PMUREG(0x3C80)
#define S5P_PMU_GPS_CONF			S5P_PMUREG(0x3CE0)

#define S5P_CORE_LOCAL_PWR_EN			0x3

#define S5P_USE_DELAYED_RESET_ASSERTION		(1 << 12)
#define S5P_USE_DELAYED_RESET_OFFSET		12

#define S5P_PMU_SATA_PHY_CONTROL_EN		0x1
#define S5P_INT_LOCAL_PWR_EN			0x7

#define S5P_CHECK_SLEEP				0x00000BAD
#define S5P_CHECK_DIDLE				0xBAD00000
#define S5P_CHECK_LPA				0xABAD0000

#endif /* __ASM_ARCH_REGS_PMU_H */
