#include "stdafx.h"
#include "Item_GreatBall.h"

Item_GreatBall::Item_GreatBall()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_GREAT_BALL, TextureKey::UI_ICON_ITEM_GREAT_BALL);
	type = ItemType::GREAT_BALL;
}

Item_GreatBall::~Item_GreatBall()
{
}

void Item_GreatBall::Use()
{



}
