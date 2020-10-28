#include "stdafx.h"
#include "Character.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"

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
	// 카메라가 몬스터를 향하는 각
	Vector3 camPos = Camera::GetPosition();
	float degree1 = Vector3::AngleY(camPos, transform->position);

	// 몬스터 월드 각
	float degree2 = D3DXToDegree(atan2f(direction.x, direction.z));

	return (degree2 - degree1);
}

void Character::UpdateAnimation()
{
	float angle = GetAngleFromCamera();

	angle += 202.5f;
	
	if (angle > 360.f)
	{
		angle -= 360;
	}

	if ((int)angle % 45 > 22.5f) {
		angle /= 45.f;
		angle -= 1;
	}
	else {
		angle /= 45.f;
	}
	int index = angle;

	if (index > 7)
		index -= 8;
	else if (index < 0)
		index += 8;
	// 상태
	anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
	//int count = endArray[(int)state] - startArray[(int)state] + 1;

	//TextureKey key = (TextureKey)(startArray[(int)state] + index * count);
	//anim->SetSprite(key, (TextureKey)((count - 1) + (int)key));

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