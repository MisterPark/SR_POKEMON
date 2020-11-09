#include "stdafx.h"
#include "Item_Lemon.h"

Item_Lemon::Item_Lemon()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_LEMON, TextureKey::UI_ICON_ITEM_LEMON);
	stat.hp = 10.f;
	type = ItemType::LEMON;
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
}
