#include "stdafx.h"
#include "Coin.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"

Coin::Coin()
{
	Initialize();
}

Coin::Coin(const Vector3& pos, int money)
{
	transform->position = pos;
	stat.money = money;
	Initialize();
}

Coin::~Coin()
{
	CollisionManager::GetInstance()->DisregisterObject(this);
}

void Coin::Initialize()
{
	//SetTexture(State::IDLE, TextureKey::COINPOKE_1, 27);
	team = Team::MONSTERTEAM;
	CollisionManager::RegisterObject(COLTYPE::COIN, this);
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	anim->SetSprite(TextureKey::COINPOKE_1, TextureKey::COINPOKE_27);
	anim->SetLoop(true);
	anim->SetDelay(0.06f);
	
	offsetY = 0.3f;
	lifeTime = 5.f;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	delay = 1.5f;
	stat.attack = 0.f;

	//stat.money;

	//UpdateAnimation();
}

void Coin::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
	if (offsetYAdd) {
		offsetY += 0.004f;
		if (offsetY > 0.4f)
			offsetYAdd = false;
	}
	else {
		offsetY -= 0.004f;
		if (offsetY < 0.2f)
			offsetYAdd = true;
	}

	lifeTime -= TimeManager::DeltaTime();
	if (lifeTime < 0.f) isDead = true;
	else if (lifeTime < 1.f) {
		float sizeDec = TimeManager::DeltaTime() * 0.2f;
		transform->scale.x -= sizeDec;
		transform->scale.y -= sizeDec;
		transform->scale.z -= sizeDec;
	}

	delay -= TimeManager::DeltaTime();
	if (delay < 0.f) {
		Vector3 RandomPos;
		RandomPos.x = transform->position.x + ((Random::Value(10) - 5) * 0.05f);
		RandomPos.y = transform->position.y + ((Random::Value(10) - 5) * 0.05f);
		RandomPos.z = transform->position.z + ((Random::Value(10) - 5) * 0.05f);
		Effect* fx = Effect::Create(RandomPos, transform->scale, TextureKey::RING_09, TextureKey::RING_15, 0.1f);
		ObjectManager::AddObject(fx);
		delay = 1.5f;
	}
}

void Coin::Release()
{
}

Coin* Coin::Create(const Vector3& pos, int money)
{
	Coin* newCoin = new Coin(pos, money);
	return newCoin;
}

void Coin::OnCollision(GameObject* target)
{
	SoundManager::PlayOverlapSound(L"CoinGet.wav", SoundChannel::MONSTER);
	SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
	Player::GetInstance()->GetCharacter()->stat.money += stat.money;

	Vector3 RandomPos;
	for (int i = 0; i < 3; i++)
	{
		RandomPos.x = transform->position.x + ((Random::Value(10) - 5) * 0.05f);
		RandomPos.y = transform->position.y + ((Random::Value(10) - 5) * 0.05f);
		RandomPos.z = transform->position.z + ((Random::Value(10) - 5) * 0.05f);
		Effect* fx = Effect::Create(RandomPos, transform->scale, TextureKey::RING_09, TextureKey::RING_15, 0.1f);
		ObjectManager::AddObject(fx);
	}
	Die();
}

void Coin::OnTerrain()
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