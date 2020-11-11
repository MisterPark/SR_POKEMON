#include "stdafx.h"
#include "Item_StoneOfSun.h"

Item_StoneOfSun::Item_StoneOfSun()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_SUN, TextureKey::UI_ICON_ITEM_STONE_OF_SUN);
	type = ItemType::STONE_OF_SUN;

	name = L"태양의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n태양처럼 빨갛다.";
}

Item_StoneOfSun::~Item_StoneOfSun()
{
}

void Item_StoneOfSun::Use()
{



}
