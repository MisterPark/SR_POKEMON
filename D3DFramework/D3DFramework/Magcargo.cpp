#include "stdafx.h"
#include "Magcargo.h"
#include "Plane.h"
#include "Rectangle.h"
#include "DamageSkin.h"
#include "Effect.h"
#include "PlayerInfoPanel.h"
#include "TargetInfoPanel.h"
#include "Bullet_FireMiniBomb.h"
#include "Coin.h"

Magcargo::Magcargo()
{
	Initialize();
}

Magcargo::Magcargo(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	Initialize();
}

Magcargo::~Magcargo()
{
}

void Magcargo::Initialize()
{
	name = L"마그카르고";
	type = TYPE::MAGCARGO;
	number = Pokemon::Magcargo;

	SetTexture(State::WALK, TextureKey::MAGCA_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::MAGCA_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::MAGCA_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::MAGCA_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::MAGCA_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.1f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 50;
	defaultMaxHp = 450;

	increaseAttack = defaultAttack * 0.05;
	increaseMaxHp = defaultMaxHp * 0.05;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBomb));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireXCrossBomb));

	SetStatByLevel();
	UpdateAnimation();

}

void Magcargo::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();

}

void Magcargo::Render()
{
	Character::Render();
}

void Magcargo::Release()
{
}

bool Magcargo::Attack(const Vector3& dir, const int& attackType)
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

Magcargo* Magcargo::Create(const Vector3& pos, const Vector3& dir)
{
	Magcargo* newPokemon = new Magcargo(pos, dir);
	return newPokemon;
}

void Magcargo::OnCollision(GameObject* target)
{


	if (isInvincible == false)
	{
		if (this->team == target->team) return;

		Character* playerCharacter = Player::GetInstance()->GetCharacter();

		// TODO : 경훈 / 임시 :  데미지 오차 처리 ( 나중에 Stat만들고 없애셈)
		if (stat.hp > stat.maxHp)
		{
			stat.hp = stat.maxHp;
		}

		float error = target->stat.attack * 0.4f;
		float errorHalf = error * 0.5f;
		error = Random::Range(0.f, error);
		error -= errorHalf;
		float damageSum = target->stat.attack + error;
		stat.hp -= damageSum;


		if (damageSum < 0)
		{
			if (damageSum < -1)
			{
				DamageSkin* skin = (DamageSkin*)ObjectManager::GetInstance()->CreateObject<DamageSkin>();
				skin->transform->position = this->transform->position;
				skin->SetDamage(-damageSum);
				skin->SetColor(D3DCOLOR_XRGB(0, 200, 0));
			}

			if (healEffectStack > 1.f)
			{
				Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_HEART1_01, TextureKey::BULLET_HEART1_05, 0.2f);
				/*fx->transform->position.y += 1.f;*/
				ObjectManager::AddObject(fx);
				healEffectStack = 0.f;
			}
		}

		// 데미지 스킨
		else if (damageSum >= 1)
		{
			DamageSkin* skin = (DamageSkin*)ObjectManager::GetInstance()->CreateObject<DamageSkin>();
			skin->transform->position = this->transform->position;
			skin->SetDamage(damageSum);
			if (this == playerCharacter)
			{
				skin->SetColor(D3DCOLOR_XRGB(200, 0, 200));
				PlayerInfoPanel::ActiveRedFilter();
			}

		}

		if (damageSum > 0.f && this == playerCharacter)
		{
			PlayerInfoPanel::ActiveRedFilter();
		}


		// 사망처리
		if (!IsDead() && stat.hp <= 0)
		{
			DeadAction();
			if (this->team == Team::MONSTERTEAM) {
				Player::GetInstance()->ChangeNextPokemon(type, number);
				Coin* coin = Coin::Create(this->transform->position, this->stat.money);
				ObjectManager::AddObject(coin);
				CollisionManager::RegisterObject(COLTYPE::COIN, coin);
			}

			//
			stat.hp = 0;
			if (dontDestroy == true) return;

			Die();
			if (nullptr == spawner)
				return;
			spawner->monsterCount--;
			return;

		}

		// 상대가 플레이어면서 몬스터일때 해당
		if (damageSum < 0)return;

		if (playerCharacter == this) return;
		TargetInfoPanel::SetTarget(this);
		TargetInfoPanel::Show();
	}
	else
		return;
}

void Magcargo::DeadAction() {
	Vector3 Dir3 = { (direction.x + direction.z) * 0.5f,  0.5f, (-direction.x + direction.z) * 0.5f };

	Bullet_FireMiniBomb* bullet = dynamic_cast<Bullet_FireMiniBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireMiniBomb>());
	bullet->transform->position = transform->position;
	Vector3 Dir2 = { Dir3.x,0.f,Dir3.z };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->SetInitAttack(stat.attack);
	bullet->team = team;

	if (team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 0.5f);
	}
	else if (team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 2.f);
	}


	bullet = dynamic_cast<Bullet_FireMiniBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireMiniBomb>());
	bullet->transform->position = transform->position;
	Dir2 = { Dir3.z, 0.f, -Dir3.x };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->SetInitAttack(stat.attack);
	bullet->team = team;

	if (team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 0.5f);
	}
	else if (team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 2.f);
	}


	bullet = dynamic_cast<Bullet_FireMiniBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireMiniBomb>());
	bullet->transform->position = transform->position;
	Dir2 = { -Dir3.x, 0.f, -Dir3.z };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->SetInitAttack(stat.attack);
	bullet->team = team;

	if (team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 0.5f);
	}
	else if (team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 2.f);
	}


	bullet = dynamic_cast<Bullet_FireMiniBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireMiniBomb>());
	bullet->transform->position = transform->position;
	Dir2 = { -Dir3.z,0.f,Dir3.x };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->SetInitAttack(stat.attack);
	bullet->team = team;

	if (team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 0.5f);
	}
	else if (team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(stat.attack * 2.f);
	}
}