#include "stdafx.h"
#include "MainGame.h"
#include "TestScene.h"
#include "SkyBox.h"
#include "TitleScene.h"

using namespace PKH;

PKH::MainGame* pMainGame = nullptr;

PKH::MainGame::MainGame()
{
}

PKH::MainGame::~MainGame()
{
}

PKH::MainGame* MainGame::GetInstance()
{
    if (pMainGame == nullptr)
    {
        pMainGame = new MainGame;
    }
    
    return pMainGame;
}

void PKH::MainGame::Destroy()
{
    if (pMainGame)
    {
        delete pMainGame;
        pMainGame = nullptr;
    }
}

void PKH::MainGame::Initialize()
{
	Network::GetInstance();
	Network::Initialize();
	LobbyWindow::GetInstance();
	Random::InitState();

	// �ٸ� ��� �Ŵ��� �ʱ�ȭ
	TimeManager::GetInstance();
	TimeManager::SetFPS(60.f);
	
	D2DRenderManager::GetInstance();
	ObjectManager::GetInstance();
	CollisionManager::GetInstance();
	LightManager::GetInstance();
	InputManager::GetInstance();
	SkyBox::GetInstance();
	Player::GetInstance();

	//RenderManager::GetInstance();

	SceneManager::GetInstance();

	Camera::GetInstance();
	FileManager::GetInstance();
	Cursor::GetInstance();

	SoundManager::GetInstance()->Initialize();
	LoadManager::GetInstance();

	LoadUISprite();

	
	SkillManager::GetInstance();

	// ���ε�
	SceneManager::LoadScene<TitleScene>();
}

void PKH::MainGame::Update()
{
	// 1. ��ǲ ����
	InputManager::Update();

	// 2. �� �Ŵ��� ������Ʈ
	SceneManager::Update();

	// 3. Player ������Ʈ
	Player::GetInstance()->Update();
	SkillManager::GetInstance()->Update();

	// 4. Obj ������Ʈ
	ObjectManager::Update();

	Camera::GetInstance()->Update();
	SkyBox::GetInstance()->Update();
	
	Player::GetInstance()->PostUpdate();
	SkillManager::GetInstance()->PostUpdate();
	CollisionManager::GetInstance()->Update();
	ObjectManager::PostUpdate();

	if (!TimeManager::SkipFrame())
	{
		D2DRenderManager::Clear();

		SkyBox::GetInstance()->Render();
		ObjectManager::PreRender();
		ObjectManager::Render();
		ObjectManager::PostRender();


		D2DRenderManager::Present();
	}
}

void PKH::MainGame::Release()
{
	// �ٸ� ��� �Ŵ��� ����
	LoadManager::Destroy();
	SceneManager::Destroy();
	TimeManager::Destroy();
	ObjectManager::Destroy();
	CollisionManager::Destroy();
	SkyBox::Destroy();
	//RenderManager::Release();
	D2DRenderManager::Destroy();
	InputManager::Destroy();
	Camera::Destroy();
	FileManager::Destroy();
	LightManager::Destroy();
	SoundManager::Destroy();
	Cursor::Destroy();
	Player::Destroy();
	SkillManager::Destroy();
	LobbyWindow::Destroy();
	Network::Destroy();
}

void PKH::MainGame::Pause()
{
}

void PKH::MainGame::Resume()
{
}

void PKH::MainGame::Shutdown()
{
	PostQuitMessage(0);
}


