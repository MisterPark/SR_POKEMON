#include "stdafx.h"
#include "Bullet.h"
#include "Rectangle.h"

Bullet::Bullet()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
}

Bullet::Bullet(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const int & type, const bool & isPlayer) :
	direction(dir), isPlayer(isPlayer)
{
	transform->position = pos;
	transform->scale = scale;

	Initialize();

	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
}

Bullet::~Bullet()
{
	CollisionManager::DisregisterObject(this);
}

void Bullet::Update()
{
	GameObject::Update();
	Move(direction);
	Billboard();
	UpdateAnimation();
}

void Bullet::Render()
{
	GameObject::Render();
}

void Bullet::Initialize()
{
	SetTexture(State::IDLE, TextureKey::BULLET_TEARS_01, 15);
	state = State::IDLE;
}

void Bullet::Release()
{
}

float Bullet::GetAngleFromCamera()
{
	// 카메라가 몬스터를 향하는 각
	Vector3 camPos = Camera::GetPosition();
	float degree1 = Vector3::AngleY(camPos, transform->position);

	// 몬스터 월드 각
	float degree2 = D3DXToDegree(atan2f(direction.x, direction.z));

	return (degree2 - degree1);
}

void Bullet::UpdateAnimation()
{
	//float angle = GetAngleFromCamera();

	//angle += 202.5f;

	//if (angle > 360.f)
	//{
	//	angle -= 360;
	//}

	//if ((int)angle % 45 > 22.5f) {
	//	angle /= 45.f;
	//	angle -= 1;
	//}
	//else {
	//	angle /= 45.f;
	//}
	//int index = angle;

	//if (index > 7)
	//	index -= 8;
	//else if (index < 0)
	//	index += 8;
	//// 상태
	//anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
	anim->SetSprite(startArray[(int)state][0], endArray[(int)state][0]);
}

void Bullet::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame)
{
	for (int i = 0; i < 8; i++)
	{
		startArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame));
		if (-1 == _endFrame)
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_aniFrame - 1));
		else
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_endFrame - 1));
	}
}


void Bullet::SetDir(const Vector3 & dir)
{
	D3DXVec3Normalize(&direction, &dir);
}

void Bullet::MoveForward()
{
	Move(direction);
}

void Bullet::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;
	}
}

Bullet * Bullet::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const int & type, const bool & isPlayer)
{
	Bullet* newBullet = new Bullet(pos, scale, dir, type, isPlayer);
	
	return newBullet;
}
