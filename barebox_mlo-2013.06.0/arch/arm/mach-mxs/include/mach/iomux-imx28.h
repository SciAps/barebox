/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/* 3322222222221111111111
 * 10987654321098765432109876543210
 *                            ^^^^^_ Bit offset
 *                         ^^^______ Register Number
 *                       ^^_________ Function
 *                      ^___________ Drive strength feature present
 *                     ^____________ Pull up present
 *                   ^^_____________ Drive strength setting
 *                  ^_______________ Pull up / bit keeper setting
 *                 ^________________ Voltage select present
 *                ^_________________ Voltage selection
 *            ^_____________________ direction if enabled as GPIO (1 = output)
 *           ^______________________ initial output value if enabled as GPIO
 *                                   and configured as output
 *          ^_______________________ Bit keeper present
 */
#ifndef __MACH_IOMUX_IMX28_H
#define __MACH_IOMUX_IMX28_H

/* control pad's function */
#define FBANK_SHIFT (5)
#define PORTF(bank,bit)	(((bank) << FBANK_SHIFT) | (bit))
#define GET_GPIO_NO(x) ((x) & 0xff)
#define FUNC_SHIFT 8
#define FUNC(x)	((x) << FUNC_SHIFT)
#define GET_FUNC(x) (((x) >> FUNC_SHIFT) & 3)
#define IS_GPIO (3)

/* control pad's GPIO feature if enabled */
#define GPIO_OUT (1 << 20)
#define GPIO_VALUE(x) ((x) << 21)
#define GPIO_IN (0 << 20)
#define GET_GPIODIR(x) (!!((x) & (1 << 20)))
#define GET_GPIOVAL(x) (!!((x) & (1 << 21)))

/* control pad's drive strength */
#define SE (1 << 10)
#define SE_PRESENT(x) (!!((x) & SE))
#define STRENGTH(x) ((x) << 12)
#define S4MA 0	/* used to define a 4 mA drive strength */
#define S8MA 1	/* used to define a 8 mA drive strength */
#define S12MA 2	/* used to define a 12 mA drive strength */
#define S16MA 3	/* used to define a 16 mA drive strength,
		   not all pads can drive this current! */
#define GET_STRENGTH(x) (((x) >> 12) & 0x3)

/* control pad's pull up / bit keeper feature */
#define PE (1 << 11)
#define BK (1 << 22)
#define PE_PRESENT(x) (!!((x) & PE))
#define BK_PRESENT(x) (!!((x) & BK))
#define PULLUP(x) ((x) << 14)
#define BITKEEPER(x) ((x) << 14)
#define GET_PULLUP(x) (!!((x) & PULLUP(1)))
#define GET_BITKEEPER(x) (!!((x) & BITKEEPER(1)))

/* control pad's voltage feature */
#define VE (1 << 15)
#define VE_PRESENT(x) (!!((x) & VE))
#define VE_1_8V (0 << 16)
#define VE_3_3V (1 << 16)
#define GET_VOLTAGE(x) (!!((x) & (1 << 16)))

/* Bank 0, GPIO pins 0 ... 31 */
#define GPMI_RESETN		(FUNC(0) | PORTF(0, 28) | SE | VE | PE)
#define GPMI_RESETN_SSP3_CMD	(FUNC(1) | PORTF(0, 28) | SE | VE | PE)
#define GPMI_RESETN_GPIO	(FUNC(3) | PORTF(0, 28) | SE | VE | PE)
#define GPMI_CLE		(FUNC(0) | PORTF(0, 27) | SE | VE | PE)
#define GPMI_CLE_SSP3_D2	(FUNC(1) | PORTF(0, 27) | SE | VE | PE)
#define GPMI_CLE_SSP3_D5	(FUNC(2) | PORTF(0, 27) | SE | VE | PE)
#define GPMI_CLE_GPIO		(FUNC(3) | PORTF(0, 27) | SE | VE | PE)
#define GPMI_ALE		(FUNC(0) | PORTF(0, 26) | SE | VE | PE)
#define GPMI_ALE_SSP3_D1	(FUNC(1) | PORTF(0, 26) | SE | VE | PE)
#define GPMI_ALE_SSP3_D4	(FUNC(2) | PORTF(0, 26) | SE | VE | PE)
#define GPMI_ALE_GPIO		(FUNC(3) | PORTF(0, 26) | SE | VE | PE)
#define GPMI_WRN		(FUNC(0) | PORTF(0, 25) | SE | VE | BK)
#define GPMI_WRN_SSP1_SCK	(FUNC(1) | PORTF(0, 25) | SE | VE | BK)
#define GPMI_WRN_GPIO		(FUNC(3) | PORTF(0, 25) | SE | VE | BK)
#define GPMI_RDN		(FUNC(0) | PORTF(0, 24) | SE | VE | PE)
#define GPMI_RDN_SSP3_SCK	(FUNC(1) | PORTF(0, 24) | SE | VE | PE)
#define GPMI_RDN_GPIO		(FUNC(3) | PORTF(0, 24) | SE | VE | PE)
#define GPMI_READY3		(FUNC(0) | PORTF(0, 23) | SE | VE | PE)
#define GPMI_READY3_CAN0_RX	(FUNC(1) | PORTF(0, 23) | SE | VE | PE)
#define GPMI_READY3_HSDAC_TRIG	(FUNC(2) | PORTF(0, 23) | SE | VE | PE)
#define GPMI_READY3_GPIO	(FUNC(3) | PORTF(0, 23) | SE | VE | PE)
#define GPMI_READY2		(FUNC(0) | PORTF(0, 22) | SE | VE | PE)
#define GPMI_READY2_CAN0_TX	(FUNC(1) | PORTF(0, 22) | SE | VE | PE)
#define GPMI_READY2_ENET0_TX_ER	(FUNC(2) | PORTF(0, 22) | SE | VE | PE)
#define GPMI_READY2_GPIO	(FUNC(3) | PORTF(0, 22) | SE | VE | PE)
#define GPMI_READY1		(FUNC(0) | PORTF(0, 21) | SE | VE | PE)
#define GPMI_READY1_SSP1_CMD	(FUNC(1) | PORTF(0, 21) | SE | VE | PE)
#define GPMI_READY1_GPIO	(FUNC(3) | PORTF(0, 21) | SE | VE | PE)
#define GPMI_READY0		(FUNC(0) | PORTF(0, 20) | SE | VE | PE)
#define GPMI_READY0_SSP1_CD	(FUNC(1) | PORTF(0, 20) | SE | VE | PE)
#define GPMI_READY0_USB0_ID	(FUNC(2) | PORTF(0, 20) | SE | VE | PE)
#define GPMI_READY0_GPIO	(FUNC(3) | PORTF(0, 20) | SE | VE | PE)
#define GPMI_CE3N		(FUNC(0) | PORTF(0, 19) | SE | VE | PE)
#define GPMI_CE3N_CAN1_RX	(FUNC(1) | PORTF(0, 19) | SE | VE | PE)
#define GPMI_CE3N_SAIF1_MCLK	(FUNC(2) | PORTF(0, 19) | SE | VE | PE)
#define GPMI_CE3N_GPIO		(FUNC(3) | PORTF(0, 19) | SE | VE | PE)
#define GPMI_CE2N		(FUNC(0) | PORTF(0, 18) | SE | VE | PE)
#define GPMI_CE2N_CAN1_TX	(FUNC(1) | PORTF(0, 18) | SE | VE | PE)
#define GPMI_CE2N_ENET0_RX_ER	(FUNC(2) | PORTF(0, 18) | SE | VE | PE)
#define GPMI_CE2N_GPIO		(FUNC(3) | PORTF(0, 18) | SE | VE | PE)
#define GPMI_CE1N		(FUNC(0) | PORTF(0, 17) | SE | VE | PE)
#define GPMI_CE1N_SSP3_D3	(FUNC(1) | PORTF(0, 17) | SE | VE | PE)
#define GPMI_CE1N_GPIO		(FUNC(3) | PORTF(0, 17) | SE | VE | PE)
#define GPMI_CE0N		(FUNC(0) | PORTF(0, 16) | SE | VE | PE)
#define GPMI_CE0N_SSP3_D0	(FUNC(1) | PORTF(0, 16) | SE | VE | PE)
#define GPMI_CE0N_GPIO		(FUNC(3) | PORTF(0, 16) | SE | VE | PE)
#define GPMI_D7			(FUNC(0) | PORTF(0, 7) | SE | VE | PE)
#define GPMI_D7_SSP1_D7		(FUNC(1) | PORTF(0, 7) | SE | VE | PE)
#define GPMI_D7_GPIO		(FUNC(3) | PORTF(0, 7) | SE | VE | PE)
#define GPMI_D6			(FUNC(0) | PORTF(0, 6) | SE | VE | PE)
#define GPMI_D6_SSP1_D6		(FUNC(1) | PORTF(0, 6) | SE | VE | PE)
#define GPMI_D6_GPIO		(FUNC(3) | PORTF(0, 6) | SE | VE | PE)
#define GPMI_D5			(FUNC(0) | PORTF(0, 5) | SE | VE | PE)
#define GPMI_D5_SSP1_D5		(FUNC(1) | PORTF(0, 5) | SE | VE | PE)
#define GPMI_D5_GPIO		(FUNC(3) | PORTF(0, 5) | SE | VE | PE)
#define GPMI_D4			(FUNC(0) | PORTF(0, 4) | SE | VE | PE)
#define GPMI_D4_SSP1_D4		(FUNC(1) | PORTF(0, 4) | SE | VE | PE)
#define GPMI_D4_GPIO		(FUNC(3) | PORTF(0, 4) | SE | VE | PE)
#define GPMI_D3			(FUNC(0) | PORTF(0, 3) | SE | VE | PE)
#define GPMI_D3_SSP1_D3		(FUNC(1) | PORTF(0, 3) | SE | VE | PE)
#define GPMI_D3_GPIO		(FUNC(3) | PORTF(0, 3) | SE | VE | PE)
#define GPMI_D2			(FUNC(0) | PORTF(0, 2) | SE | VE | PE)
#define GPMI_D2_SSP1_D2		(FUNC(1) | PORTF(0, 2) | SE | VE | PE)
#define GPMI_D2_GPIO		(FUNC(3) | PORTF(0, 2) | SE | VE | PE)
#define GPMI_D1			(FUNC(0) | PORTF(0, 1) | SE | VE | PE)
#define GPMI_D1_SSP1_D1		(FUNC(1) | PORTF(0, 1) | SE | VE | PE)
#define GPMI_D1_GPIO		(FUNC(3) | PORTF(0, 1) | SE | VE | PE)
#define GPMI_D0			(FUNC(0) | PORTF(0, 0) | SE | VE | PE)
#define GPMI_D0_SSP1_D0		(FUNC(1) | PORTF(0, 0) | SE | VE | PE)
#define GPMI_D0_GPIO		(FUNC(3) | PORTF(0, 0) | SE | VE | PE)

