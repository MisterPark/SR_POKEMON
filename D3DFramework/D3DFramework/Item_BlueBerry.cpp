#include "stdafx.h"
#include "Item_BlueBerry.h"

Item_BlueBerry::Item_BlueBerry()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_BLUEBERRY, TextureKey::UI_ICON_ITEM_BLUEBERRY);
	stat.hp = 10.f;
	type = ItemType::GRAPE;
}

Item_BlueBerry::~Item_BlueBerry()
{
}

void Item_BlueBerry::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;
}
