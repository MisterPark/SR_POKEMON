#include "stdafx.h"
#include "Projectile.h"
#include "Rectangle.h"
#include "Effect.h"
#include "Bullet.h"

Projectile::Projectile()
{
}

Projectile::Projectile(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float lifeTime, float att) :
	direction(dir), lifeTime(lifeTime), att(att)
{
	transform->position = pos;
	transform->scale = size;
	moveSpeed = speed;

	SetTexture(State::IDLE, start, 1);
	SetTexture(State::ATTACK, start, int(int(end) - int(start)));

	Initialize();
}

Projectile::~Projectile()
{
}

void Projectile::Initialize()
{
	CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, this);

	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	state = State::IDLE;

	anim->SetSprite(startArray[(int)state], endArray[(int)state]);
	anim->SetDelay(0.1f);
	anim->SetLoop(false);
}

void Projectile::Update()
{
	GameObject::Update();

	if (State::ATTACK == state)
	{
		if (anim->GetCurrentSprite() == endArray[(int)state])
		{
			isDead = true;
		}
	}

	Move(direction);

	Billboard();

	CalcLifeTime();
}

void Projectile::Release()
{
}

void Projectile::OnCollision(GameObject * target)
{
	if (target->isAlliance == this->isAlliance) return;

	if (dynamic_cast<Bullet*>(target)) return;

	Vector3 pos = target->transform->position;

	Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_EXPLOSION_01, TextureKey::FIRE_EXPLOSION_08, 0.03f);
	ObjectManager::AddObject(fx);

	lifeTime = -1.f;
	ChangeState(State::ATTACK);
	
	static int i = 0;

	cout << ++i << endl;
}

void Projectile::CalcLifeTime()
{
	lifeTime -= TimeManager::DeltaTime();

	if (lifeTime <= 0.f)
	{
		ChangeState(State::ATTACK);
	}
}

void Projectile::ChangeState(State nextState)
{
	if (state != nextState)
	{
		state = nextState;
		anim->SetSprite(startArray[(int)state], endArray[(int)state]);
	}
}

void Projectile::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame)
{
	startArray[(int)_state] = (TextureKey)((int)_beginTextureKey);
	endArray[(int)_state] = (TextureKey)((int)_beginTextureKey + (_aniFrame - 1));
}

Projectile * Projectile::Create(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float lifeTime, float att)
{
	Projectile* instance = new Projectile(pos, size, start, end, dir, speed, lifeTime, att);
	return instance;
}