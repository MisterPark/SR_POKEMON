#include "stdafx.h"
#include "Item_StoneOfWater.h"

Item_StoneOfWater::Item_StoneOfWater()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_WATER, TextureKey::UI_ICON_ITEM_STONE_OF_WATER);
	type = ItemType::STONE_OF_WATER;

	name = L"���� ��";
	description = L"��� Ư�� ���ϸ���\n��ȭ��Ű�� �̻��� ��.\n\n������ Ǫ������ ��� �ִ�.";
}

Item_StoneOfWater::~Item_StoneOfWater()
{
}

void Item_StoneOfWater::Use()
{



}
