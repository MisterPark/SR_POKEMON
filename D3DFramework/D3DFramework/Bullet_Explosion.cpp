#include "stdafx.h"
#include "Bullet_Explosion.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"
#include "Bullet_RedBall.h"
Bullet_Explosion::Bullet_Explosion()
{
	anim->SetSprite(TextureKey::BULLET_REDBALL1_01, TextureKey::BULLET_REDBALL1_07);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.4f, 0.4f, 0.4f };

	lifeTime = 2.f;
	stat.moveSpeed = 2.5f;
	

	isOnTerrain = false;

}

Bullet_Explosion::~Bullet_Explosion()
{

}

void Bullet_Explosion::Update()
{
	Bullet::Update();

	
	if (lifeTime < 0)
	{
		for (int i = -4; i < 4; i++)
		{
			Bullet_RedBall* bullet = dynamic_cast<Bullet_RedBall*>(ObjectManager::GetInstance()->CreateObject<Bullet_RedBall>());
			bullet->transform->position = transform->position;
			Vector3 rDir = direction;

			rDir.x = i * 0.2;


			bullet->stat.attack = stat.attack * 1000.f;

			Vector3::Normalize(&rDir);
			bullet->SetDir(rDir);
			float size = 0.2f;
			bullet->transform->scale = { size,size,size };
			if (team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(stat.attack);
			}
			else if (team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(stat.attack);
			}
		}
		Die();
	}


}

void Bullet_Explosion::Render()
{
	Bullet::Render();
}

void Bullet_Explosion::OnCollision(GameObject* target)
{
	Die();
}