/*
 * (C) Copyright 2004-2009
 * Texas Instruments, <www.ti.com>
 * Richard Woodruff <r-woodruff2@ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <common.h>
#include <io.h>
#include <sizes.h>
#include <mach/omap4-mux.h>
#include <mach/omap4-silicon.h>
#include <mach/omap4-clock.h>
#include <mach/syslib.h>
#include <asm/barebox-arm.h>
#include <asm/barebox-arm-head.h>

#define TPS62361_VSEL0_GPIO    182

#define LPDDR2_64M             0x0
#define LPDDR2_128M            0x1
#define LPDDR2_256M            0x2
#define LPDDR2_512M            0x3
#define LPDDR2_1G              0x4
#define LPDDR2_2G              0x5
#define LPDDR2_4G              0x6
#define LPDDR2_8G              0x7
#define LPDDR2_16G             0x8
#define LPDDR2_32G             0x9

#define LPDDR2_DENSITY_MASK            0x3C
#define LPDDR2_DENSITY_SHIFT           2

#define EMIF_SDRAM_CONFIG               0x0008
#define EMIF_LPDDR2_MODE_REG_CONFIG     0x0050
#define EMIF_LPDDR2_MODE_REG_DATA       0x0040

void set_muxconf_regs(void);

#ifdef CONFIG_SAFE_BOOT
/* 512MB under worst temperatures */
/* refresh tim 8ms */
static const struct ddr_regs ddr_regs_mt42L64M64_25_400_mhz = {
	.tim1		= 0x12EB16A2,
	.tim2		= 0x20370DD2,
	.tim3		= 0x00B1C33F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000168, /* refresh period = 8ms */
	.config_init	= 0x80001AB1,
	.config_final	= 0x80001AB1,
	.zq_config	= 0x500BC852, /* zqs interval = 50ms */
	.mr1		= 0x83,
	.mr2		= 0x4
};

/* 512MB with 4GBit Page Size under worst temperatures */
/* refresh tim 8ms */
static const struct ddr_regs ddr_regs_mt42L128M32_25_400_mhz = {
	.tim1		= 0x12EB16A2,
	.tim2		= 0x20370DD2,
	.tim3		= 0x00B1C33F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000168, /* refresh period = 8ms */
	.config_init	= 0x80001AB2,
	.config_final	= 0x80001AB2,
	.zq_config	= 0x500BC852, /* zqs interval = 50ms */
	.mr1		= 0x83,
	.mr2		= 0x4
};

/* 1GB under worst temperatures */
/* refresh time 8ms */
static const struct ddr_regs ddr_regs_mt42L128M64_25_400_mhz = {
	.tim1		= 0x12EB16A2,
	.tim2		= 0x205715D2,
	.tim3		= 0x00B1C53F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000168, /* refresh period = 8ms */
	.config_init	= 0x80001AB9,
	.config_final	= 0x80001AB9,
	.zq_config	= 0xF00BC852, /* zqs interval = 50ms */
	.mr1		= 0x83,
	.mr2		= 0x4
};
/* 1GB under worst temperatures with 1CS*/
/* refresh time 8ms */
static const struct ddr_regs ddr_regs_mt42L128M64D2LL_25_400_mhz = {
	.tim1		= 0x12EB16A2,
	.tim2		= 0x205715D2,
	.tim3		= 0x00B1C53F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000168, /* refresh period = 8ms */
	.config_init	= 0x80001AB2,
	.config_final	= 0x80001AB2,
	.zq_config	= 0x500BC852, /* zqs interval = 50ms */
	.mr1		= 0x83,
	.mr2		= 0x4
};
#else
/* 512MB */
static const struct ddr_regs ddr_regs_mt42L64M64_25_400_mhz = {
	.tim1		= 0x10EB0662,
	.tim2		= 0x20370DD2,
	.tim3		= 0x00B1C33F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000618, /* refresh period = 32ms */
	.config_init	= 0x80001AB1,
	.config_final	= 0x80001AB1, /* zqs interval = 50ms */
	.zq_config	= 0x500B3214,
	.mr1		= 0x83,
	.mr2		= 0x4
};

/* 512MB with 4 GBit*/
static const struct ddr_regs ddr_regs_mt42L128M32_25_400_mhz = {
	.tim1		= 0x10EB0662,
	.tim2		= 0x20370DD2,
	.tim3		= 0x00B1C33F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000618, /* refresh period = 32ms */
	.config_init	= 0x80001AB2,
	.config_final	= 0x80001AB2, /* zqs interval = 50ms */
	.zq_config	= 0x500B3214,
	.mr1		= 0x83,
	.mr2		= 0x4
};

