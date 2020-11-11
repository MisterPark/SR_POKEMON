#include "stdafx.h"
#include "Item_StoneOfDark.h"

Item_StoneOfDark::Item_StoneOfDark()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_DARK, TextureKey::UI_ICON_ITEM_STONE_OF_DARK);
	type = ItemType::STONE_OF_DARK;

	name = L"어둠의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n칠흑처럼 어둡다.";
}

Item_StoneOfDark::~Item_StoneOfDark()
{
}

void Item_StoneOfDark::Use()
{



}
