#include "stdafx.h"
#include "Item.h"
#include "Inventory.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

Item::Item()
{
	Initialize();
}

Item::~Item()
{
	Release();
}

void Item::Initialize()
{
	stat.attack = 0.f;
	offsetY = 0.2f;
	transform->scale = { 0.2f,0.2f,0.2f };
	team = Team::MONSTERTEAM;
	CollisionManager::RegisterObject(COLTYPE::ITEM, this);
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	anim->SetSprite(TextureKey::NONE, TextureKey::NONE);
	anim->SetLoop(false);
}

void Item::Release()
{
	
	CollisionManager::DisregisterObject(COLTYPE::ITEM, this);
}

void Item::Update()
{
	UpDown();
	GameObject::Update();
	OnTerrain();
	Billboard();
}

void Item::OnCollision(GameObject* target)
{
	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;
	if (player != target)return;
	if (inSlot) return;
	// TODO : °æÈÆ/ ÀÎº¥Åä¸®¿¡ ¾ÆÀÌÅÛ »ðÀÔ
	// ÀÎº¥²ËÃÆÀ¸¸é ³ë´ÙÀÌ

	if (Inventory::Push(this))
	{
		this->inSlot = true;
	}

}

void Item::OnTerrain()
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

void Item::UpDown()
{
	downTick += TimeManager::DeltaTime();
	if (downTick > downDuration)
	{
		downTick = 0.f;
		downFlag = !downFlag;
	}

	if (downFlag)
	{
		offsetY -= TimeManager::DeltaTime() * 0.2f;
	}
	else
	{
		offsetY += TimeManager::DeltaTime() * 0.2f;
	}
}
