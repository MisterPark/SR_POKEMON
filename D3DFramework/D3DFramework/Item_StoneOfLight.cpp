#include "stdafx.h"
#include "Item_StoneOfLight.h"

Item_StoneOfLight::Item_StoneOfLight()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_LIGHT, TextureKey::UI_ICON_ITEM_STONE_OF_LIGHT);
	type = ItemType::STONE_OF_LIGHT;

	name = L"���� ��";
	description = L"��� Ư�� ���ϸ���\n��ȭ��Ű�� �̻��� ��.\n\n��ó�� ���νô�.";
}

Item_StoneOfLight::~Item_StoneOfLight()
{
}

void Item_StoneOfLight::Use()
{



}
