#include "stdafx.h"
#include "Item_PokeBall.h"

Item_PokeBall::Item_PokeBall()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_POKE_BALL, TextureKey::UI_ICON_ITEM_POKE_BALL);
	type = ItemType::POKE_BALL;
}

Item_PokeBall::~Item_PokeBall()
{
}

void Item_PokeBall::Use()
{



}
