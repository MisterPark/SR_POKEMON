#pragma once

namespace PKH
{
	enum class TextureKey
	{
		NONE,
		SKY_U,
		SKY_D,
		SKY_L,
		SKY_R,
		SKY_F,
		SKY_B,
		CURSOR_TARGET,
		LOCK_ON,
		TITLE_SCREEN,
		BLUE_FILTER,

		// PG 01
		PG01_WALK_D_01,
		PG01_WALK_D_02,
		PG01_WALK_D_03,
		PG01_WALK_LD_01,
		PG01_WALK_LD_02,
		PG01_WALK_LD_03,
		PG01_WALK_L_01,
		PG01_WALK_L_02,
		PG01_WALK_L_03,
		PG01_WALK_LU_01,
		PG01_WALK_LU_02,
		PG01_WALK_LU_03,
		PG01_WALK_U_01,
		PG01_WALK_U_02,
		PG01_WALK_U_03,
		PG01_WALK_RU_01,
		PG01_WALK_RU_02,
		PG01_WALK_RU_03,
		PG01_WALK_R_01,
		PG01_WALK_R_02,
		PG01_WALK_R_03,
		PG01_WALK_RD_01,
		PG01_WALK_RD_02,
		PG01_WALK_RD_03,

		PG01_ATTACK_D_01,
		PG01_ATTACK_D_02,
		PG01_ATTACK_LD_01,
		PG01_ATTACK_LD_02,
		PG01_ATTACK_L_01,
		PG01_ATTACK_L_02,
		PG01_ATTACK_LU_01,
		PG01_ATTACK_LU_02,
		PG01_ATTACK_U_01,
		PG01_ATTACK_U_02,
		PG01_ATTACK_RU_01,
		PG01_ATTACK_RU_02,
		PG01_ATTACK_R_01,
		PG01_ATTACK_R_02,
		PG01_ATTACK_RD_01,
		PG01_ATTACK_RD_02,

		PG01_SKILL_D_01,
		PG01_SKILL_D_02,
		PG01_SKILL_LD_01,
		PG01_SKILL_LD_02,
		PG01_SKILL_L_01,
		PG01_SKILL_L_02,
		PG01_SKILL_LU_01,
		PG01_SKILL_LU_02,
		PG01_SKILL_U_01,
		PG01_SKILL_U_02,
		PG01_SKILL_RU_01,
		PG01_SKILL_RU_02,
		PG01_SKILL_R_01,
		PG01_SKILL_R_02,
		PG01_SKILL_RD_01,
		PG01_SKILL_RD_02,

		// PG 02
		PG02_WALK_D_01,
		PG02_WALK_D_02,
		PG02_WALK_D_03,
		PG02_WALK_LD_01,
		PG02_WALK_LD_02,
		PG02_WALK_LD_03,
		PG02_WALK_L_01,
		PG02_WALK_L_02,
		PG02_WALK_L_03,
		PG02_WALK_LU_01,
		PG02_WALK_LU_02,
		PG02_WALK_LU_03,
		PG02_WALK_U_01,
		PG02_WALK_U_02,
		PG02_WALK_U_03,
		PG02_WALK_RU_01,
		PG02_WALK_RU_02,
		PG02_WALK_RU_03,
		PG02_WALK_R_01,
		PG02_WALK_R_02,
		PG02_WALK_R_03,
		PG02_WALK_RD_01,
		PG02_WALK_RD_02,
		PG02_WALK_RD_03,

		PG02_ATTACK_D_01,
		PG02_ATTACK_D_02,
		PG02_ATTACK_LD_01,
		PG02_ATTACK_LD_02,
		PG02_ATTACK_L_01,
		PG02_ATTACK_L_02,
		PG02_ATTACK_LU_01,
		PG02_ATTACK_LU_02,
		PG02_ATTACK_U_01,
		PG02_ATTACK_U_02,
		PG02_ATTACK_RU_01,
		PG02_ATTACK_RU_02,
		PG02_ATTACK_R_01,
		PG02_ATTACK_R_02,
		PG02_ATTACK_RD_01,
		PG02_ATTACK_RD_02,

		PG02_SKILL_D_01,
		PG02_SKILL_D_02,
		PG02_SKILL_LD_01,
		PG02_SKILL_LD_02,
		PG02_SKILL_L_01,
		PG02_SKILL_L_02,
		PG02_SKILL_LU_01,
		PG02_SKILL_LU_02,
		PG02_SKILL_U_01,
		PG02_SKILL_U_02,
		PG02_SKILL_RU_01,
		PG02_SKILL_RU_02,
		PG02_SKILL_R_01,
		PG02_SKILL_R_02,
		PG02_SKILL_RD_01,
		PG02_SKILL_RD_02,

		// PG 03
		PG03_WALK_D_01,
		PG03_WALK_D_02,
		PG03_WALK_D_03,
		PG03_WALK_LD_01,
		PG03_WALK_LD_02,
		PG03_WALK_LD_03,
		PG03_WALK_L_01,
		PG03_WALK_L_02,
		PG03_WALK_L_03,
		PG03_WALK_LU_01,
		PG03_WALK_LU_02,
		PG03_WALK_LU_03,
		PG03_WALK_U_01,
		PG03_WALK_U_02,
		PG03_WALK_U_03,
		PG03_WALK_RU_01,
		PG03_WALK_RU_02,
		PG03_WALK_RU_03,
		PG03_WALK_R_01,
		PG03_WALK_R_02,
		PG03_WALK_R_03,
		PG03_WALK_RD_01,
		PG03_WALK_RD_02,
		PG03_WALK_RD_03,

		PG03_ATTACK_D_01,
		PG03_ATTACK_D_02,
		PG03_ATTACK_LD_01,
		PG03_ATTACK_LD_02,
		PG03_ATTACK_L_01,
		PG03_ATTACK_L_02,
		PG03_ATTACK_LU_01,
		PG03_ATTACK_LU_02,
		PG03_ATTACK_U_01,
		PG03_ATTACK_U_02,
		PG03_ATTACK_RU_01,
		PG03_ATTACK_RU_02,
		PG03_ATTACK_R_01,
		PG03_ATTACK_R_02,
		PG03_ATTACK_RD_01,
		PG03_ATTACK_RD_02,

		PG03_SKILL_D_01,
		PG03_SKILL_D_02,
		PG03_SKILL_LD_01,
		PG03_SKILL_LD_02,
		PG03_SKILL_L_01,
		PG03_SKILL_L_02,
		PG03_SKILL_LU_01,
		PG03_SKILL_LU_02,
		PG03_SKILL_U_01,
		PG03_SKILL_U_02,
		PG03_SKILL_RU_01,
		PG03_SKILL_RU_02,
		PG03_SKILL_R_01,
		PG03_SKILL_R_02,
		PG03_SKILL_RD_01,
		PG03_SKILL_RD_02,