/* Bank 1, GPIO pins 32 ... 63 */
#define LCD_ENABLE		(FUNC(0) | PORTF(1, 31) | SE | VE | BK)
#define LCD_ENABLE_GPIO		(FUNC(3) | PORTF(1, 31) | SE | VE | BK)
#define LCD_DOTCLK		(FUNC(0) | PORTF(1, 30) | SE | VE | BK)
#define LCD_DOTCLK_SAIF1_MCLK	(FUNC(1) | PORTF(1, 30) | SE | VE | BK)
#define LCD_DOTCLK_ETM_TCLK	(FUNC(2) | PORTF(1, 30) | SE | VE | BK)
#define LCD_DOTCLK_GPIO		(FUNC(3) | PORTF(1, 30) | SE | VE | BK)
#define LCD_HSYNC		(FUNC(0) | PORTF(1, 29) | SE | VE | BK)
#define LCD_HSYNC_SAIF1_SDATA1	(FUNC(1) | PORTF(1, 29) | SE | VE | BK)
#define LCD_HSYNC_ETM_TCTL	(FUNC(2) | PORTF(1, 29) | SE | VE | BK)
#define LCD_HSYNC_GPIO		(FUNC(3) | PORTF(1, 29) | SE | VE | BK)
#define LCD_VSYNC		(FUNC(0) | PORTF(1, 28) | SE | VE | BK)
#define LCD_VSYNC_SAIF1_SDATA0	(FUNC(1) | PORTF(1, 28) | SE | VE | BK)
#define LCD_VSYNC_GPIO		(FUNC(3) | PORTF(1, 28) | SE | VE | BK)
#define LCD_CS			(FUNC(0) | PORTF(1, 27) | SE | VE | BK)
#define LCD_CS_LCD_ENABLE	(FUNC(1) | PORTF(1, 27) | SE | VE | BK)
#define LCD_CS_GPIO		(FUNC(3) | PORTF(1, 27) | SE | VE | BK)
#define LCD_RS			(FUNC(0) | PORTF(1, 26) | SE | VE | BK)
#define LCD_RS_LCD_DOTCLK	(FUNC(1) | PORTF(1, 26) | SE | VE | BK)
#define LCD_RS_GPIO		(FUNC(3) | PORTF(1, 26) | SE | VE | BK)
#define LCD_WR_RWN		(FUNC(0) | PORTF(1, 25) | SE | VE | BK)
#define LCD_WR_RWN_LCD_HSYNC	(FUNC(1) | PORTF(1, 25) | SE | VE | BK)
#define LCD_WR_RWN_ETM_TCLK	(FUNC(2) | PORTF(1, 25) | SE | VE | BK)
#define LCD_WR_RWN_GPIO		(FUNC(3) | PORTF(1, 25) | SE | VE | BK)
#define LCD_RD_E		(FUNC(0) | PORTF(1, 24) | SE | VE | BK)
#define LCD_RD_E_LCD_VSYNC	(FUNC(1) | PORTF(1, 24) | SE | VE | BK)
#define LCD_RD_E_ETM_TCTL	(FUNC(2) | PORTF(1, 24) | SE | VE | BK)
#define LCD_RD_E_GPIO		(FUNC(3) | PORTF(1, 24) | SE | VE | BK)
#define LCD_D23			(FUNC(0) | PORTF(1, 23) | SE | VE | BK)
#define LCD_D23_ENET1_1588_EVENT3_IN (FUNC(1) | PORTF(1, 23) | SE | VE | BK)
#define LCD_D23_ETM_DA0		(FUNC(2) | PORTF(1, 23) | SE | VE | BK)
#define LCD_D23_GPIO		(FUNC(3) | PORTF(1, 23) | SE | VE | BK)
#define LCD_D22			(FUNC(0) | PORTF(1, 22) | SE | VE | BK)
#define LCD_D22_ENET1_1588_EVENT3_OUT (FUNC(1) | PORTF(1, 22) | SE | VE | BK)
#define LCD_D22_ETM_DA1		(FUNC(2) | PORTF(1, 22) | SE | VE | BK)
#define LCD_D22_GPIO		(FUNC(3) | PORTF(1, 22) | SE | VE | BK)
#define LCD_D21			(FUNC(0) | PORTF(1, 21) | SE | VE | BK)
#define LCD_D21_ENET1_1588_EVENT2_IN (FUNC(1) | PORTF(1, 21) | SE | VE | BK)
#define LCD_D21_ETM_DA2		(FUNC(2) | PORTF(1, 21) | SE | VE | BK)
#define LCD_D21_GPIO		(FUNC(3) | PORTF(1, 21) | SE | VE | BK)
#define LCD_D20			(FUNC(0) | PORTF(1, 20) | SE | VE | BK)
#define LCD_D20_ENET1_1588_EVENT2_OUT (FUNC(1) | PORTF(1, 20) | SE | VE | BK)
#define LCD_D20_ETM_DA3		(FUNC(2) | PORTF(1, 20) | SE | VE | BK)
#define LCD_D20_GPIO		(FUNC(3) | PORTF(1, 20) | SE | VE | BK)
#define LCD_D19			(FUNC(0) | PORTF(1, 19) | SE | VE | BK)
#define LCD_D19_ETM_DA4		(FUNC(2) | PORTF(1, 19) | SE | VE | BK)
#define LCD_D19_GPIO		(FUNC(3) | PORTF(1, 19) | SE | VE | BK)
#define LCD_D18			(FUNC(0) | PORTF(1, 18) | SE | VE | BK)
#define LCD_D18_ETM_DA5		(FUNC(2) | PORTF(1, 18) | SE | VE | BK)
#define LCD_D18_GPIO		(FUNC(3) | PORTF(1, 18) | SE | VE | BK)
#define LCD_D17			(FUNC(0) | PORTF(1, 17) | SE | VE | BK)
#define LCD_D17_ETM_DA6		(FUNC(2) | PORTF(1, 17) | SE | VE | BK)
#define LCD_D17_GPIO		(FUNC(3) | PORTF(1, 17) | SE | VE | BK)
#define LCD_D16			(FUNC(0) | PORTF(1, 16) | SE | VE | BK)
#define LCD_D16_ETM_DA7		(FUNC(2) | PORTF(1, 16) | SE | VE | BK)
#define LCD_D16_GPIO		(FUNC(3) | PORTF(1, 16) | SE | VE | BK)
#define LCD_D15			(FUNC(0) | PORTF(1, 15) | SE | VE | BK)
#define LCD_D15_ETM_DA15	(FUNC(2) | PORTF(1, 15) | SE | VE | BK)
#define LCD_D15_GPIO		(FUNC(3) | PORTF(1, 15) | SE | VE | BK)
#define LCD_D14			(FUNC(0) | PORTF(1, 14) | SE | VE | BK)
#define LCD_D14_ETM_DA14	(FUNC(2) | PORTF(1, 14) | SE | VE | BK)
#define LCD_D14_GPIO		(FUNC(3) | PORTF(1, 14) | SE | VE | BK)
#define LCD_D13			(FUNC(0) | PORTF(1, 13) | SE | VE | BK)
#define LCD_D13_ETM_DA13	(FUNC(2) | PORTF(1, 13) | SE | VE | BK)
#define LCD_D13_GPIO		(FUNC(3) | PORTF(1, 13) | SE | VE | BK)
#define LCD_D12			(FUNC(0) | PORTF(1, 12) | SE | VE | BK)
#define LCD_D12_ETM_DA12	(FUNC(2) | PORTF(1, 12) | SE | VE | BK)
#define LCD_D12_GPIO		(FUNC(3) | PORTF(1, 12) | SE | VE | BK)
#define LCD_D11			(FUNC(0) | PORTF(1, 11) | SE | VE | BK)
#define LCD_D11_ETM_DA11	(FUNC(2) | PORTF(1, 11) | SE | VE | BK)
#define LCD_D11_GPIO		(FUNC(3) | PORTF(1, 11) | SE | VE | BK)
#define LCD_D10			(FUNC(0) | PORTF(1, 10) | SE | VE | BK)
#define LCD_D10_ETM_DA10	(FUNC(2) | PORTF(1, 10) | SE | VE | BK)
#define LCD_D10_GPIO		(FUNC(3) | PORTF(1, 10) | SE | VE | BK)
#define LCD_D9			(FUNC(0) | PORTF(1, 9) | SE | VE | BK)
#define LCD_D9_ETM_DA4		(FUNC(1) | PORTF(1, 9) | SE | VE | BK)
#define LCD_D9_ETM_DA9		(FUNC(2) | PORTF(1, 9) | SE | VE | BK)
#define LCD_D9_GPIO		(FUNC(3) | PORTF(1, 9) | SE | VE | BK)
#define LCD_D8			(FUNC(0) | PORTF(1, 8) | SE | VE | BK)
#define LCD_D8_ETM_DA3		(FUNC(1) | PORTF(1, 8) | SE | VE | BK)
#define LCD_D8_ETM_DA8		(FUNC(2) | PORTF(1, 8) | SE | VE | BK)
#define LCD_D8_GPIO		(FUNC(3) | PORTF(1, 8) | SE | VE | BK)
#define LCD_D7			(FUNC(0) | PORTF(1, 7) | SE | VE | BK)
#define LCD_D7_ETM_DA7		(FUNC(2) | PORTF(1, 7) | SE | VE | BK)
#define LCD_D7_GPIO		(FUNC(3) | PORTF(1, 7) | SE | VE | BK)
#define LCD_D6			(FUNC(0) | PORTF(1, 6) | SE | VE | BK)
#define LCD_D6_ETM_DA6		(FUNC(2) | PORTF(1, 6) | SE | VE | BK)
#define LCD_D6_GPIO		(FUNC(3) | PORTF(1, 6) | SE | VE | BK)
#define LCD_D5			(FUNC(0) | PORTF(1, 5) | SE | VE | BK)
#define LCD_D5_ETM_DA5		(FUNC(2) | PORTF(1, 5) | SE | VE | BK)
#define LCD_D5_GPIO		(FUNC(3) | PORTF(1, 5) | SE | VE | BK)
#define LCD_D4			(FUNC(0) | PORTF(1, 4) | SE | VE | BK)
#define LCD_D4_ETM_DA9		(FUNC(1) | PORTF(1, 4) | SE | VE | BK)
#define LCD_D4_ETM_DA4		(FUNC(2) | PORTF(1, 4) | SE | VE | BK)
#define LCD_D4_GPIO		(FUNC(3) | PORTF(1, 4) | SE | VE | BK)
#define LCD_D3			(FUNC(0) | PORTF(1, 3) | SE | VE | BK)
#define LCD_D3_ETM_DA8		(FUNC(1) | PORTF(1, 3) | SE | VE | BK)
#define LCD_D3_ETM_DA3		(FUNC(2) | PORTF(1, 3) | SE | VE | BK)
#define LCD_D3_GPIO		(FUNC(3) | PORTF(1, 3) | SE | VE | BK)
#define LCD_D2			(FUNC(0) | PORTF(1, 2) | SE | VE | BK)
#define LCD_D2_ETM_DA2		(FUNC(2) | PORTF(1, 2) | SE | VE | BK)
#define LCD_D2_GPIO		(FUNC(3) | PORTF(1, 2) | SE | VE | BK)
#define LCD_D1			(FUNC(0) | PORTF(1, 1) | SE | VE | BK)
#define LCD_D1_ETM_DA1		(FUNC(2) | PORTF(1, 1) | SE | VE | BK)
#define LCD_D1_GPIO		(FUNC(3) | PORTF(1, 1) | SE | VE | BK)
#define LCD_D0			(FUNC(0) | PORTF(1, 0) | SE | VE | BK)
#define LCD_D0_ETM_DA0		(FUNC(2) | PORTF(1, 0) | SE | VE | BK)
#define LCD_D0_GPIO		(FUNC(3) | PORTF(1, 0) | SE | VE | BK)

