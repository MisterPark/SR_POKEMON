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

	//anim->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	anim->SetSprite(TextureKey::CATER_WALK_D_01, TextureKey::CATER_WALK_D_03);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);
	//transform->RotateY(90);
	offsetY = 1.f;
	state = State::END;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Monster_Caterpie::~Monster_Caterpie()
{
}

void Monster_Caterpie::Update()
{
	//�躤��(z)
	direction = transform->look;

	Vector3::Normalize(&direction);

	

	transform->position.x += 0.1;

	/*MoveDir = D3DXToRadian(60);*/
	Monster::Update();

}

void Monster_Caterpie::Render()
{
	Monster::Render();
}



