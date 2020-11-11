#include "stdafx.h"
#include "Item_Lemon.h"

Item_Lemon::Item_Lemon()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_LEMON, TextureKey::UI_ICON_ITEM_LEMON);
	stat.hp = 50.f;
	type = ItemType::LEMON;

	name = L"레몬";
	description = L"체력을 \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' 회복";
}

Item_Lemon::~Item_Lemon()
{
}

void Item_Lemon::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;

	Item::Use();
}
