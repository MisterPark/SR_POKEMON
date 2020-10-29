#include "stdafx.h"
#include "MainGame.h"
#include "TestScene.h"

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
	Random::InitState();

	// 다른 모든 매니저 초기화
	TimeManager::GetInstance();
	TimeManager::SetFPS(60.f);
	D2DRenderManager::GetInstance();
	CollisionManager::GetInstance();
	InputManager::GetInstance();
	Player::GetInstance();

	//RenderManager::GetInstance();

	SceneManager::GetInstance();

	Camera::GetInstance();
	FileManager::GetInstance();
	Cursor::GetInstance();

	SoundManager::GetInstance()->Initialize();
	LoadMonsterSprite();
	LoadPlayerSprite();
	LoadETCSprite();

	ObjectManager::GetInstance();

	// 씬로드
	SceneManager::LoadScene<TestScene>();
}

void PKH::MainGame::Update()
{
	// 1. 인풋 먼저
	InputManager::Update();

	// 2. 씬 매니저 업데이트
	SceneManager::Update();

	// 3. Player 업데이트
	Player::GetInstance()->Update();

	// 4. Obj 업데이트
	ObjectManager::Update();

	Camera::GetInstance()->Update();
	CollisionManager::Update();
	

	ObjectManager::PostUpdate();

	if (!TimeManager::SkipFrame())
	{
		D2DRenderManager::Clear();

		ObjectManager::PreRender();
		ObjectManager::Render();
		ObjectManager::PostRender();


		D2DRenderManager::Present();
	}
}