/* Bank 2, GPIO pins 64 ... 95 */
#define SSP3_D3			(FUNC(0) | PORTF(2, 27) | SE | VE | PE)
#define SSP3_D3_AUART4_CTS	(FUNC(1) | PORTF(2, 27) | SE | VE | PE)
#define SSP3_D3_ENET1_1588_EVENT1_IN (FUNC(2) | PORTF(2, 27) | SE | VE | PE)
#define SSP3_D3_GPIO		(FUNC(3) | PORTF(2, 27) | SE | VE | PE)
#define SSP3_D0			(FUNC(0) | PORTF(2, 26) | SE | VE | PE)
#define SSP3_D0_AUART4_RTS	(FUNC(1) | PORTF(2, 26) | SE | VE | PE)
#define SSP3_D0_ENET1_1588_EVENT1_OUT (FUNC(2) | PORTF(2, 26) | SE | VE | PE)
#define SSP3_D0_GPIO		(FUNC(3) | PORTF(2, 26) | SE | VE | PE)
#define SSP3_CMD		(FUNC(0) | PORTF(2, 25) | SE | VE | PE)
#define SSP3_CMD_AUART4_RX	(FUNC(1) | PORTF(2, 25) | SE | VE | PE)
#define SSP3_CMD_ENET1_1588_EVENT0_IN (FUNC(2) | PORTF(2, 25) | SE | VE | PE)
#define SSP3_CMD_GPIO		(FUNC(3) | PORTF(2, 25) | SE | VE | PE)
#define SSP3_SCK		(FUNC(0) | PORTF(2, 24) | SE | VE | PE)
#define SSP3_SCK_AUART4_TX	(FUNC(1) | PORTF(2, 24) | SE | VE | PE)
#define SSP3_SCK_ENET1_1588_EVENT0_OUT (FUNC(2) | PORTF(2, 24) | SE | VE | PE)
#define SSP3_SCK_GPIO		(FUNC(3) | PORTF(2, 24) | SE | VE | PE)
#define SSP2_D5			(FUNC(0) | PORTF(2, 21) | SE | VE | PE)
#define SSP2_D5_SSP2_D2		(FUNC(1) | PORTF(2, 21) | SE | VE | PE)
#define SSP2_D5_USB0_OC		(FUNC(2) | PORTF(2, 21) | SE | VE | PE)
#define SSP2_D5_GPIO		(FUNC(3) | PORTF(2, 21) | SE | VE | PE)
#define SSP2_D4			(FUNC(0) | PORTF(2, 20) | SE | VE | PE)
#define SSP2_D4_SSP2_D1		(FUNC(1) | PORTF(2, 20) | SE | VE | PE)
#define SSP2_D4_USB1_OC		(FUNC(2) | PORTF(2, 20) | SE | VE | PE)
#define SSP2_D4_GPIO		(FUNC(3) | PORTF(2, 20) | SE | VE | PE)
#define SSP2_D3			(FUNC(0) | PORTF(2, 19) | SE | VE | PE)
#define SSP2_D3_AUART3_TX	(FUNC(1) | PORTF(2, 19) | SE | VE | PE)
#define SSP2_D3_SAIF1_SDATA2	(FUNC(2) | PORTF(2, 19) | SE | VE | PE)
#define SSP2_D3_GPIO		(FUNC(3) | PORTF(2, 19) | SE | VE | PE)
#define SSP2_D0			(FUNC(0) | PORTF(2, 18) | SE | VE | PE)
#define SSP2_D0_AUART3_RX	(FUNC(1) | PORTF(2, 18) | SE | VE | PE)
#define SSP2_D0_SAIF1_SDATA1	(FUNC(2) | PORTF(2, 18) | SE | VE | PE)
#define SSP2_D0_GPIO		(FUNC(3) | PORTF(2, 18) | SE | VE | PE)
#define SSP2_CMD		(FUNC(0) | PORTF(2, 17) | SE | VE | PE)
#define SSP2_CMD_AUART2_TX	(FUNC(1) | PORTF(2, 17) | SE | VE | PE)
#define SSP2_CMD_SAIF0_SDATA2	(FUNC(2) | PORTF(2, 17) | SE | VE | PE)
#define SSP2_CMD_GPIO		(FUNC(3) | PORTF(2, 17) | SE | VE | PE)
#define SSP2_SCK		(FUNC(0) | PORTF(2, 16) | SE | VE | PE)
#define SSP2_SCK_AUART2_RX	(FUNC(1) | PORTF(2, 16) | SE | VE | PE)
#define SSP2_SCK_SAIF0_SDATA1	(FUNC(2) | PORTF(2, 16) | SE | VE | PE)
#define SSP2_SCK_GPIO		(FUNC(3) | PORTF(2, 16) | SE | VE | PE)
#define SSP1_D3			(FUNC(0) | PORTF(2, 15) | SE | VE | PE)
#define SSP1_D3_SSP2_D7		(FUNC(1) | PORTF(2, 15) | SE | VE | PE)
#define SSP1_D3_ENET_1588_EVENT3_IN (FUNC(2) | PORTF(4, 15) | SE | VE | PE)
#define SSP1_D3_GPIO		(FUNC(3) | PORTF(2, 15) | SE | VE | PE)
#define SSP1_D0			(FUNC(0) | PORTF(2, 14) | SE | VE | PE)
#define SSP1_D0_SSP2_D6		(FUNC(1) | PORTF(2, 14) | SE | VE | PE)
#define SSP1_D0_ENET_1588_EVENT3_OUT (FUNC(2) | PORTF(2, 14) | SE | VE | PE)
#define SSP1_D0_GPIO		(FUNC(3) | PORTF(2, 14) | SE | VE | PE)
#define SSP1_CMD		(FUNC(0) | PORTF(2, 13) | SE | VE | PE)
#define SSP1_CMD_SSP2_D2	(FUNC(1) | PORTF(2, 13) | SE | VE | PE)
#define SSP1_CMD_ENET_1588_EVENT2_IN (FUNC(2) | PORTF(2, 13) | SE | VE | PE)
#define SSP1_CMD_GPIO		(FUNC(3) | PORTF(2, 13) | SE | VE | PE)
#define SSP1_SCK		(FUNC(0) | PORTF(2, 12) | SE | VE | PE)
#define SSP1_SCK_SSP2_D1	(FUNC(1) | PORTF(2, 12) | SE | VE | PE)
#define SSP1_SCK_ENET_1588_EVENT2_OUT (FUNC(2) | PORTF(2, 12) | SE | VE | PE)
#define SSP1_SCK_GPIO		(FUNC(3) | PORTF(2, 12) | SE | VE | PE)
#define SSP0_SCK		(FUNC(0) | PORTF(2, 10) | SE | VE | BK)
#define SSP0_SCK_GPIO		(FUNC(3) | PORTF(2, 10) | SE | VE | BK)
#define SSP0_CD			(FUNC(0) | PORTF(2, 9) | SE | VE | PE)
#define SSP0_CD_GPIO		(FUNC(3) | PORTF(2, 9) | SE | VE | PE)
#define SSP0_CMD		(FUNC(0) | PORTF(2, 8) | SE | VE | PE)
#define SSP0_CMD_GPIO		(FUNC(3) | PORTF(2, 8) | SE | VE | PE)
#define SSP0_D7			(FUNC(0) | PORTF(2, 7) | SE | VE | PE)
#define SSP0_D7_SSP2_SCK	(FUNC(1) | PORTF(2, 7) | SE | VE | PE)
#define SSP0_D7_GPIO		(FUNC(3) | PORTF(2, 7) | SE | VE | PE)
#define SSP0_D6			(FUNC(0) | PORTF(2, 6) | SE | VE | PE)
#define SSP0_D6_SSP2_CMD	(FUNC(1) | PORTF(2, 6) | SE | VE | PE)
#define SSP0_D6_GPIO		(FUNC(3) | PORTF(2, 6) | SE | VE | PE)
#define SSP0_D5			(FUNC(0) | PORTF(2, 5) | SE | VE | PE)
#define SSP0_D5_SSP2_D3		(FUNC(1) | PORTF(2, 5) | SE | VE | PE)
#define SSP0_D5_GPIO		(FUNC(3) | PORTF(2, 5) | SE | VE | PE)
#define SSP0_D4			(FUNC(0) | PORTF(2, 4) | SE | VE | PE)
#define SSP0_D4_SSP2_D0		(FUNC(1) | PORTF(2, 4) | SE | VE | PE)
#define SSP0_D4_GPIO		(FUNC(3) | PORTF(2, 4) | SE | VE | PE)
#define SSP0_D3			(FUNC(0) | PORTF(2, 3) | SE | VE | PE)
#define SSP0_D3_GPIO		(FUNC(3) | PORTF(2, 3) | SE | VE | PE)
#define SSP0_D2			(FUNC(0) | PORTF(2, 2) | SE | VE | PE)
#define SSP0_D2_GPIO		(FUNC(3) | PORTF(2, 2) | SE | VE | PE)
#define SSP0_D1			(FUNC(0) | PORTF(2, 1) | SE | VE | PE)
#define SSP0_D1_GPIO		(FUNC(3) | PORTF(2, 1) | SE | VE | PE)
#define SSP0_D0			(FUNC(0) | PORTF(2, 0) | SE | VE | PE)
#define SSP0_D0_GPIO		(FUNC(3) | PORTF(2, 0) | SE | VE | PE)