		// PF 01
		PF01_WALK_D_01,
		PF01_WALK_D_02,
		PF01_WALK_D_03,
		PF01_WALK_LD_01,
		PF01_WALK_LD_02,
		PF01_WALK_LD_03,
		PF01_WALK_L_01,
		PF01_WALK_L_02,
		PF01_WALK_L_03,
		PF01_WALK_LU_01,
		PF01_WALK_LU_02,
		PF01_WALK_LU_03,
		PF01_WALK_U_01,
		PF01_WALK_U_02,
		PF01_WALK_U_03,
		PF01_WALK_RU_01,
		PF01_WALK_RU_02,
		PF01_WALK_RU_03,
		PF01_WALK_R_01,
		PF01_WALK_R_02,
		PF01_WALK_R_03,
		PF01_WALK_RD_01,
		PF01_WALK_RD_02,
		PF01_WALK_RD_03,
		
		PF01_ATTACK_D_01,
		PF01_ATTACK_LD_01,
		PF01_ATTACK_L_01,
		PF01_ATTACK_LU_01,
		PF01_ATTACK_U_01,
		PF01_ATTACK_RU_01,
		PF01_ATTACK_R_01,
		PF01_ATTACK_RD_01,
		
		PF01_SKILL_D_01,
		PF01_SKILL_D_02,
		PF01_SKILL_LD_01,
		PF01_SKILL_LD_02,
		PF01_SKILL_L_01,
		PF01_SKILL_L_02,
		PF01_SKILL_LU_01,
		PF01_SKILL_LU_02,
		PF01_SKILL_U_01,
		PF01_SKILL_U_02,
		PF01_SKILL_RU_01,
		PF01_SKILL_RU_02,
		PF01_SKILL_R_01,
		PF01_SKILL_R_02,
		PF01_SKILL_RD_01,
		PF01_SKILL_RD_02,
		
		// PG 02
		PF02_WALK_D_01,
		PF02_WALK_D_02,
		PF02_WALK_D_03,
		PF02_WALK_LD_01,
		PF02_WALK_LD_02,
		PF02_WALK_LD_03,
		PF02_WALK_L_01,
		PF02_WALK_L_02,
		PF02_WALK_L_03,
		PF02_WALK_LU_01,
		PF02_WALK_LU_02,
		PF02_WALK_LU_03,
		PF02_WALK_U_01,
		PF02_WALK_U_02,
		PF02_WALK_U_03,
		PF02_WALK_RU_01,
		PF02_WALK_RU_02,
		PF02_WALK_RU_03,
		PF02_WALK_R_01,
		PF02_WALK_R_02,
		PF02_WALK_R_03,
		PF02_WALK_RD_01,
		PF02_WALK_RD_02,
		PF02_WALK_RD_03,
		
		PF02_ATTACK_D_01,
		PF02_ATTACK_D_02,
		PF02_ATTACK_LD_01,
		PF02_ATTACK_LD_02,
		PF02_ATTACK_L_01,
		PF02_ATTACK_L_02,
		PF02_ATTACK_LU_01,
		PF02_ATTACK_LU_02,
		PF02_ATTACK_U_01,
		PF02_ATTACK_U_02,
		PF02_ATTACK_RU_01,
		PF02_ATTACK_RU_02,
		PF02_ATTACK_R_01,
		PF02_ATTACK_R_02,
		PF02_ATTACK_RD_01,
		PF02_ATTACK_RD_02,
		
		PF02_SKILL_D_01,
		PF02_SKILL_D_02,
		PF02_SKILL_LD_01,
		PF02_SKILL_LD_02,
		PF02_SKILL_L_01,
		PF02_SKILL_L_02,
		PF02_SKILL_LU_01,
		PF02_SKILL_LU_02,
		PF02_SKILL_U_01,
		PF02_SKILL_U_02,
		PF02_SKILL_RU_01,
		PF02_SKILL_RU_02,
		PF02_SKILL_R_01,
		PF02_SKILL_R_02,
		PF02_SKILL_RD_01,
		PF02_SKILL_RD_02,
		
		// PG 03
		PF03_WALK_D_01,
		PF03_WALK_D_02,
		PF03_WALK_D_03,
		PF03_WALK_LD_01,
		PF03_WALK_LD_02,
		PF03_WALK_LD_03,
		PF03_WALK_L_01,
		PF03_WALK_L_02,
		PF03_WALK_L_03,
		PF03_WALK_LU_01,
		PF03_WALK_LU_02,
		PF03_WALK_LU_03,
		PF03_WALK_U_01,
		PF03_WALK_U_02,
		PF03_WALK_U_03,
		PF03_WALK_RU_01,
		PF03_WALK_RU_02,
		PF03_WALK_RU_03,
		PF03_WALK_R_01,
		PF03_WALK_R_02,
		PF03_WALK_R_03,
		PF03_WALK_RD_01,
		PF03_WALK_RD_02,
		PF03_WALK_RD_03,
		
		PF03_ATTACK_D_01,
		PF03_ATTACK_D_02,
		PF03_ATTACK_LD_01,
		PF03_ATTACK_LD_02,
		PF03_ATTACK_L_01,
		PF03_ATTACK_L_02,
		PF03_ATTACK_LU_01,
		PF03_ATTACK_LU_02,
		PF03_ATTACK_U_01,
		PF03_ATTACK_U_02,
		PF03_ATTACK_RU_01,
		PF03_ATTACK_RU_02,
		PF03_ATTACK_R_01,
		PF03_ATTACK_R_02,
		PF03_ATTACK_RD_01,
		PF03_ATTACK_RD_02,
		
		PF03_SKILL_D_01,
		PF03_SKILL_D_02,
		PF03_SKILL_LD_01,
		PF03_SKILL_LD_02,
		PF03_SKILL_L_01,
		PF03_SKILL_L_02,
		PF03_SKILL_LU_01,
		PF03_SKILL_LU_02,
		PF03_SKILL_U_01,
		PF03_SKILL_U_02,
		PF03_SKILL_RU_01,
		PF03_SKILL_RU_02,
		PF03_SKILL_R_01,
		PF03_SKILL_R_02,
		PF03_SKILL_RD_01,
		PF03_SKILL_RD_02,

		// 플레이어 끝