void PKH::MainGame::LoadUISprite()
{
	// ���ҽ� �ε�
	D2DRenderManager::LoadSprite(TextureKey::UI_TITLE_SCREEN, L"Texture\\UI\\pokeTitle2.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_CURSOR, L"Texture\\UI\\Cursor.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_BUTTON, L"Texture\\UI\\PokemonButton.png");
	// �������
	D2DRenderManager::LoadSprite(TextureKey::UI_BLUE_FILTER, L"Texture\\UI\\BlueFilter.png");
	

	D2DRenderManager::LoadSprite(TextureKey::UI_HP_BAR_01, L"Texture\\UI\\HP_BAR_01.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_HP_BAR_02, L"Texture\\UI\\HP_BAR_02.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_HP_BAR_03, L"Texture\\UI\\HP_BAR_03.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_HP_BAR_04, L"Texture\\UI\\HP_BAR_04.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_HP_BAR_05, L"Texture\\UI\\HP_BAR_05.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_HP_BAR_06, L"Texture\\UI\\HP_BAR_06.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_EXP_BAR_01, L"Texture\\UI\\EXP_BAR_01.png");

	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_00, L"Texture\\UI\\Damage\\NoRed0.0.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_01, L"Texture\\UI\\Damage\\NoRed0.1.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_02, L"Texture\\UI\\Damage\\NoRed0.2.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_03, L"Texture\\UI\\Damage\\NoRed0.3.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_04, L"Texture\\UI\\Damage\\NoRed0.4.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_05, L"Texture\\UI\\Damage\\NoRed0.5.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_06, L"Texture\\UI\\Damage\\NoRed0.6.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_07, L"Texture\\UI\\Damage\\NoRed0.7.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_08, L"Texture\\UI\\Damage\\NoRed0.8.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_NUM_RED_09, L"Texture\\UI\\Damage\\NoRed0.9.png");

	// �� ������
	D2DRenderManager::LoadSprite(TextureKey::UI_FACE_POKEMON_1ST, L"Texture\\UI\\pokemon_icon_1st.png", 13, 12);
	D2DRenderManager::LoadSprite(TextureKey::UI_FACE_POKEMON_2ND, L"Texture\\UI\\pokemon_icon_2nd.png", 11, 12);
	D2DRenderManager::LoadSprite(TextureKey::UI_FACE_POKEMON_3RD, L"Texture\\UI\\pokemon_icon_3rd.png", 12, 12);

	D2DRenderManager::LoadSprite(TextureKey::UI_DROH_SCREEN, L"Texture\\UI\\doctorOUI.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_CELEBI_SCREEN, L"Texture\\UI\\Celebi.png");
	// ICON
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_BORDER, L"Texture\\UI\\iconBorder.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_BLACK_FILTER, L"Texture\\UI\\iconFilter.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_RED_FILTER, L"Texture\\UI\\redFilter.png");

	D2DRenderManager::LoadSprite(TextureKey::ICON_FIELDFIRE, L"Texture\\Player\\Icon\\FieldFire.png");
	D2DRenderManager::LoadSprite(TextureKey::ICON_XCLAW, L"Texture\\Player\\Icon\\XClaw.png");
	D2DRenderManager::LoadSprite(TextureKey::ICON_METEOR, L"Texture\\Player\\Icon\\Meteor.png");
	D2DRenderManager::LoadSprite(TextureKey::ICON_SYNTHESIS, L"Texture\\Player\\Icon\\Synthesis.png");
	D2DRenderManager::LoadSprite(TextureKey::ICON_LEECHSEED, L"Texture\\Player\\Icon\\LeechSeed.png");
	D2DRenderManager::LoadSprite(TextureKey::ICON_PETALBLIZZARD, L"Texture\\Player\\Icon\\PetalBlizzard.png");
	

	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ARROW_LEFT, L"Texture\\UI\\leftArrow.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ARROW_RIGHT, L"Texture\\UI\\rightArrow.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ARROW_REFRESH, L"Texture\\UI\\refreshArrow.png");

	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_STAT_HEART, L"Texture\\UI\\StatIcon_01.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_STAT_ATTACK, L"Texture\\UI\\StatIcon_02.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_STAT_SPEED, L"Texture\\UI\\StatIcon_03.png");

	D2DRenderManager::LoadSprite(TextureKey::UI_BAG, L"Texture\\UI\\bag.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SLOT, L"Texture\\UI\\slot.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_TOMATO, L"Texture\\UI\\item_01.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_CLAM, L"Texture\\UI\\item_02.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_GRAPE, L"Texture\\UI\\item_03.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_PEAR, L"Texture\\UI\\item_04.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_GAJI, L"Texture\\UI\\item_05.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_LEMON, L"Texture\\UI\\item_06.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_BLUEBERRY, L"Texture\\UI\\item_07.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_HP_POTION, L"Texture\\UI\\item_08.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_EXP_POTION, L"Texture\\UI\\item_09.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_FIRE, L"Texture\\UI\\item_10.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_WATER, L"Texture\\UI\\item_11.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_LEAF, L"Texture\\UI\\item_12.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_THUNDER, L"Texture\\UI\\item_13.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_MOON, L"Texture\\UI\\item_14.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_SUN, L"Texture\\UI\\item_15.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_LIGHT, L"Texture\\UI\\item_16.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_AWAKE, L"Texture\\UI\\item_17.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_STONE_OF_DARK, L"Texture\\UI\\item_18.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_POKE_BALL, L"Texture\\UI\\item_19.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_GREAT_BALL, L"Texture\\UI\\item_20.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_ULTRA_BALL, L"Texture\\UI\\item_21.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_ICON_ITEM_MASTER_BALL, L"Texture\\UI\\item_22.png");

	D2DRenderManager::LoadSprite(TextureKey::UI_DIALOG, L"Texture\\UI\\dialog.png");

	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_TEARS, L"Texture\\UI\\SkillIcon\\skillicon_01.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_WATER, L"Texture\\UI\\SkillIcon\\skillicon_02.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_WATERBOMB, L"Texture\\UI\\SkillIcon\\skillicon_03.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_SHELL, L"Texture\\UI\\SkillIcon\\skillicon_04.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_TSUNAMI, L"Texture\\UI\\SkillIcon\\skillicon_05.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_BUBBLE, L"Texture\\UI\\SkillIcon\\skillicon_06.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_REDBALL, L"Texture\\UI\\SkillIcon\\skillicon_07.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_EXPLOSION, L"Texture\\UI\\SkillIcon\\skillicon_08.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_FIREBOMB, L"Texture\\UI\\SkillIcon\\skillicon_09.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_FIREXCROSSBOMB, L"Texture\\UI\\SkillIcon\\skillicon_10.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_SNOWVULCAN, L"Texture\\UI\\SkillIcon\\skillicon_11.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_MINIRUSH, L"Texture\\UI\\SkillIcon\\skillicon_12.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_CROSSPOISON, L"Texture\\UI\\SkillIcon\\skillicon_13.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_XPOISON, L"Texture\\UI\\SkillIcon\\skillicon_14.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_HEALBULLET, L"Texture\\UI\\SkillIcon\\skillicon_15.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_REVERSEHEALBULLET, L"Texture\\UI\\SkillIcon\\skillicon_16.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_WEB, L"Texture\\UI\\SkillIcon\\skillicon_17.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_WATERFLOW, L"Texture\\UI\\SkillIcon\\skillicon_18.png");
	D2DRenderManager::LoadSprite(TextureKey::UI_SKILL_ICON_ACCELWATER, L"Texture\\UI\\SkillIcon\\skillicon_19.png");
}										
