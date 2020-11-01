#include "stdafx.h"
#include "Player.h"

Player* Player::instance = nullptr;

Player::Player() :
	character(nullptr), radianX(0.f), radianY(0.f),
	attackCoolTime(0.f), skillCoolTime(0.f),
	isAttack(false), isSkill(false), isFix(true)
{
	Initialize();
}

Player::~Player()
{
	Release();
}

Player * Player::GetInstance()
{
	if (nullptr == instance) instance = new Player;
	return instance;
}

void Player::Destroy()
{
	if (nullptr != instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void Player::Update()
{
	if (nullptr == character) return;

	KeyInput();

	if (isFix)
	{
		CalcCoolTime();
		Attack();
		CalcMouse();
		ResetMousePoint();
	}
}

void Player::PostUpdate()
{
	Vector3* pos = character->transform->Get_Pos();

	if (0.f > pos->x) pos->x = 0.f;
	if (dfTERRAIN_WIDTH - 1 < pos->x) pos->x = dfTERRAIN_WIDTH - 1;
	if (0.f > pos->z) pos->z = 0.f;
	if (dfTERRAIN_HEIGHT - 1 < pos->z) pos->z = dfTERRAIN_HEIGHT - 1;
}

void Player::SetCharacter(Character * object)
{
	character = object;

	Camera::GetInstance()->SetTarget(character);
}

void Player::Initialize()
{
}

void Player::Release()
{
}

void Player::ResetMousePoint()
{
	POINT pt = { dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2 };
	ClientToScreen(g_hwnd, &pt);
	SetCursorPos(pt.x, pt.y);
}

void Player::CalcCoolTime()
{
	if (isAttack)
	{
		attackCoolTime -= TimeManager::DeltaTime();
		if (0.f >= attackCoolTime)
		{
			isAttack = false;
		}
	}

	if (isSkill)
	{
		skillCoolTime -= TimeManager::DeltaTime();
		if (0.f >= skillCoolTime)
		{
			isSkill = false;
		}
	}
}

void Player::Attack()
{
	if (!isAttack && !isSkill)
	{
		if (InputManager::GetMouseLButton())
		{
			Vector3 pos = Camera::ScreenToWorldPoint(Vector3(dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2, 1.f));

			Vector3 characterPos = character->transform->position;
			characterPos.y += character->offsetY;

			Vector3 dir = pos - characterPos;

			Vector3::Normalize(&dir);

			character->SetDir(dir);
			character->Attack(dir, 0);

			attackCoolTime = 0.4f;
			isAttack = true;
		}
		else if (InputManager::GetMouseRButton())
		{
			Vector3 pos = Camera::ScreenToWorldPoint(Vector3(dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2, 1.f));

			Vector3 characterPos = character->transform->position;
			characterPos.y += character->offsetY;

			Vector3 dir = pos - characterPos;

			Vector3::Normalize(&dir);

			character->SetDir(dir);
			character->Attack(dir, 1);

			skillCoolTime = 0.6f;
			isSkill = true;
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

	if (radianX > D3DXToRadian(20.f))
		radianX = D3DXToRadian(20.f);
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

	if (!isAttack && !isSkill)
	{

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
			ChangeState(State::WALK);
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
			ChangeState(State::WALK);
		}
		else if (InputManager::GetKey('A'))
		{
			isKeyDown = true;
			character->SetDir(-character->transform->right);
			character->SetMoveSpeed(moveSpeed);
			character->MoveForward();
			ChangeState(State::WALK);
		}
		else if (InputManager::GetKey('D'))
		{
			isKeyDown = true;
			character->SetDir(character->transform->right);
			character->SetMoveSpeed(moveSpeed);
			character->MoveForward();
			ChangeState(State::WALK);
		}

		if (!isKeyDown)
		{
			ChangeState(State::IDLE);
		}
	}

	if (InputManager::GetKeyDown('Q'))
	{
		isFix ^= true;
	}
}

void Player::ChangeState(State state)
{
	if (!isAttack && !isSkill)
	{
		character->ChangeState(state);
	}
}