		BUTTER_WALK_D_01,
		BUTTER_WALK_D_02,
		BUTTER_WALK_D_03,
		BUTTER_WALK_LD_01,
		BUTTER_WALK_LD_02,
		BUTTER_WALK_LD_03,
		BUTTER_WALK_L_01,
		BUTTER_WALK_L_02,
		BUTTER_WALK_L_03,
		BUTTER_WALK_LU_01,
		BUTTER_WALK_LU_02,
		BUTTER_WALK_LU_03,
		BUTTER_WALK_U_01,
		BUTTER_WALK_U_02,
		BUTTER_WALK_U_03,
		BUTTER_WALK_RU_01,
		BUTTER_WALK_RU_02,
		BUTTER_WALK_RU_03,
		BUTTER_WALK_R_01,
		BUTTER_WALK_R_02,
		BUTTER_WALK_R_03,
		BUTTER_WALK_RD_01,
		BUTTER_WALK_RD_02,
		BUTTER_WALK_RD_03,

		BUTTER_ATTACK_D_01,
		BUTTER_ATTACK_D_02,
		BUTTER_ATTACK_LD_01,
		BUTTER_ATTACK_LD_02,
		BUTTER_ATTACK_L_01,
		BUTTER_ATTACK_L_02,
		BUTTER_ATTACK_LU_01,
		BUTTER_ATTACK_LU_02,
		BUTTER_ATTACK_U_01,
		BUTTER_ATTACK_U_02,
		BUTTER_ATTACK_RU_01,
		BUTTER_ATTACK_RU_02,
		BUTTER_ATTACK_R_01,
		BUTTER_ATTACK_R_02,
		BUTTER_ATTACK_RD_01,
		BUTTER_ATTACK_RD_02,

		CATER_WALK_D_01,
		CATER_WALK_D_02,
		CATER_WALK_D_03,
		CATER_WALK_LD_01,
		CATER_WALK_LD_02,
		CATER_WALK_LD_03,
		CATER_WALK_L_01,
		CATER_WALK_L_02,
		CATER_WALK_L_03,
		CATER_WALK_LU_01,
		CATER_WALK_LU_02,
		CATER_WALK_LU_03,
		CATER_WALK_U_01,
		CATER_WALK_U_02,
		CATER_WALK_U_03,
		CATER_WALK_RU_01,
		CATER_WALK_RU_02,
		CATER_WALK_RU_03,
		CATER_WALK_R_01,
		CATER_WALK_R_02,
		CATER_WALK_R_03,
		CATER_WALK_RD_01,
		CATER_WALK_RD_02,
		CATER_WALK_RD_03,

		CATER_ATTACK_D_01,
		CATER_ATTACK_D_02,
		CATER_ATTACK_LD_01,
		CATER_ATTACK_LD_02,
		CATER_ATTACK_L_01,
		CATER_ATTACK_L_02,
		CATER_ATTACK_LU_01,
		CATER_ATTACK_LU_02,
		CATER_ATTACK_U_01,
		CATER_ATTACK_U_02,
		CATER_ATTACK_RU_01,
		CATER_ATTACK_RU_02,
		CATER_ATTACK_R_01,
		CATER_ATTACK_R_02,
		CATER_ATTACK_RD_01,
		CATER_ATTACK_RD_02,

		CELE_WALK_D_01,
		CELE_WALK_D_02,
		CELE_WALK_D_03,
		CELE_WALK_LD_01,
		CELE_WALK_LD_02,
		CELE_WALK_LD_03,
		CELE_WALK_L_01,
		CELE_WALK_L_02,
		CELE_WALK_L_03,
		CELE_WALK_LU_01,
		CELE_WALK_LU_02,
		CELE_WALK_LU_03,
		CELE_WALK_U_01,
		CELE_WALK_U_02,
		CELE_WALK_U_03,
		CELE_WALK_RU_01,
		CELE_WALK_RU_02,
		CELE_WALK_RU_03,
		CELE_WALK_R_01,
		CELE_WALK_R_02,
		CELE_WALK_R_03,
		CELE_WALK_RD_01,
		CELE_WALK_RD_02,
		CELE_WALK_RD_03,


		CELE_HURT_D_01,
		CELE_HURT_LD_01,
		CELE_HURT_L_01,
		CELE_HURT_LU_01,
		CELE_HURT_U_01,
		CELE_HURT_RU_01,
		CELE_HURT_R_01,
		CELE_HURT_RD_01,
			

		META_WALK_D_01,
		META_WALK_D_02,
		META_WALK_D_03,
		META_WALK_LD_01,
		META_WALK_LD_02,
		META_WALK_LD_03,
		META_WALK_L_01,
		META_WALK_L_02,
		META_WALK_L_03,
		META_WALK_LU_01,
		META_WALK_LU_02,
		META_WALK_LU_03,
		META_WALK_U_01,
		META_WALK_U_02,
		META_WALK_U_03,
		META_WALK_RU_01,
		META_WALK_RU_02,
		META_WALK_RU_03,
		META_WALK_R_01,
		META_WALK_R_02,
		META_WALK_R_03,
		META_WALK_RD_01,
		META_WALK_RD_02,
		META_WALK_RD_03,

		META_ATTACK_D_01,
		META_ATTACK_D_02,
		META_ATTACK_LD_01,
		META_ATTACK_LD_02,
		META_ATTACK_L_01,
		META_ATTACK_L_02,
		META_ATTACK_LU_01,
		META_ATTACK_LU_02,
		META_ATTACK_U_01,
		META_ATTACK_U_02,
		META_ATTACK_RU_01,
		META_ATTACK_RU_02,
		META_ATTACK_R_01,
		META_ATTACK_R_02,
		META_ATTACK_RD_01,
		META_ATTACK_RD_02,

		ODDI_WALK_D_01,
		ODDI_WALK_D_02,
		ODDI_WALK_D_03,
		ODDI_WALK_LD_01,
		ODDI_WALK_LD_02,
		ODDI_WALK_LD_03,
		ODDI_WALK_L_01,
		ODDI_WALK_L_02,
		ODDI_WALK_L_03,
		ODDI_WALK_LU_01,
		ODDI_WALK_LU_02,
		ODDI_WALK_LU_03,
		ODDI_WALK_U_01,
		ODDI_WALK_U_02,
		ODDI_WALK_U_03,
		ODDI_WALK_RU_01,
		ODDI_WALK_RU_02,
		ODDI_WALK_RU_03,
		ODDI_WALK_R_01,
		ODDI_WALK_R_02,
		ODDI_WALK_R_03,
		ODDI_WALK_RD_01,
		ODDI_WALK_RD_02,
		ODDI_WALK_RD_03,

		ODDI_ATTACK_D_01,
		ODDI_ATTACK_D_02,
		ODDI_ATTACK_LD_01,
		ODDI_ATTACK_LD_02,
		ODDI_ATTACK_L_01,
		ODDI_ATTACK_L_02,
		ODDI_ATTACK_LU_01,
		ODDI_ATTACK_LU_02,
		ODDI_ATTACK_U_01,
		ODDI_ATTACK_U_02,
		ODDI_ATTACK_RU_01,
		ODDI_ATTACK_RU_02,
		ODDI_ATTACK_R_01,
		ODDI_ATTACK_R_02,
		ODDI_ATTACK_RD_01,
		ODDI_ATTACK_RD_02,

