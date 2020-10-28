#include "stdafx.h"
#include "Bullet.h"
#include "Rectangle.h"

Bullet::Bullet()
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
	SetTexture(State::IDLE, TextureKey::BULLET_TEARS_01, 15);
	state = State::IDLE;
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
