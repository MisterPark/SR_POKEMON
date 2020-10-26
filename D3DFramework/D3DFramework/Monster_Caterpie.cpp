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
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Monster_Caterpie::~Monster_Caterpie()
{
}

void Monster_Caterpie::Update()
{
	//룩벡터(z)
	MoveDir = transform->look;

	Vector3::Normalize(&MoveDir);

	

	transform->position.x += 0.1;

	/*MoveDir = D3DXToRadian(60);*/
	Monster::Update();

}

void Monster_Caterpie::Render()
{
	Monster::Render();
}



