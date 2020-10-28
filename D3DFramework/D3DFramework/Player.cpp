#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	Initialize();
}

Player::Player(PlayerCharacter * _character) :
	character(_character)
{
	Initialize();
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	ResetMousePoint();

	Camera::GetInstance()->SetTarget(character);
}

void Player::Update()
{
	if (nullptr == character) return;

	CalcSpawnTime();
	Attack();
	KeyInput();
	CalcMouse();
	ResetMousePoint();

	GameObject::Update();
}

void Player::Render()
{
}

void Player::Release()
{
	//character->Die();
}

Player * Player::Create(PlayerCharacter * _character)
{
	Player* newPlayer = new Player(_character);
	return newPlayer;
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

void Player::Attack()
{
	if (canSpawn)
	{
		if (InputManager::GetMouseLButton())
		{
			Vector3 pos = Camera::ScreenToWorldPoint(Vector3(dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2, 1.f));

			Vector3 dir = pos - transform->position;

			Vector3::Normalize(&dir);

			character->Attack(dir);

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

	character->transform->eulerAngles.x = radianX;
	character->transform->eulerAngles.y = radianY;
}

void Player::KeyInput()
{
	bool isKeyDown = false;
	float moveSpeed = 5.f;


	if (InputManager::GetKey('W'))
	{
		isKeyDown = true;

		if (InputManager::GetKey('A'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			character->SetDir(character->transform->look - character->transform->right);
		}
		else if (InputManager::GetKey('D'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			character->SetDir(character->transform->look + character->transform->right);
		}
		else
		{
			character->SetDir(character->transform->look);
		}

		character->SetMoveSpeed(moveSpeed);
		character->MoveForward();
	}
	else if (InputManager::GetKey('S'))
	{
		isKeyDown = true;

		if (InputManager::GetKey('A'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			character->SetDir(-character->transform->look - character->transform->right);
		}
		else if (InputManager::GetKey('D'))
		{
			moveSpeed = 5.f / sqrt(2.f);
			character->SetDir(-character->transform->look + character->transform->right);
		}
		else
		{
			character->SetDir(-character->transform->look);
		}

		character->SetMoveSpeed(moveSpeed);
		character->MoveForward();
	}
	else if (InputManager::GetKey('A'))
	{
		isKeyDown = true;
		character->SetDir(-character->transform->right);
		character->SetMoveSpeed(moveSpeed);
		character->MoveForward();
	}
	else if (InputManager::GetKey('D'))
	{
		isKeyDown = true;
		character->SetDir(character->transform->right);
		character->SetMoveSpeed(moveSpeed);
		character->MoveForward();
	}

	if (!isKeyDown)
	{
		character->ChangeState(State::IDLE);
	}
}
