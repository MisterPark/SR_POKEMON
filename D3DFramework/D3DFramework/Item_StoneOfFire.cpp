#include "stdafx.h"
#include "Item_StoneOfFire.h"

Item_StoneOfFire::Item_StoneOfFire()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_FIRE, TextureKey::UI_ICON_ITEM_STONE_OF_FIRE);
	type = ItemType::STONE_OF_FIRE;

	name = L"�Ҳ��� ��";
	description = L"��� Ư�� ���ϸ���\n��ȭ��Ű�� �̻��� ��.\n\n��Ȳ���� ��� �ִ�.";
}

Item_StoneOfFire::~Item_StoneOfFire()
{
}

void Item_StoneOfFire::Use()
{



}
