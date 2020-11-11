#include "stdafx.h"
#include "Item_Tomato.h"

Item_Tomato::Item_Tomato()
{
	type = ItemType::TOMATO;
	anim->SetSprite(TextureKey::UI_ICON_ITEM_TOMATO, TextureKey::UI_ICON_ITEM_TOMATO);
	stat.hp = 10.f;

	name = L"�丶��";
	description = L"ü���� \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' ȸ��";
}

Item_Tomato::~Item_Tomato()
{
}

void Item_Tomato::Use()
{
	// TODO : ���� / �������� �÷��̾ �����ִ� ��Ȳ�̶� �̷��� ��
	// ���߿� �Ű������� GameObject* �� �ް� ���� �������� ����ߴ��� �˾ƾ�������

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return; 

	player->HealMyself(stat.hp);
	count--;

	Item::Use();
}