		SCY_WALK_D_01,
		SCY_WALK_D_02,
		SCY_WALK_D_03,
		SCY_WALK_LD_01,
		SCY_WALK_LD_02,
		SCY_WALK_LD_03,
		SCY_WALK_L_01,
		SCY_WALK_L_02,
		SCY_WALK_L_03,
		SCY_WALK_LU_01,
		SCY_WALK_LU_02,
		SCY_WALK_LU_03,
		SCY_WALK_U_01,
		SCY_WALK_U_02,
		SCY_WALK_U_03,
		SCY_WALK_RU_01,
		SCY_WALK_RU_02,
		SCY_WALK_RU_03,
		SCY_WALK_R_01,
		SCY_WALK_R_02,
		SCY_WALK_R_03,
		SCY_WALK_RD_01,
		SCY_WALK_RD_02,
		SCY_WALK_RD_03,

		SCY_ATTACK_D_01,
		SCY_ATTACK_D_02,
		SCY_ATTACK_LD_01,
		SCY_ATTACK_LD_02,
		SCY_ATTACK_L_01,
		SCY_ATTACK_L_02,
		SCY_ATTACK_LU_01,
		SCY_ATTACK_LU_02,
		SCY_ATTACK_U_01,
		SCY_ATTACK_U_02,
		SCY_ATTACK_RU_01,
		SCY_ATTACK_RU_02,
		SCY_ATTACK_R_01,
		SCY_ATTACK_R_02,
		SCY_ATTACK_RD_01,
		SCY_ATTACK_RD_02,

		VILE_WALK_D_01,
		VILE_WALK_D_02,
		VILE_WALK_D_03,
		VILE_WALK_LD_01,
		VILE_WALK_LD_02,
		VILE_WALK_LD_03,
		VILE_WALK_L_01,
		VILE_WALK_L_02,
		VILE_WALK_L_03,
		VILE_WALK_LU_01,
		VILE_WALK_LU_02,
		VILE_WALK_LU_03,
		VILE_WALK_U_01,
		VILE_WALK_U_02,
		VILE_WALK_U_03,
		VILE_WALK_RU_01,
		VILE_WALK_RU_02,
		VILE_WALK_RU_03,
		VILE_WALK_R_01,
		VILE_WALK_R_02,
		VILE_WALK_R_03,
		VILE_WALK_RD_01,
		VILE_WALK_RD_02,
		VILE_WALK_RD_03,

		VILE_ATTACK_D_01,
		VILE_ATTACK_D_02,
		VILE_ATTACK_LD_01,
		VILE_ATTACK_LD_02,
		VILE_ATTACK_L_01,
		VILE_ATTACK_L_02,
		VILE_ATTACK_LU_01,
		VILE_ATTACK_LU_02,
		VILE_ATTACK_U_01,
		VILE_ATTACK_U_02,
		VILE_ATTACK_RU_01,
		VILE_ATTACK_RU_02,
		VILE_ATTACK_R_01,
		VILE_ATTACK_R_02,
		VILE_ATTACK_RD_01,
		VILE_ATTACK_RD_02,

		//수속성
		GOLD_WALK_D_01,
		GOLD_WALK_D_02,
		GOLD_WALK_D_03,
		GOLD_WALK_LD_01,
		GOLD_WALK_LD_02,
		GOLD_WALK_LD_03,
		GOLD_WALK_L_01,
		GOLD_WALK_L_02,
		GOLD_WALK_L_03,
		GOLD_WALK_LU_01,
		GOLD_WALK_LU_02,
		GOLD_WALK_LU_03,
		GOLD_WALK_U_01,
		GOLD_WALK_U_02,
		GOLD_WALK_U_03,
		GOLD_WALK_RU_01,
		GOLD_WALK_RU_02,
		GOLD_WALK_RU_03,
		GOLD_WALK_R_01,
		GOLD_WALK_R_02,
		GOLD_WALK_R_03,
		GOLD_WALK_RD_01,
		GOLD_WALK_RD_02,
		GOLD_WALK_RD_03,

		GOLD_ATTACK_D_01,
		GOLD_ATTACK_D_02,
		GOLD_ATTACK_LD_01,
		GOLD_ATTACK_LD_02,
		GOLD_ATTACK_L_01,
		GOLD_ATTACK_L_02,
		GOLD_ATTACK_LU_01,
		GOLD_ATTACK_LU_02,
		GOLD_ATTACK_U_01,
		GOLD_ATTACK_U_02,
		GOLD_ATTACK_RU_01,
		GOLD_ATTACK_RU_02,
		GOLD_ATTACK_R_01,
		GOLD_ATTACK_R_02,
		GOLD_ATTACK_RD_01,
		GOLD_ATTACK_RD_02,

		JYNX_WALK_D_01,
		JYNX_WALK_D_02,
		JYNX_WALK_D_03,
		JYNX_WALK_LD_01,
		JYNX_WALK_LD_02,
		JYNX_WALK_LD_03,
		JYNX_WALK_L_01,
		JYNX_WALK_L_02,
		JYNX_WALK_L_03,
		JYNX_WALK_LU_01,
		JYNX_WALK_LU_02,
		JYNX_WALK_LU_03,
		JYNX_WALK_U_01,
		JYNX_WALK_U_02,
		JYNX_WALK_U_03,
		JYNX_WALK_RU_01,
		JYNX_WALK_RU_02,
		JYNX_WALK_RU_03,
		JYNX_WALK_R_01,
		JYNX_WALK_R_02,
		JYNX_WALK_R_03,
		JYNX_WALK_RD_01,
		JYNX_WALK_RD_02,
		JYNX_WALK_RD_03,

		JYNX_ATTACK_D_01,
		JYNX_ATTACK_D_02,
		JYNX_ATTACK_LD_01,
		JYNX_ATTACK_LD_02,
		JYNX_ATTACK_L_01,
		JYNX_ATTACK_L_02,
		JYNX_ATTACK_LU_01,
		JYNX_ATTACK_LU_02,
		JYNX_ATTACK_U_01,
		JYNX_ATTACK_U_02,
		JYNX_ATTACK_RU_01,
		JYNX_ATTACK_RU_02,
		JYNX_ATTACK_R_01,
		JYNX_ATTACK_R_02,
		JYNX_ATTACK_RD_01,
		JYNX_ATTACK_RD_02,


