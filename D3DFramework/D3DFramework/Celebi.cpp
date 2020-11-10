#include "stdafx.h"
#include "Celebi.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"

Celebi::Celebi()
{
	Initialize();
}

Celebi::Celebi(const Vector3& pos)
{
	transform->position = pos;
	Initialize();
}

Celebi::~Celebi()
{
	CollisionManager::GetInstance()->DisregisterObject(this);
}

void Celebi::Initialize()
{
	//SetTexture(State::IDLE, TextureKey::COINPOKE_1, 27);
	team = Team::MONSTERTEAM;
	CollisionManager::RegisterObject(COLTYPE::COIN, this);
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	SetTexture(State::WALK, TextureKey::CELE_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::CELE_WALK_D_01, 3, 1);
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::WALK;

	offsetY = 0.7f;
	transform->scale = { 0.5f, 0.5f, 0.5f };
	stat.attack = 0.f;

	//stat.money;

	UpdateAnimation();
}

void Celebi::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
	UpdateAnimation();
}

void Celebi::Release()
{
}

Celebi* Celebi::Create(const Vector3& pos)
{
	Celebi* newNpc = new Celebi(pos);
	return newNpc;
}

void Celebi::OnCollision(GameObject* target)
{
	int myProgress = QuestManager::GetInstance()->GetProgress(NpcName::CELEBI);

	switch (myProgress)
	{
	case 1: {

	}
		break;
	case 2: {

	}
		break;
	case 3: {

	}
		break;
	default:
		break;
	}
}

void Celebi::OnTerrain()
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

float Celebi::GetAngleFromCamera()
{
	Vector3 camPos = Camera::GetPosition();

	Vector3 toRealCam = camPos - transform->position;
	Vector3 toCam = toRealCam;
	toCam.y = 0;
	Vector3 myDir = direction;

	D3DXVec3Normalize(&toCam, &toCam);
	D3DXVec3Normalize(&toRealCam, &toRealCam);
	D3DXVec3Normalize(&myDir, &myDir);

	float radian = acos(D3DXVec3Dot(&toCam, &myDir));
	float degree = D3DXToDegree(radian);

	Vector3 cross;
	D3DXVec3Cross(&cross, &toRealCam, &myDir);

	Vector3 empty = { 0, 0, 0 };

	if (cross == empty)
		int i = 0;

	Vector3 up = transform->up;

	float upDot = D3DXVec3Dot(&cross, &up);

	if (0 > upDot)
	{
		degree = 360 - degree;
	}

	return degree;
}

void Celebi::UpdateAnimation()
{
	float angle = GetAngleFromCamera();

	angle += 22.5f;

	int index = angle / 45.f;

	index %= 8;

	if (oldState != state)
	{
		anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
	}
	else
	{
		int curIndex = ((int)anim->GetEndSprite() - (int)anim->GetCurrentSprite());

		anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
		curIndex = (int)endArray[(int)state][index] - curIndex;
		anim->SetCurrentSprite((TextureKey)curIndex);
	}
}

void Celebi::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame) {
	for (int i = 0; i < 8; i++)
	{
		startArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame));
		if (-1 == _endFrame)
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_aniFrame - 1));
		else
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_endFrame - 1));
	}
}