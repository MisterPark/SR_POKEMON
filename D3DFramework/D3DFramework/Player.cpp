#include "stdafx.h"
#include "Player.h"
#include "Rectangle.h"
#include "Environment.h"
#include "Bullet.h"

Player::Player() :
	Character::Character()
{
	Initialize();
}

Player::~Player()
{
	Release();
	//Character::~Character();
}

void Player::Initialize()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	
	moveSpeed = 5.f;

	transform->scale = Vector3(0.2f, 0.2f, 0.2f);

	curState = ATTACK;
	curDir = U;
	offsetY = 0.2f;

	SetAnim();

	ResetMousePoint();

	Camera::GetInstance()->SetTarget(this);
}

void Player::Update()
{
	CalcSpawnTime();
	SpawnBullet();
	KeyInput();
	CalcMouse();
	ResetMousePoint();

	//SetAnim();
	Character::Update();
}

void Player::Render()
{
	Character::Render();
}

void Player::Release()
{
	//Character::Release();
}

void Player::ChangeAnim(STATE state, DIR dir)
{
	if (state != curState || dir != curDir)
	{
		curState = state;
		curDir = dir;
		SetAnim();
	}
}

void Player::ResetMousePoint()
{
	POINT pt = { dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2 };
	ClientToScreen(g_hwnd, &pt);
	SetCursorPos(pt.x, pt.y);
}

void Player::CalcSpawnTime()
{
	if (!canSpawn)
	{
		spawnTime -= TimeManager::DeltaTime();
		if (0.f >= spawnTime)
		{
			canSpawn = true;
		}
	}
}

void Player::SpawnBullet()
{
	if (canSpawn)
	{
		if (InputManager::GetMouseLButton())
		{
			Camera::ScreenToWorldPoint(Vector3(dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2, 1.f));

			//GameObject* newBullet = Bullet::Create(transform->position, Vector3(0.2f, 0.2f, 0.2f), dir, 0);
			//ObjectManager::AddObject(newBullet);

			spawnTime = 1.f;
			canSpawn = false;
		}
	}
}

void Player::CalcMouse()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	float xSize = (pt.x - (dfCLIENT_WIDTH / 2)) * 30.f / (dfCLIENT_WIDTH / 2);
	float ySize = (pt.y - (dfCLIENT_HEIGHT / 2)) * 30.f / (dfCLIENT_HEIGHT / 2);

	radianX += D3DXToRadian(ySize);

	if (radianX > D3DXToRadian(30.f))
		radianX = D3DXToRadian(30.f);
	else if (radianX < D3DXToRadian(-15.f))
		radianX = D3DXToRadian(-15.f);

	radianY += D3DXToRadian(xSize);

	transform->eulerAngles.x = radianX;
	transform->eulerAngles.y = radianY;

	OnTerrain();
	
}

void Player::KeyInput()
{
	bool isKeyDown = false;

	if (InputManager::GetKey('W'))
	{
		isKeyDown = true;
		moveSpeed = 5.f;
		Vector3 dir = transform->look;

		if (InputManager::GetKey('A'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			ChangeAnim(WALK, LU);
			dir += -transform->right;
		}
		else if (InputManager::GetKey('D'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			ChangeAnim(WALK, RU);
			dir += transform->right;
		}
		else
		{
			ChangeAnim(WALK, U);
		}

		Move(dir);
	}
	else if (InputManager::GetKey('S'))
	{
		isKeyDown = true;
		moveSpeed = 5.f;
		Vector3 dir = -transform->look;

		if (InputManager::GetKey('A'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			ChangeAnim(WALK, LD);
			dir += -transform->right;
		}
		else if (InputManager::GetKey('D'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			ChangeAnim(WALK, RD);
			dir += transform->right;
		}
		else
		{
			ChangeAnim(WALK, D);
		}

		Move(dir);
	}
	else if (InputManager::GetKey('A'))
	{
		isKeyDown = true;
		moveSpeed = 5.f;
		ChangeAnim(WALK, L);
		Move(-transform->right);
	}
	else if (InputManager::GetKey('D'))
	{
		isKeyDown = true;
		moveSpeed = 5.f;
		ChangeAnim(WALK, R);
		Move(transform->right);
	}

	if (!isKeyDown)
	{
		ChangeAnim(IDLE, curDir);
	}
}

void Player::SetAnim()
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