		WAG_WALK_D_01,
		WAG_WALK_D_02,
		WAG_WALK_D_03,
		WAG_WALK_LD_01,
		WAG_WALK_LD_02,
		WAG_WALK_LD_03,
		WAG_WALK_L_01,
		WAG_WALK_L_02,
		WAG_WALK_L_03,
		WAG_WALK_LU_01,
		WAG_WALK_LU_02,
		WAG_WALK_LU_03,
		WAG_WALK_U_01,
		WAG_WALK_U_02,
		WAG_WALK_U_03,
		WAG_WALK_RU_01,
		WAG_WALK_RU_02,
		WAG_WALK_RU_03,
		WAG_WALK_R_01,
		WAG_WALK_R_02,
		WAG_WALK_R_03,
		WAG_WALK_RD_01,
		WAG_WALK_RD_02,
		WAG_WALK_RD_03,

		WAG_ATTACK_D_01,
		WAG_ATTACK_D_02,
		WAG_ATTACK_LD_01,
		WAG_ATTACK_LD_02,
		WAG_ATTACK_L_01,
		WAG_ATTACK_L_02,
		WAG_ATTACK_LU_01,
		WAG_ATTACK_LU_02,
		WAG_ATTACK_U_01,
		WAG_ATTACK_U_02,
		WAG_ATTACK_RU_01,
		WAG_ATTACK_RU_02,
		WAG_ATTACK_R_01,
		WAG_ATTACK_R_02,
		WAG_ATTACK_RD_01,
		WAG_ATTACK_RD_02,

		WRATH_WALK_D_01,
		WRATH_WALK_D_02,
		WRATH_WALK_D_03,
		WRATH_WALK_LD_01,
		WRATH_WALK_LD_02,
		WRATH_WALK_LD_03,
		WRATH_WALK_L_01,
		WRATH_WALK_L_02,
		WRATH_WALK_L_03,
		WRATH_WALK_LU_01,
		WRATH_WALK_LU_02,
		WRATH_WALK_LU_03,
		WRATH_WALK_U_01,
		WRATH_WALK_U_02,
		WRATH_WALK_U_03,
		WRATH_WALK_RU_01,
		WRATH_WALK_RU_02,
		WRATH_WALK_RU_03,
		WRATH_WALK_R_01,
		WRATH_WALK_R_02,
		WRATH_WALK_R_03,
		WRATH_WALK_RD_01,
		WRATH_WALK_RD_02,
		WRATH_WALK_RD_03,

		WRATH_ATTACK_D_01,
		WRATH_ATTACK_D_02,
		WRATH_ATTACK_LD_01,
		WRATH_ATTACK_LD_02,
		WRATH_ATTACK_L_01,
		WRATH_ATTACK_L_02,
		WRATH_ATTACK_LU_01,
		WRATH_ATTACK_LU_02,
		WRATH_ATTACK_U_01,
		WRATH_ATTACK_U_02,
		WRATH_ATTACK_RU_01,
		WRATH_ATTACK_RU_02,
		WRATH_ATTACK_R_01,
		WRATH_ATTACK_R_02,
		WRATH_ATTACK_RD_01,
		WRATH_ATTACK_RD_02,

		PSY_WALK_D_01,
		PSY_WALK_D_02,
		PSY_WALK_D_03,
		PSY_WALK_LD_01,
		PSY_WALK_LD_02,
		PSY_WALK_LD_03,
		PSY_WALK_L_01,
		PSY_WALK_L_02,
		PSY_WALK_L_03,
		PSY_WALK_LU_01,
		PSY_WALK_LU_02,
		PSY_WALK_LU_03,
		PSY_WALK_U_01,
		PSY_WALK_U_02,
		PSY_WALK_U_03,
		PSY_WALK_RU_01,
		PSY_WALK_RU_02,
		PSY_WALK_RU_03,
		PSY_WALK_R_01,
		PSY_WALK_R_02,
		PSY_WALK_R_03,
		PSY_WALK_RD_01,
		PSY_WALK_RD_02,
		PSY_WALK_RD_03,

		PSY_ATTACK_D_01,
		PSY_ATTACK_D_02,
		PSY_ATTACK_LD_01,
		PSY_ATTACK_LD_02,
		PSY_ATTACK_L_01,
		PSY_ATTACK_L_02,
		PSY_ATTACK_LU_01,
		PSY_ATTACK_LU_02,
		PSY_ATTACK_U_01,
		PSY_ATTACK_U_02,
		PSY_ATTACK_RU_01,
		PSY_ATTACK_RU_02,
		PSY_ATTACK_R_01,
		PSY_ATTACK_R_02,
		PSY_ATTACK_RD_01,
		PSY_ATTACK_RD_02,


		PSY_ATTACK2_D_01,
		PSY_ATTACK2_D_02,
		PSY_ATTACK2_LD_01,
		PSY_ATTACK2_LD_02,
		PSY_ATTACK2_L_01,
		PSY_ATTACK2_L_02,
		PSY_ATTACK2_LU_01,
		PSY_ATTACK2_LU_02,
		PSY_ATTACK2_U_01,
		PSY_ATTACK2_U_02,
		PSY_ATTACK2_RU_01,
		PSY_ATTACK2_RU_02,
		PSY_ATTACK2_R_01,
		PSY_ATTACK2_R_02,
		PSY_ATTACK2_RD_01,
		PSY_ATTACK2_RD_02,

		SUI_WALK_D_01,
		SUI_WALK_D_02,
		SUI_WALK_D_03,
		SUI_WALK_LD_01,
		SUI_WALK_LD_02,
		SUI_WALK_LD_03,
		SUI_WALK_L_01,
		SUI_WALK_L_02,
		SUI_WALK_L_03,
		SUI_WALK_LU_01,
		SUI_WALK_LU_02,
		SUI_WALK_LU_03,
		SUI_WALK_U_01,
		SUI_WALK_U_02,
		SUI_WALK_U_03,
		SUI_WALK_RU_01,
		SUI_WALK_RU_02,
		SUI_WALK_RU_03,
		SUI_WALK_R_01,
		SUI_WALK_R_02,
		SUI_WALK_R_03,
		SUI_WALK_RD_01,
		SUI_WALK_RD_02,
		SUI_WALK_RD_03,

		SUI_ATTACK_D_01,
		SUI_ATTACK_D_02,
		SUI_ATTACK_LD_01,
		SUI_ATTACK_LD_02,
		SUI_ATTACK_L_01,
		SUI_ATTACK_L_02,
		SUI_ATTACK_LU_01,
		SUI_ATTACK_LU_02,
		SUI_ATTACK_U_01,
		SUI_ATTACK_U_02,
		SUI_ATTACK_RU_01,
		SUI_ATTACK_RU_02,
		SUI_ATTACK_R_01,
		SUI_ATTACK_R_02,
		SUI_ATTACK_RD_01,
		SUI_ATTACK_RD_02,