/* Bank 3, GPIO pins 96 ... 127 */
#define LCD_RESET		(FUNC(0) | PORTF(3, 30))
#define LCD_RESET_LCD_VSYNC	(FUNC(1) | PORTF(3, 30))
#define LCD_RESET_GPIO		(FUNC(3) | PORTF(3, 30))
#define PWM4			(FUNC(0) | PORTF(3, 29))
#define PWM4_GPIO		(FUNC(3) | PORTF(3, 29))
#define PWM3			(FUNC(0) | PORTF(3, 28))
#define PWM3_GPIO		(FUNC(3) | PORTF(3, 28))
#define SPDIF_TX		(FUNC(0) | PORTF(3, 27) | SE | VE | BK)
#define SPDIF_TX_ENET1_RX_ER	(FUNC(2) | PORTF(3, 27) | SE | VE | BK)
#define SPDIF_TX_GPIO		(FUNC(3) | PORTF(3, 27) | SE | VE | BK)
#define SAIF1_SDATA0		(FUNC(0) | PORTF(3, 26) | SE | VE | BK)
#define SAIF1_SDATA0_PWM7	(FUNC(1) | PORTF(3, 26) | SE | VE | BK)
#define SAIF1_SDATA0_SAIF0_SDATA1 (FUNC(2) | PORTF(3, 26) | SE | VE | BK)
#define SAIF1_SDATA0_GPIO	(FUNC(3) | PORTF(3, 26) | SE | VE | BK)
#define I2C0_SDA		(FUNC(0) | PORTF(3, 25) | SE | VE | BK)
#define I2C0_SDA_TIMROT_ROTARYB	(FUNC(1) | PORTF(3, 25) | SE | VE | BK)
#define I2C0_SDA_DUART_TX	(FUNC(2) | PORTF(3, 25) | SE | VE | BK)
#define I2C0_SDA_GPIO		(FUNC(3) | PORTF(3, 25) | SE | VE | BK)
#define I2C0_SCL		(FUNC(0) | PORTF(3, 24) | SE | VE | BK)
#define I2C0_SCL_TIMROT_ROTARYA	(FUNC(1) | PORTF(3, 24) | SE | VE | BK)
#define I2C0_SCL_DUART_RX	(FUNC(2) | PORTF(3, 24) | SE | VE | BK)
#define I2C0_SCL_GPIO		(FUNC(3) | PORTF(3, 24) | SE | VE | BK)
#define SAIF0_SDATA0		(FUNC(0) | PORTF(3, 23) | SE | VE | BK)
#define SAIF0_SDATA0_PWM6	(FUNC(1) | PORTF(3, 23) | SE | VE | BK)
#define SAIF0_SDATA0_AUART4_TX	(FUNC(2) | PORTF(3, 23) | SE | VE | BK)
#define SAIF0_SDATA0_GPIO	(FUNC(3) | PORTF(3, 23) | SE | VE | BK)
#define SAIF0_BITCLK		(FUNC(0) | PORTF(3, 22) | SE | VE | BK)
#define SAIF0_BITCLK_PWM5	(FUNC(1) | PORTF(3, 22) | SE | VE | BK)
#define SAIF0_BITCLK_AUART4_RX	(FUNC(2) | PORTF(3, 22) | SE | VE | BK)
#define SAIF0_BITCLK_GPIO	(FUNC(3) | PORTF(3, 22) | SE | VE | BK)
#define SAIF0_LRCLK		(FUNC(0) | PORTF(3, 21) | SE | VE | BK)
#define SAIF0_LRCLK_PWM4	(FUNC(1) | PORTF(3, 21) | SE | VE | BK)
#define SAIF0_LRCLK_AUART4_RTS	(FUNC(2) | PORTF(3, 21) | SE | VE | BK)
#define SAIF0_LRCLK_GPIO	(FUNC(3) | PORTF(3, 21) | SE | VE | BK)
#define SAIF0_MCLK		(FUNC(0) | PORTF(3, 20) | SE | VE | BK)
#define SAIF0_MCLK_PWM3		(FUNC(1) | PORTF(3, 20) | SE | VE | BK)
#define SAIF0_MCLK_AUART4_CTS	(FUNC(2) | PORTF(3, 20) | SE | VE | BK)
#define SAIF0_MCLK_GPIO		(FUNC(3) | PORTF(3, 20) | SE | VE | BK)
#define PWM2			(FUNC(0) | PORTF(3, 18))
#define PWM2_USB0_ID		(FUNC(1) | PORTF(3, 18))
#define PWM2_USB1_OC		(FUNC(2) | PORTF(3, 18))
#define PWM2_GPIO		(FUNC(3) | PORTF(3, 18))
#define PWM1			(FUNC(0) | PORTF(3, 17))
#define PWM1_I2C1_SDA		(FUNC(1) | PORTF(3, 17))
#define PWM1_DUART_TX		(FUNC(2) | PORTF(3, 17))
#define PWM1_GPIO		(FUNC(3) | PORTF(3, 17))
#define PWM0			(FUNC(0) | PORTF(3, 16))
#define PWM0_I2C1_SCL		(FUNC(1) | PORTF(3, 16))
#define PWM0_DUART_RX		(FUNC(2) | PORTF(3, 16))
#define PWM0_GPIO		(FUNC(3) | PORTF(3, 16))
#define AUART3_RTS		(FUNC(0) | PORTF(3, 15) | SE | VE | BK)
#define AUART3_RTS_CAN1_RX	(FUNC(1) | PORTF(3, 15) | SE | VE | BK)
#define AUART3_RTS_ENET0_1588_EVENT1_IN	(FUNC(2) | PORTF(3, 15) | SE | VE | BK)
#define AUART3_RTS_GPIO		(FUNC(3) | PORTF(3, 15) | SE | VE | BK)
#define AUART3_CTS		(FUNC(0) | PORTF(3, 14) | SE | VE | BK | BK)
#define AUART3_CTS_CAN1_TX	(FUNC(1) | PORTF(3, 14) | SE | VE | BK)
#define AUART3_CTS_ENET0_1588_EVENT1_OUT (FUNC(2) | PORTF(3, 14) | SE | VE | BK)
#define AUART3_CTS_GPIO		(FUNC(3) | PORTF(3, 14) | SE | VE | BK)
#define AUART3_TX		(FUNC(0) | PORTF(3, 13) | SE | VE | BK)
#define AUART3_TX_CAN0_RX	(FUNC(1) | PORTF(3, 13) | SE | VE | BK)
#define AUART3_TX_ENET0_1588_EVENT0_IN	(FUNC(2) | PORTF(3, 13) | SE | VE | BK)
#define AUART3_TX_GPIO		(FUNC(3) | PORTF(3, 13) | SE | VE | BK)
#define AUART3_RX		(FUNC(0) | PORTF(3, 12) | SE | VE | BK)
#define AUART3_RX_CAN0_TX	(FUNC(1) | PORTF(3, 12) | SE | VE | BK)
#define AUART3_RX_ENET0_1588_EVENT0_OUT	(FUNC(2) | PORTF(3, 12) | SE | VE | BK)
#define AUART3_RX_GPIO		(FUNC(3) | PORTF(3, 12) | SE | VE | BK)
#define AUART2_RTS		(FUNC(0) | PORTF(3, 11) | SE | VE | BK)
#define AUART2_RTS_I2C1_SDA	(FUNC(1) | PORTF(3, 11) | SE | VE | BK)
#define AUART2_RTS_SAIF1_IRCLK	(FUNC(2) | PORTF(3, 11) | SE | VE | BK)
#define AUART2_RTS_GPIO		(FUNC(3) | PORTF(3, 11) | SE | VE | BK)
#define AUART2_CTS		(FUNC(0) | PORTF(3, 10) | SE | VE | BK)
#define AUART2_CTS_I2C1_SCL	(FUNC(1) | PORTF(3, 10) | SE | VE | BK)
#define AUART2_CTS_SAIF1_BITCLK	(FUNC(2) | PORTF(3, 10) | SE | VE | BK)
#define AUART2_CTS_GPIO		(FUNC(3) | PORTF(3, 10) | SE | VE | BK)
#define AUART2_TX		(FUNC(0) | PORTF(3, 9) | SE | VE | PE)
#define AUART2_TX_SSP3_D2	(FUNC(1) | PORTF(3, 9) | SE | VE | PE)
#define AUART2_TX_SSP3_D5	(FUNC(2) | PORTF(3, 9) | SE | VE | PE)
#define AUART2_TX_GPIO		(FUNC(3) | PORTF(3, 9) | SE | VE | PE)
#define AUART2_RX		(FUNC(0) | PORTF(3, 8) | SE | VE | PE)
#define AUART2_RX_SSP3_D1	(FUNC(1) | PORTF(3, 8) | SE | VE | PE)
#define AUART2_RX_SSP3_D4	(FUNC(2) | PORTF(3, 8) | SE | VE | PE)
#define AUART2_RX_GPIO		(FUNC(3) | PORTF(3, 8) | SE | VE | PE)
#define AUART1_RTS		(FUNC(0) | PORTF(3, 7) | SE | VE | PE)
#define AUART1_RTS_USB0_ID	(FUNC(1) | PORTF(3, 7) | SE | VE | PE)
#define AUART1_RTS_ROTARYB	(FUNC(2) | PORTF(3, 7) | SE | VE | PE)
#define AUART1_RTS_GPIO		(FUNC(3) | PORTF(3, 7) | SE | VE | PE)
#define AUART1_CTS		(FUNC(0) | PORTF(3, 6) | SE | VE | PE)
#define AUART1_CTS_USB0_OC	(FUNC(1) | PORTF(3, 6) | SE | VE | PE)
#define AUART1_CTS_ROTARYA	(FUNC(2) | PORTF(3, 6) | SE | VE | PE)
#define AUART1_CTS_GPIO		(FUNC(3) | PORTF(3, 6) | SE | VE | PE)
#define AUART1_TX		(FUNC(0) | PORTF(3, 5) | SE | VE | BK)
#define AUART1_TX_SSP3_CD	(FUNC(1) | PORTF(3, 5) | SE | VE | BK)
#define AUART1_TX_PWM1		(FUNC(2) | PORTF(3, 5) | SE | VE | BK)
#define AUART1_TX_GPIO		(FUNC(3) | PORTF(3, 5) | SE | VE | BK)
#define AUART1_RX		(FUNC(0) | PORTF(3, 4) | SE | VE | BK)
#define AUART1_RX_SSP2_CD	(FUNC(1) | PORTF(3, 4) | SE | VE | BK)
#define AUART1_RX_PWM0		(FUNC(2) | PORTF(3, 4) | SE | VE | BK)
#define AUART1_RX_GPIO		(FUNC(3) | PORTF(3, 4) | SE | VE | BK)
#define AUART0_RTS		(FUNC(0) | PORTF(3, 3) | SE | VE | BK)
#define AUART0_RTS_AUART4_TX	(FUNC(1) | PORTF(3, 3) | SE | VE | BK)
#define AUART0_RTS_DUART_TX	(FUNC(2) | PORTF(3, 3) | SE | VE | BK)
#define AUART0_RTS_GPIO		(FUNC(3) | PORTF(3, 3) | SE | VE | BK)
#define AUART0_CTS		(FUNC(0) | PORTF(3, 2) | SE | VE | BK)
#define AUART0_CTS_AUART4_RX	(FUNC(1) | PORTF(3, 2) | SE | VE | BK)
#define AUART0_CTS_DUART_RX	(FUNC(2) | PORTF(3, 2) | SE | VE | BK)
#define AUART0_CTS_GPIO		(FUNC(3) | PORTF(3, 2) | SE | VE | BK)
#define AUART0_TX		(FUNC(0) | PORTF(3, 1) | SE | VE | BK)
#define AUART0_TX_I2C0_SDA	(FUNC(1) | PORTF(3, 1) | SE | VE | BK)
#define AUART0_TX_DUART_RTS	(FUNC(2) | PORTF(3, 1) | SE | VE | BK)
#define AUART0_TX_GPIO		(FUNC(3) | PORTF(3, 1) | SE | VE | BK)
#define AUART0_RX		(FUNC(0) | PORTF(3, 0) | SE | VE | BK)
#define AUART0_RX_I2C0_SCL	(FUNC(1) | PORTF(3, 0) | SE | VE | BK)
#define AUART0_RX_DUART_CTS	(FUNC(2) | PORTF(3, 0) | SE | VE | BK)
#define AUART0_RX_GPIO		(FUNC(3) | PORTF(3, 0) | SE | VE | BK)