/* 1GB */
static const struct ddr_regs ddr_regs_mt42L128M64_25_400_mhz = {
	.tim1		= 0x10EB0662,
	.tim2		= 0x205715D2,
	.tim3		= 0x00B1C53F,
	.phy_ctrl_1	= 0x849FF409,
	.ref_ctrl	= 0x00000618,
	.config_init	= 0x80001AB9,
	.config_final	= 0x80001AB9,
	.zq_config	= 0xF00B3214,
	.mr1		= 0x83,
	.mr2		= 0x4
};

/* 1GB with one CS */
static const struct ddr_regs ddr_regs_mt42L128M64D2LL_25_400_mhz = {
        .tim1           = 0x10EB0662,
        .tim2           = 0x205715D2,
        .tim3           = 0x00B1C53F,
        .phy_ctrl_1     = 0x849FF409,
        .ref_ctrl       = 0x00000618,
        .config_init    = 0x80001AB2,
        .config_final   = 0x80001AB2,
        .zq_config      = 0x500B3214,
        .mr1            = 0x83,
        .mr2            = 0x4
};
#endif

static void noinline pcm049_init_lowlevel(void)
{
	struct dpll_param core = OMAP4_CORE_DPLL_PARAM_19M2_DDR400;
	struct dpll_param mpu44xx = OMAP4_MPU_DPLL_PARAM_19M2_MPU1000;
	struct dpll_param mpu4460 = OMAP4_MPU_DPLL_PARAM_19M2_MPU920;
	struct dpll_param iva = OMAP4_IVA_DPLL_PARAM_19M2;
	struct dpll_param per = OMAP4_PER_DPLL_PARAM_19M2;
	struct dpll_param abe = OMAP4_ABE_DPLL_PARAM_19M2;
	struct dpll_param usb = OMAP4_USB_DPLL_PARAM_19M2;
	unsigned int rev = omap4_revision();

	unsigned int density;
	
	set_muxconf_regs();
	
	omap4_ddr_init(&ddr_regs_mt42L64M64_25_400_mhz, &core);
	writel(EMIF_SDRAM_CONFIG, OMAP44XX_EMIF1_BASE + EMIF_LPDDR2_MODE_REG_CONFIG);
	
	density = (readl(OMAP44XX_EMIF1_BASE + EMIF_LPDDR2_MODE_REG_DATA)
			& LPDDR2_DENSITY_MASK) >> LPDDR2_DENSITY_SHIFT; 

#ifdef CONFIG_1024MB_DDR2RAM
	if (density == LPDDR2_2G) {
		omap4_ddr_init(&ddr_regs_mt42L128M64_25_400_mhz, &core);
	} else if (density == LPDDR2_4G) { 
		omap4_ddr_init(&ddr_regs_mt42L128M64D2LL_25_400_mhz, &core);
	}
#else
	if (density == LPDDR2_4G) { 
		omap4_ddr_init(&ddr_regs_mt42L128M32_25_400_mhz, &core);
	}
#endif

	/* Set VCORE1 = 1.3 V, VCORE2 = VCORE3 = 1.21V */
	if (rev < OMAP4460_ES1_0)
		omap4430_scale_vcores();
	else
		omap4460_scale_vcores(TPS62361_VSEL0_GPIO, 1320);

	writel(CM_SYS_CLKSEL_19M2, CM_SYS_CLKSEL);

	/* Configure all DPLL's at 100% OPP */
	if (rev < OMAP4460_ES1_0)
		omap4_configure_mpu_dpll(&mpu44xx);
	else
		omap4_configure_mpu_dpll(&mpu4460);

	omap4_configure_iva_dpll(&iva);
	omap4_configure_per_dpll(&per);
	omap4_configure_abe_dpll(&abe);
	omap4_configure_usb_dpll(&usb);

	/* Enable all clocks */
	omap4_enable_all_clocks();

	sr32(OMAP44XX_SCRM_AUXCLK3, 8, 1, 0x1);  /* enable software ioreq */
	sr32(OMAP44XX_SCRM_AUXCLK3, 1, 2, 0x0);  /* set for sys_clk (19.2MHz) */
	sr32(OMAP44XX_SCRM_AUXCLK3, 16, 4, 0x0); /* set divisor to 1 */
	sr32(OMAP44XX_SCRM_ALTCLKSRC, 0, 1, 0x1);  /* activate clock source */
	sr32(OMAP44XX_SCRM_ALTCLKSRC, 2, 2, 0x3);  /* enable clocks */
}

void barebox_arm_reset_vector(void)
{
	arm_cpu_lowlevel_init();

	if (get_pc() > 0x80000000)
		goto out;

	arm_setup_stack(0x4030d000);

	pcm049_init_lowlevel();
out:
	barebox_arm_entry(0x80000000, SZ_512M, 0);
}
