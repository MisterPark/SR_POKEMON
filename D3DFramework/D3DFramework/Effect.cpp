#include "stdafx.h"
#include "Effect.h"
#include "Rectangle.h"

Effect::Effect()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	CollisionManager::RegisterObject(this);
}

Effect::Effect(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir) :
	direction(dir)
{
	transform->position = pos;
	transform->scale = scale;

	

	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	CollisionManager::RegisterObject(this);
}

Effect::~Effect()
{
	CollisionManager::DisregisterObject(this);
}

void Effect::Update()
{
	GameObject::Update();
	if (isBillboard) Billboard();
	if (isMove) MoveForward();
	UpdateAnimation();
	
}

void Effect::Render()
{
	GameObject::Render();
}

void Effect::Initialize()
{
}

void Effect::Release()
{
}

float Effect::GetAngleFromCamera()
{
	// 카메라가 몬스터를 향하는 각
	Vector3 camPos = Camera::GetPosition();
	float degree1 = Vector3::AngleY(camPos, transform->position);

	// 몬스터 월드 각
	float degree2 = D3DXToDegree(atan2f(direction.x, direction.z));

	return (degree2 - degree1);
}

void Effect::UpdateAnimation()
{
	anim->SetSprite(startArray[(int)state][0], endArray[(int)state][0]);
}

void Effect::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame)
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

void Effect::SetAniTexture(State _state, TextureKey _beginTextureKey, int _aniFrame)
{
	startArray[(int)_state][(int)Direction::D] = (TextureKey)((int)_beginTextureKey);
	endArray[(int)_state][(int)Direction::D] = (TextureKey)((int)_beginTextureKey + _aniFrame - 1);
}

void Effect::SetDir(const Vector3 & dir)
{
	D3DXVec3Normalize(&direction, &dir);
}

void Effect::MoveForward()
{
	Move(direction);
}

void Effect::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;
	}
}

Effect * Effect::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Effect* newEffect = new Effect(pos, scale, dir);

	return newEffect;
}
