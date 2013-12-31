/*
 * (c) 2012 Steffen Trumtrar <s.trumtrar@pengutronix.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#define ZYNQ_UART0_BASE_ADDR		0xE0000000
#define ZYNQ_UART1_BASE_ADDR		0xE0001000
#define ZYNQ_I2C0_BASE_ADDR		0xE0004000
#define ZYNQ_I2C1_BASE_ADDR		0xE0005000
#define ZYNQ_SPI0_BASE_ADDR		0xE0006000
#define ZYNQ_SPI1_BASE_ADDR		0xE0007000
#define ZYNQ_CAN0_BASE_ADDR		0xE0008000
#define ZYNQ_CAN1_BASE_ADDR		0xE0009000
#define ZYNQ_GPIO_BASE_ADDR		0xE000A000
#define ZYNQ_GEM0_BASE_ADDR		0xE000B000

#define ZYNQ_SLCR_BASE			0xF8000000
#define ZYNQ_SLCR_SCL			(ZYNQ_SLCR_BASE + 0x000)
#define ZYNQ_SLCR_LOCK			(ZYNQ_SLCR_BASE + 0x004)
#define ZYNQ_SLCR_UNLOCK		(ZYNQ_SLCR_BASE + 0x008)
#define ZYNQ_SLCR_LOCKSTA		(ZYNQ_SLCR_BASE + 0x00C)
#define ZYNQ_CLOCK_CTRL_BASE		(ZYNQ_SLCR_BASE + 0x100)
#define ZYNQ_ARM_PLL_CTRL		0x000
#define ZYNQ_DDR_PLL_CTRL		0x004
#define ZYNQ_IO_PLL_CTRL		0x008
#define ZYNQ_PLL_STATUS			0x00C
#define ZYNQ_ARM_PLL_CFG		0x010
#define ZYNQ_DDR_PLL_CFG		0x014
#define ZYNQ_IO_PLL_CFG			0x018
#define ZYNQ_ARM_CLK_CTRL		0x020
#define ZYNQ_DDR_CLK_CTRL		0x024
#define ZYNQ_DCI_CLK_CTRL		0x028
#define ZYNQ_APER_CLK_CTRL		0x02C
#define ZYNQ_USB0_CLK_CTRL		0x030
#define ZYNQ_USB1_CLK_CTRL		0x034
#define ZYNQ_GEM0_RCLK_CTRL		0x038
#define ZYNQ_GEM1_RCLK_CTRL		0x03C
#define ZYNQ_GEM0_CLK_CTRL		0x040
#define ZYNQ_GEM1_CLK_CTRL		0x044
#define ZYNQ_SMC_CLK_CTRL		0x048
#define ZYNQ_LQSPI_CLK_CTRL		0x04C
#define ZYNQ_SDIO_CLK_CTRL		0x050
#define ZYNQ_UART_CLK_CTRL		0x054
#define ZYNQ_SPI_CLK_CTRL		0x058
#define ZYNQ_CAN_CLK_CTRL		0x05C
#define ZYNQ_CAN_MIOCLK_CTRL		0x060
#define ZYNQ_DBG_CLK_CTRL		0x064
#define ZYNQ_PCAP_CLK_CTRL		0x068
#define ZYNQ_TOPSW_CLK_CTRL		0x06C
#define ZYNQ_FPGA0_CLK_CTRL		0x070
#define ZYNQ_FPGA1_CLK_CTRL		0x080
#define ZYNQ_FPGA2_CLK_CTRL		0x090
#define ZYNQ_FPGA3_CLK_CTRL		0x0A0
#define ZYNQ_CLK_621_TRUE		0x0C4
#define ZYNQ_RST_CTRL_BASE		(ZYNQ_SLCR_BASE + 0x200)
#define ZYNQ_PSS_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x000)
#define ZYNQ_DDR_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x004)
#define ZYNQ_TOPSW_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x008)
#define ZYNQ_DMAC_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x00C)
#define ZYNQ_USB_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x010)
#define ZYNQ_GEM_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x014)
#define ZYNQ_SDIO_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x018)
#define ZYNQ_SPI_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x01C)
#define ZYNQ_CAN_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x020)
#define ZYNQ_I2C_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x024)
#define ZYNQ_UART_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x028)
#define ZYNQ_GPIO_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x02C)
#define ZYNQ_LQSPI_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x030)
#define ZYNQ_SMC_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x034)
#define ZYNQ_OCM_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x038)
#define ZYNQ_DEVCI_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x03C)
#define ZYNQ_FPGA_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x040)
#define ZYNQ_A9_CPU_RST_CTRL		(ZYNQ_RST_CTRL_BASE + 0x044)
#define ZYNQ_RS_AWDT_CTRL		(ZYNQ_RST_CTRL_BASE + 0x04C)
#define ZYNQ_REBOOT_STATUS		(ZYNQ_SLCR_BASE + 0x258)
#define ZYNQ_BOOT_MODE			(ZYNQ_SLCR_BASE + 0x25C)
#define ZYNQ_APU_CTRL			(ZYNQ_SLCR_BASE + 0x300)
#define ZYNQ_WDT_CLK_SEL		(ZYNQ_SLCR_BASE + 0x304)
#define ZYNQ_PSS_IDCODE			(ZYNQ_SLCR_BASE + 0x530)
#define ZYNQ_DDR_URGENT			(ZYNQ_SLCR_BASE + 0x600)
#define ZYNQ_DDR_CAL_START		(ZYNQ_SLCR_BASE + 0x60C)
#define ZYNQ_DDR_REF_START		(ZYNQ_SLCR_BASE + 0x614)
#define ZYNQ_DDR_CMD_STA		(ZYNQ_SLCR_BASE + 0x618)
#define ZYNQ_DDR_URGENT_SEL		(ZYNQ_SLCR_BASE + 0x61C)
#define ZYNQ_DDR_DFI_STATUS		(ZYNQ_SLCR_BASE + 0x620)
#define ZYNQ_MIO_BASE			(ZYNQ_SLCR_BASE + 0x700)
#define ZYNQ_MIO_LOOPBACK		(ZYNQ_MIO_BASE + 0x104)
#define ZYNQ_MIO_MST_TRI0		(ZYNQ_MIO_BASE + 0x10C)
#define ZYNQ_MIO_MST_TRI1		(ZYNQ_MIO_BASE + 0x110)
#define ZYNQ_SD0_WP_SEL			(ZYNQ_SLCR_BASE + 0x830)
#define ZYNQ_SD1_WP_SEL			(ZYNQ_SLCR_BASE + 0x834)
#define ZYNQ_LVL_SHIFTR_EN		(ZYNQ_SLCR_BASE + 0x900)
#define ZYNQ_OCM_CFG			(ZYNQ_SLCR_BASE + 0x910)
#define ZYNQ_GPIOB_BASE			(ZYNQ_SLCR_BASE + 0xB00)
#define ZYNQ_GPIOB_CTRL			(ZYNQ_GPIOB_BASE + 0x000)
#define ZYNQ_GPIOB_CFG_CMOS18		(ZYNQ_GPIOB_BASE + 0x004)
#define ZYNQ_GPIOB_CFG_CMOS25		(ZYNQ_GPIOB_BASE + 0x008)
#define ZYNQ_GPIOB_CFG_CMOS33		(ZYNQ_GPIOB_BASE + 0x00C)
#define ZYNQ_GPIOB_CFG_LVTTL		(ZYNQ_GPIOB_BASE + 0x010)
#define ZYNQ_GPIOB_CFG_HSTL		(ZYNQ_GPIOB_BASE + 0x014)
#define ZYNQ_GPIOB_DRV_BIAS_CTRL	(ZYNQ_GPIOB_BASE + 0x018)
#define ZYNQ_DDRIOB_BASE		(ZYNQ_SLCR_BASE + 0xB40)
#define ZYNQ_DDRIOB_ADDR0		(ZYNQ_DDRIOB_BASE + 0x000)
#define ZYNQ_DDRIOB_ADDR1		(ZYNQ_DDRIOB_BASE + 0x004)
#define ZYNQ_DDRIOB_DATA0		(ZYNQ_DDRIOB_BASE + 0x008)
#define ZYNQ_DDRIOB_DATA1		(ZYNQ_DDRIOB_BASE + 0x00C)
#define ZYNQ_DDRIOB_DIFF0		(ZYNQ_DDRIOB_BASE + 0x010)
#define ZYNQ_DDRIOB_DIFF1		(ZYNQ_DDRIOB_BASE + 0x014)
#define ZYNQ_DDRIOB_CLOCK		(ZYNQ_DDRIOB_BASE + 0x018)
#define ZYNQ_DDRIOB_DRIVE_SLEW_ADDR	(ZYNQ_DDRIOB_BASE + 0x01C)
#define ZYNQ_DDRIOB_DRIVE_SLEW_DATA	(ZYNQ_DDRIOB_BASE + 0x020)
#define ZYNQ_DDRIOB_DRIVE_SLEW_DIFF	(ZYNQ_DDRIOB_BASE + 0x024)
#define ZYNQ_DDRIOB_DRIVE_SLEW_CLOCK	(ZYNQ_DDRIOB_BASE + 0x028)
#define ZYNQ_DDRIOB_DDR_CTRL		(ZYNQ_DDRIOB_BASE + 0x02C)
#define ZYNQ_DDRIOB_DCI_CTRL		(ZYNQ_DDRIOB_BASE + 0x030)
#define ZYNQ_DDRIOB_DCI_STATUS		(ZYNQ_DDRIOB_BASE + 0x034)

#define ZYNQ_TTC0_BASE_ADDR		0xF8001000
#define ZYNQ_TTC1_BASE_ADDR		0xF8002000

#define ZYNQ_DDRC_BASE			0xF8006000

#define CORTEXA9_SCU_TIMER_BASE_ADDR	0xF8F00600