void PKH::MainGame::Release()
{
	// 다른 모든 매니저 해제
	SceneManager::Destroy();
	TimeManager::Destroy();
	ObjectManager::Destroy();
	//RenderManager::Release();
	D2DRenderManager::Destroy();
	InputManager::Destroy();
	CollisionManager::Destroy();
	Camera::Destroy();
	FileManager::Destroy();

	SoundManager::Destroy();
	Cursor::Destroy();
	Player::DestroyInstance();
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

void PKH::MainGame::LoadETCSprite()
{
	// 리소스 로드
	D2DRenderManager::LoadSprite(TextureKey::TITLE_SCREEN, L"Texture\\pokeTitle.png");

	D2DRenderManager::LoadSprite(TextureKey::SKY_U, L"Texture\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_D, L"Texture\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_L, L"Texture\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_R, L"Texture\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_F, L"Texture\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_B, L"Texture\\SKYBOX_B.png");


	//눈물총알
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_01, L"Texture\\Bullet\\Bullet_Tears01.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_02, L"Texture\\Bullet\\Bullet_Tears02.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_03, L"Texture\\Bullet\\Bullet_Tears03.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_04, L"Texture\\Bullet\\Bullet_Tears04.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_05, L"Texture\\Bullet\\Bullet_Tears05.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_06, L"Texture\\Bullet\\Bullet_Tears06.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_07, L"Texture\\Bullet\\Bullet_Tears07.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_08, L"Texture\\Bullet\\Bullet_Tears08.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_09, L"Texture\\Bullet\\Bullet_Tears09.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_10, L"Texture\\Bullet\\Bullet_Tears10.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_11, L"Texture\\Bullet\\Bullet_Tears11.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_12, L"Texture\\Bullet\\Bullet_Tears12.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_13, L"Texture\\Bullet\\Bullet_Tears13.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_14, L"Texture\\Bullet\\Bullet_Tears14.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TEARS_15, L"Texture\\Bullet\\Bullet_Tears15.png");
}

void PKH::MainGame::LoadUISprite()
{
}

void PKH::MainGame::LoadMonsterSprite()
{

	//버터플
	//이동
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_D_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_D_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_D_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_LD_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_LD_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_LD_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_L_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_L_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_L_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_LU_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_LU_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_LU_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_U_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_U_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_U_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RD (3).png");


	//공격
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_D_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_D_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_L_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_L_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_U_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_U_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_R_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_R_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RD (2).png");

	//캐터피
	//이동
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_D_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_D_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_D_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_LD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_LD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_LD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_L_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_L_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_L_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_LU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_LU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_LU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_U_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_U_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_U_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_R_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (3).png");
	//공격								   		
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_D_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_D_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_L_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_L_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_U_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_U_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RD (2).png");

	//세레비
	//이동
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_D_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_D_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_D_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_LD_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_LD_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_LD_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_L_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_L_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_L_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_LU_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_LU_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_LU_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_U_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_U_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_U_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_RU_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_RU_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_RU_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_R_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_R_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_R_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_RD_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_RD_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_WALK_RD_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_D_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_LD_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_L_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_LU_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_U_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_RU_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_R_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CELE_HURT_RD_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\RD (1).png");
	//단데기
	//이동
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_D_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_D_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_D_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_LD_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_LD_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_LD_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_L_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_L_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_L_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_LU_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_LU_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_LU_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_U_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_U_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_U_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_RU_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_RU_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_RU_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_R_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_R_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_R_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_RD_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_RD_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::META_WALK_RD_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_D_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_L_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_U_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_R_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::META_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\RD (1).png");


	//뚜벅쵸
	//이동
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_D_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_D_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_D_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_LD_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_LD_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_LD_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_L_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_L_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_L_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_LU_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_LU_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_LU_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_U_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_U_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_U_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_RU_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_RU_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_RU_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_R_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_R_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_R_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_RD_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_RD_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_WALK_RD_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_D_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_D_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_L_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_L_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_U_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_U_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_R_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_R_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RD (2).png");
	//스라크
	//이동
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_D_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_D_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_D_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_LD_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_LD_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_LD_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_L_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_L_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_L_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_LU_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_LU_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_LU_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_U_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_U_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_U_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_RU_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_RU_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_RU_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_R_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_R_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_R_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_RD_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_RD_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_WALK_RD_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RD (3).png");
	//공격
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_D_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_D_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_L_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_L_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_U_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_U_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_R_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_R_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SCY_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RD (2).png");
	//라플레시아
	//이동
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_D_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_D_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_D_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_LD_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_LD_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_LD_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_L_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_L_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_L_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_LU_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_LU_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_LU_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_U_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_U_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_U_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_RU_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_RU_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_RU_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_R_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_R_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_R_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_RD_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_RD_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_WALK_RD_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RD (3).png");
	//공격								   
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_D_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_D_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_L_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_L_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_U_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_U_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_R_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_R_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::VILE_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RD (2).png");
	//수속성
	//골덕
	//이동
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_D_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_D_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_D_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_LD_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_LD_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_LD_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_L_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_L_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_L_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_LU_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_LU_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_LU_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_U_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_U_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_U_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_RU_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_RU_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_RU_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_R_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_R_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_R_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_RD_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_RD_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_WALK_RD_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_D_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_D_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LD_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LD_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_L_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_L_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LU_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LU_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_U_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_U_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RU_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RU_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_R_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_R_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RD_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RD_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RD (2).png");
	//루주라
	//이동
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_D_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_D_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_D_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_LD_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_LD_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_LD_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_L_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_L_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_L_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_LU_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_LU_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_LU_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_U_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_U_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_U_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_RU_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_RU_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_RU_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_R_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_R_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_R_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_RD_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_RD_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_WALK_RD_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_D_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_D_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LD_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LD_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_L_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_L_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LU_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LU_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_U_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_U_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RU_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RU_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_R_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_R_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RD_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RD_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RD (2).png");

	//발챙이
	//이동
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_D_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_D_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_D_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_LD_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_LD_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_LD_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_L_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_L_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_L_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_LU_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_LU_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_LU_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_U_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_U_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_U_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_RU_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_RU_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_RU_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_R_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_R_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_R_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_RD_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_RD_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_WALK_RD_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_D_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_LD_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_L_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_LU_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_U_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_RU_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_R_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WAG_ATTACK_RD_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\RD (1).png");



	//강챙이
	//이동
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_D_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_D_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_D_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_LD_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_LD_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_LD_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_L_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_L_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_L_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_LU_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_LU_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_LU_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_U_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_U_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_U_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_RU_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_RU_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_RU_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_R_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_R_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_R_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_RD_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_RD_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_WALK_RD_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_D_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_D_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LD_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LD_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_L_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_L_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LU_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LU_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_U_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_U_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RU_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RU_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_R_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_R_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RD_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RD_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RD (2).png");

	//고라파덕
	//이동
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_D_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_D_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_D_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_LD_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_LD_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_LD_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_L_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_L_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_L_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_LU_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_LU_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_LU_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_U_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_U_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_U_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RU_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RU_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RU_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_R_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_R_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_R_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RD_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RD_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RD_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_D_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_D_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_LD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_LD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_L_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_L_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_LU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_LU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_U_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_U_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RU_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RU_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RU_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_R_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_R_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_R_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RD_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RD_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_WALK_RD_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_RU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_RU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_R_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_R_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_RD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK_RD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RD (2).png");
	//공격2
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_D_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_D_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_L_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_L_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_U_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_U_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_R_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_R_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RD (2).png");
	//스이쿤
	//이동
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_D_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_D_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_D_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_LD_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_LD_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_LD_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_L_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_L_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_L_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_LU_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_LU_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_LU_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_U_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_U_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_U_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_RU_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_RU_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_RU_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_R_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_R_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_R_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_RD_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_RD_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_WALK_RD_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_D_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_D_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_LD_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_LD_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_L_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_L_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_LU_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_LU_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_U_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_U_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_RU_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_RU_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_R_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_R_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_RD_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SUI_ATTACK_RD_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RD (2).png");
	//화속성
	//윈디
	//이동
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_D_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_D_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_D_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_LD_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_LD_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_LD_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_L_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_L_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_L_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_LU_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_LU_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_LU_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_U_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_U_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_U_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_RU_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_RU_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_RU_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_R_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_R_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_R_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_RD_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_RD_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_WALK_RD_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_D_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_D_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_L_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_L_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_U_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_U_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_R_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_R_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RD (2).png");
	//그란돈
	//이동
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_D_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_D_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_D_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_LD_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_LD_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_LD_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_L_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_L_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_L_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_LU_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_LU_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_LU_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_U_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_U_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_U_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_RU_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_RU_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_RU_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_R_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_R_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_R_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_RD_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_RD_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_WALK_RD_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_D_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_D_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_L_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_L_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_U_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_U_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_R_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_R_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROU_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RD (2).png");
	//가디
	//이동
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_D_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_D_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_D_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_LD_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_LD_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_LD_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_L_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_L_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_L_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_LU_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_LU_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_LU_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_U_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_U_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_U_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_RU_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_RU_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_RU_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_R_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_R_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_R_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_RD_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_RD_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_WALK_RD_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_D_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_D_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_L_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_L_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_U_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_U_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_R_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_R_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::GROW_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RD (2).png");
	//마그카르고
	//이동
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_D_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_D_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_D_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_LD_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_LD_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_LD_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_L_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_L_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_L_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_LU_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_LU_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_LU_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_U_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_U_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_U_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_RU_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_RU_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_RU_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_R_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_R_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_R_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_RD_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_RD_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_WALK_RD_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_D_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_D_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_L_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_L_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_U_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_U_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_R_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_R_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RD (2).png");
	//포니타
	//이동
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_D_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_D_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_D_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_LD_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_LD_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_LD_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_L_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_L_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_L_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_LU_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_LU_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_LU_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_U_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_U_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_U_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_RU_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_RU_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_RU_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_R_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_R_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_R_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_RD_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_RD_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_WALK_RD_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RD (3).png");
	//공격								   	 PONY
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_D_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_D_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_L_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_L_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_U_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_U_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_R_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_R_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PONY_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RD (2).png");
	//날쌩마
	//이동
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_D_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_D_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_D_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_LD_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_LD_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_LD_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_L_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_L_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_L_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_LU_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_LU_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_LU_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_U_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_U_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_U_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_RU_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_RU_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_RU_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_R_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_R_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_R_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_RD_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_RD_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_WALK_RD_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_D_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_D_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_L_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_L_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_U_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_U_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_R_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_R_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RD (2).png");
	//마그마그
	//이동
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_D_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_D_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_D_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\D (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_LD_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_LD_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_LD_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LD (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_L_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_L_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_L_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\L (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_LU_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_LU_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_LU_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_U_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_U_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_U_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\U (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_RU_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_RU_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_RU_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_R_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_R_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_R_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_RD_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_RD_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_WALK_RD_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RD (3).png");
	//공격								   	 
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_D_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\D (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_D_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\D (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_L_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\L (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_L_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\L (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_U_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\U (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_U_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\U (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_R_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_R_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RD (2).png");
}

void PKH::MainGame::LoadPlayerSprite()
{
	// == PG01 START ==
	// WALK
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_D_01, L"Texture\\Player\\Grass\\01\\WALK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_D_02, L"Texture\\Player\\Grass\\01\\WALK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_D_03, L"Texture\\Player\\Grass\\01\\WALK\\D\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_LD_01, L"Texture\\Player\\Grass\\01\\WALK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_LD_02, L"Texture\\Player\\Grass\\01\\WALK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_LD_03, L"Texture\\Player\\Grass\\01\\WALK\\LD\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_L_01, L"Texture\\Player\\Grass\\01\\WALK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_L_02, L"Texture\\Player\\Grass\\01\\WALK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_L_03, L"Texture\\Player\\Grass\\01\\WALK\\L\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_LU_01, L"Texture\\Player\\Grass\\01\\WALK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_LU_02, L"Texture\\Player\\Grass\\01\\WALK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_LU_03, L"Texture\\Player\\Grass\\01\\WALK\\LU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_U_01, L"Texture\\Player\\Grass\\01\\WALK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_U_02, L"Texture\\Player\\Grass\\01\\WALK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_U_03, L"Texture\\Player\\Grass\\01\\WALK\\U\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_RU_01, L"Texture\\Player\\Grass\\01\\WALK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_RU_02, L"Texture\\Player\\Grass\\01\\WALK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_RU_03, L"Texture\\Player\\Grass\\01\\WALK\\RU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_R_01, L"Texture\\Player\\Grass\\01\\WALK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_R_02, L"Texture\\Player\\Grass\\01\\WALK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_R_03, L"Texture\\Player\\Grass\\01\\WALK\\R\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_RD_01, L"Texture\\Player\\Grass\\01\\WALK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_RD_02, L"Texture\\Player\\Grass\\01\\WALK\\RD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_WALK_RD_03, L"Texture\\Player\\Grass\\01\\WALK\\RD\\2.png");

	// ATTACK
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_D_01, L"Texture\\Player\\Grass\\01\\ATTACK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_D_02, L"Texture\\Player\\Grass\\01\\ATTACK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_LD_01, L"Texture\\Player\\Grass\\01\\ATTACK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_LD_02, L"Texture\\Player\\Grass\\01\\ATTACK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_L_01, L"Texture\\Player\\Grass\\01\\ATTACK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_L_02, L"Texture\\Player\\Grass\\01\\ATTACK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_LU_01, L"Texture\\Player\\Grass\\01\\ATTACK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_LU_02, L"Texture\\Player\\Grass\\01\\ATTACK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_U_01, L"Texture\\Player\\Grass\\01\\ATTACK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_U_02, L"Texture\\Player\\Grass\\01\\ATTACK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_RU_01, L"Texture\\Player\\Grass\\01\\ATTACK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_RU_02, L"Texture\\Player\\Grass\\01\\ATTACK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_R_01, L"Texture\\Player\\Grass\\01\\ATTACK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_R_02, L"Texture\\Player\\Grass\\01\\ATTACK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_RD_01, L"Texture\\Player\\Grass\\01\\ATTACK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_ATTACK_RD_02, L"Texture\\Player\\Grass\\01\\ATTACK\\RD\\1.png");
	// == PG01 END ==

}