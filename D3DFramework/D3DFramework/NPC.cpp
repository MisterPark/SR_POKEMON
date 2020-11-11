#include "stdafx.h"
#include "NPC.h"
#include "Environment.h"
#include "Terrain.h"
#include "Rectangle.h"
#include "Dialog.h"

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
	CollisionManager::RegisterObject(COLTYPE::COL_NPC, this);

	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	anim->SetLoop(false);
}

void NPC::Release()
{
	CollisionManager::DisregisterObject(COLTYPE::COL_NPC, this);
}

void NPC::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
	if(animation) UpdateAnimation();
}

void NPC::OnCollision(GameObject* target)
{
	Character* pc = Player::GetInstance()->GetCharacter();
	if (pc == nullptr) return;
	if (pc != target)return;

	if (Dialog::GetInstance()->isVisible == false)
	{
		if (InputManager::GetKeyDown('F'))
		{
			OnEvent();
		}
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

float NPC::GetAngleFromCamera()
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

void NPC::UpdateAnimation()
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

void NPC::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame)
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

Vector3 NPC::DirFromPlayer(bool _posY /*= false*/)
{
	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return Vector3{ 0.f, 0.f, 0.f };

	Vector3 Dir = player->transform->position - transform->position;
	if (!_posY)
		Dir.y = 0.f;
	Vector3::Normalize(&Dir);
	return Dir;
}