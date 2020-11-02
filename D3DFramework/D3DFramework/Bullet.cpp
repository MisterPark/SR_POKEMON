#include "stdafx.h"
#include "Bullet.h"
#include "Rectangle.h"
#include "Environment.h"
#include "Terrain.h"
Bullet::Bullet()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	for (int i = 0; i < 3; i++)
	{
		Time[i] = 0.f;
	}
	for (int i = 0; i < 3; i++)
	{
		Frame[i] = 0;
	}
}

Bullet::Bullet(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const bool & alliance) :
	direction(dir)
{
	transform->position = pos;
	transform->scale = scale;

	isAlliance = alliance;

	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
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
	if (isBillboard) Billboard();
	if (isOnTerrain) OnTerrain();
	UpdateAnimation();
}

void Bullet::Render()
{
	GameObject::Render();
}

void Bullet::Initialize()
{
}

void Bullet::Release()
{
}

void Bullet::OnTerrain()
{
	GameObject* obj = ObjectManager::GetInstance()->FindObject<Environment>();
	if (obj == nullptr)
	{
		transform->position.y = offsetY;
		return;
	}
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");
	if (mesh == nullptr)
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

void Bullet::SetAniTexture(State _state, TextureKey _beginTextureKey, int _aniFrame)
{
	startArray[(int)_state][(int)Direction::D] = (TextureKey)((int)_beginTextureKey);
	endArray[(int)_state][(int)Direction::D] = (TextureKey)((int)_beginTextureKey + _aniFrame - 1);
}

Vector3 Bullet::PlayerSearchDir(bool PosY)
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	if (g == nullptr) return Vector3{ 0.f, 0.f, 0.f };
	Transform* PlayerT = g->transform;

	Vector3 dir = PlayerT->position - transform->position;

	if (!PosY)
		dir.y = 0.f;

	return dir;
}

Vector3 Bullet::MonsterSearchDir(bool PosY, float SearchRange)
{
	bool isAlliance = true;
	GameObject* g =  nullptr;
	while (isAlliance) {
		g = ObjectManager::GetInstance()->FindObject<Character>();

		isAlliance = g->isAlliance;
	}
	if (g == nullptr) return Vector3{ 0.f, 0.f, 0.f };

	Transform* PlayerT = g->transform;
	Vector3 dir = PlayerT->position - transform->position;

	if (!PosY)
		dir.y = 0.f;

	return dir;
}

void Bullet::SetDir(const Vector3 & dir)
{
	D3DXVec3Normalize(&direction, &dir);
}

void Bullet::MoveForward()
{
	Move(direction);
}

void Bullet::MoveForwardExceptY()
{
	Vector3::Normalize(&direction);
	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();
}

void Bullet::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;
	}
}

Bullet * Bullet::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const bool & isPlayer)
{
	Bullet* newBullet = new Bullet(pos, scale, dir, isPlayer);
	
	return newBullet;
}