/* Bank 4, GPIO pins 128 ... 159 */
#define JTAG_RTCK		(FUNC(0) | PORTF(4, 20) | SE | VE | BK)
#define JTAG_RTCK_GPIO		(FUNC(3) | PORTF(4, 20) | SE | VE | BK)
#define ENET_CLK		(FUNC(0) | PORTF(4, 16) | SE | VE | BK)
#define ENET_CLK_GPIO		(FUNC(3) | PORTF(4, 16) | SE | VE | BK)
#define ENET0_CRS		(FUNC(0) | PORTF(4, 15) | SE | VE | BK)
#define ENET0_CRS_ENET1_RX_EN	(FUNC(1) | PORTF(4, 15) | SE | VE | BK)
#define ENET0_CRS_ENET0_1588_EVENT3_IN (FUNC(2) | PORTF(4, 15) | SE | VE | BK)
#define ENET0_CRS_GPIO		(FUNC(3) | PORTF(4, 15) | SE | VE | BK)
#define ENET0_COL		(FUNC(0) | PORTF(4, 14) | SE | VE | BK)
#define ENET0_COL_ENET1_TX_EN	(FUNC(1) | PORTF(4, 14) | SE | VE | BK)
#define ENET0_COL_1588_EVENT3_OUT (FUNC(2) | PORTF(4, 14) | SE | VE | BK)
#define ENET0_COL_GPIO		(FUNC(3) | PORTF(4, 14) | SE | VE | BK)
#define ENET0_RX_CLK		(FUNC(0) | PORTF(4, 13) | SE | VE | BK)
#define ENET0_RX_CLK_RX_ER	(FUNC(1) | PORTF(4, 13) | SE | VE | BK)
#define ENET0_RX_ENET0_1588_EVENT2_IN (FUNC(2) | PORTF(4, 13) | SE | VE | BK)
#define ENET0_RX_CLK_GPIO	(FUNC(3) | PORTF(4, 13) | SE | VE | BK)
#define ENET0_TXD3		(FUNC(0) | PORTF(4, 12) | SE | VE | BK)
#define ENET0_TXD3_ENET1_TXD1	(FUNC(1) | PORTF(4, 12) | SE | VE | BK)
#define ENET0_TXD3_ENET0_1588_EVENT1_IN (FUNC(2) | PORTF(4, 12) | SE | VE | BK)
#define ENET0_TXD3_GPIO		(FUNC(3) | PORTF(4, 12) | SE | VE | BK)
#define ENET0_TXD2		(FUNC(0) | PORTF(4, 11) | SE | VE | BK)
#define ENET0_TXD2_ENET1_TXD0	(FUNC(1) | PORTF(4, 11) | SE | VE | BK)
#define ENET0_TXD2_ENET0_1588_EVENT1_OUT (FUNC(2) | PORTF(4, 11) | SE | VE | BK)
#define ENET0_TXD2_GPIO		(FUNC(3) | PORTF(4, 11) | SE | VE | BK)
#define ENET0_RXD3		(FUNC(0) | PORTF(4, 10) | SE | VE | BK)
#define ENET0_RXD3_ENET1_RXD1	(FUNC(1) | PORTF(4, 10) | SE | VE | BK)
#define ENET0_RXD3_ENET0_1588_EVENT0_IN (FUNC(2) | PORTF(4, 10) | SE | VE | BK)
#define ENET0_RXD3_GPIO		(FUNC(3) | PORTF(4, 10) | SE | VE | BK)
#define ENET0_RXD2		(FUNC(0) | PORTF(4, 9) | SE | VE | BK)
#define ENET0_RXD2_ENET1_RXD0	(FUNC(1) | PORTF(4, 9) | SE | VE | BK)
#define ENET0_RXD2_ENET0_1588_EVENT0_OUT (FUNC(2) | PORTF(4, 9) | SE | VE | BK)
#define ENET0_RXD2_GPIO		(FUNC(3) | PORTF(4, 9) | SE | VE | BK)
#define ENET0_TXD1		(FUNC(0) | PORTF(4, 8) | SE | VE | PE)
#define ENET0_TXD1_GPMI_READY7	(FUNC(1) | PORTF(4, 8) | SE | VE | PE)
#define ENET0_TXD1_GPIO		(FUNC(3) | PORTF(4, 8) | SE | VE | PE)
#define ENET0_TXD0		(FUNC(0) | PORTF(4, 7) | SE | VE | PE)
#define ENET0_TXD0_GPMI_READY6	(FUNC(1) | PORTF(4, 7) | SE | VE | PE)
#define ENET0_TXD0_GPIO		(FUNC(3) | PORTF(4, 7) | SE | VE | PE)
#define ENET0_TX_EN		(FUNC(0) | PORTF(4, 6) | SE | VE | PE)
#define ENET0_TX_EN_GPMI_READY5	(FUNC(1) | PORTF(4, 6) | SE | VE | PE)
#define ENET0_TX_EN_GPIO	(FUNC(3) | PORTF(4, 6) | SE | VE | PE)
#define ENET0_TX_CLK		(FUNC(0) | PORTF(4, 5) | SE | VE | BK)
#define ENET0_TX_CLK_HSADC_TRIGGER (FUNC(1) | PORTF(4, 5) | SE | VE | BK)
#define ENET0_TX_CLK_ENET0_1588_EVENT2_OUT (FUNC(2) | PORTF(4, 5) | SE | VE | BK)
#define ENET0_TX_CLK_GPIO	(FUNC(3) | PORTF(4, 5) | SE | VE | BK)
#define ENET0_RXD1		(FUNC(0) | PORTF(4, 4) | SE | VE | PE)
#define ENET0_RXD1_GPMI_READY4	(FUNC(1) | PORTF(4, 4) | SE | VE | PE)
#define ENET0_RXD1_GPIO		(FUNC(3) | PORTF(4, 4) | SE | VE | PE)
#define ENET0_RXD0		(FUNC(0) | PORTF(4, 3) | SE | VE | PE)
#define ENET0_RXD0_GPMI_CE7N	(FUNC(1) | PORTF(4, 3) | SE | VE | PE)
#define ENET0_RXD0_SAIF1_SDATA2	(FUNC(2) | PORTF(4, 3) | SE | VE | PE)
#define ENET0_RXD0_GPIO		(FUNC(3) | PORTF(4, 3) | SE | VE | PE)
#define ENET0_RX_EN		(FUNC(0) | PORTF(4, 2) | SE | VE | PE)
#define ENET0_RX_EN_GPMI_CE6N	(FUNC(1) | PORTF(4, 2) | SE | VE | PE)
#define ENET0_RX_EN_SAIF1_SDATA1 (FUNC(2) | PORTF(4, 2) | SE | VE | PE)
#define ENET0_RX_EN_GPIO	(FUNC(3) | PORTF(4, 2) | SE | VE | PE)
#define ENET0_MDIO		(FUNC(0) | PORTF(4, 1) | SE | VE | PE)
#define ENET0_MDIO_GPMI_CE5N	(FUNC(1) | PORTF(4, 1) | SE | VE | PE)
#define ENET0_MDIO_SAIF0_SDATA2	(FUNC(2) | PORTF(4, 1) | SE | VE | PE)
#define ENET0_MDIO_GPIO		(FUNC(3) | PORTF(4, 1) | SE | VE | PE)
#define ENET0_MDC		(FUNC(0) | PORTF(4, 0) | SE | VE | PE)
#define ENET0_MDC_GPMI_CE4N	(FUNC(1) | PORTF(4, 0) | SE | VE | PE)
#define ENET0_MDC_SAIF0_SDATA1	(FUNC(2) | PORTF(4, 0) | SE | VE | PE)
#define ENET0_MDC_GPIO		(FUNC(3) | PORTF(4, 0) | SE | VE | PE)

