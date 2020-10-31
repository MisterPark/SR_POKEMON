#include "stdafx.h"
#include "Character.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Bulbasaur.h"

Character::Character()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	CollisionManager::RegisterObject(this);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	
}

Character::~Character()
{
	CollisionManager::DisregisterObject(this);
}

void Character::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
	UpdateAnimation();
}

void Character::Render()
{
	GameObject::Render();
	RenderName();
}

void Character::RenderName()
{
	Matrix view = Camera::GetViewMatrix();
	Vector3 viewPos;
	D3DXVec3TransformCoord(&viewPos, &transform->position, &view);
	if (viewPos.z < 0.f)
	{
		return;
	}
	float camDist = Vector3::Distance(Camera::GetInstance()->GetPosition(), this->transform->position);
	Vector3 pos = Camera::WorldToScreenPoint(transform->position);
	pos.y -= transform->scale.y + 40 - camDist;
	pos.x -= 30;
	D2DRenderManager::DrawFont(name, pos.x, pos.y, D3DCOLOR_XRGB(255, 255, 255));
}

void Character::Initialize()
{
}

void Character::Release()
{
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

	// ป๓ลย
	anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
}

void Character::SetDir(const Vector3 & dir)
{
	D3DXVec3Normalize(&direction, &dir);
}

void Character::MoveForward()
{
	Move(direction);
}

void Character::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;
	}
}

void Character::Attack(const Vector3 & dir)
{
}

void Character::Skill(const Vector3 & dir)
{
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