		//화속성
		ARCA_WALK_D_01,
		ARCA_WALK_D_02,
		ARCA_WALK_D_03,
		ARCA_WALK_LD_01,
		ARCA_WALK_LD_02,
		ARCA_WALK_LD_03,
		ARCA_WALK_L_01,
		ARCA_WALK_L_02,
		ARCA_WALK_L_03,
		ARCA_WALK_LU_01,
		ARCA_WALK_LU_02,
		ARCA_WALK_LU_03,
		ARCA_WALK_U_01,
		ARCA_WALK_U_02,
		ARCA_WALK_U_03,
		ARCA_WALK_RU_01,
		ARCA_WALK_RU_02,
		ARCA_WALK_RU_03,
		ARCA_WALK_R_01,
		ARCA_WALK_R_02,
		ARCA_WALK_R_03,
		ARCA_WALK_RD_01,
		ARCA_WALK_RD_02,
		ARCA_WALK_RD_03,

		ARCA_ATTACK_D_01,
		ARCA_ATTACK_D_02,
		ARCA_ATTACK_LD_01,
		ARCA_ATTACK_LD_02,
		ARCA_ATTACK_L_01,
		ARCA_ATTACK_L_02,
		ARCA_ATTACK_LU_01,
		ARCA_ATTACK_LU_02,
		ARCA_ATTACK_U_01,
		ARCA_ATTACK_U_02,
		ARCA_ATTACK_RU_01,
		ARCA_ATTACK_RU_02,
		ARCA_ATTACK_R_01,
		ARCA_ATTACK_R_02,
		ARCA_ATTACK_RD_01,
		ARCA_ATTACK_RD_02,

		GROU_WALK_D_01,
		GROU_WALK_D_02,
		GROU_WALK_D_03,
		GROU_WALK_LD_01,
		GROU_WALK_LD_02,
		GROU_WALK_LD_03,
		GROU_WALK_L_01,
		GROU_WALK_L_02,
		GROU_WALK_L_03,
		GROU_WALK_LU_01,
		GROU_WALK_LU_02,
		GROU_WALK_LU_03,
		GROU_WALK_U_01,
		GROU_WALK_U_02,
		GROU_WALK_U_03,
		GROU_WALK_RU_01,
		GROU_WALK_RU_02,
		GROU_WALK_RU_03,
		GROU_WALK_R_01,
		GROU_WALK_R_02,
		GROU_WALK_R_03,
		GROU_WALK_RD_01,
		GROU_WALK_RD_02,
		GROU_WALK_RD_03,

		GROU_ATTACK_D_01,
		GROU_ATTACK_D_02,
		GROU_ATTACK_LD_01,
		GROU_ATTACK_LD_02,
		GROU_ATTACK_L_01,
		GROU_ATTACK_L_02,
		GROU_ATTACK_LU_01,
		GROU_ATTACK_LU_02,
		GROU_ATTACK_U_01,
		GROU_ATTACK_U_02,
		GROU_ATTACK_RU_01,
		GROU_ATTACK_RU_02,
		GROU_ATTACK_R_01,
		GROU_ATTACK_R_02,
		GROU_ATTACK_RD_01,
		GROU_ATTACK_RD_02,

		GROW_WALK_D_01,
		GROW_WALK_D_02,
		GROW_WALK_D_03,
		GROW_WALK_LD_01,
		GROW_WALK_LD_02,
		GROW_WALK_LD_03,
		GROW_WALK_L_01,
		GROW_WALK_L_02,
		GROW_WALK_L_03,
		GROW_WALK_LU_01,
		GROW_WALK_LU_02,
		GROW_WALK_LU_03,
		GROW_WALK_U_01,
		GROW_WALK_U_02,
		GROW_WALK_U_03,
		GROW_WALK_RU_01,
		GROW_WALK_RU_02,
		GROW_WALK_RU_03,
		GROW_WALK_R_01,
		GROW_WALK_R_02,
		GROW_WALK_R_03,
		GROW_WALK_RD_01,
		GROW_WALK_RD_02,
		GROW_WALK_RD_03,

		GROW_ATTACK_D_01,
		GROW_ATTACK_D_02,
		GROW_ATTACK_LD_01,
		GROW_ATTACK_LD_02,
		GROW_ATTACK_L_01,
		GROW_ATTACK_L_02,
		GROW_ATTACK_LU_01,
		GROW_ATTACK_LU_02,
		GROW_ATTACK_U_01,
		GROW_ATTACK_U_02,
		GROW_ATTACK_RU_01,
		GROW_ATTACK_RU_02,
		GROW_ATTACK_R_01,
		GROW_ATTACK_R_02,
		GROW_ATTACK_RD_01,
		GROW_ATTACK_RD_02,

		MAGCA_WALK_D_01,
		MAGCA_WALK_D_02,
		MAGCA_WALK_D_03,
		MAGCA_WALK_LD_01,
		MAGCA_WALK_LD_02,
		MAGCA_WALK_LD_03,
		MAGCA_WALK_L_01,
		MAGCA_WALK_L_02,
		MAGCA_WALK_L_03,
		MAGCA_WALK_LU_01,
		MAGCA_WALK_LU_02,
		MAGCA_WALK_LU_03,
		MAGCA_WALK_U_01,
		MAGCA_WALK_U_02,
		MAGCA_WALK_U_03,
		MAGCA_WALK_RU_01,
		MAGCA_WALK_RU_02,
		MAGCA_WALK_RU_03,
		MAGCA_WALK_R_01,
		MAGCA_WALK_R_02,
		MAGCA_WALK_R_03,
		MAGCA_WALK_RD_01,
		MAGCA_WALK_RD_02,
		MAGCA_WALK_RD_03,

		MAGCA_ATTACK_D_01,
		MAGCA_ATTACK_D_02,
		MAGCA_ATTACK_LD_01,
		MAGCA_ATTACK_LD_02,
		MAGCA_ATTACK_L_01,
		MAGCA_ATTACK_L_02,
		MAGCA_ATTACK_LU_01,
		MAGCA_ATTACK_LU_02,
		MAGCA_ATTACK_U_01,
		MAGCA_ATTACK_U_02,
		MAGCA_ATTACK_RU_01,
		MAGCA_ATTACK_RU_02,
		MAGCA_ATTACK_R_01,
		MAGCA_ATTACK_R_02,
		MAGCA_ATTACK_RD_01,
		MAGCA_ATTACK_RD_02,

