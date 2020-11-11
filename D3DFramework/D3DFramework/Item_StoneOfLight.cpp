#include "stdafx.h"
#include "Item_StoneOfLight.h"

Item_StoneOfLight::Item_StoneOfLight()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_LIGHT, TextureKey::UI_ICON_ITEM_STONE_OF_LIGHT);
	type = ItemType::STONE_OF_LIGHT;

	name = L"빛의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n빛처럼 눈부시다.";
}

Item_StoneOfLight::~Item_StoneOfLight()
{
}

void Item_StoneOfLight::Use()
{



}
