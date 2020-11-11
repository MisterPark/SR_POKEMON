#include "stdafx.h"
#include "Item_ExpPotion.h"

Item_ExpPotion::Item_ExpPotion()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_EXP_POTION, TextureKey::UI_ICON_ITEM_EXP_POTION);
	stat.exp = 100.f;
	type = ItemType::EXP_POTION;

	name = L"����ġ ����";
	description = L"����ġ�� \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' ����";
}

Item_ExpPotion::~Item_ExpPotion()
{
}

void Item_ExpPotion::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	
	player->IncreaseEXP(stat.exp);
	count--;
}
