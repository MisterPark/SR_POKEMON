#include "stdafx.h"
#include "Item_StoneOfFire.h"

Item_StoneOfFire::Item_StoneOfFire()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_FIRE, TextureKey::UI_ICON_ITEM_STONE_OF_FIRE);
	type = ItemType::STONE_OF_FIRE;

	name = L"불꽃의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n주황색을 띠고 있다.";
}

Item_StoneOfFire::~Item_StoneOfFire()
{
}

void Item_StoneOfFire::Use()
{



}
