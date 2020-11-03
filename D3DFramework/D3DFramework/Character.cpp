#include "stdafx.h"
#include "Character.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Bulbasaur.h"

Character::Character() :
	canMove(true)
{
	team = Team::MONSTERTEAM;
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
}

Character::~Character()
{
	Release();
	CollisionManager::GetInstance()->DisregisterObject(this);
}

void Character::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
	UpdateAnimation();
	CalcMoveTime();
}

void Character::Render()
{
	GameObject::Render();
	RenderInfomation();
}

void Character::RenderInfomation()
{
	if (transform->zOrder < 0.f)
	{
		return;
	}
	// 카메라와 거리
	float camDist = Vector3::Distance(Camera::GetInstance()->GetPosition(), this->transform->position);
	if (camDist < 15.f)
	{
		// 이름길이
		float len = name.length();
		float strW = 20;
		Vector3 pos = Camera::WorldToScreenPoint(transform->position);
		pos.y -= transform->scale.y + 40 - camDist;
		pos.x -= (len / 2.f) * strW;
		D2DRenderManager::DrawFont(name, pos.x, pos.y, D3DCOLOR_XRGB(255, 255, 255));

		D2DRenderManager::DrawSprite(TextureKey::UI_HP_BAR_04, pos, 0);
	}


	
}

void Character::Initialize()
{
}

void Character::Release()
{
	for (auto skill : skillSet)
	{
		if (nullptr != skill)
		{
			delete skill;
			skill = nullptr;
		}
	}

	skillSet.clear();
	skillSet.shrink_to_fit();
}

void Character::CalcMoveTime()
{
	if (!canMove)
	{
		moveStopTime -= TimeManager::DeltaTime();

		if (0.f > moveStopTime)
		{
			canMove = true;
			moveStopTime = 0.f;
		}
	}
}

void Character::OnTerrain()
{
	GameObject* obj = ObjectManager::GetInstance()->FindObject<Environment>();
	if (obj == nullptr)
	{
		transform->position.y = offsetY;
		return;
	}
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");
	if(mesh == nullptr)
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

float Character::GetAngleFromCamera()
{
	Vector3 camPos = Camera::GetPosition();

	Vector3 toCam = camPos - transform->position;
	toCam.y = 0.f;
	Vector3 myDir = direction;

	Matrix rotX;
	float radianX = transform->eulerAngles.x;
	float radianY = transform->eulerAngles.y;
	D3DXMatrixRotationX(&rotX, -radianX);
	D3DXVec3TransformNormal(&myDir, &myDir, &rotX);

	D3DXVec3Normalize(&toCam, &toCam);
	D3DXVec3Normalize(&myDir, &myDir);

	float radian = acos(D3DXVec3Dot(&toCam, &myDir));
	float degree = D3DXToDegree(radian);

	Vector3 cross;
	D3DXVec3Cross(&cross, &toCam, &myDir);

	Vector3 up = transform->up;

	float upDot = D3DXVec3Dot(&cross, &up);

	if (0.f > upDot) 
		degree = 360 - degree;

	return degree;
}

void Character::UpdateAnimation()
{
	float angle = GetAngleFromCamera();

	angle += 22.5f;

	int index = angle / 45.f;

	index %= 8;

	// 상태
	anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
}

void Character::SetDir(const Vector3 & dir)
{
	D3DXVec3Normalize(&direction, &dir);
}

Skill* Character::GetSkillCollTime(int skillNumber)
{
	
	for (auto& skill : skillSet) {
		skillNumber--;
		if (skillNumber == 0)
			return skill;
		else
			continue;
	}
	return nullptr;
}

void Character::MoveForward()
{
	if(canMove) Move(direction);
}

void Character::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;
	}
}

void Character::Attack(const Vector3 & dir, const int & attackType)
{
}

bool Character::IsNotAlliance(GameObject * a, GameObject * b)
{
	Character* cb = dynamic_cast<Character*>(b);
	if (cb == nullptr) return false;
	return (a->team != b->team);
}

void Character::SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame) {
	for (int i = 0; i < 8; i++)
	{
		startArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame));
		if (-1 == _endFrame)
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_aniFrame - 1));
		else
			endArray[(int)_state][(int)Direction::D + i] = (TextureKey)((int)_beginTextureKey + (i * _aniFrame) + (_endFrame - 1));
	}
}