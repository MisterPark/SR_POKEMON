#include "stdafx.h"
#include "Bulbasaur.h"
#include "Bullet.h"

Bulbasaur::Bulbasaur()
{
	Init();
}

Bulbasaur::Bulbasaur(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Init();
}

Bulbasaur::~Bulbasaur()
{
}

void Bulbasaur::Init()
{
	startArray[(int)State::WALK][(int)Direction::D] = TextureKey::PG01_WALK_D_01;
	endArray[(int)State::WALK][(int)Direction::D] = TextureKey::PG01_WALK_D_03;
	startArray[(int)State::WALK][(int)Direction::LD] = TextureKey::PG01_WALK_LD_01;
	endArray[(int)State::WALK][(int)Direction::LD] = TextureKey::PG01_WALK_LD_03;
	startArray[(int)State::WALK][(int)Direction::L] = TextureKey::PG01_WALK_L_01;
	endArray[(int)State::WALK][(int)Direction::L] = TextureKey::PG01_WALK_L_03;
	startArray[(int)State::WALK][(int)Direction::LU] = TextureKey::PG01_WALK_LU_01;
	endArray[(int)State::WALK][(int)Direction::LU] = TextureKey::PG01_WALK_LU_03;
	startArray[(int)State::WALK][(int)Direction::U] = TextureKey::PG01_WALK_U_01;
	endArray[(int)State::WALK][(int)Direction::U] = TextureKey::PG01_WALK_U_03;
	startArray[(int)State::WALK][(int)Direction::RU] = TextureKey::PG01_WALK_RU_01;
	endArray[(int)State::WALK][(int)Direction::RU] = TextureKey::PG01_WALK_RU_03;
	startArray[(int)State::WALK][(int)Direction::R] = TextureKey::PG01_WALK_R_01;
	endArray[(int)State::WALK][(int)Direction::R] = TextureKey::PG01_WALK_R_03;
	startArray[(int)State::WALK][(int)Direction::RD] = TextureKey::PG01_WALK_RD_01;
	endArray[(int)State::WALK][(int)Direction::RD] = TextureKey::PG01_WALK_RD_03;

	startArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::PG01_ATTACK_D_01;
	endArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::PG01_ATTACK_D_02;
	startArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::PG01_ATTACK_LD_01;
	endArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::PG01_ATTACK_LD_02;
	startArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::PG01_ATTACK_L_01;
	endArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::PG01_ATTACK_L_02;
	startArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::PG01_ATTACK_LU_01;
	endArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::PG01_ATTACK_LU_02;
	startArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::PG01_ATTACK_U_01;
	endArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::PG01_ATTACK_U_02;
	startArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::PG01_ATTACK_RU_01;
	endArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::PG01_ATTACK_RU_02;
	startArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::PG01_ATTACK_R_01;
	endArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::PG01_ATTACK_R_02;
	startArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::PG01_ATTACK_RD_01;
	endArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::PG01_ATTACK_RD_02;

	anim->SetLoop(true);
	offsetY = 2.f;
	state = State::WALK;
}

void Bulbasaur::Attack(const Vector3 & dir)
{
	Bullet* newBullet = Bullet::Create(transform->position, { 1.f, 1.f, 1.f }, dir, 0);
	ObjectManager::AddObject(newBullet);
}

void Bulbasaur::Skill(const Vector3 & dir)
{
}

Bulbasaur * Bulbasaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Bulbasaur* newBulbasaur = new Bulbasaur(pos, scale, dir);
	return newBulbasaur;
}
