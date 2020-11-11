#include "stdafx.h"
#include "Item.h"
#include "Inventory.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"
#include "AllItems.h"

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

Item* Item::CreateRandom()
{
	int random = Random::Range(0, 50);

	Item* item = nullptr;

	ItemType t = (ItemType)random;
	switch (t)
	{
	case ItemType::NONE:
		break;
	case ItemType::TOMATO:
		item = new Item_Tomato;
		break;
	case ItemType::CLAM:
		item = new Item_Clam;
		break;
	case ItemType::GRAPE:
		item = new Item_Grape;
		break;
	case ItemType::PEAR:
		item = new Item_Pear;
		break;
	case ItemType::GAJI:
		item = new Item_Gaji;
		break;
	case ItemType::LEMON:
		item = new Item_Lemon;
		break;
	case ItemType::BLUEBERRY:
		item = new Item_BlueBerry;
		break;
	case ItemType::HP_POTION:
		item = new Item_HpPotion;
		break;
	case ItemType::EXP_POTION:
		item = new Item_ExpPotion;
		break;
	case ItemType::STONE_OF_FIRE:
		item = new Item_StoneOfFire;
		break;
	case ItemType::STONE_OF_WATER:
		item = new Item_StoneOfWater;
		break;
	case ItemType::STONE_OF_LEAF:
		item = new Item_StoneOfLeaf;
		break;
	case ItemType::STONE_OF_THUNDER:
		item = new Item_StoneOfThunder;
		break;
	case ItemType::STONE_OF_MOON:
		item = new Item_StoneOfMoon;
		break;
	case ItemType::STONE_OF_SUN:
		item = new Item_StoneOfSun;
		break;
	case ItemType::STONE_OF_LIGHT:
		item = new Item_StoneOfLight;
		break;
	case ItemType::STONE_OF_AWAKE:
		item = new Item_StoneOfAwake;
		break;
	case ItemType::STONE_OF_DARK:
		item = new Item_StoneOfDark;
		break;
	case ItemType::POKE_BALL:

		break;
	case ItemType::GREAT_BALL:
		break;
	case ItemType::ULTRA_BALL:
		break;
	case ItemType::MASTER_BALL:
		break;
	default:
		break;
	}


	return item;
}
