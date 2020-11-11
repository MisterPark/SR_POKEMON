#include "stdafx.h"
#include "Item_StoneOfMoon.h"

Item_StoneOfMoon::Item_StoneOfMoon()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_MOON, TextureKey::UI_ICON_ITEM_STONE_OF_MOON);
	type = ItemType::STONE_OF_MOON;

	name = L"달의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n밤하늘처럼 까맣다.";
}

Item_StoneOfMoon::~Item_StoneOfMoon()
{
}

void Item_StoneOfMoon::Use()
{



}
