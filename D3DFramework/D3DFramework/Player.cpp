#include "stdafx.h"
#include "Player.h"
#include "PlayerInfoPanel.h"
#include "Charmander.h"
#include "Charmeleon.h"
#include "Inventory.h"
#include "AllCharacters.h"
#include "Dialog.h"
Player* Player::instance = nullptr;

Player::Player() :
	character(nullptr), radianX(0.f), radianY(0.f),
	isFix(true), skillNum(1)
{
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

void Player::Show()
{
	if (instance == nullptr)return;
	if (instance->character == nullptr)return;

	instance->character->isVisible = true;
}

void Player::Hide()
{
	if (instance == nullptr)return;
	if (instance->character == nullptr)return;

	instance->character->isVisible = false;
}

void Player::Initialize()
{
	metamorphosisList.reserve(3);

	MetamorphosisToDitto();

	nextPokemon = make_pair(TYPE::END, Pokemon::None);
}

void Player::Update()
{
	if (nullptr == character) return;


	KeyInput();
	
	CalcMetamorphosisTime();

	if (isFix)
	{
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
	if (nullptr == object) return;
	// 처음 세팅할 때
	if (nullptr == character)
	{
		character = object;
		character->dontDestroy = true;
		character->team = Team::PLAYERTEAM;
		skillSetSize = character->GetSkillSetSize();
		if (skillSetSize >= 1) skillNum = 1;
		else skillNum = 0;
		CollisionManager::GetInstance()->RegisterObject(COLTYPE::PLAYER, character);
		PlayerInfoPanel::SetTarget(character);
		Camera::GetInstance()->SetTarget(character);
		character->infoVisible = false;

		++pokemonIndex;
		metamorphosisList.emplace_back(make_pair(character->type, character->number));
	}
	// 처음 세팅이 아닐 때
	else
	{
		// 변신 전 필요한 데이터 저장
		Vector3 pos = character->transform->position;
		Vector3 dir = character->direction;
		STAT oldStat = character->GetStat();

		character->dontDestroy = false;
		character->Die();

		// 변신 후 세팅
		character = object;
		character->dontDestroy = true;
		character->team = Team::PLAYERTEAM;
		character->transform->position = pos;
		character->direction = dir;
		character->stat = oldStat;
		character->infoVisible = false;

		skillSetSize = character->GetSkillSetSize();
		if (skillSetSize >= 1) skillNum = 1;
		else skillNum = 0;
		CollisionManager::GetInstance()->RegisterObject(COLTYPE::PLAYER, character);
		PlayerInfoPanel::SetTarget(character);
		Camera::GetInstance()->SetTarget(character);
	}

	/*
	if (character != nullptr)
	{
		if (character == object) return;

		saveStat = character->GetStat();
		character->dontDestroy = false;
		character->Die();
	}
	character = object;

	Camera::GetInstance()->SetTarget(character);
	if (nullptr != object)
	{
		character->dontDestroy = true;
		character->team = Team::PLAYERTEAM;
		skillSetSize = character->GetSkillSetSize();
		CollisionManager::GetInstance()->RegisterObject(COLTYPE::PLAYER, character);
		PlayerInfoPanel::SetTarget(object);
	}
	*/
}

void Player::Release()
{
	metamorphosisList.clear();
}

void Player::ResetMousePoint()
{
	POINT pt = { dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2 };
	ClientToScreen(g_hwnd, &pt);
	SetCursorPos(pt.x, pt.y);
}

void Player::Attack()
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
	}
	else if (InputManager::GetMouseRButton())
	{
		Vector3 pos = Camera::ScreenToWorldPoint(Vector3(dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2, 1.f));

		Vector3 characterPos = character->transform->position;
		characterPos.y += character->offsetY;

		Vector3 dir = pos - characterPos;

		Vector3::Normalize(&dir);

		character->SetDir(dir);
		character->Attack(dir, skillNum);
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
	if (Dialog::GetInstance()->isVisible == false)
	{
		if (InputManager::GetKeyDown(VK_SPACE))
		{
			Metamorphosis();
			//Evolution();
			//Camera::Shake();
		}

		if (InputManager::GetKeyDown('I'))
		{
			if (character != nullptr)
			{
				Inventory* inven = Inventory::GetInstance();
				Inventory::Show(!inven->isVisible);
				isFix ^= true;
				//Cursor::Show(!Cursor::IsVisible());
			}

		}

		if (InputManager::GetMouseWheelUp())
		{
			if (0 < skillSetSize)
			{
				--skillNum;
				if (skillNum < 1)
				{
					skillNum += (skillSetSize - 1);
				}
			}
		}

		if (InputManager::GetMouseWheelDown())
		{
			if (0 < skillSetSize)
			{
				++skillNum;

				if (skillNum >= skillSetSize)
				{
					skillNum %= skillSetSize;
					++skillNum;
				}
			}
		}

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
	}
	if (!isKeyDown && character->GetCanMove())
	{
		ChangeState(State::IDLE);
	}

	if (InputManager::GetKeyDown('Q'))
	{
		isFix ^= true;
	}
}

void Player::ChangeState(State state)
{
	if (character->GetCanMove())
	{
		character->ChangeState(state);
	}
}

void Player::Metamorphosis()
{
	if (canMetamorphosis)
	{
		if (TYPE::END != nextPokemon.first)
		{
			metamorphosisList.emplace_back(nextPokemon);
			SetCharacterByType(nextPokemon.first);

			++pokemonIndex;
			nextPokemon.first = TYPE::END;
			nextPokemon.second = Pokemon::None;

			metamorphosisTime = 5.f;
			canMetamorphosis = false;
		}
	}
}

void Player::PermanentMetamorphosis()
{
	if (TYPE::END != nextPokemon.first)
	{
		metamorphosisList.emplace_back(nextPokemon);
		SetCharacterByType(nextPokemon.first);

		++pokemonIndex;
		permanentIndex = pokemonIndex;
		nextPokemon.first = TYPE::END;
		nextPokemon.second = Pokemon::None;

		canMetamorphosis = true;
	}
}

void Player::MetamorphosisToDitto()
{
	metamorphosisList.clear();

	pokemonIndex = -1;
	SetCharacterByType(TYPE::DITTO);
	permanentIndex = 0;
	canMetamorphosis = true;
}

void Player::SetCharacterByType(TYPE type)
{
	Character* pokemon = nullptr;

	Vector3 pos = { 0.f, 0.f, 0.f };
	Vector3 dir = { 0.f, 0.f, 1.f };

	if (nullptr != character)
	{
		pos = character->transform->position;
		dir = character->direction;
	}

	switch (type)
	{
	case TYPE::BULBASAUR:
		pokemon = Bulbasaur::Create(pos, dir);
		break;
	case TYPE::IVYSAUR:
		pokemon = Ivysaur::Create(pos, dir);
		break;
	case TYPE::VENUSAUR:
		pokemon = Venusaur::Create(pos, dir);
		break;
	case TYPE::CATERPIE:
		pokemon = Caterpie::Create(pos, dir);
		break;
	case TYPE::METAPOD:
		pokemon = Metapod::Create(pos, dir);
		break;
	case TYPE::ODDISH:
		pokemon = Oddish::Create(pos, dir);
		break;
	case TYPE::GLOOM:
		pokemon = Gloom::Create(pos, dir);
		break;
	case TYPE::VILEPLUME:
		pokemon = Vileplume::Create(pos, dir);
		break;
	case TYPE::SCYTHER:
		pokemon = Scyther::Create(pos, dir);
		break;
	case TYPE::BUTTERFREE:
		pokemon = Butterfree::Create(pos, dir);
		break;
	case TYPE::SQUIRTLE:
		pokemon = Squirtle::Create(pos, dir);
		break;
	case TYPE::WARTORTLE:
		pokemon = Wartortle::Create(pos, dir);
		break;
	case TYPE::BLASTOISE:
		pokemon = Blastoise::Create(pos, dir);
		break;
	case TYPE::PSYDUCK:
		pokemon = Psyduck::Create(pos, dir);
		break;
	case TYPE::GOLDUCK:
		pokemon = Golduck::Create(pos, dir);
		break;
	case TYPE::POLIWAG:
		pokemon = Poliwag::Create(pos, dir);
		break;
	case TYPE::POLIWHIRL:
		pokemon = Poliwhirl::Create(pos, dir);
		break;
	case TYPE::POLIWRATH:
		pokemon = Poliwrath::Create(pos, dir);
		break;
	case TYPE::JYNX:
		pokemon = Jynx::Create(pos, dir);
		break;
	case TYPE::SUICUNE:
		pokemon = Suicune::Create(pos, dir);
		break;
	case TYPE::CHARMANDER:
		pokemon = Charmander::Create(pos, dir);
		break;
	case TYPE::CHARMELEON:
		pokemon = Charmeleon::Create(pos, dir);
		break;
	case TYPE::CHARIZARD:
		pokemon = Charizard::Create(pos, dir);
		break;
	case TYPE::GROWLITHE:
		pokemon = Growlithe::Create(pos, dir);
		break;
	case TYPE::ARCANINE:
		pokemon = Arcanine::Create(pos, dir);
		break;
	case TYPE::PONYTA:
		pokemon = Ponyta::Create(pos, dir);
		break;
	case TYPE::RAPIDASH:
		pokemon = Rapidash::Create(pos, dir);
		break;
	case TYPE::SLUGMA:
		pokemon = Slugma::Create(pos, dir);
		break;
	case TYPE::MAGCARGO:
		pokemon = Magcargo::Create(pos, dir);
		break;
	case TYPE::GROUDON:
		pokemon = Groudon::Create(pos, dir);
		break;
	case TYPE::DITTO:
		pokemon = Ditto::Create(pos, dir);
		break;
	}

	if (nullptr != pokemon)
	{
		ObjectManager::AddObject(pokemon);
		pokemon->dontDestroy = true;
	}

	SetCharacter(pokemon);
}

void Player::CalcMetamorphosisTime()
{
	if (!canMetamorphosis)
	{
		metamorphosisTime -= TimeManager::DeltaTime();

		if (0.f > metamorphosisTime)
		{
			canMetamorphosis = true;
			metamorphosisTime = 0.f;
			ComeBackFromMetamorpho();
		}
	}
}

void Player::ComeBackFromMetamorpho()
{
	if (permanentIndex < pokemonIndex)
	{
		auto iter = metamorphosisList.begin();
		iter += pokemonIndex;

		metamorphosisList.erase(iter);

		--pokemonIndex;

		SetCharacterByType(metamorphosisList[pokemonIndex].first);
	}
}

void Player::ChangeNextPokemon(TYPE pokemon, Pokemon number)
{
	if (TYPE::END != pokemon)
	{
		nextPokemon.first = pokemon;
		nextPokemon.second = number;
	}
}
