#include "stdafx.h"
#include "Item_StoneOfWater.h"

Item_StoneOfWater::Item_StoneOfWater()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_WATER, TextureKey::UI_ICON_ITEM_STONE_OF_WATER);
	type = ItemType::STONE_OF_WATER;

	name = L"물의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n투명한 푸른색을 띄고 있다.";
}

Item_StoneOfWater::~Item_StoneOfWater()
{
}

void Item_StoneOfWater::Use()
{



}
