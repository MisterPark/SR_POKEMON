#include "stdafx.h"
#include "Bullet_Synthesis.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Synthesis::Bullet_Synthesis()
{
	anim->SetSprite(TextureKey::BULLET_INVISIBLE_01, TextureKey::BULLET_INVISIBLE_01);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 4.f;
	stat.moveSpeed = 0.f;

}

Bullet_Synthesis::~Bullet_Synthesis()
{
}

void Bullet_Synthesis::Update()
{
	Bullet::Update();
	

}

void Bullet_Synthesis::Render()
{
	Bullet::Render();
}

void Bullet_Synthesis::OnCollision(GameObject* target)
{
	stack += TimeManager::DeltaTime();
	if (stack > 1)
	{
		Effect* fx = Effect::Create(target->transform->position, target->transform->scale, TextureKey::EFFECT_SYNTHESIS_01, TextureKey::EFFECT_SYNTHESIS_12, 0.05f);
		ObjectManager::AddObject(fx);
		stack = 0;
	}
}