#include "stdafx.h"
#include "Player.h"
#include "PlayerInfoPanel.h"

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

	canMove = character->GetCanMove();

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
	if (nullptr == character) return;
	Vector3* pos = character->transform->Get_Pos();
	
	float limitedX = 2.3f;
	float limitedZ = 2.3f;
	if (limitedX > pos->x) pos->x = limitedX;
	if (dfTERRAIN_WIDTH - (limitedX + 1) < pos->x) pos->x = dfTERRAIN_WIDTH - (limitedX + 1);
	if (limitedZ > pos->z) pos->z = limitedZ;
	if (dfTERRAIN_HEIGHT - (limitedZ +1) < pos->z) pos->z = dfTERRAIN_HEIGHT - (limitedZ + 1);

	character->OnTerrain();
}

void Player::SetCharacter(Character * object)
{
	character = object;

	Camera::GetInstance()->SetTarget(character);
	if (nullptr != object)
	{
		character->team = Team::PLAYERTEAM;
		CollisionManager::GetInstance()->RegisterObject(COLTYPE::PLAYER, character);
	}

	PlayerInfoPanel::SetTarget(object);
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

			attackCoolTime = character->GetSkillCollTime(1)->GetCoolTime();
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

			skillCoolTime = character->GetSkillCollTime(2)->GetCoolTime();
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
