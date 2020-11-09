#include "stdafx.h"
#include "Item_Pear.h"

Item_Pear::Item_Pear()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_PEAR, TextureKey::UI_ICON_ITEM_PEAR);
	stat.hp = 10.f;
	type = ItemType::PEAR;
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
}
