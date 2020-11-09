#include "stdafx.h"
#include "Item_StoneOfDark.h"

Item_StoneOfDark::Item_StoneOfDark()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_DARK, TextureKey::UI_ICON_ITEM_STONE_OF_DARK);
	type = ItemType::STONE_OF_DARK;
}

Item_StoneOfDark::~Item_StoneOfDark()
{
}

void Item_StoneOfDark::Use()
{



}
