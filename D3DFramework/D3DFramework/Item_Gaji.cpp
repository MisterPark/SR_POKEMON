#include "stdafx.h"
#include "Item_Gaji.h"

Item_Gaji::Item_Gaji()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_GAJI, TextureKey::UI_ICON_ITEM_GAJI);
	stat.hp = 10.f;
	type = ItemType::GAJI;

	name = L"����";
	description = L"ü���� \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' ȸ��";
}

Item_Gaji::~Item_Gaji()
{
}

void Item_Gaji::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;
}
