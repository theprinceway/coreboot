/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#define DGPU_RST_N GPP_U4
#define DGPU_PWR_EN GPP_U5
#define DGPU_GC6 GPP_D2

#ifndef __ACPI__

#include <soc/gpe.h>
#include <soc/gpio.h>

/* Pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
		// UART2_RXD
		PAD_NC(GPP_C20, NONE),
		// UART2_TXD
		PAD_CFG_NF(GPP_C21, UP_20K, DEEP, NF1),
		// DGPU_RST#_PCH
		PAD_CFG_TERM_GPO(GPP_U4, 0, NONE, DEEP),
		// DGPU_PWR_EN
		PAD_CFG_TERM_GPO(GPP_U5, 0, NONE, DEEP),
};

/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
		// PM_BATLOW #
		PAD_CFG_NF(GPD0, UP_20K, PWROK, NF1),
		// AC_PRESENT
		PAD_CFG_NF(GPD1, NATIVE, PWROK, NF1),
		// LAN_WAKEUP#
		PAD_CFG_GPI(GPD2, NONE, PWROK),
		// PWR_BTN#
		PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1),
		// SUSB#_PCH
		PAD_CFG_NF(GPD4, NONE, PWROK, NF1),
		// SUSC#_PCH
		PAD_CFG_NF(GPD5, NONE, PWROK, NF1),
		// SLP_A# test point
		PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
		// GPD7_REST
		PAD_CFG_TERM_GPO(GPD7, 1, NONE, PWROK),
		// SUS_CLK
		PAD_CFG_NF(GPD8, NONE, PWROK, NF1),
		// GPD9_RTD3
		PAD_CFG_TERM_GPO(GPD9, 0, NONE, PWROK),
		// SLP_S5# test point
		PAD_CFG_NF(GPD10, UP_20K, DEEP, NF1),
		// LAN_DISABLE#
		PAD_CFG_GPI(GPD11, UP_20K, DEEP),
		// ESPI_IO0_EC
		PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1),
		// ESPI_IO1_EC
		PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1),
		// ESPI_IO2_EC
		PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1),
		// ESPI_IO3_EC
		PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1),
		// ESPI_CS_EC#
		PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1),
		// ESPI_CLK_EC
		PAD_CFG_NF(GPP_A5, DN_20K, DEEP, NF1),
		// ESPI_RESET_N
		PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
		// NC
		PAD_NC(GPP_A7, NONE),
		// CNVI_RST#
		PAD_CFG_NF(GPP_A8, NONE, DEEP, NF2),
		// CNVI_CLKREQ
		PAD_CFG_NF(GPP_A9, NONE, DEEP, NF3),
		// NC
		PAD_NC(GPP_A10, NONE),
		// NC
		PAD_NC(GPP_A11, NONE),
		// SATAGP1
		PAD_NC(GPP_A12, NONE),
		// PCH_BT_EN
		PAD_CFG_TERM_GPO(GPP_A13, 1, NONE, PLTRST),
		// NC
		PAD_NC(GPP_A14, NONE),
		// NC
		PAD_NC(GPP_A15, NONE),
		// 10K pull-up
		PAD_NC(GPP_A16, NONE),
		// NC
		PAD_NC(GPP_A17, NONE),
		// HDMI_HPD
		PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1),
		// NC
		PAD_NC(GPP_A19, NONE),
		// NC
		PAD_NC(GPP_A20, NONE),
		// NC
		PAD_NC(GPP_A21, NONE),
		// NC
		PAD_NC(GPP_A22, NONE),
		// GPPC_A23_TBT_FORCE_PWR
		PAD_CFG_TERM_GPO(GPP_A23, 0, NONE, PLTRST),
		// VCCIN_AUX_VID0
		PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),
		// VCCIN_AUX_VID1
		PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),
		// VRALERT#_PD
		PAD_CFG_GPI(GPP_B2, UP_20K, DEEP),
		// GPP_B3 - touchpad interrupt
		PAD_CFG_GPI_APIC_EDGE_LOW(GPP_B3, NONE, PLTRST),
		// NC
		PAD_NC(GPP_B4, NONE),
		// Test point
		PAD_NC(GPP_B5, NONE),
		// Test point
		PAD_NC(GPP_B6, NONE),
		// NC
		PAD_NC(GPP_B7, NONE),
		// SB_BLON
		PAD_CFG_TERM_GPO(GPP_B8, 1, NONE, DEEP),
		// NC
		PAD_NC(GPP_B9, NONE),
		// NC
		PAD_NC(GPP_B10, NONE),
		// TBTA-PCH_I2C_INT
		PAD_CFG_NF(GPP_B11, NONE, PWROK, NF1),
		// SLP_S0#
		PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
		// PLT_RST#
		PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
		// PCH_SPKR
		PAD_CFG_TERM_GPO(GPP_B14, 0, NONE, DEEP),
		// PCH_GPP_B15 - TODO
		PAD_CFG_TERM_GPO(GPP_B15, 1, NONE, DEEP),
		// NC
		PAD_NC(GPP_B16, NONE),
		// NC
		PAD_NC(GPP_B17, NONE),
		// No reboot strap
		PAD_NC(GPP_B18, NONE),
		// NC
		PAD_NC(GPP_B19, NONE),
		// NC
		PAD_NC(GPP_B20, NONE),
		// NC
		PAD_NC(GPP_B21, NONE),
		// PCH_GPP_B22 - 20k pull-down
		PAD_NC(GPP_B22, NONE),
		// Clock frequency strap
		PAD_CFG_TERM_GPO(GPP_B23, 0, NONE, DEEP),
		// SMB_CLK and SMB_CLK_DDR
		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
		// SMB_DATA and SMB_DAT_DDR
		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
		// Intel AMT TLS strap
		PAD_NC(GPP_C2, NONE),
		// SML0_CLK
		PAD_CFG_NF(GPP_C3, NONE, DEEP, NF1),
		// SML0_DATA
		PAD_CFG_NF(GPP_C4, NONE, DEEP, NF1),
		// Boot strap bit 0
		PAD_NC(GPP_C5, NONE),
		// TBT-PCH_I2C_SCL
		PAD_CFG_NF(GPP_C6, NONE, PWROK, NF1),
		// TBT-PCH_I2C_SDA
		PAD_CFG_NF(GPP_C7, NONE, PWROK, NF1),
		// NC
		PAD_NC(GPP_C8, NONE),
		// NC
		PAD_NC(GPP_C9, NONE),
		// NC
		PAD_NC(GPP_C10, NONE),
		// NC
		PAD_NC(GPP_C11, NONE),
		// NC
		PAD_NC(GPP_C12, NONE),
		// NC
		PAD_NC(GPP_C13, NONE),
		// TPM_PIRQ#
		_PAD_CFG_STRUCT(GPP_C14, 0x40100100, 0x3000),
		// NC
		PAD_NC(GPP_C15, NONE),
		// T_SDA
		PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),
		// T_SCL
		PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),
		// PCH_I2C_SDA
		PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
		// PCH_I2C_SCL
		PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
		// UART2_RXD
		PAD_NC(GPP_C20, NONE),
		// UART2_TXD
		PAD_CFG_NF(GPP_C21, UP_20K, DEEP, NF1),
		// LAN_PLT_RST#
		PAD_CFG_TERM_GPO(GPP_C22, 1, NONE, PLTRST),
		// PCH_GPP_C23 - 4.7k pull-down
		_PAD_CFG_STRUCT(GPP_C23, 0x40880100, 0x0000),
		// DGPU_SELECT#
		PAD_CFG_GPI(GPP_D0, NONE, DEEP),
		// GPU_EVENT#
		PAD_CFG_TERM_GPO(GPP_D1, 1, NONE, PLTRST),
		// GC6_FB_EN_PCH
		PAD_CFG_GPI(GPP_D2, NONE, PLTRST),
		// DGPU_PWRGD_R
		PAD_CFG_GPI(GPP_D3, NONE, PLTRST),
		PAD_NC(GPP_D4, NONE),
		// SSD1_CLKREQ#
		PAD_CFG_NF(GPP_D5, NONE, DEEP, NF1),
		// WLAN_CLKREQ#
		PAD_CFG_NF(GPP_D6, NONE, DEEP, NF1),
		// PEG_CLKREQ#
		PAD_CFG_NF(GPP_D7, NONE, DEEP, NF1),
		// CARD_CLKREQ#
		PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
		// NC
		PAD_NC(GPP_D9, NONE),
		// 4.7k pull-up
		PAD_NC(GPP_D10, NONE),
		// BOARD_ID - low = GTX 1650Ti, high = GTX 1650 - check GPP_D12
		PAD_CFG_GPI(GPP_D11, DN_20K, DEEP),
		// GPP_D12 - low = NVIDIA GPU, high = Intel GPU only
		PAD_CFG_GPI(GPP_D12, DN_20K, DEEP),
		// dGPU_OVRM
		PAD_CFG_TERM_GPO(GPP_D13, 0, NONE, DEEP),
		// SSD1_PWR_DN#
		PAD_CFG_TERM_GPO(GPP_D14, 1, NONE, PLTRST),
		// NC
		PAD_NC(GPP_D15, NONE),
		// NC
		PAD_NC(GPP_D16, NONE),
		// DGPU_PRSNT#
		PAD_CFG_GPI(GPP_D17, DN_20K, DEEP),
		// 1V8_MAIN_EN_R
		PAD_CFG_GPI(GPP_D18, DN_20K, DEEP),
		// NC
		PAD_NC(GPP_D19, NONE),
		// Test point
		PAD_NC(GPP_E0, NONE),
		// ROM_I2C_EN
		PAD_CFG_TERM_GPO(GPP_E1, 0, NONE, PLTRST),
		// SWI#
		_PAD_CFG_STRUCT(GPP_E2, 0x40880100, 0x0000),
		// SCI# - unused, tunneled over eSPI
		PAD_CFG_GPI(GPP_E3, DN_20K, DEEP),
		// Test point
		PAD_NC(GPP_E4, NONE),
		// DEVSLP1
		PAD_NC(GPP_E5, NONE),
		// PCH_GPP_E6
		PAD_NC(GPP_E6, NONE),
		// SMI#
		_PAD_CFG_STRUCT(GPP_E7, 0x82840100, 0x0000),
		// PCH_SATAHDD_LED#
		PAD_NC(GPP_E8, NONE),
		// 10k pull-up
		PAD_NC(GPP_E9, NONE),
		// PCH_GPP_E10
		PAD_NC(GPP_E10, NONE),
		// PCH_GPP_E11
		PAD_NC(GPP_E11, NONE),
		// NC
		PAD_NC(GPP_E12, NONE),
		// NC
		PAD_NC(GPP_E13, NONE),
		// EDP_HPD
		PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
		// ALERT#_R
		PAD_NC(GPP_E15, NONE),
		// SB_KBCRST#
		PAD_CFG_GPI(GPP_E16, DN_20K, DEEP),
		// NC
		PAD_NC(GPP_E17, NONE),
		// GPP_E18_TBT_LSX0_TXD - TODO
		PAD_NC(GPP_E18, NATIVE),
		// GPP_E19_TBT_LSX0_RXD - TODO
		PAD_NC(GPP_E19, NATIVE),
		// NC
		PAD_NC(GPP_E20, NONE),
		// NC
		PAD_NC(GPP_E21, NONE),
		// NC
		PAD_NC(GPP_E22, NONE),
		// NC
		PAD_NC(GPP_E23, NONE),
		// CNVI_BRI_DT
		PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),
		// CNVI_BRI_RSP
		PAD_CFG_NF(GPP_F1, UP_20K, DEEP, NF1),
		// CNVI_RGI_DT
		PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),
		// CNVI_RGI_RSP
		PAD_CFG_NF(GPP_F3, UP_20K, DEEP, NF1),
		// NC
		PAD_NC(GPP_F4, NONE),
		// NC
		PAD_NC(GPP_F5, NONE),
		// CNVI_GNSS_PA_PLANKING - TODO
		PAD_NC(GPP_F6, NONE),
		// GPIO_LANRTD3
		PAD_CFG_TERM_GPO(GPP_F7, 1, NONE, DEEP),
		// NC
		PAD_NC(GPP_F8, NONE),
		// GPIO_LAN_EN
		PAD_CFG_TERM_GPO(GPP_F9, 1, NONE, DEEP),
		// 4.7k pull-up
		PAD_NC(GPP_F10, NONE),
		// NC
		PAD_NC(GPP_F11, NONE),
		// NC
		PAD_NC(GPP_F12, NONE),
		// NC
		PAD_NC(GPP_F13, NONE),
		// NC
		PAD_NC(GPP_F14, NONE),
		// NC
		PAD_NC(GPP_F15, NONE),
		// NC
		PAD_NC(GPP_F16, NONE),
		// TPM_DET#
		PAD_CFG_GPI(GPP_F17, NONE, PLTRST),
		// NC
		PAD_NC(GPP_F18, NONE),
		// NC
		PAD_NC(GPP_F19, NONE),
		// NC
		PAD_NC(GPP_F20, NONE),
		// EXT_PWR_GATE# - TODO
		PAD_CFG_GPI(GPP_F21, DN_20K, DEEP),
		// VNN_CTRL - TODO
		PAD_NC(GPP_F22, NONE),
		// 1P05_CTRL - TODO
		PAD_NC(GPP_F23, NONE),
		// GPP_H0_RTD3
		PAD_CFG_TERM_GPO(GPP_H0, 1, NONE, PLTRST),
		// 4.7k pull-up
		PAD_NC(GPP_H1, NONE),
		// 4.7k pull-up
		PAD_NC(GPP_H2, NONE),
		// NC
		PAD_CFG_GPI(GPP_H3, DN_20K, DEEP),
		// GPPH_I2C2_SDA
		PAD_CFG_NF(GPP_H4, NONE, DEEP, NF1),
		// GPPH_I2C2_SCL
		PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1),
		// NC
		PAD_NC(GPP_H6, NONE),
		// SWI# - TODO
		PAD_NC(GPP_H7, NONE),
		// CNVI_MFUART2_RXD - TODO
		PAD_CFG_GPI(GPP_H8, DN_20K, DEEP),
		// CNVI_MFUART2_TXD - TODO
		PAD_CFG_GPI(GPP_H9, DN_20K, DEEP),
		// LAN_CLKREQ#
		PAD_CFG_NF(GPP_H10, NONE, DEEP, NF1),
		// NC
		PAD_NC(GPP_H11, NONE),
		// NC
		PAD_NC(GPP_H12, NONE),
		// NC
		PAD_NC(GPP_H13, NONE),
		// NC
		PAD_NC(GPP_H14, NONE),
		// NC
		PAD_NC(GPP_H15, NONE),
		// HDMI_CTRLCLK
		PAD_CFG_NF(GPP_H16, NONE, DEEP, NF1),
		// HDMI_CTRLDATA
		PAD_CFG_NF(GPP_H17, NONE, DEEP, NF1),
		// CPU_C10_GATE#
		PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1),
		// CNVI_WAKE#
		PAD_NC(GPP_H19, NONE),
		// PM_CLKRUN#
		PAD_NC(GPP_H20, NONE),
		// NC
		PAD_NC(GPP_H21, NONE),
		// NC
		PAD_NC(GPP_H22, NONE),
		// NC
		PAD_NC(GPP_H23, NONE),
		// HDA_BITCLK
		PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1),
		// HDA_SYNC
		PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1),
		// HDA_SDOUT
		PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1),
		// HDA_SDIN0
		PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1),
		// AZ_RST#_R
		PAD_CFG_NF(GPP_R4, NONE, DEEP, NF1),
		// NC
		PAD_NC(GPP_R5, NONE),
		// NC
		PAD_NC(GPP_R6, NONE),
		// NC
		PAD_NC(GPP_R7, NONE),
		// NC
		PAD_NC(GPP_S0, NONE),
		// NC
		PAD_NC(GPP_S1, NONE),
		// NC
		PAD_NC(GPP_S2, NONE),
		// NC
		PAD_NC(GPP_S3, NONE),
		// NC
		PAD_NC(GPP_S4, NONE),
		// NC
		PAD_NC(GPP_S5, NONE),
		// GPPC_DMIC_CLK - TODO
		PAD_NC(GPP_S6, NONE),
		// GPPC_DMIC_DATA - TODO
		PAD_NC(GPP_S7, NONE),
		// NC
		PAD_NC(GPP_T2, NONE),
		// NC
		PAD_NC(GPP_T3, NONE),
		// DGPU_RST#_PCH
		PAD_CFG_TERM_GPO(GPP_U4, 1, NONE, DEEP),
		// DGPU_PWR_EN
		PAD_CFG_TERM_GPO(GPP_U5, 1, NONE, DEEP),
};

#endif

#endif
