#include "stdafx.h"
#include "Character.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Bullet_Water.h"

Character::Character()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

}

Character::~Character()
{
	CollisionManager::DisregisterObject(this);
}

void Character::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
	UpdateAnimation();

}

void Character::Render()
{
	GameObject::Render();
}

void Character::Initialize()
{
}

void Character::Release()
{
}

void Character::OnTerrain()
{
	GameObject* obj = ObjectManager::GetInstance()->FindObject<Environment>();
	if (obj == nullptr)
	{
		transform->position.y = offsetY;
		return;
	}
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");
	if(mesh == nullptr)
	{
		transform->position.y = offsetY;
		return;
	}

	float y;
	bool onTerrain = mesh->GetYFromPoint(&y, transform->position.x, transform->position.z);
	if (onTerrain)
		transform->position.y = y + offsetY;
	else
	{
		transform->position.y = offsetY;
	}
}

float Character::GetAngleFromCamera()
{
	Vector3 camPos = Camera::GetPosition();

	Vector3 toCam = camPos - transform->position;
	toCam.y = 0.f;
	Vector3 myDir = direction;

	D3DXVec3Normalize(&toCam, &toCam);
	D3DXVec3Normalize(&myDir, &myDir);

	float radian = acos(D3DXVec3Dot(&toCam, &myDir));
	float degree = D3DXToDegree(radian);

	Vector3 cross;
	D3DXVec3Cross(&cross, &toCam, &myDir);

	Vector3 up = { 0.f, 1.f, 0.f };

	float upDot = D3DXVec3Dot(&cross, &up);

	if (0.f > upDot) degree = 360 - degree;

	return degree;
}

void Character::UpdateAnimation()
{
	float angle = GetAngleFromCamera();

	angle += 22.5f;

	int index = angle / 45.f;

	index %= 8;

	// ป๓ลย
	anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
}

void Character::SetDir(const Vector3 & dir)
{
	D3DXVec3Normalize(&direction, &dir);
}

void Character::MoveForward()
{
	Move(direction);
}

void Character::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;
	}
}

void Character::Attack(const Vector3 & dir)
{
}

void Character::Skill(const Vector3 & dir)
{
}

void Character::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame) {
	for (int i = 0; i < 8; i++)
	{
		startArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame));
		if (-1 == _endFrame)
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_aniFrame - 1));
		else
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_endFrame - 1));
	}
}