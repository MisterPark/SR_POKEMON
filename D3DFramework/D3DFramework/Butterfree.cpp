#include "stdafx.h"
#include "Butterfree.h"

Butterfree::Butterfree()
{
	startArray[(int)State::WALK][(int)Direction::D] = TextureKey::BUTTER_WALK_D_01;
	endArray[(int)State::WALK][(int)Direction::D] = TextureKey::BUTTER_WALK_D_03;
	startArray[(int)State::WALK][(int)Direction::LD] = TextureKey::BUTTER_WALK_LD_01;
	endArray[(int)State::WALK][(int)Direction::LD] = TextureKey::BUTTER_WALK_LD_03;
	startArray[(int)State::WALK][(int)Direction::L] = TextureKey::BUTTER_WALK_L_01;
	endArray[(int)State::WALK][(int)Direction::L] = TextureKey::BUTTER_WALK_L_03;
	startArray[(int)State::WALK][(int)Direction::LU] = TextureKey::BUTTER_WALK_LU_01;
	endArray[(int)State::WALK][(int)Direction::LU] = TextureKey::BUTTER_WALK_LU_03;
	startArray[(int)State::WALK][(int)Direction::U] = TextureKey::BUTTER_WALK_U_01;
	endArray[(int)State::WALK][(int)Direction::U] = TextureKey::BUTTER_WALK_U_03;
	startArray[(int)State::WALK][(int)Direction::RU] = TextureKey::BUTTER_WALK_RU_01;
	endArray[(int)State::WALK][(int)Direction::RU] = TextureKey::BUTTER_WALK_RU_03;
	startArray[(int)State::WALK][(int)Direction::R] = TextureKey::BUTTER_WALK_R_01;
	endArray[(int)State::WALK][(int)Direction::R] = TextureKey::BUTTER_WALK_R_03;
	startArray[(int)State::WALK][(int)Direction::RD] = TextureKey::BUTTER_WALK_RD_01;
	endArray[(int)State::WALK][(int)Direction::RD] = TextureKey::BUTTER_WALK_RD_03;

	startArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::BUTTER_ATTACK_D_01;
	endArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::BUTTER_ATTACK_D_02;
	startArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::BUTTER_ATTACK_LD_01;
	endArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::BUTTER_ATTACK_LD_02;
	startArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::BUTTER_ATTACK_L_01;
	endArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::BUTTER_ATTACK_L_02;
	startArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::BUTTER_ATTACK_LU_01;
	endArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::BUTTER_ATTACK_LU_02;
	startArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::BUTTER_ATTACK_U_01;
	endArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::BUTTER_ATTACK_U_02;
	startArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::BUTTER_ATTACK_RU_01;
	endArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::BUTTER_ATTACK_RU_02;
	startArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::BUTTER_ATTACK_R_01;
	endArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::BUTTER_ATTACK_R_02;
	startArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::BUTTER_ATTACK_RD_01;
	endArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::BUTTER_ATTACK_RD_02;

	anim->SetLoop(true);
	offsetY = 2.5f;
	state = State::WALK;
}

Butterfree::~Butterfree()
{
}
