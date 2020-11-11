#include "stdafx.h"
#include "Item_StoneOfThunder.h"

Item_StoneOfThunder::Item_StoneOfThunder()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_THUNDER, TextureKey::UI_ICON_ITEM_STONE_OF_THUNDER);
	type = ItemType::STONE_OF_THUNDER;

	name = L"천둥의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n천둥번개 무늬가 있다.";
}

Item_StoneOfThunder::~Item_StoneOfThunder()
{
}

void Item_StoneOfThunder::Use()
{



}
