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
	
	//RenderManager::GetInstance();

	SceneManager::GetInstance();

	Camera::GetInstance();
	FileManager::GetInstance();
	Cursor::GetInstance();

	SoundManager::GetInstance()->Initialize();

    // 리소스 로드
	D2DRenderManager::LoadSprite(TextureKey::SKY_U, L"Texture\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_D, L"Texture\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_L, L"Texture\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_R, L"Texture\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_F, L"Texture\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_B, L"Texture\\SKYBOX_B.png");

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

	D2DRenderManager::LoadSprite(TextureKey::CURSOR_TARGET, L"Texture\\HUD_TARGET.png");
	D2DRenderManager::LoadSprite(TextureKey::LOCK_ON, L"Texture\\LOCK_ON.png");

	ObjectManager::GetInstance();

	// 씬로드
	SceneManager::LoadScene<TestScene>();

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
}

void PKH::MainGame::Update()
{
	InputManager::Update();
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

	SceneManager::Update();
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
