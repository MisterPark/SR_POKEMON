#include "stdafx.h"
#include "Item_Clam.h"

Item_Clam::Item_Clam()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_CLAM, TextureKey::UI_ICON_ITEM_CLAM);
	stat.hp = 10.f;
	type = ItemType::CLAM;

	name = L"보라색 조개";
	description = L"체력을 \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' 회복";
}

Item_Clam::~Item_Clam()
{
}

void Item_Clam::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;

	Item::Use();
}
