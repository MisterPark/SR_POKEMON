#include "stdafx.h"
#include "Butterfree.h"

Butterfree::Butterfree()
{
	//SetTexture( ����, ó���ؽ���, �ϳ��� ���� �����Ӽ�);
	SetTexture(State::WALK, TextureKey::BUTTER_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::BUTTER_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::BUTTER_WALK_D_01, 3);
	for (int i = 0; i < 8; i++)
	{
		endArray[(int)State::IDLE][(int)Direction::D + i] = (TextureKey)((int)endArray[(int)State::IDLE][(int)Direction::D + i] - 2);
	}
	
	anim->SetLoop(true);
	offsetY = 2.5f;
	state = State::WALK;
}

Butterfree::~Butterfree()
{
}
