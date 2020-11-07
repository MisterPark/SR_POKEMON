#include "stdafx.h"
#include "Bullet.h"
#include "Rectangle.h"
#include "Environment.h"
#include "Terrain.h"
#include "Character.h"
Bullet::Bullet()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	team = Team::NEUTRAL;

	direction = { 0.f, 0.f, 1.f };
	stat.attack = 1.f;
	stat.moveSpeed = 10.f;
	lifeTime = 2.f;
	offsetY = 0.f;
	animDelay = 0.5f;

	isCollideOnTerrain = false;
	isOnTerrain = false;
	isBillboard = true;
	isLoop = true;
}

Bullet::~Bullet()
{
	CollisionManager::GetInstance()->DisregisterObject(this);
	Release();
}

void Bullet::Initialize()
{
}

void Bullet::Update()
{
	GameObject::Update();
	Move(direction);
	OnTerrain();
	CollideOnTerrain();

	if (isBillboard) Billboard();
	CalcLifeTime();
}

void Bullet::Render()
{
	GameObject::Render();
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

	if (isOnTerrain)
	{
		if (onTerrain)
			transform->position.y = y + offsetY;
		else
		{
			transform->position.y = offsetY;
		}
	}
	else
	{
		if (transform->position.y < y)
			isCollideOnTerrain = true;
	}
}

void Bullet::CalcLifeTime()
{
	lifeTime -= TimeManager::DeltaTime();
	if (0.f >= lifeTime) Die();
}

void Bullet::CollideOnTerrain()
{
	if (isCollideOnTerrain) Die();
}

Vector3 Bullet::PlayerSearchDir(bool PosY)
{
	GameObject* g = ObjectManager::GetInstance()->GetNearestObject<Character>((GameObject*)this, Character::IsNotAlliance);

	if (g == nullptr) return Vector3{ 0.f, 0.f, 0.f };
	Transform* PlayerT = g->transform;

	Vector3 dir = PlayerT->position - transform->position;

	if (!PosY)
		dir.y = 0.f;

	return dir;
}

Vector3 Bullet::MonsterSearchDir(bool PosY, float SearchRange)
{
	//TODO: 나중에 플레이어로 따라가게 수정 완료해야함
	bool isAlliance = true;
	GameObject* target =  nullptr;
	while (isAlliance) {
		target = ObjectManager::GetInstance()->FindObject<Character>();
	}
	if (target == nullptr) return Vector3{ 0.f, 0.f, 0.f };

	Transform* PlayerT = target->transform;
	Vector3 dir = PlayerT->position - transform->position;

	if (!PosY)
		dir.y = 0.f;

	return dir;
}

void Bullet::MoveForward()
{
	Move(direction);
}

void Bullet::MoveForwardExceptY()
{
	Vector3::Normalize(&direction);
	transform->position.x += direction.x * stat.moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * stat.moveSpeed * TimeManager::DeltaTime();
}

void Bullet::SetTeam(Team _team)
{
	team = _team;
}
