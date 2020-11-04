#include "stdafx.h"
#include "Poliwhirl.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Poliwhirl::Poliwhirl()
{
	Initialize();
}

Poliwhirl::Poliwhirl(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Poliwhirl::~Poliwhirl()
{
}

void Poliwhirl::Initialize()
{
	name = L"¼ö·úÃ¬ÀÌ";
	number = Pokemon::Poliwhirl;

	SetTexture(State::WALK, TextureKey::WHIRL_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::WHIRL_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::WHIRL_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::WHIRL_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::WHIRL_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	attack = 40;
	hp = 300;
	maxHp = 300;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	UpdateAnimation();

}

void Poliwhirl::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Poliwhirl::Render()
{
	Character::Render();
}

void Poliwhirl::Release()
{
}

bool Poliwhirl::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		}
		return true;
	}
	return false;
}

Poliwhirl* Poliwhirl::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Poliwhirl* newPokemon = new Poliwhirl(pos, scale, dir);
	return newPokemon;
}