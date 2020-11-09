#include "stdafx.h"
#include "Item_HpPotion.h"

Item_HpPotion::Item_HpPotion()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_HP_POTION, TextureKey::UI_ICON_ITEM_HP_POTION);
	stat.hp = 10.f;
	type = ItemType::HP_POTION;
}

Item_HpPotion::~Item_HpPotion()
{
}

void Item_HpPotion::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;
}
