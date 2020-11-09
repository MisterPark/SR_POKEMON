#include "stdafx.h"
#include "Item_UltraBall.h"

Item_UltraBall::Item_UltraBall()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_ULTRA_BALL, TextureKey::UI_ICON_ITEM_ULTRA_BALL);
	type = ItemType::ULTRA_BALL;
}

Item_UltraBall::~Item_UltraBall()
{
}

void Item_UltraBall::Use()
{



}
