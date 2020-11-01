#include "stdafx.h"
#include "Metapod.h"
#include "Rectangle.h"
#include "PlayerBullet.h"
#include "Bullet.h"
#include "FieldFire.h"

Metapod::Metapod()
{
	Initialize();
}

Metapod::Metapod(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Metapod::~Metapod()
{
}

void Metapod::Initialize()
{
	name = L"단데기";
	SetTexture(State::WALK, TextureKey::META_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::META_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::META_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::META_ATTACK_D_01, 2, 1);
	SetTexture(State::SKILL, TextureKey::META_ATTACK_D_01, 2, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 0.7f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	hp = 6.f;

	UpdateAnimation();
}

void Metapod::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Metapod::Render()
{
	Character::Render();
}

void Metapod::Release()
{
}

void Metapod::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Metapod* Metapod::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Metapod* newPokemon = new Metapod(pos, scale, dir);
	return newPokemon;
}

void Metapod::OnCollision(GameObject* target)
{
	if (target->isAlliance == this->isAlliance) {
		return;
	}

	if (dynamic_cast<PlayerBullet*>(target)) {
		//몬스터와 충돌 이벤트
		hp -= dynamic_cast<Bullet*>(target)->att;

		if (hp < 0.f)
			isDead = true;
	}

	else if (dynamic_cast<FieldFire*>(target)) {
		//몬스터와 충돌 이벤트
		hp -= dynamic_cast<FieldFire*>(target)->GetAtt();

		if (hp < 0.f)
			isDead = true;
	}
}