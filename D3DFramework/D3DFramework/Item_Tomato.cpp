#include "stdafx.h"
#include "Item_Tomato.h"

Item_Tomato::Item_Tomato()
{
	type = ItemType::TOMATO;
	anim->SetSprite(TextureKey::UI_ICON_ITEM_TOMATO, TextureKey::UI_ICON_ITEM_TOMATO);
	stat.hp = 10.f;

	name = L"토마토";
	description = L"체력을 \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' 회복";
}

Item_Tomato::~Item_Tomato()
{
}

void Item_Tomato::Use()
{
	// TODO : 경훈 / 아이템을 플레이어만 쓸수있는 상황이라서 이렇게 함
	// 나중엔 매개변수로 GameObject* 를 받고 누가 아이템을 사용했는지 알아야할지도

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return; 

	player->HealMyself(stat.hp);
	count--;

	Item::Use();
}
