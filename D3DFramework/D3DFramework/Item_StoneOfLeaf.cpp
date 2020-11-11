#include "stdafx.h"
#include "Item_StoneOfLeaf.h"

Item_StoneOfLeaf::Item_StoneOfLeaf()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_LEAF, TextureKey::UI_ICON_ITEM_STONE_OF_LEAF);
	type = ItemType::STONE_OF_LEAF;

	name = L"리프의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n잎사귀 무늬가 있다.";
}

Item_StoneOfLeaf::~Item_StoneOfLeaf()
{
}

void Item_StoneOfLeaf::Use()
{



}
