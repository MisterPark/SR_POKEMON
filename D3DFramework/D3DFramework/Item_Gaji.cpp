#include "stdafx.h"
#include "Item_Gaji.h"

Item_Gaji::Item_Gaji()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_GRAPE, TextureKey::UI_ICON_ITEM_GRAPE);
	stat.hp = 10.f;
	type = ItemType::GAJI;
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
