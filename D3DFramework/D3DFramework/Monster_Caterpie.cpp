#include "stdafx.h"
#include "Monster_Caterpie.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Caterpie::Monster_Caterpie()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	//ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	ani->SetSprite(TextureKey::CATER_WALK_D_01, TextureKey::CATER_WALK_D_03);
	ani->SetLoop(true);
	ani->SetDelay(0.2f);
	//transform->RotateY(90);
	offsetY = 1.f;
	CurrentStatus = Status::END;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Monster_Caterpie::~Monster_Caterpie()
{
}

void Monster_Caterpie::Update()
{
	//���Ͱ� �ٶ󺸴� ����.
	Vector3 dir = { 0.f,0.f,1.f };
	dir.Normalized();
	MoveDir = dir;
	/*Move(dir);*/
	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	//�÷��̾��� ��ġ
	Transform* PlayerT = g->transform;

	//�÷��̾�� ���ͱ����� �Ÿ�
	Vector3 Dist =  PlayerT->position - transform->position;
	Dist.Normalized();

	//ī�޶��� �躤��
	Vector3 vCameraLook = Camera::GetInstance()->transform->look;

	float Angle = Vector3::Angle(Dist, vCameraLook);

	
	
	if (Angle <22.5 && Angle>-22.5)
	{
		ani->SetSprite(TextureKey::CATER_WALK_D_01, TextureKey::CATER_WALK_D_03);
	}
	else
	{
		ani->SetSprite(TextureKey::CATER_WALK_U_01, TextureKey::CATER_WALK_U_03);
	}
	Monster::Update();

}

void Monster_Caterpie::Render()
{
	Monster::Render();
}



