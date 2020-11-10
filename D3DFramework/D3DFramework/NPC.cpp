#include "stdafx.h"
#include "NPC.h"
#include "Environment.h"
#include "Terrain.h"
#include "Rectangle.h"

NPC::NPC()
{
	Initialize();
}

NPC::~NPC()
{
	Release();
}

void NPC::Initialize()
{
	stat.attack = 0.f;
	offsetY = 1.f;
	team = Team::MONSTERTEAM;
	CollisionManager::RegisterObject(COLTYPE::NPC, this);

	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	anim->SetLoop(false);
}

void NPC::Release()
{
	CollisionManager::DisregisterObject(COLTYPE::NPC, this);
}

void NPC::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
}

void NPC::OnCollision(GameObject* target)
{
	Character* pc = Player::GetInstance()->GetCharacter();
	if (pc == nullptr) return;
	if (pc != target)return;

	if (InputManager::GetKeyDown('F'))
	{
		OnEvent();
	}
	
}

void NPC::OnTerrain()
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
