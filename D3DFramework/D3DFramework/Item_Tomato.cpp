#include "stdafx.h"
#include "Item_Tomato.h"

Item_Tomato::Item_Tomato()
{
	name = L"�丶��";
	type = ItemType::TOMATO;
	anim->SetSprite(TextureKey::UI_ICON_ITEM_TOMATO, TextureKey::UI_ICON_ITEM_TOMATO);
	stat.hp = 10.f;

}

Item_Tomato::~Item_Tomato()
{
	int a = 10;
}

void Item_Tomato::Use()
{
	// TODO : ���� / �������� �÷��̾ �����ִ� ��Ȳ�̶� �̷��� ��
	// ���߿� �Ű������� GameObject* �� �ް� ���� �������� ����ߴ��� �˾ƾ�������

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return; 

	player->HealMyself(stat.hp);
	count--;
}
