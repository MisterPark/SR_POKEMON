#include "stdafx.h"
#include "Caterpie.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Caterpie::Caterpie()
{
	Initialize();
}

Caterpie::Caterpie(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	Initialize();
}

void Caterpie::Initialize()
{
	name = L"Ä³ÅÍÇÇ";
	type = TYPE::CATERPIE;
	number = Pokemon::Caterpie;

	SetTexture(State::WALK, TextureKey::CATER_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::CATER_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::CATER_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::CATER_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::CATER_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.3f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WebShot));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Rush));

	transform->scale = { 0.3f, 0.3f, 0.3f };
	stat.attack = 15;
	stat.hp = 60;
	stat.maxHp = 60;

	UpdateAnimation();
}

Caterpie::~Caterpie()
{
}

void Caterpie::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Caterpie::Render()
{
	Character::Render();
}

void Caterpie::Release()
{
}

bool Caterpie::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		if (team == Team::PLAYERTEAM) {
			switch (attackType)
			{
			case 0: ChangeState(State::ATTACK); break;
			case 1: ChangeState(State::ATTACK); break;
			}
		}
		return true;
	}
	return false;
}

Caterpie* Caterpie::Create(const Vector3& pos, const Vector3& dir)
{
	Caterpie* newPokemon = new Caterpie(pos, dir);
	return newPokemon;
}
