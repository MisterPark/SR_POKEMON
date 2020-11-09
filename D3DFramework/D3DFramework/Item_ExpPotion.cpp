#include "stdafx.h"
#include "Item_ExpPotion.h"

Item_ExpPotion::Item_ExpPotion()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_EXP_POTION, TextureKey::UI_ICON_ITEM_EXP_POTION);
	stat.exp = 10.f;
	type = ItemType::EXP_POTION;
}

Item_ExpPotion::~Item_ExpPotion()
{
}

void Item_ExpPotion::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.exp);
	count--;
}