		PONY_WALK_D_01,
		PONY_WALK_D_02,
		PONY_WALK_D_03,
		PONY_WALK_LD_01,
		PONY_WALK_LD_02,
		PONY_WALK_LD_03,
		PONY_WALK_L_01,
		PONY_WALK_L_02,
		PONY_WALK_L_03,
		PONY_WALK_LU_01,
		PONY_WALK_LU_02,
		PONY_WALK_LU_03,
		PONY_WALK_U_01,
		PONY_WALK_U_02,
		PONY_WALK_U_03,
		PONY_WALK_RU_01,
		PONY_WALK_RU_02,
		PONY_WALK_RU_03,
		PONY_WALK_R_01,
		PONY_WALK_R_02,
		PONY_WALK_R_03,
		PONY_WALK_RD_01,
		PONY_WALK_RD_02,
		PONY_WALK_RD_03,

		PONY_ATTACK_D_01,
		PONY_ATTACK_D_02,
		PONY_ATTACK_LD_01,
		PONY_ATTACK_LD_02,
		PONY_ATTACK_L_01,
		PONY_ATTACK_L_02,
		PONY_ATTACK_LU_01,
		PONY_ATTACK_LU_02,
		PONY_ATTACK_U_01,
		PONY_ATTACK_U_02,
		PONY_ATTACK_RU_01,
		PONY_ATTACK_RU_02,
		PONY_ATTACK_R_01,
		PONY_ATTACK_R_02,
		PONY_ATTACK_RD_01,
		PONY_ATTACK_RD_02,

		RAPID_WALK_D_01,
		RAPID_WALK_D_02,
		RAPID_WALK_D_03,
		RAPID_WALK_LD_01,
		RAPID_WALK_LD_02,
		RAPID_WALK_LD_03,
		RAPID_WALK_L_01,
		RAPID_WALK_L_02,
		RAPID_WALK_L_03,
		RAPID_WALK_LU_01,
		RAPID_WALK_LU_02,
		RAPID_WALK_LU_03,
		RAPID_WALK_U_01,
		RAPID_WALK_U_02,
		RAPID_WALK_U_03,
		RAPID_WALK_RU_01,
		RAPID_WALK_RU_02,
		RAPID_WALK_RU_03,
		RAPID_WALK_R_01,
		RAPID_WALK_R_02,
		RAPID_WALK_R_03,
		RAPID_WALK_RD_01,
		RAPID_WALK_RD_02,
		RAPID_WALK_RD_03,

		RAPID_ATTACK_D_01,
		RAPID_ATTACK_D_02,
		RAPID_ATTACK_LD_01,
		RAPID_ATTACK_LD_02,
		RAPID_ATTACK_L_01,
		RAPID_ATTACK_L_02,
		RAPID_ATTACK_LU_01,
		RAPID_ATTACK_LU_02,
		RAPID_ATTACK_U_01,
		RAPID_ATTACK_U_02,
		RAPID_ATTACK_RU_01,
		RAPID_ATTACK_RU_02,
		RAPID_ATTACK_R_01,
		RAPID_ATTACK_R_02,
		RAPID_ATTACK_RD_01,
		RAPID_ATTACK_RD_02,

		SLUG_WALK_D_01,
		SLUG_WALK_D_02,
		SLUG_WALK_D_03,
		SLUG_WALK_LD_01,
		SLUG_WALK_LD_02,
		SLUG_WALK_LD_03,
		SLUG_WALK_L_01,
		SLUG_WALK_L_02,
		SLUG_WALK_L_03,
		SLUG_WALK_LU_01,
		SLUG_WALK_LU_02,
		SLUG_WALK_LU_03,
		SLUG_WALK_U_01,
		SLUG_WALK_U_02,
		SLUG_WALK_U_03,
		SLUG_WALK_RU_01,
		SLUG_WALK_RU_02,
		SLUG_WALK_RU_03,
		SLUG_WALK_R_01,
		SLUG_WALK_R_02,
		SLUG_WALK_R_03,
		SLUG_WALK_RD_01,
		SLUG_WALK_RD_02,
		SLUG_WALK_RD_03,

		SLUG_ATTACK_D_01,
		SLUG_ATTACK_D_02,
		SLUG_ATTACK_LD_01,
		SLUG_ATTACK_LD_02,
		SLUG_ATTACK_L_01,
		SLUG_ATTACK_L_02,
		SLUG_ATTACK_LU_01,
		SLUG_ATTACK_LU_02,
		SLUG_ATTACK_U_01,
		SLUG_ATTACK_U_02,
		SLUG_ATTACK_RU_01,
		SLUG_ATTACK_RU_02,
		SLUG_ATTACK_R_01,
		SLUG_ATTACK_R_02,
		SLUG_ATTACK_RD_01,
		SLUG_ATTACK_RD_02,
		/////////////////// 총알시작  ///////////////////
		BULLET_TEARS_01,
		BULLET_TEARS_02,
		BULLET_TEARS_03,
		BULLET_TEARS_04,
		BULLET_TEARS_05,
		BULLET_TEARS_06,
		BULLET_TEARS_07,
		BULLET_TEARS_08,
		BULLET_TEARS_09,
		BULLET_TEARS_10,
		BULLET_TEARS_11,
		BULLET_TEARS_12,
		BULLET_TEARS_13,
		BULLET_TEARS_14,
		BULLET_TEARS_15,

		BULLET_LEAF_01,
		BULLET_LEAF_02,
		BULLET_LEAF_03,
		BULLET_LEAF_04,
		BULLET_LEAF_05,
		BULLET_LEAF_06,
		BULLET_LEAF_07,
		BULLET_LEAF_08,
		BULLET_LEAF_09,

		FIRE_KICK_01,
		FIRE_KICK_02,
		FIRE_KICK_03,
		FIRE_KICK_04,
		FIRE_KICK_05,
		FIRE_KICK_06,

		BULLET_FIRE_01,
		BULLET_FIRE_02,
		BULLET_FIRE_03,
		BULLET_FIRE_04,
		BULLET_FIRE_05,

		BULLET_WATER_01,
		BULLET_WATER_02,

		BULLET_BUBBLE1_01,
		BULLET_BUBBLE1_02,
		BULLET_BUBBLE1_03,
		BULLET_BUBBLE1_04,
		BULLET_BUBBLE1_05,
		BULLET_BUBBLE1_06,
		BULLET_BUBBLE1_07,
		BULLET_BUBBLE1_08,
		BULLET_BUBBLE1_09,
		BULLET_BUBBLE1_10,
		BULLET_BUBBLE1_11,
		BULLET_BUBBLE1_12,
		BULLET_BUBBLE1_13,
		BULLET_BUBBLE1_14,
		BULLET_BUBBLE1_15,
		BULLET_BUBBLE1_16,
		BULLET_BUBBLE1_17,
		BULLET_BUBBLE1_18,
		BULLET_BUBBLE1_19,
		BULLET_BUBBLE1_20,
		BULLET_BUBBLE1_21,

