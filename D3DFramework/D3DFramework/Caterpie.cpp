#include "stdafx.h"
#include "Caterpie.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"
#include "PlayerBullet.h"
#include "FieldFire.h"

Caterpie::Caterpie()
{
	Initialize();
}

Caterpie::Caterpie(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

void Caterpie::Initialize()
{
	name = L"캐터피";
	SetTexture(State::WALK, TextureKey::CATER_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::CATER_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::CATER_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::CATER_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::CATER_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	hp = 6.f;

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

void Caterpie::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Caterpie* Caterpie::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Caterpie* newPokemon = new Caterpie(pos, scale, dir);
	return newPokemon;
}

void Caterpie::OnCollision(GameObject* target)
{
	if (target->isAlliance == this->isAlliance) {
		return;
	}

	if (dynamic_cast<PlayerBullet*>(target)) {
	   //몬스터와 충돌 이벤트
		hp -= dynamic_cast<Bullet*>(target)->att;

		if(hp < 0.f)
			isDead = true;
	}

	else if (dynamic_cast<FieldFire*>(target)) {
		//몬스터와 충돌 이벤트
		hp -= dynamic_cast<FieldFire*>(target)->GetAtt();

		if (hp < 0.f)
			isDead = true;
	}
}