#include "stdafx.h"
#include "Item_HpPotion.h"

Item_HpPotion::Item_HpPotion()
{
	anim->SetSprite(TextureKey::UI_ICON_ITEM_HP_POTION, TextureKey::UI_ICON_ITEM_HP_POTION);
	stat.hp = 100.f;
	type = ItemType::HP_POTION;
	name = L"체력 물약";
	description = L"체력을 \'";
	WCHAR wstr[8] = {};
	wsprintf(wstr, L"%d", (int)stat.hp);
	description += wstr;
	description += L"\' 회복";
}

Item_HpPotion::~Item_HpPotion()
{
}

void Item_HpPotion::Use()
{

	Character* player = Player::GetInstance()->GetCharacter();
	if (player == nullptr) return;

	player->HealMyself(stat.hp);
	count--;

	SoundManager::PlayOverlapSound(L"Drink.wav", SoundChannel::EFFECT);
	SoundManager::SetVolume(SoundChannel::EFFECT, 0.1f);
}
