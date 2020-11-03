#include "stdafx.h"
#include "Skill_RushAttack.h"
#include "PlayerBullet.h"
#include "Effect.h"
#include "Bullet_Water.h"

Skill_RushAttack::Skill_RushAttack()
{
	coolTime = 1.65f;
}

Skill_RushAttack::~Skill_RushAttack()
{
}

void Skill_RushAttack::InitActiveTime()
{
	// activeTime = 1.65f;
}

void Skill_RushAttack::Update()
{

	CalcActiveTime();
}

/*
void Skill_RushAttack::Active(const Character* character)
{
	//Time[1] += TimeManager::DeltaTime();
	//if (1.5f < Time[1]) {
	//	MovePlayerFollow(15.f);
	//	if (1.65f < Time[1]) {
	//		c->state = State::READY;
	//		Time[1] = 0;
	//		//
	//		for (int j = -2; j < 3; j++)
	//		{
	//			for (int i = -2; i < 3; i++)
	//			{
	//				Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	//				Vector3 Dir2 = { c->direction.x + j * 0.8f, 0.f, c->direction.z + i * 0.8f };
	//				Dir2.Normalized();
	//				b->SetDir(Dir2);
	//				*(b->transform) = *c->transform;
	//				b->transform->position.y -= 0.5f;
	//				b->transform->scale.x = 0.7f;
	//				b->transform->scale.y = 0.7f;
	//				b->transform->scale.z = 0.7f;
	//			}
	//		}
	//		c->anim->SetDelay(0.1f);
	//	}
	//}
}
*/

Skill * Skill_RushAttack::Create()
{
	Skill* instance = new Skill_RushAttack;

	return instance;
}