#include "stdafx.h"
#include "Item_StoneOfSun.h"

Item_StoneOfSun::Item_StoneOfSun()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_SUN, TextureKey::UI_ICON_ITEM_STONE_OF_SUN);
	type = ItemType::STONE_OF_SUN;
}

Item_StoneOfSun::~Item_StoneOfSun()
{
}

void Item_StoneOfSun::Use()
{



}
