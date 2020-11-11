#include "stdafx.h"
#include "Item_Grape.h"

Item_Grape::Item_Grape()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_GRAPE, TextureKey::UI_ICON_ITEM_GRAPE);
	stat.hp = 10.f;
	type = ItemType::GRAPE;
	name = L"포도";
	description = L"체력을 \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' 회복";
}

Item_Grape::~Item_Grape()
{
}

void Item_Grape::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;
}
