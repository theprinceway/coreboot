/* SPDX-License-Identifier: GPL-2.0-only */

#include <soc/emi.h>

struct sdram_params params = {
	.source = DRAMC_PARAM_SOURCE_SDRAM_CONFIG,
	.frequency = 1600,
	.wr_level = {
		[CHANNEL_A] = { {0x22, 0x1C}, {0x23, 0x1D} },
		[CHANNEL_B] = { {0x26, 0x23}, {0x26, 0x23} }
	},
	.cbt_cs_dly = {
		[CHANNEL_A] = {0x6, 0x5},
		[CHANNEL_B] = {0x6, 0x6}
	},
	.cbt_final_vref = {
		[CHANNEL_A] = {0x56, 0x58},
		[CHANNEL_B] = {0x58, 0x56}
	},
	.emi_cona_val = 0xF053F154,
	.emi_conh_val = 0x44440003,
	.emi_conf_val = 0x00421000,
	.chn_emi_cona_val = {0x0444F051, 0x0444F051},
	.cbt_mode_extern = CBT_NORMAL_MODE,
	.delay_cell_unit = 868,
};
