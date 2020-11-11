#include "stdafx.h"
#include "Item_StoneOfAwake.h"

Item_StoneOfAwake::Item_StoneOfAwake()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_AWAKE, TextureKey::UI_ICON_ITEM_STONE_OF_AWAKE);
	type = ItemType::STONE_OF_AWAKE;

	name = L"각성의 돌";
	description = L"어느 특정 포켓몬을\n진화시키는 이상한 돌.\n\n눈동자처럼 아름답다.";
}

Item_StoneOfAwake::~Item_StoneOfAwake()
{
}

void Item_StoneOfAwake::Use()
{



}
