#include "stdafx.h"
#include "Item_StoneOfThunder.h"

Item_StoneOfThunder::Item_StoneOfThunder()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_THUNDER, TextureKey::UI_ICON_ITEM_STONE_OF_THUNDER);
	type = ItemType::STONE_OF_THUNDER;
}

Item_StoneOfThunder::~Item_StoneOfThunder()
{
}

void Item_StoneOfThunder::Use()
{



}
