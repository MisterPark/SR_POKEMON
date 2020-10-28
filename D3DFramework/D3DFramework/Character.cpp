#include "stdafx.h"
#include "Character.h"
#include "Terrain.h"
#include "Environment.h"

Character::Character()
{
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
	UpdateAnimation();
}

void Character::Render()
{
	GameObject::Render();
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
	// 카메라가 몬스터를 향하는 각
	Vector3 camPos = Camera::GetPosition();
	float degree1 = Vector3::AngleY(camPos, transform->position);

	// 몬스터 월드 각
	float degree2 = D3DXToDegree(atan2f(direction.x, direction.z));

	return (degree2 - degree1);
}

void Character::SetTextureAngle()
{
	


}

void Character::UpdateAnimation()
{
	float angle = GetAngleFromCamera();

	angle += 202.5f;
	
	if ((int)angle % 45 > 22.5f) {
		angle /= 45.f;
		angle -= 1;
	}
	else {
		angle /= 45.f;
	}
	int index = angle;

	// 상태
	anim->SetSprite(startArray[(int)state][index], endArray[(int)state][index]);
	//int count = endArray[(int)state] - startArray[(int)state] + 1;

	//TextureKey key = (TextureKey)(startArray[(int)state] + index * count);
	//anim->SetSprite(key, (TextureKey)((count - 1) + (int)key));

}