		BULLET_FIRE1_01,
		BULLET_FIRE1_02,
		BULLET_FIRE1_03,
		BULLET_FIRE1_04,
		BULLET_FIRE1_05,
		BULLET_FIRE1_06,
		BULLET_FIRE1_07,
		BULLET_FIRE1_08,
		BULLET_FIRE1_09,
		BULLET_FIRE1_10,
		BULLET_FIRE1_11,
		BULLET_FIRE1_12,
		BULLET_FIRE1_13,
		BULLET_FIRE1_14,
		BULLET_FIRE1_15,
		BULLET_FIRE1_16,
		BULLET_FIRE1_17,
		BULLET_FIRE1_18,
		BULLET_FIRE1_19,
		BULLET_FIRE1_20,
		BULLET_FIRE1_21,
		BULLET_FIRE1_22,

		BULLET_FIRE2_01,
		BULLET_FIRE2_02,
		BULLET_FIRE2_03,
		BULLET_FIRE2_04,
		BULLET_FIRE2_05,
		BULLET_FIRE2_06,
		BULLET_FIRE2_07,

		BULLET_FIRE3_01,
		BULLET_FIRE3_02,
		BULLET_FIRE3_03,
		BULLET_FIRE3_04,
		BULLET_FIRE3_05,
		BULLET_FIRE3_06,
		BULLET_FIRE3_07,
		BULLET_FIRE3_08,
		BULLET_FIRE3_09,
		BULLET_FIRE3_10,
		BULLET_FIRE3_11,
		BULLET_FIRE3_12,

		BULLET_FIREWALL1_01,
		BULLET_FIREWALL1_02,
		BULLET_FIREWALL1_03,
		BULLET_FIREWALL1_04,
		BULLET_FIREWALL1_05,
		BULLET_FIREWALL1_06,
		BULLET_FIREWALL1_07,
		BULLET_FIREWALL1_08,
		BULLET_FIREWALL1_09,
		BULLET_FIREWALL1_10,
		BULLET_FIREWALL1_11,
		BULLET_FIREWALL1_12,
		BULLET_FIREWALL1_13,
		BULLET_FIREWALL1_14,

		BULLET_ICE1_01,
		BULLET_ICE1_02,
		BULLET_ICE1_03,
		BULLET_ICE1_04,
		BULLET_ICE1_05,
		BULLET_ICE1_06,
		BULLET_ICE1_07,
		BULLET_ICE1_08,
		BULLET_ICE1_09,
		BULLET_ICE1_10,
		BULLET_ICE1_11,
		BULLET_ICE1_12,
		BULLET_ICE1_13,
		BULLET_ICE1_14,
		BULLET_ICE1_15,
				
		BULLET_LCLAW1_01,
		BULLET_LCLAW1_02,
		BULLET_LCLAW1_03,
		BULLET_LCLAW1_04,
		BULLET_LCLAW1_05,
		BULLET_LCLAW1_06,
		BULLET_LCLAW1_07,

		BULLET_RCLAW1_01,
		BULLET_RCLAW1_02,
		BULLET_RCLAW1_03,
		BULLET_RCLAW1_04,
		BULLET_RCLAW1_05,
		BULLET_RCLAW1_06,
		BULLET_RCLAW1_07,

		BULLET_WATER1_01,
		BULLET_WATER1_02,
		BULLET_WATER1_03,
		BULLET_WATER1_04,

		BULLET_WATER2_01,
		BULLET_WATER2_02,
		BULLET_WATER2_03,
		BULLET_WATER2_04,
		BULLET_WATER2_05,
		BULLET_WATER2_06,
		BULLET_WATER2_07,
		BULLET_WATER2_08,
		BULLET_WATER2_09,
		BULLET_WATER2_10,
		BULLET_WATER2_11,
		BULLET_WATER2_12,
		BULLET_WATER2_13,
		BULLET_WATER2_14,
		BULLET_WATER2_15,

		BULLET_WEB1_01,
		BULLET_WEB1_02,
		BULLET_WEB1_03,

		BULLET_WIND1_01,
		BULLET_WIND1_02,
		BULLET_WIND1_03,
		BULLET_WIND1_04,
		BULLET_WIND1_05,
		BULLET_WIND1_06,
		BULLET_WIND1_07,
		BULLET_WIND1_08,
		BULLET_WIND1_09,
		BULLET_WIND1_10,
		BULLET_WIND1_11,
		BULLET_WIND1_12,
		BULLET_WIND1_13,
		BULLET_WIND1_14,
		BULLET_WIND1_15,

		BULLET_TORNADO1_01,
		BULLET_TORNADO1_02,
		BULLET_TORNADO1_03,
		BULLET_TORNADO1_04,
		BULLET_TORNADO1_05,
		BULLET_TORNADO1_06,
		BULLET_TORNADO1_07,
		BULLET_TORNADO1_08,
		BULLET_TORNADO1_09,
		BULLET_TORNADO1_10,

		BULLET_TORNADO2_01,
		BULLET_TORNADO2_02,
		BULLET_TORNADO2_03,
		BULLET_TORNADO2_04,
		BULLET_TORNADO2_05,
		BULLET_TORNADO2_06,
		BULLET_TORNADO2_07,
		BULLET_TORNADO2_08,
		BULLET_TORNADO2_09,
		BULLET_TORNADO2_10,

		BULLET_POISION1_01,
		BULLET_POISION1_02,
		BULLET_POISION1_03,
		BULLET_POISION1_04,
		BULLET_POISION1_05,
		BULLET_POISION1_06,
		BULLET_POISION1_07,
		BULLET_POISION1_08,
		BULLET_POISION1_09,
		BULLET_POISION1_10,
		BULLET_POISION1_11,
		BULLET_POISION1_12,
		BULLET_POISION1_13,
		BULLET_POISION1_14,
		BULLET_POISION1_15,

		GRASS_MAP,
		GRASS_MAP2,
		WATER_MAP,
		BROOK_MAP,
		FIRE_MAP,
			//
		GRASS_WATER_ENVIRONMENT,
		WATER_WATER_ENVIRONMENT,
		FIRE_WATER_ENVIRONMENT,
		TREE01,
		TREE02,
		TREE03,
		TREE04,

		PALMTREE01,
		PALMTREE02,
		PALMTREE03,
		PALMTREE04,

		RANGE,		
	};

	enum class TextureType
	{
		DEFAULT,
		CUBE,
	};
	
	class Texture
	{
	public:
		Texture();
		~Texture();

		int GetSpriteWidth()const;
		int GetSpriteHeight()const;

		LPDIRECT3DTEXTURE9 pTexture = nullptr;
		D3DXIMAGE_INFO imageInfo;
		DWORD rowCount = 1;
		DWORD colCount = 1;
	};


}