/*
 * Bank 5, GPIO pins 160 ... 191
 * Note: These pins are disabled instead of being GPIOs
 */
#define EMI_DDR_OPEN		(FUNC(0) | PORTF(5, 26) | BK)
#define EMI_DDR_OPEN_OFF	(FUNC(3) | PORTF(5, 26) | BK)
#define EMI_DSQ1		(FUNC(0) | PORTF(5, 23) | BK)
#define EMI_DSQ1_OFF		(FUNC(3) | PORTF(5, 23) | BK)
#define EMI_DSQ0		(FUNC(0) | PORTF(5, 22) | BK)
#define EMI_DSQ0_OFF		(FUNC(3) | PORTF(5, 22) | BK)
#define EMI_CLK			(FUNC(0) | PORTF(5, 21) | BK)
#define EMI_CLK_OFF		(FUNC(3) | PORTF(5, 21) | BK)
#define EMI_DDR_OPEN_FB		(FUNC(0) | PORTF(5, 20) | BK)
#define EMI_DDR_OPEN_FB_OFF	(FUNC(3) | PORTF(5, 20) | BK)
#define EMI_DQM1		(FUNC(0) | PORTF(5, 19) | BK)
#define EMI_DQM1_OFF		(FUNC(3) | PORTF(5, 19) | BK)
#define EMI_ODT1		(FUNC(0) | PORTF(5, 18) | BK)
#define EMI_ODT1_OFF		(FUNC(3) | PORTF(5, 18) | BK)
#define EMI_DQM0		(FUNC(0) | PORTF(5, 17) | BK)
#define EMI_DQM0_OFF		(FUNC(3) | PORTF(5, 17) | BK)
#define EMI_ODT0		(FUNC(0) | PORTF(5, 16) | BK)
#define EMI_ODT0_OFF		(FUNC(3) | PORTF(5, 16) | BK)
#define EMI_DATA15		(FUNC(0) | PORTF(5, 15) | BK)
#define EMI_DATA15_OFF		(FUNC(3) | PORTF(5, 15) | BK)
#define EMI_DATA14		(FUNC(0) | PORTF(5, 14) | BK)
#define EMI_DATA14_OFF		(FUNC(3) | PORTF(5, 14) | BK)
#define EMI_DATA13		(FUNC(0) | PORTF(5, 13) | BK)
#define EMI_DATA13_OFF		(FUNC(3) | PORTF(5, 13) | BK)
#define EMI_DATA12		(FUNC(0) | PORTF(5, 12) | BK)
#define EMI_DATA12_OFF		(FUNC(3) | PORTF(5, 12) | BK)
#define EMI_DATA11		(FUNC(0) | PORTF(5, 11) | BK)
#define EMI_DATA10_OFF		(FUNC(3) | PORTF(5, 10) | BK)
#define EMI_DATA10		(FUNC(0) | PORTF(5, 10) | BK)
#define EMI_DATA10_OFF		(FUNC(3) | PORTF(5, 10) | BK)
#define EMI_DATA9		(FUNC(0) | PORTF(5, 9) | BK)
#define EMI_DATA9_OFF		(FUNC(3) | PORTF(5, 9) | BK)
#define EMI_DATA8		(FUNC(0) | PORTF(5, 8) | BK)
#define EMI_DATA8_OFF		(FUNC(3) | PORTF(5, 8) | BK)
#define EMI_DATA7		(FUNC(0) | PORTF(5, 7) | BK)
#define EMI_DATA7_OFF		(FUNC(3) | PORTF(5, 7) | BK)
#define EMI_DATA6		(FUNC(0) | PORTF(5, 6) | BK)
#define EMI_DATA6_OFF		(FUNC(3) | PORTF(5, 6) | BK)
#define EMI_DATA5		(FUNC(0) | PORTF(5, 5) | BK)
#define EMI_DATA5_OFF		(FUNC(3) | PORTF(5, 5) | BK)
#define EMI_DATA4		(FUNC(0) | PORTF(5, 4) | BK)
#define EMI_DATA4_OFF		(FUNC(3) | PORTF(5, 4) | BK)
#define EMI_DATA3		(FUNC(0) | PORTF(5, 3) | BK)
#define EMI_DATA3_OFF		(FUNC(3) | PORTF(5, 3) | BK)
#define EMI_DATA2		(FUNC(0) | PORTF(5, 2) | BK)
#define EMI_DATA2_OFF		(FUNC(3) | PORTF(5, 2) | BK)
#define EMI_DATA1		(FUNC(0) | PORTF(5, 1) | BK)
#define EMI_DATA1_OFF		(FUNC(3) | PORTF(5, 1) | BK)
#define EMI_DATA0		(FUNC(0) | PORTF(5, 0) | BK)
#define EMI_DATA0_OFF		(FUNC(3) | PORTF(5, 0) | BK)

