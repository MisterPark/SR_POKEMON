#include "stdafx.h"
#include "Item_StoneOfMoon.h"

Item_StoneOfMoon::Item_StoneOfMoon()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_MOON, TextureKey::UI_ICON_ITEM_STONE_OF_MOON);
	type = ItemType::STONE_OF_MOON;

	name = L"���� ��";
	description = L"��� Ư�� ���ϸ���\n��ȭ��Ű�� �̻��� ��.\n\n���ϴ�ó�� ��Ĵ�.";
}

Item_StoneOfMoon::~Item_StoneOfMoon()
{
}

void Item_StoneOfMoon::Use()
{



}
