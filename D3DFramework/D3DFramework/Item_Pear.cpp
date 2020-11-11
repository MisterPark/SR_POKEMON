#include "stdafx.h"
#include "Item_Pear.h"

Item_Pear::Item_Pear()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_PEAR, TextureKey::UI_ICON_ITEM_PEAR);
	stat.hp = 30.f;
	type = ItemType::PEAR;

	name = L"��";
	description = L"ü���� \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' ȸ��";
}

Item_Pear::~Item_Pear()
{
}

void Item_Pear::Use()
{
	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;

	Item::Use();
}