/*
 * Bank 6, GPIO pins 192 ... 223
 * Note: This pins are disabled instead of being GPIOs
 */
#define EMI_CKE			(FUNC(0) | PORTF(6, 24) | BK)
#define EMI_CKE_OFF		(FUNC(3) | PORTF(6, 24) | BK)
#define EMI_CE1N		(FUNC(0) | PORTF(6, 23) | BK)
#define EMI_CE1N_OFF		(FUNC(3) | PORTF(6, 23) | BK)
#define EMI_CE0N		(FUNC(0) | PORTF(6, 22) | BK)
#define EMI_CE0N_OFF		(FUNC(3) | PORTF(6, 22) | BK)
#define EMI_WEN			(FUNC(0) | PORTF(6, 21) | BK)
#define EMI_WEN_OFF		(FUNC(3) | PORTF(6, 21) | BK)
#define EMI_RASN		(FUNC(0) | PORTF(6, 20) | BK)
#define EMI_RASN_OFF		(FUNC(3) | PORTF(6, 20) | BK)
#define EMI_CASN		(FUNC(0) | PORTF(6, 19) | BK)
#define EMI_CASN_OFF		(FUNC(3) | PORTF(6, 19) | BK)
#define EMI_BA2			(FUNC(0) | PORTF(6, 18) | BK)
#define EMI_BA2_OFF		(FUNC(3) | PORTF(6, 18) | BK)
#define EMI_BA1			(FUNC(0) | PORTF(6, 17) | BK)
#define EMI_BA1_OFF		(FUNC(3) | PORTF(6, 17) | BK)
#define EMI_BA0			(FUNC(0) | PORTF(6, 16) | BK)
#define EMI_BA0_OFF		(FUNC(3) | PORTF(6, 16) | BK)
#define EMI_A14			(FUNC(0) | PORTF(6, 14) | BK)
#define EMI_A14_OFF		(FUNC(3) | PORTF(6, 14) | BK)
#define EMI_A13			(FUNC(0) | PORTF(6, 13) | BK)
#define EMI_A13_OFF		(FUNC(3) | PORTF(6, 13) | BK)
#define EMI_A12			(FUNC(0) | PORTF(6, 12) | BK)
#define EMI_A12_OFF		(FUNC(3) | PORTF(6, 12) | BK)
#define EMI_A11			(FUNC(0) | PORTF(6, 11) | BK)
#define EMI_A11_OFF		(FUNC(3) | PORTF(6, 11) | BK)
#define EMI_A10			(FUNC(0) | PORTF(6, 10) | BK)
#define EMI_A10_OFF		(FUNC(3) | PORTF(6, 10) | BK)
#define EMI_A9			(FUNC(0) | PORTF(6, 9) | BK)
#define EMI_A9_OFF		(FUNC(3) | PORTF(6, 9) | BK)
#define EMI_A8			(FUNC(0) | PORTF(6, 8) | BK)
#define EMI_A8_OFF		(FUNC(3) | PORTF(6, 8) | BK)
#define EMI_A7			(FUNC(0) | PORTF(6, 7) | BK)
#define EMI_A7_OFF		(FUNC(3) | PORTF(6, 7) | BK)
#define EMI_A6			(FUNC(0) | PORTF(6, 6) | BK)
#define EMI_A6_OFF		(FUNC(3) | PORTF(6, 6) | BK)
#define EMI_A5			(FUNC(0) | PORTF(6, 5) | BK)
#define EMI_A5_OFF		(FUNC(3) | PORTF(6, 5) | BK)
#define EMI_A4			(FUNC(0) | PORTF(6, 4) | BK)
#define EMI_A4_OFF		(FUNC(3) | PORTF(6, 4) | BK)
#define EMI_A3			(FUNC(0) | PORTF(6, 3) | BK)
#define EMI_A3_OFF		(FUNC(3) | PORTF(6, 3) | BK)
#define EMI_A2			(FUNC(0) | PORTF(6, 2) | BK)
#define EMI_A2_OFF		(FUNC(3) | PORTF(6, 2) | BK)
#define EMI_A1			(FUNC(0) | PORTF(6, 1) | BK)
#define EMI_A1_OFF		(FUNC(3) | PORTF(6, 1) | BK)
#define EMI_A0			(FUNC(0) | PORTF(6, 0) | BK)
#define EMI_A0_OFF		(FUNC(3) | PORTF(6, 0) | BK)

#endif /* __MACH_IOMUX_IMX28_H */
