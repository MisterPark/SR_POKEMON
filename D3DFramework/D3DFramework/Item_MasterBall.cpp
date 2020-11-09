#include "stdafx.h"
#include "Item_MasterBall.h"

Item_MasterBall::Item_MasterBall()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_MASTER_BALL, TextureKey::UI_ICON_ITEM_MASTER_BALL);
	type = ItemType::MASTER_BALL;
}

Item_MasterBall::~Item_MasterBall()
{
}

void Item_MasterBall::Use()
{



}
