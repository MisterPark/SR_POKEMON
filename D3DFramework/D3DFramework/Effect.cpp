#include "stdafx.h"
#include "Effect.h"
#include "Rectangle.h"
#include "Plane.h"

Effect::Effect()
{
}

Effect::Effect(const Vector3 & pos, const Vector3& size, TextureKey start, TextureKey end, float delay, bool plane, bool isBillY, float radianY, bool loop, float lifeTime, bool isMove, float speed, const Vector3 & dir) :
	startKey(start), endKey(end), animSpeed(delay),
	isPlane(plane), isBillboardY(isBillY), isLoop(loop),
	lifeTime(lifeTime), isMove(isMove), direction(dir)
{
	transform->position = pos;
	transform->scale = size;
	transform->eulerAngles.y = radianY;
	moveSpeed = speed;

	Mesh* mesh;

	if (isPlane) mesh = (Mesh*)AddComponent<PKH::Plane>(L"Mesh");
	else mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");

	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	Initialize();
}

Effect::~Effect()
{
}

void Effect::Initialize()
{
	anim->SetSprite(startKey, endKey);
	anim->SetDelay(animSpeed);
	anim->SetLoop(isLoop);
}

void Effect::Update()
{
	GameObject::Update();

	if (isBillboardY) BillboardYaw();

	if (isMove) Move(direction);

	if (IsDie()) isDead = true;
}

void Effect::Render()
{
	GameObject::Render();
}

void Effect::Release()
{
}

bool Effect::IsDie()
{
	if (!isLoop)
	{
		return anim->IsEndFrame();
	}
	else
	{
		lifeTime -= TimeManager::DeltaTime();

		if (lifeTime <= 0.f) return true;
	}
}

Effect * Effect::Create(const Vector3 & pos, const Vector3& size, TextureKey start, TextureKey end, float delay, bool plane, bool isBillY, float radianY, bool loop, float lifeTime, bool isMove, float speed, const Vector3 & dir)
{
	Effect* instance = new Effect(pos, size, start, end, delay, plane, isBillY, radianY, loop, lifeTime, isMove, speed, dir);

	return instance;
}