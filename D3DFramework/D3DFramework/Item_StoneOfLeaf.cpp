#include "stdafx.h"
#include "Item_StoneOfLeaf.h"

Item_StoneOfLeaf::Item_StoneOfLeaf()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_LEAF, TextureKey::UI_ICON_ITEM_STONE_OF_LEAF);
	type = ItemType::STONE_OF_LEAF;
}

Item_StoneOfLeaf::~Item_StoneOfLeaf()
{
}

void Item_StoneOfLeaf::Use()
{



}
