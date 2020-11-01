#include "stdafx.h"
#include "Scyther.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Bullet_Tornado.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Bullet.h"
#include "FieldFire.h"

Scyther::Scyther()
{
	Initialize();
}

Scyther::Scyther(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Scyther::~Scyther()
{
}

void Scyther::Initialize()
{
	name = L"스라크";
	SetTexture(State::WALK, TextureKey::SCY_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::SCY_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 3.5f;
	offsetY = 1.f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	hp = 60.f;

	UpdateAnimation();
}

void Scyther::Update()
{
	//Parttern();
	Character::Update();

}

void Scyther::Render()
{
	Character::Render();
}

void Scyther::Release()
{
}

void Scyther::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Scyther* Scyther::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Scyther* newPokemon = new Scyther(pos, scale, dir);
	return newPokemon;
}

void Scyther::OnCollision(GameObject* target)
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
