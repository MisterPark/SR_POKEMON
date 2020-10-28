#include "stdafx.h"
#include "Psyduck.h"

Psyduck::Psyduck()
{
	startArray[(int)State::WALK][(int)Direction::D] = TextureKey::PSY_WALK_D_01;
	endArray[(int)State::WALK][(int)Direction::D] = TextureKey::PSY_WALK_D_03;
	startArray[(int)State::WALK][(int)Direction::LD] = TextureKey::PSY_WALK_LD_01;
	endArray[(int)State::WALK][(int)Direction::LD] = TextureKey::PSY_WALK_LD_03;
	startArray[(int)State::WALK][(int)Direction::L] = TextureKey::PSY_WALK_L_01;
	endArray[(int)State::WALK][(int)Direction::L] = TextureKey::PSY_WALK_L_03;
	startArray[(int)State::WALK][(int)Direction::LU] = TextureKey::PSY_WALK_LU_01;
	endArray[(int)State::WALK][(int)Direction::LU] = TextureKey::PSY_WALK_LU_03;
	startArray[(int)State::WALK][(int)Direction::U] = TextureKey::PSY_WALK_U_01;
	endArray[(int)State::WALK][(int)Direction::U] = TextureKey::PSY_WALK_U_03;
	startArray[(int)State::WALK][(int)Direction::RU] = TextureKey::PSY_WALK_RU_01;
	endArray[(int)State::WALK][(int)Direction::RU] = TextureKey::PSY_WALK_RU_03;
	startArray[(int)State::WALK][(int)Direction::R] = TextureKey::PSY_WALK_R_01;
	endArray[(int)State::WALK][(int)Direction::R] = TextureKey::PSY_WALK_R_03;
	startArray[(int)State::WALK][(int)Direction::RD] = TextureKey::PSY_WALK_RD_01;
	endArray[(int)State::WALK][(int)Direction::RD] = TextureKey::PSY_WALK_RD_03;

	startArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::PSY_ATTACK2_D_01;
	endArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::PSY_ATTACK2_D_02;
	startArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::PSY_ATTACK2_LD_01;
	endArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::PSY_ATTACK2_LD_02;
	startArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::PSY_ATTACK2_L_01;
	endArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::PSY_ATTACK2_L_02;
	startArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::PSY_ATTACK2_LU_01;
	endArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::PSY_ATTACK2_LU_02;
	startArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::PSY_ATTACK2_U_01;
	endArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::PSY_ATTACK2_U_02;
	startArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::PSY_ATTACK2_RU_01;
	endArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::PSY_ATTACK2_RU_02;
	startArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::PSY_ATTACK2_R_01;
	endArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::PSY_ATTACK2_R_02;
	startArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::PSY_ATTACK2_RD_01;
	endArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::PSY_ATTACK2_RD_02;

	anim->SetLoop(true);
	offsetY = 2.5f;
	state = State::WALK;
}

Psyduck::~Psyduck()
{
}
