#include "stdafx.h"
#include "Item_StoneOfAwake.h"

Item_StoneOfAwake::Item_StoneOfAwake()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_STONE_OF_AWAKE, TextureKey::UI_ICON_ITEM_STONE_OF_AWAKE);
	type = ItemType::STONE_OF_AWAKE;

	name = L"������ ��";
	description = L"��� Ư�� ���ϸ���\n��ȭ��Ű�� �̻��� ��.\n\n������ó�� �Ƹ����.";
}

Item_StoneOfAwake::~Item_StoneOfAwake()
{
}

void Item_StoneOfAwake::Use()
{



}
