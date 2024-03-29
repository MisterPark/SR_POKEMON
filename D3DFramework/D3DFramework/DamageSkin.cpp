#include "stdafx.h"
#include "DamageSkin.h"

DamageSkin::DamageSkin()
{
}

DamageSkin::~DamageSkin()
{
}

void DamageSkin::Initialize()
{
}

void DamageSkin::Release()
{
}

void DamageSkin::UpdateUI()
{
}

void DamageSkin::Update()
{
	
	GameObject::Update();


	float deltaTime = TimeManager::DeltaTime();
	lifeTick += deltaTime;
	if (lifeTick > lifeTime)
	{
		Die();
	}

	transform->position.y += deltaTime;

}

void DamageSkin::Render()
{
	Matrix view = Camera::GetViewMatrix();
	Vector3 viewPos;
	D3DXVec3TransformCoord(&viewPos, &transform->position, &view);
	if (viewPos.z < 0.f)
	{
		return;
	}

	Vector3 pos = Camera::WorldToScreenPoint(transform->position);
	if (pos.z < 0.f) return;
	WCHAR wstr[20] = {};
	wsprintf(wstr, L"%d", damage);
	RenderManager::DrawFont(wstr, pos.x, pos.y, color);

}

void DamageSkin::SetDamage(int _damage)
{
	damage = _damage;
}

void DamageSkin::SetColor(D3DCOLOR _color)
{
	color = _color;
}
