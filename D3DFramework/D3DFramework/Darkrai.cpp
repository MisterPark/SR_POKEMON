#include "stdafx.h"
#include "Darkrai.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Effect.h"

Darkrai::Darkrai()
{
	Initialize();
}

Darkrai::Darkrai(const Vector3& pos, const Vector3& dir, int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Darkrai::~Darkrai()
{
}

void Darkrai::Initialize()
{
	name = L"다크라이";
	type = TYPE::DARKRAI;
	number = Pokemon::Darkrai;

	SetTexture(State::WALK, TextureKey::DARK_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::DARK_WALK_D_01, 3);
	SetTexture(State::READY, TextureKey::DARK_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::DARK_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::DARK_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::DARK_ATTACK_D_01, 2);
	SetTexture(State::SKILL3, TextureKey::DARK_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 4.5f;
	
	state = State::READY;

	offsetY = 1.f;
	transform->scale = { 1.f, 1.f, 1.f };

	defaultAttack = 100;
	defaultMaxHp = 4000;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::DarkBallFall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::GuidEnergyBall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::GravityEnergyBall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::DiagonalEnergyBall));


	SetStatByLevel();
	UpdateAnimation();

}

void Darkrai::Update()
{
	//Pattern();
	Character::Update();
	//ShadowCreate();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Darkrai::Render()
{
	Character::Render();
}

void Darkrai::Release()
{
}

bool Darkrai::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		case 1: ChangeState(State::ATTACK); break;
		case 2: ChangeState(State::ATTACK); break;
		case 3: ChangeState(State::ATTACK); break;
		}
		return true;
	}
	return false;
}

Darkrai* Darkrai::Create(const Vector3& pos, const Vector3& dir, int lv)
{
	Darkrai* newPokemon = new Darkrai(pos, dir, lv);
	return newPokemon;
}

void Darkrai::ShadowCreate() {
	if(state == State::WALK || state == State::READY)
	delay -= TimeManager::DeltaTime();
	if (delay < 0.f) {
		delay = 0.1f;
		float angle = GetAngleFromCamera();

		angle += 22.5f;

		int index = int(angle / 45.f);

		index %= 8;

		int textureKey= (int)TextureKey::DARK_SHADOW_01 + index * 3;
		//Effect* fx = Effect::Create(transform->position, transform->scale, (TextureKey)(textureKey+2), (TextureKey)(textureKey + 2), 1.f);
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::DARK_SHADOW_01, TextureKey::DARK_SHADOW_03, 1.f);
		ObjectManager::AddObject(fx);
	}
}