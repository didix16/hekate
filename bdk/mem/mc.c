/*
 * Copyright (c) 2018 naehrwert
 * Copyright (c) 2018-2022 CTCaer
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <memory_map.h>
#include <mem/mc.h>
#include <soc/timer.h>
#include <soc/t210.h>
#include <soc/clock.h>

void mc_config_tsec_carveout(u32 bom, u32 size1mb, bool lock)
{
	MC(MC_SEC_CARVEOUT_BOM) = bom;
	MC(MC_SEC_CARVEOUT_SIZE_MB) = size1mb;
	if (lock)
		MC(MC_SEC_CARVEOUT_REG_CTRL) = 1;
}

void mc_config_carveout()
{
	*(vu32 *)0x8005FFFC = 0xC0EDBBCC;
	MC(MC_VIDEO_PROTECT_GPU_OVERRIDE_0) = 1;
	MC(MC_VIDEO_PROTECT_GPU_OVERRIDE_1) = 0;
	MC(MC_VIDEO_PROTECT_BOM) = 0;
	MC(MC_VIDEO_PROTECT_SIZE_MB) = 0;
	MC(MC_VIDEO_PROTECT_REG_CTRL) = 1;

	// Configure TSEC carveout @ 0x90000000, 1MB.
	//mc_config_tsec_carveout(0x90000000, 1, false);
	mc_config_tsec_carveout(0, 0, true);

	MC(MC_MTS_CARVEOUT_BOM) = 0;
	MC(MC_MTS_CARVEOUT_SIZE_MB) = 0;
	MC(MC_MTS_CARVEOUT_ADR_HI) = 0;
	MC(MC_MTS_CARVEOUT_REG_CTRL) = 1;

	MC(MC_SECURITY_CARVEOUT1_BOM) = 0;
	MC(MC_SECURITY_CARVEOUT1_BOM_HI) = 0;
	MC(MC_SECURITY_CARVEOUT1_SIZE_128KB) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT1_CLIENT_FORCE_INTERNAL_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT1_CFG0) = 0x4000006;

	MC(MC_SECURITY_CARVEOUT2_BOM) = 0x80020000;
	MC(MC_SECURITY_CARVEOUT2_BOM_HI) = 0;
	MC(MC_SECURITY_CARVEOUT2_SIZE_128KB) = 2;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_ACCESS2) = 0x3100000;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_ACCESS4) = 0x300;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT2_CLIENT_FORCE_INTERNAL_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT2_CFG0) = 0x440167E;

	MC(MC_SECURITY_CARVEOUT3_BOM) = 0;
	MC(MC_SECURITY_CARVEOUT3_BOM_HI) = 0;
	MC(MC_SECURITY_CARVEOUT3_SIZE_128KB) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_ACCESS2) = 0x3000000;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_ACCESS4) = 0x300;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT3_CLIENT_FORCE_INTERNAL_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT3_CFG0) = 0x4401E7E;

	MC(MC_SECURITY_CARVEOUT4_BOM) = 0;
	MC(MC_SECURITY_CARVEOUT4_BOM_HI) = 0;
	MC(MC_SECURITY_CARVEOUT4_SIZE_128KB) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT4_CLIENT_FORCE_INTERNAL_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT4_CFG0) = 0x8F;

	MC(MC_SECURITY_CARVEOUT5_BOM) = 0;
	MC(MC_SECURITY_CARVEOUT5_BOM_HI) = 0;
	MC(MC_SECURITY_CARVEOUT5_SIZE_128KB) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS0) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS1) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS2) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS3) = 0;
	MC(MC_SECURITY_CARVEOUT5_CLIENT_FORCE_INTERNAL_ACCESS4) = 0;
	MC(MC_SECURITY_CARVEOUT5_CFG0) = 0x8F;
}

void mc_enable_ahb_redirect()
{
	// Enable ARC_CLK_OVR_ON.
	CLOCK(CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRD) |= BIT(19);
	//MC(MC_IRAM_REG_CTRL) &= ~BIT(0);
	MC(MC_IRAM_BOM) = IRAM_BASE;
	MC(MC_IRAM_TOM) = DRAM_START; // Default is only IRAM: 0x4003F000.
}

void mc_disable_ahb_redirect()
{
	MC(MC_IRAM_BOM) = 0xFFFFF000;
	MC(MC_IRAM_TOM) = 0;
	// Disable IRAM_CFG_WRITE_ACCESS (sticky).
	//MC(MC_IRAM_REG_CTRL) |= BIT(0);
	// Disable ARC_CLK_OVR_ON.
	CLOCK(CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRD) &= ~BIT(19);
}

bool mc_client_has_access(void *address)
{
	// Check if address is in DRAM or if arbitration for IRAM is enabled.
	if ((u32)address >= DRAM_START)
		return true; // Access by default.
	else if ((u32)address >= IRAM_BASE && MC(MC_IRAM_BOM) == IRAM_BASE)
		return true; // Access by AHB arbitration.

	// No access to address space.
	return false;
}

void mc_enable()
{
	// Reset EMC source to PLLP.
	CLOCK(CLK_RST_CONTROLLER_CLK_SOURCE_EMC) = (CLOCK(CLK_RST_CONTROLLER_CLK_SOURCE_EMC) & 0x1FFFFFFF) | (2 << 29u);
	// Enable and clear reset for memory clocks.
	CLOCK(CLK_RST_CONTROLLER_CLK_ENB_H_SET) = BIT(CLK_H_EMC) | BIT(CLK_H_MEM);
	CLOCK(CLK_RST_CONTROLLER_CLK_ENB_X_SET) = BIT(CLK_X_EMC_DLL);
	CLOCK(CLK_RST_CONTROLLER_RST_DEV_H_CLR) = BIT(CLK_H_EMC) | BIT(CLK_H_MEM);
	usleep(5);

#ifdef BDK_MC_ENABLE_AHB_REDIRECT
	mc_enable_ahb_redirect();
#else
	mc_disable_ahb_redirect();
#endif
}
