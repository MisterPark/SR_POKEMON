#include "stdafx.h"
#include "Item_Clam.h"

Item_Clam::Item_Clam()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_CLAM, TextureKey::UI_ICON_ITEM_CLAM);
	stat.hp = 10.f;
	type = ItemType::CLAM;
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
}
