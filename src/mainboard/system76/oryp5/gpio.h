/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#define DGPU_RST_N GPP_F22
#define DGPU_PWR_EN GPP_F23
// Not used for GC6 2.1: #define DGPU_GC6 GPP_C12

#ifndef __ACPI__

#include <soc/gpe.h>
#include <soc/gpio.h>

/* Pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
		PAD_CFG_TERM_GPO(GPP_F22, 0, NONE, DEEP), // DGPU_RST_N
		PAD_CFG_TERM_GPO(GPP_F23, 0, NONE, DEEP), // DGPU_PWR_EN
};

/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
		PAD_CFG_NF(GPD0, NONE, DEEP, NF1), // PM_BATLOW#
		PAD_CFG_NF(GPD1, NATIVE, DEEP, NF1), // AC_PRESENT
		PAD_CFG_GPI(GPD2, NATIVE, PWROK), // LAN_WAKEUP#
		PAD_CFG_NF(GPD3, UP_20K, DEEP, NF1), // PWR_BTN#
		PAD_CFG_NF(GPD4, NONE, DEEP, NF1), // SUSB#_PCH
		PAD_CFG_NF(GPD5, NONE, DEEP, NF1), // SUSC#_PCH
		PAD_CFG_NF(GPD6, UP_20K, PWROK, NF1), // NC
		PAD_CFG_GPI(GPD7, UP_20K, PWROK), // GPD_7
		PAD_CFG_NF(GPD8, NONE, DEEP, NF1), // SUSCLK
		PAD_CFG_GPI(GPD9, UP_20K, PWROK), // NC
		PAD_CFG_NF(GPD10, UP_20K, PWROK, NF1), // NC
		PAD_CFG_TERM_GPO(GPD11, 1, NONE, DEEP), // LAN_DISABLE#
		PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1), // SB_KBCRST#
		PAD_CFG_NF(GPP_A1, NONE, DEEP, NF1), // LPC_AD0
		PAD_CFG_NF(GPP_A2, NONE, DEEP, NF1), // LPC_AD1
		PAD_CFG_NF(GPP_A3, NONE, DEEP, NF1), // LPC_AD2
		PAD_CFG_NF(GPP_A4, NONE, DEEP, NF1), // LPC_AD3
		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1), // LPC_FRAME#
		PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1), // SERIRQ
		PAD_CFG_NF(GPP_A7, NONE, DEEP, NF1), // LPC_PIRQA#
		PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1), // PM_CLKRUN#
		PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1), // PCLK_KBC
		PAD_CFG_NF(GPP_A10, NONE, DEEP, NF1), // NC
		PAD_CFG_GPI_APIC_HIGH(GPP_A11, NONE, PLTRST), // INTP_OUT
		PAD_CFG_GPI(GPP_A12, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_A13, UP_20K, DEEP), // SUSWARN#
		PAD_CFG_GPI(GPP_A14, UP_20K, DEEP), // NC (test point)
		PAD_CFG_GPI(GPP_A15, UP_20K, DEEP), // SUS_PWR_ACK#
		PAD_CFG_GPI(GPP_A16, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_A17, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_A18, UP_20K, DEEP), // NC
		PAD_CFG_TERM_GPO(GPP_A19, 1, NONE, DEEP), // SB_BLON
		PAD_CFG_GPI(GPP_A20, NONE, DEEP), // PEX_WAKE#
		PAD_CFG_GPI(GPP_A21, UP_20K, DEEP), // NC
		PAD_CFG_TERM_GPO(GPP_A22, 1, NONE, DEEP), // WLAN_SSD2_GPIO1
		PAD_CFG_TERM_GPO(GPP_A23, 1, NONE, DEEP), // WLAN_SSD2_GPIO
		PAD_CFG_GPI(GPP_B0, UP_20K, DEEP), // TPM_PIRQ#
		PAD_CFG_GPI(GPP_B1, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_B2, UP_20K, DEEP), // NC
		PAD_CFG_TERM_GPO(GPP_B3, 1, NONE, DEEP), // BT_RF_KILL_R_N
		PAD_CFG_TERM_GPO(GPP_B4, 1, NONE, DEEP), // WIFI_RF_KILL_R_N
		PAD_CFG_GPI(GPP_B5, UP_20K, PLTRST), // NC
		PAD_CFG_GPI(GPP_B6, UP_20K, PLTRST), // NC
		PAD_CFG_TERM_GPO(GPP_B7, 1, NONE, PLTRST), // CR_GPIO_RST#
		PAD_CFG_TERM_GPO(GPP_B8, 1, NONE, PLTRST), // CR_GPIO_WAKE#
		PAD_CFG_GPI(GPP_B9, UP_20K, PLTRST), // NC
		PAD_CFG_TERM_GPO(GPP_B10, 0, NONE, PLTRST), // NC
		PAD_CFG_GPI(GPP_B11, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_B12, UP_20K, DEEP), // SLP_S0#
		PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1), // PLT_RST#
		PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1), // PCH_SPKR
		PAD_CFG_GPI(GPP_B15, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_B16, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_B17, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_B18, UP_20K, DEEP), // LPSS_GSPI0_MOSI
		PAD_CFG_GPI(GPP_B19, UP_20K, DEEP), // NC
		PAD_CFG_GPI_SMI(GPP_B20, NONE, DEEP, EDGE_SINGLE, NONE), // SMI#
		PAD_CFG_GPI(GPP_B21, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_B22, UP_20K, DEEP), // LPSS_GSPI1_MOSI
		PAD_CFG_GPI_SCI_LOW(GPP_B23, UP_20K, PLTRST, LEVEL), // SCI#
		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1), // SMB_CLK
		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1), // SMB_DATA
		PAD_CFG_GPI(GPP_C2, UP_20K, DEEP), // GPP_C2_BT_UART_WAKE_N
		PAD_CFG_GPI(GPP_C3, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_C4, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_C5, UP_20K, DEEP), // M.2_WLAN_WIFI_WAKE_N
		PAD_CFG_GPI(GPP_C6, UP_20K, DEEP), // SMC_CPU_THERM
		PAD_CFG_GPI(GPP_C7, UP_20K, DEEP), // SMD_CPU_THERM
		PAD_CFG_GPI(GPP_C8, NONE, DEEP), // TPM_DET
		PAD_CFG_GPI(GPP_C9, DN_20K, DEEP), // BOARD_ID1
		PAD_CFG_GPI(GPP_C10, DN_20K, DEEP), // BOARD_ID2
		PAD_CFG_GPI(GPP_C11, DN_20K, DEEP), // BOARD_ID3
		PAD_CFG_GPI(GPP_C12, NONE, DEEP), // GC6_FB_EN_PCH
		PAD_CFG_TERM_GPO(GPP_C13, 1, NONE, DEEP), // GPU_EVENT#
		PAD_CFG_TERM_GPO(GPP_C14, 1, NONE, DEEP), // M.2_PLT_RST_CNTRL1#
		PAD_CFG_TERM_GPO(GPP_C15, 1, NONE, DEEP), // M.2_PLT_RST_CNTRL2#
		PAD_CFG_NF(GPP_C16, NONE, PLTRST, NF1), // I2C_SDA_TP
		PAD_CFG_NF(GPP_C17, NONE, PLTRST, NF1), // I2C_SCL_TP
		PAD_CFG_NF(GPP_C18, NONE, PLTRST, NF1), // SMD_7411_I2C
		PAD_CFG_NF(GPP_C19, NONE, PLTRST, NF1), // SMC_7411_I2C
		PAD_CFG_NF(GPP_C20, UP_20K, DEEP, NF1), // UART2_RXD ==> NC (test point)
		PAD_CFG_NF(GPP_C21, UP_20K, DEEP, NF1), // UART2_TXD ==> NC (test point)
		PAD_CFG_NF(GPP_C22, UP_20K, DEEP, NF1), // UART2_RTS# (test point), LAN_PLT_RST#
		PAD_CFG_NF(GPP_C23, UP_20K, DEEP, NF1), // BOARD_ID4
		PAD_CFG_GPI(GPP_D0, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D1, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D2, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D3, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D4, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_D5, NONE, DEEP, NF3), // M.2_BT_PCMFRM_CRF_RST_N
		PAD_CFG_NF(GPP_D6, NONE, DEEP, NF3), // M.2_BT_PCMOUT_CLKREQ0
		PAD_CFG_GPI(GPP_D7, UP_20K, DEEP), // M.2_BT_PCMIN
		PAD_CFG_GPI(GPP_D8, UP_20K, DEEP), // M.2_BT_PCMCLK
		PAD_CFG_GPI(GPP_D9, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D10, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D11, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D12, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D13, UP_20K, DEEP), // 10k pull up
		PAD_CFG_GPI(GPP_D14, UP_20K, DEEP), // 10k pull up
		PAD_CFG_GPI(GPP_D15, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D16, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_D17, UP_20K, DEEP, NF1), // NC
		PAD_CFG_NF(GPP_D18, UP_20K, DEEP, NF1), // NC
		PAD_CFG_NF(GPP_D19, UP_20K, DEEP, NF1), // NC
		PAD_CFG_NF(GPP_D20, UP_20K, DEEP, NF1), // NC
		PAD_CFG_GPI(GPP_D21, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D22, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_D23, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_E0, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_E1, NONE, DEEP, NF1), // M.2_SSD1_PEDET
		PAD_CFG_GPI(GPP_E2, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_E3, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_E4, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_E5, UP_20K, DEEP), // M2_P0_SATA_DEVSLP
		PAD_CFG_GPI(GPP_E6, UP_20K, DEEP), // NC
		PAD_CFG_GPI_APIC_EDGE_LOW(GPP_E7, NONE, PLTRST), // TP_ATTN#
		PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1), // PCH_SATAHDD_LED#
		PAD_CFG_GPI(GPP_E9, UP_20K, DEEP), // USB_OC0# ==> NC (test point)
		PAD_CFG_GPI(GPP_E10, UP_20K, DEEP), // USB_OC1# ==> NC (test point)
		PAD_CFG_GPI(GPP_E11, UP_20K, DEEP), // USB_OC2# ==> NC (test point)
		PAD_CFG_GPI(GPP_E12, UP_20K, DEEP), // USB_OC3# ==> NC (test point)
		PAD_CFG_GPI(GPP_F0, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1), // M.2_SSD2_PEDET
		PAD_CFG_GPI(GPP_F2, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F3, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F4, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F5, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1), // M2_P4_SATA_DEVSLP
		PAD_CFG_GPI(GPP_F7, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F8, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F9, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F10, UP_20K, DEEP), // BIOS_REC
		PAD_CFG_GPI(GPP_F11, UP_20K, DEEP), // GPP_F11
		PAD_CFG_GPI(GPP_F12, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F13, UP_20K, DEEP), // GP39_GFX_CRB_DETECT
		PAD_CFG_GPI(GPP_F14, UP_20K, DEEP), // 10k pull up to H_SKTOCC_N
		PAD_CFG_GPI(GPP_F15, UP_20K, DEEP), // USB_OC4# ==> NC (test point)
		PAD_CFG_GPI(GPP_F16, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F17, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_F18, UP_20K, DEEP), // USB_OC7# ==> NC (test point)
		PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1), // NB_ENAVDD
		PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1), // BLON
		PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1), // EDP_BRIGHTNESS
		PAD_CFG_TERM_GPO(GPP_F22, 1, NONE, DEEP), // DGPU_RST#_PCH
		PAD_CFG_TERM_GPO(GPP_F23, 1, NONE, DEEP), // DGPU_PWR_EN
		PAD_CFG_GPI(GPP_G0, UP_20K, DEEP), // NC
		PAD_NC(GPP_G1, NONE), // CNVI_WIGIG_DET#
		PAD_CFG_GPI(GPP_G2, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_G3, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_G4, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_G5, UP_20K, DEEP), // NC
		PAD_CFG_GPI_SCI_LOW(GPP_G6, NONE, DEEP, LEVEL), // SWI#
		PAD_CFG_GPI(GPP_G7, UP_20K, DEEP), // NC
		PAD_CFG_TERM_GPO(GPP_H0, 0, NONE, PLTRST), // NC
		PAD_CFG_TERM_GPO(GPP_H1, 0, NONE, PLTRST), // NC
		PAD_CFG_NF(GPP_H2, NONE, DEEP, NF1), // CLK_REQ9_PEG#
		PAD_CFG_TERM_GPO(GPP_H3, 0, NONE, PLTRST), // NC
		PAD_CFG_TERM_GPO(GPP_H4, 0, NONE, PLTRST), // NC
		PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1), // CLK_REQ12_SSD2#
		PAD_CFG_NF(GPP_H6, NONE, DEEP, NF1), // CLK_REQ13_SSD1#
		PAD_CFG_NF(GPP_H7, NONE, DEEP, NF1), // GPP_H_0_SRCCLKREQB_14
		PAD_CFG_NF(GPP_H8, NONE, DEEP, NF1), // CLK_REQ15_LAN#
		PAD_CFG_NF(GPP_H9, NONE, DEEP, NF1), // CLK_REQ16_CARD#
		PAD_CFG_GPI(GPP_H10, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H11, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H12, UP_20K, DEEP), // GPP_H_12 (test point)
		PAD_CFG_GPI(GPP_H13, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H14, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H15, UP_20K, DEEP), // GPP_H15
		PAD_CFG_GPI(GPP_H16, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H17, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H18, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H19, UP_20K, DEEP), // GPIO_CARD1
		PAD_CFG_GPI(GPP_H20, UP_20K, DEEP), // GPIO_CARD
		PAD_CFG_GPI(GPP_H21, DN_20K, DEEP), // 4.7k pull up, 20k pull down
		PAD_CFG_GPI(GPP_H22, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_H23, UP_20K, DEEP), // NC
		PAD_CFG_GPI_SCI_LOW(GPP_I0, NONE, DEEP, EDGE_BOTH), // G_DP_DHPD_A
		PAD_CFG_GPI_SCI_LOW(GPP_I1, NONE, DEEP, EDGE_BOTH), // HDMI_HPD
		PAD_CFG_GPI_SCI_LOW(GPP_I2, NONE, DEEP, EDGE_BOTH), // G_DP_DHPD_E
		PAD_CFG_GPI(GPP_I3, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_I4, NONE, DEEP, NF1), // EDP_HDP
		PAD_CFG_GPI(GPP_I5, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I6, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I7, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I8, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I9, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I10, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I11, UP_20K, DEEP), // H_SKTOCC_N
		PAD_CFG_TERM_GPO(GPP_I12, 1, NONE, DEEP), // SATA_PWR_EN
		PAD_CFG_GPI(GPP_I13, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_I14, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_J0, NONE, DEEP, NF1), // CNVI_GNSS_PA_BLANKING
		PAD_CFG_TERM_GPO(GPP_J1, 1, NONE, DEEP), // GPP_J1
		PAD_CFG_GPI(GPP_J2, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_J3, UP_20K, DEEP), // NC
		PAD_CFG_NF(GPP_J4, NONE, DEEP, NF1), // M.2_CNV_VRI_DT_BT_UART0_RTS
		PAD_CFG_NF(GPP_J5, UP_20K, DEEP, NF1), // M.2_CNV_BRI_RSP
		PAD_CFG_NF(GPP_J6, NONE, DEEP, NF1), // M.2_CNV_RGI_DT_BT_UART0_TX
		PAD_CFG_NF(GPP_J7, UP_20K, DEEP, NF1), // M.2_CNV_RGI_RSP
		PAD_CFG_GPI(GPP_J8, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_J9, UP_20K, DEEP), // CNVI_MFUART2_TXD
		PAD_CFG_GPI(GPP_J10, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_J11, UP_20K, DEEP), // NC
		PAD_NC(GPP_K0, NONE), // NC
		PAD_CFG_GPI(GPP_K1, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K2, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K3, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K4, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K5, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K6, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K7, UP_20K, DEEP), // NC
		PAD_CFG_TERM_GPO(GPP_K8, 1, NONE, DEEP), // SATA_M2_PWR_EN1
		PAD_CFG_TERM_GPO(GPP_K9, 1, NONE, DEEP), // SATA_M2_PWR_EN2
		PAD_CFG_GPI(GPP_K10, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K11, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K12, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K13, UP_20K, DEEP), // NC
		PAD_CFG_TERM_GPO(GPP_K14, 0, UP_20K, DEEP), // GPP_K_14_GSXDIN (test point), 7411_TEST_R
		PAD_CFG_GPI(GPP_K15, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K16, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K17, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K18, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K19, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K20, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K21, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K22, UP_20K, DEEP), // NC
		PAD_CFG_GPI(GPP_K23, UP_20K, DEEP), // NC
};

#endif

#endif
