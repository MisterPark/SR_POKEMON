#include "stdafx.h"
#include "Bullet.h"
#include "Rectangle.h"

Bullet::Bullet() :
	Character::Character()
{
}

Bullet::Bullet(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const int & type, const bool & isPlayer) :
	dir(dir), type(type), isPlayer(isPlayer)
{
	transform->position = pos;
	transform->scale = scale;

	Initialize();
}

Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{
	AddComponent<PKH::Rectangle>(L"Mesh");
	Animation2D* anim = (Animation2D*)AddComponent<Animation2D>(L"Animation");

	anim->SetSprite(TextureKey::BULLET_TEARS_01, TextureKey::BULLET_TEARS_15);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);
}

void Bullet::Update()
{
	Move(dir);

	Character::Update();
}

void Bullet::Render()
{
	Character::Render();
}

void Bullet::Release()
{
}

Bullet * Bullet::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const int & type, const bool & isPlayer)
{
	Bullet* newBullet = new Bullet(pos, scale, dir, type, isPlayer);
	
	return newBullet;
}
