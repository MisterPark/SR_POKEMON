#include "stdafx.h"
#include "TestObj.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

TestObj::TestObj()
{
	Initialize();
}

TestObj::~TestObj()
{
	Release();
	//Character::~Character();
}

void TestObj::Initialize()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	
	moveSpeed = 5.f;

	transform->scale = Vector3(0.2f, 0.2f, 0.2f);

	curState = ATTACK;
	curDir = U;
	offsetY = 0.2f;

	SetAnim();
}

void TestObj::Update()
{
	CalcDir();
	Character::Update();
}

void TestObj::Render()
{
	Character::Render();
}

void TestObj::Release()
{
	//Character::Release();
}

void TestObj::SetPos(const Vector3 & pos)
{
	transform->position = pos;
}

void TestObj::SetDir(const Vector3 & dir)
{
	myDir = dir;
}

void TestObj::ChangeAnim(STATE state, DIR dir)
{
	if (state != curState || dir != curDir)
	{
		curState = state;
		curDir = dir;
		SetAnim();
	}
}

void TestObj::CalcDir()
{
	Vector3 cameraPos = Camera::GetPosition();
	Vector3 dir = cameraPos - transform->position;

	Vector3::Normalize(&dir);
	Vector3::Normalize(&myDir);

	Vector3 cross;
	D3DXVec3Cross(&cross, &dir, &myDir);

	float upDot = Vector3::Dot(Vector3(0.f, 1.f, 0.f), cross);

	float dot = Vector3::Dot(dir, myDir);

	float degree = D3DXToDegree(acos(dot));

	degree = (upDot < 0.f) ? 360.f - degree : degree;

	cout << degree << endl;

	float gap = 22.5f;

	int tmpDir = curDir;

	if (315.f + gap <= degree || degree < 45.f - gap)
	{
		//ChangeAnim(IDLE, D);
	}
	else if (45.f - gap <= degree && degree < 45.f + gap)
	{
		++tmpDir;
		//ChangeAnim(IDLE, LD);
	}
	else if (90.f - gap <= degree && degree < 90.f + gap)
	{
		tmpDir += 2;
		//ChangeAnim(IDLE, L);
	}
	else if (135.f - gap <= degree && degree < 135.f + gap)
	{
		tmpDir += 3;
		//ChangeAnim(IDLE, RU);
	}
	else if (180.f - gap <= degree && degree < 180.f + gap)
	{
		tmpDir += 4;
		//ChangeAnim(IDLE, U);
	}
	else if (225.f - gap <= degree && degree < 225.f + gap)
	{
		tmpDir += 5;
		//ChangeAnim(IDLE, LU);
	}
	else if (270.f - gap <= degree && degree < 270.f + gap)
	{
		tmpDir += 6;
		//ChangeAnim(IDLE, R);
	}
	else if (315.f - gap <= degree && degree < 315.f + gap)
	{
		tmpDir += 7;
		//ChangeAnim(IDLE, RD);
	}

	tmpDir %= 8;

	switch (tmpDir)
	{
	case 0: ChangeAnim(IDLE, D); break;
	case 1: ChangeAnim(IDLE, LD); break;
	case 2: ChangeAnim(IDLE, L); break;
	case 3: ChangeAnim(IDLE, LU); break;
	case 4: ChangeAnim(IDLE, U); break;
	case 5: ChangeAnim(IDLE, RU); break;
	case 6: ChangeAnim(IDLE, R); break;
	case 7: ChangeAnim(IDLE, RD); break;
	}
}

void TestObj::SetAnim()
{
	switch (curState)
	{
	case IDLE:
		switch (curDir)
		{
		case D:		anim->SetSprite(TextureKey::PG01_WALK_D_01,		TextureKey::PG01_WALK_D_01); break;
		case LD:	anim->SetSprite(TextureKey::PG01_WALK_LD_01,	TextureKey::PG01_WALK_LD_01); break;
		case L:		anim->SetSprite(TextureKey::PG01_WALK_L_01,		TextureKey::PG01_WALK_L_01); break;
		case LU:	anim->SetSprite(TextureKey::PG01_WALK_LU_01,	TextureKey::PG01_WALK_LU_01); break;
		case U:		anim->SetSprite(TextureKey::PG01_WALK_U_01,		TextureKey::PG01_WALK_U_01); break;
		case RU:	anim->SetSprite(TextureKey::PG01_WALK_RU_01,	TextureKey::PG01_WALK_RU_01); break;
		case R:		anim->SetSprite(TextureKey::PG01_WALK_R_01,		TextureKey::PG01_WALK_R_01); break;
		case RD:	anim->SetSprite(TextureKey::PG01_WALK_RD_01,	TextureKey::PG01_WALK_RD_01); break;
		}
		anim->SetDelay(0.2f);
		anim->SetLoop(true);
		break;

	case WALK:
		switch (curDir)
		{
		case D:		anim->SetSprite(TextureKey::PG01_WALK_D_01,		TextureKey::PG01_WALK_D_03); break;
		case LD:	anim->SetSprite(TextureKey::PG01_WALK_LD_01,	TextureKey::PG01_WALK_LD_03); break;
		case L:		anim->SetSprite(TextureKey::PG01_WALK_L_01,		TextureKey::PG01_WALK_L_03); break;
		case LU:	anim->SetSprite(TextureKey::PG01_WALK_LU_01,	TextureKey::PG01_WALK_LU_03); break;
		case U:		anim->SetSprite(TextureKey::PG01_WALK_U_01,		TextureKey::PG01_WALK_U_03); break;
		case RU:	anim->SetSprite(TextureKey::PG01_WALK_RU_01,	TextureKey::PG01_WALK_RU_03); break;
		case R:		anim->SetSprite(TextureKey::PG01_WALK_R_01,		TextureKey::PG01_WALK_R_03); break;
		case RD:	anim->SetSprite(TextureKey::PG01_WALK_RD_01,	TextureKey::PG01_WALK_RD_03); break;
		}
		anim->SetDelay(0.2f);
		anim->SetLoop(true);
		break;

	case ATTACK:
		switch (curDir)
		{
		case D:		anim->SetSprite(TextureKey::PG01_ATTACK_D_01,	TextureKey::PG01_ATTACK_D_02); break;
		case LD:	anim->SetSprite(TextureKey::PG01_ATTACK_LD_01,	TextureKey::PG01_ATTACK_LD_02); break;
		case L:		anim->SetSprite(TextureKey::PG01_ATTACK_L_01,	TextureKey::PG01_ATTACK_L_02); break;
		case LU:	anim->SetSprite(TextureKey::PG01_ATTACK_LU_01,	TextureKey::PG01_ATTACK_LU_02); break;
		case U:		anim->SetSprite(TextureKey::PG01_ATTACK_U_01,	TextureKey::PG01_ATTACK_U_02); break;
		case RU:	anim->SetSprite(TextureKey::PG01_ATTACK_RU_01,	TextureKey::PG01_ATTACK_RU_02); break;
		case R:		anim->SetSprite(TextureKey::PG01_ATTACK_R_01,	TextureKey::PG01_ATTACK_R_02); break;
		case RD:	anim->SetSprite(TextureKey::PG01_ATTACK_RD_01,	TextureKey::PG01_ATTACK_RD_02); break;
		}
		anim->SetDelay(0.2f);
		anim->SetLoop(true);
		break;
	}
}
