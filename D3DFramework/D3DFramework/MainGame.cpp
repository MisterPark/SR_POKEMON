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
	Network::GetInstance();
	Network::Initialize();
	LobbyWindow::GetInstance();
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
	SkillManager::GetInstance();

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
	
	Player::GetInstance()->PostUpdate();
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

void PKH::MainGame::LoadETCSprite()
{
	// 리소스 로드
	D2DRenderManager::LoadSprite(TextureKey::TITLE_SCREEN, L"Texture\\pokeTitle2.png");

	D2DRenderManager::LoadSprite(TextureKey::SKY_U, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_D, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_L, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_R, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_F, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKY_B, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::SKYDAY_U, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYDAY_D, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYDAY_L, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYDAY_R, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYDAY_F, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYDAY_B, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::SKYNIGHT_U, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYNIGHT_D, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYNIGHT_L, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYNIGHT_R, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYNIGHT_F, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYNIGHT_B, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::SPACE1_U, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SPACE1_D, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SPACE1_L, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SPACE1_R, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SPACE1_F, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SPACE1_B, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::SKYFIRE1_U, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYFIRE1_D, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYFIRE1_L, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYFIRE1_R, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYFIRE1_F, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYFIRE1_B, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::SKYBEACH1_U, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_U.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYBEACH1_D, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_D.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYBEACH1_L, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_L.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYBEACH1_R, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_R.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYBEACH1_F, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_F.png");
	D2DRenderManager::LoadSprite(TextureKey::SKYBEACH1_B, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_B.png");

	D2DRenderManager::LoadSprite(TextureKey::BLUE_FILTER, L"Texture\\BlueFilter.png");

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

	// 나뭇잎총알
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_01, L"Texture\\Player\\Bullet\\Leaf\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_02, L"Texture\\Player\\Bullet\\Leaf\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_03, L"Texture\\Player\\Bullet\\Leaf\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_04, L"Texture\\Player\\Bullet\\Leaf\\3.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_05, L"Texture\\Player\\Bullet\\Leaf\\4.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_06, L"Texture\\Player\\Bullet\\Leaf\\5.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_07, L"Texture\\Player\\Bullet\\Leaf\\6.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_08, L"Texture\\Player\\Bullet\\Leaf\\7.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LEAF_09, L"Texture\\Player\\Bullet\\Leaf\\8.png");

	// 발차기
	D2DRenderManager::LoadSprite(TextureKey::FIRE_KICK_01, L"Texture\\Player\\Effect\\FireKick\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_KICK_02, L"Texture\\Player\\Effect\\FireKick\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_KICK_03, L"Texture\\Player\\Effect\\FireKick\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_KICK_04, L"Texture\\Player\\Effect\\FireKick\\3.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_KICK_05, L"Texture\\Player\\Effect\\FireKick\\4.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_KICK_06, L"Texture\\Player\\Effect\\FireKick\\5.png");

	// 파이어 라운드
	D2DRenderManager::LoadSprite(TextureKey::FIRE_ROUND_01, L"Texture\\Player\\Effect\\FireRound\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_ROUND_02, L"Texture\\Player\\Effect\\FireRound\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_ROUND_03, L"Texture\\Player\\Effect\\FireRound\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_ROUND_04, L"Texture\\Player\\Effect\\FireRound\\3.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_ROUND_05, L"Texture\\Player\\Effect\\FireRound\\4.png");

	// 필드 파이어
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_01, L"Texture\\Player\\Effect\\FieldFire\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_02, L"Texture\\Player\\Effect\\FieldFire\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_03, L"Texture\\Player\\Effect\\FieldFire\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_04, L"Texture\\Player\\Effect\\FieldFire\\3.png");
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_05, L"Texture\\Player\\Effect\\FieldFire\\4.png");
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_06, L"Texture\\Player\\Effect\\FieldFire\\5.png");
	D2DRenderManager::LoadSprite(TextureKey::FIELD_FIRE_07, L"Texture\\Player\\Effect\\FieldFire\\6.png");

	// 불덩이총알
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE_01, L"Texture\\Player\\Bullet\\Fire\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE_02, L"Texture\\Player\\Bullet\\Fire\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE_03, L"Texture\\Player\\Bullet\\Fire\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE_04, L"Texture\\Player\\Bullet\\Fire\\3.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE_05, L"Texture\\Player\\Bullet\\Fire\\4.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE_06, L"Texture\\Player\\Bullet\\Fire\\5.png");

	// 불 폭발
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_01, L"Texture\\Player\\Effect\\Explosion\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_02, L"Texture\\Player\\Effect\\Explosion\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_03, L"Texture\\Player\\Effect\\Explosion\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_04, L"Texture\\Player\\Effect\\Explosion\\3.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_05, L"Texture\\Player\\Effect\\Explosion\\4.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_06, L"Texture\\Player\\Effect\\Explosion\\5.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_07, L"Texture\\Player\\Effect\\Explosion\\6.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_08, L"Texture\\Player\\Effect\\Explosion\\7.png");

	// 물대포총알
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER_01, L"Texture\\Player\\Bullet\\Water\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER_02, L"Texture\\Player\\Bullet\\Water\\1.png");

	//몬스터 총알
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_01, L"Texture\\Bullet\\Bubble1\\Bubble1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_02, L"Texture\\Bullet\\Bubble1\\Bubble1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_03, L"Texture\\Bullet\\Bubble1\\Bubble1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_04, L"Texture\\Bullet\\Bubble1\\Bubble1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_05, L"Texture\\Bullet\\Bubble1\\Bubble1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_06, L"Texture\\Bullet\\Bubble1\\Bubble1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_07, L"Texture\\Bullet\\Bubble1\\Bubble1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_08, L"Texture\\Bullet\\Bubble1\\Bubble1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_09, L"Texture\\Bullet\\Bubble1\\Bubble1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_10, L"Texture\\Bullet\\Bubble1\\Bubble1 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_11, L"Texture\\Bullet\\Bubble1\\Bubble1 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_12, L"Texture\\Bullet\\Bubble1\\Bubble1 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_13, L"Texture\\Bullet\\Bubble1\\Bubble1 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_14, L"Texture\\Bullet\\Bubble1\\Bubble1 (14).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_15, L"Texture\\Bullet\\Bubble1\\Bubble1 (15).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_16, L"Texture\\Bullet\\Bubble1\\Bubble1 (16).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_17, L"Texture\\Bullet\\Bubble1\\Bubble1 (17).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_18, L"Texture\\Bullet\\Bubble1\\Bubble1 (18).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_19, L"Texture\\Bullet\\Bubble1\\Bubble1 (19).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_20, L"Texture\\Bullet\\Bubble1\\Bubble1 (20).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_21, L"Texture\\Bullet\\Bubble1\\Bubble1 (21).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_01, L"Texture\\Bullet\\Fire1\\Fire1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_02, L"Texture\\Bullet\\Fire1\\Fire1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_03, L"Texture\\Bullet\\Fire1\\Fire1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_04, L"Texture\\Bullet\\Fire1\\Fire1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_05, L"Texture\\Bullet\\Fire1\\Fire1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_06, L"Texture\\Bullet\\Fire1\\Fire1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_07, L"Texture\\Bullet\\Fire1\\Fire1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_08, L"Texture\\Bullet\\Fire1\\Fire1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_09, L"Texture\\Bullet\\Fire1\\Fire1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_10, L"Texture\\Bullet\\Fire1\\Fire1 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_11, L"Texture\\Bullet\\Fire1\\Fire1 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_12, L"Texture\\Bullet\\Fire1\\Fire1 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_13, L"Texture\\Bullet\\Fire1\\Fire1 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_14, L"Texture\\Bullet\\Fire1\\Fire1 (14).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_15, L"Texture\\Bullet\\Fire1\\Fire1 (15).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_16, L"Texture\\Bullet\\Fire1\\Fire1 (16).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_17, L"Texture\\Bullet\\Fire1\\Fire1 (17).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_18, L"Texture\\Bullet\\Fire1\\Fire1 (18).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_19, L"Texture\\Bullet\\Fire1\\Fire1 (19).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_20, L"Texture\\Bullet\\Fire1\\Fire1 (20).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_21, L"Texture\\Bullet\\Fire1\\Fire1 (21).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE1_22, L"Texture\\Bullet\\Fire1\\Fire1 (22).png");
	
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_01, L"Texture\\Bullet\\Fire2\\Fire2 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_02, L"Texture\\Bullet\\Fire2\\Fire2 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_03, L"Texture\\Bullet\\Fire2\\Fire2 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_04, L"Texture\\Bullet\\Fire2\\Fire2 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_05, L"Texture\\Bullet\\Fire2\\Fire2 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_06, L"Texture\\Bullet\\Fire2\\Fire2 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE2_07, L"Texture\\Bullet\\Fire2\\Fire2 (7).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_01, L"Texture\\Bullet\\Fire3\\Fire3 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_02, L"Texture\\Bullet\\Fire3\\Fire3 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_03, L"Texture\\Bullet\\Fire3\\Fire3 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_04, L"Texture\\Bullet\\Fire3\\Fire3 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_05, L"Texture\\Bullet\\Fire3\\Fire3 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_06, L"Texture\\Bullet\\Fire3\\Fire3 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_07, L"Texture\\Bullet\\Fire3\\Fire3 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_08, L"Texture\\Bullet\\Fire3\\Fire3 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_09, L"Texture\\Bullet\\Fire3\\Fire3 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_10, L"Texture\\Bullet\\Fire3\\Fire3 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_11, L"Texture\\Bullet\\Fire3\\Fire3 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIRE3_12, L"Texture\\Bullet\\Fire3\\Fire3 (12).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_01, L"Texture\\Bullet\\FireWall1\\FireWall1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_02, L"Texture\\Bullet\\FireWall1\\FireWall1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_03, L"Texture\\Bullet\\FireWall1\\FireWall1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_04, L"Texture\\Bullet\\FireWall1\\FireWall1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_05, L"Texture\\Bullet\\FireWall1\\FireWall1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_06, L"Texture\\Bullet\\FireWall1\\FireWall1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_07, L"Texture\\Bullet\\FireWall1\\FireWall1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_08, L"Texture\\Bullet\\FireWall1\\FireWall1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_09, L"Texture\\Bullet\\FireWall1\\FireWall1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_10, L"Texture\\Bullet\\FireWall1\\FireWall1 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_11, L"Texture\\Bullet\\FireWall1\\FireWall1 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_12, L"Texture\\Bullet\\FireWall1\\FireWall1 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_13, L"Texture\\Bullet\\FireWall1\\FireWall1 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_14, L"Texture\\Bullet\\FireWall1\\FireWall1 (14).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_01, L"Texture\\Bullet\\Ice1\\Ice1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_02, L"Texture\\Bullet\\Ice1\\Ice1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_03, L"Texture\\Bullet\\Ice1\\Ice1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_04, L"Texture\\Bullet\\Ice1\\Ice1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_05, L"Texture\\Bullet\\Ice1\\Ice1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_06, L"Texture\\Bullet\\Ice1\\Ice1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_07, L"Texture\\Bullet\\Ice1\\Ice1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_08, L"Texture\\Bullet\\Ice1\\Ice1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_09, L"Texture\\Bullet\\Ice1\\Ice1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_10, L"Texture\\Bullet\\Ice1\\Ice1 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_11, L"Texture\\Bullet\\Ice1\\Ice1 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_12, L"Texture\\Bullet\\Ice1\\Ice1 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_13, L"Texture\\Bullet\\Ice1\\Ice1 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_14, L"Texture\\Bullet\\Ice1\\Ice1 (14).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_ICE1_15, L"Texture\\Bullet\\Ice1\\Ice1 (15).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_01, L"Texture\\Bullet\\LClaw1\\LClaw1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_02, L"Texture\\Bullet\\LClaw1\\LClaw1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_03, L"Texture\\Bullet\\LClaw1\\LClaw1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_04, L"Texture\\Bullet\\LClaw1\\LClaw1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_05, L"Texture\\Bullet\\LClaw1\\LClaw1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_06, L"Texture\\Bullet\\LClaw1\\LClaw1 (6).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_01, L"Texture\\Bullet\\Poision1\\Poison1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_02, L"Texture\\Bullet\\Poision1\\Poison1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_03, L"Texture\\Bullet\\Poision1\\Poison1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_04, L"Texture\\Bullet\\Poision1\\Poison1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_05, L"Texture\\Bullet\\Poision1\\Poison1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_06, L"Texture\\Bullet\\Poision1\\Poison1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_07, L"Texture\\Bullet\\Poision1\\Poison1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_08, L"Texture\\Bullet\\Poision1\\Poison1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_09, L"Texture\\Bullet\\Poision1\\Poison1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_10, L"Texture\\Bullet\\Poision1\\Poison1 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_11, L"Texture\\Bullet\\Poision1\\Poison1 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_12, L"Texture\\Bullet\\Poision1\\Poison1 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_13, L"Texture\\Bullet\\Poision1\\Poison1 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_14, L"Texture\\Bullet\\Poision1\\Poison1 (14).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_POISION1_15, L"Texture\\Bullet\\Poision1\\Poison1 (15).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_01, L"Texture\\Bullet\\RClaw1\\RClaw1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_02, L"Texture\\Bullet\\RClaw1\\RClaw1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_03, L"Texture\\Bullet\\RClaw1\\RClaw1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_04, L"Texture\\Bullet\\RClaw1\\RClaw1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_05, L"Texture\\Bullet\\RClaw1\\RClaw1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_06, L"Texture\\Bullet\\RClaw1\\RClaw1 (6).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER1_01, L"Texture\\Bullet\\Water1\\Water1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER1_02, L"Texture\\Bullet\\Water1\\Water1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER1_03, L"Texture\\Bullet\\Water1\\Water1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER1_04, L"Texture\\Bullet\\Water1\\Water1 (4).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_01, L"Texture\\Bullet\\Water2\\Water2 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_02, L"Texture\\Bullet\\Water2\\Water2 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_03, L"Texture\\Bullet\\Water2\\Water2 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_04, L"Texture\\Bullet\\Water2\\Water2 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_05, L"Texture\\Bullet\\Water2\\Water2 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_06, L"Texture\\Bullet\\Water2\\Water2 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_07, L"Texture\\Bullet\\Water2\\Water2 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_08, L"Texture\\Bullet\\Water2\\Water2 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_09, L"Texture\\Bullet\\Water2\\Water2 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_10, L"Texture\\Bullet\\Water2\\Water2 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_11, L"Texture\\Bullet\\Water2\\Water2 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_12, L"Texture\\Bullet\\Water2\\Water2 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_13, L"Texture\\Bullet\\Water2\\Water2 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_14, L"Texture\\Bullet\\Water2\\Water2 (14).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WATER2_15, L"Texture\\Bullet\\Water2\\Water2 (15).png");

	//WEB
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WEB1_01, L"Texture\\Bullet\\Web1\\Web1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WEB1_02, L"Texture\\Bullet\\Web1\\Web1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WEB1_03, L"Texture\\Bullet\\Web1\\Web1 (3).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_01, L"Texture\\Bullet\\Wind1\\Wind1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_02, L"Texture\\Bullet\\Wind1\\Wind1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_03, L"Texture\\Bullet\\Wind1\\Wind1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_04, L"Texture\\Bullet\\Wind1\\Wind1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_05, L"Texture\\Bullet\\Wind1\\Wind1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_06, L"Texture\\Bullet\\Wind1\\Wind1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_07, L"Texture\\Bullet\\Wind1\\Wind1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_08, L"Texture\\Bullet\\Wind1\\Wind1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_09, L"Texture\\Bullet\\Wind1\\Wind1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_10, L"Texture\\Bullet\\Wind1\\Wind1 (10).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_11, L"Texture\\Bullet\\Wind1\\Wind1 (11).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_12, L"Texture\\Bullet\\Wind1\\Wind1 (12).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_13, L"Texture\\Bullet\\Wind1\\Wind1 (13).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_14, L"Texture\\Bullet\\Wind1\\Wind1 (14).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_WIND1_15, L"Texture\\Bullet\\Wind1\\Wind1 (15).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_01, L"Texture\\Bullet\\Tornado1\\Tornado1 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_02, L"Texture\\Bullet\\Tornado1\\Tornado1 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_03, L"Texture\\Bullet\\Tornado1\\Tornado1 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_04, L"Texture\\Bullet\\Tornado1\\Tornado1 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_05, L"Texture\\Bullet\\Tornado1\\Tornado1 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_06, L"Texture\\Bullet\\Tornado1\\Tornado1 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_07, L"Texture\\Bullet\\Tornado1\\Tornado1 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_08, L"Texture\\Bullet\\Tornado1\\Tornado1 (8).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_09, L"Texture\\Bullet\\Tornado1\\Tornado1 (9).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_10, L"Texture\\Bullet\\Tornado1\\Tornado1 (10).png");

	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_01, L"Texture\\Bullet\\Tornado2\\Tornado2 (1).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_02, L"Texture\\Bullet\\Tornado2\\Tornado2 (2).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_03, L"Texture\\Bullet\\Tornado2\\Tornado2 (3).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_04, L"Texture\\Bullet\\Tornado2\\Tornado2 (4).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_05, L"Texture\\Bullet\\Tornado2\\Tornado2 (5).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_06, L"Texture\\Bullet\\Tornado2\\Tornado2 (6).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_07, L"Texture\\Bullet\\Tornado2\\Tornado2 (7).png");
	D2DRenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_08, L"Texture\\Bullet\\Tornado2\\Tornado2 (8).png");


	D2DRenderManager::LoadSprite(TextureKey::TREE01, L"Texture\\ETC\\Tree\\Tree (1).png");
	D2DRenderManager::LoadSprite(TextureKey::TREE02, L"Texture\\ETC\\Tree\\Tree (2).png");
	D2DRenderManager::LoadSprite(TextureKey::TREE03, L"Texture\\ETC\\Tree\\Tree (3).png");
	D2DRenderManager::LoadSprite(TextureKey::TREE04, L"Texture\\ETC\\Tree\\Tree (4).png");
	D2DRenderManager::LoadSprite(TextureKey::TREE05, L"Texture\\ETC\\Tree\\Tree (5).png");
	D2DRenderManager::LoadSprite(TextureKey::TREE06, L"Texture\\ETC\\Tree\\Tree (6).png");

	D2DRenderManager::LoadSprite(TextureKey::PALMTREE01, L"Texture\\ETC\\PalmTree\\PalmTree (1).png");
	D2DRenderManager::LoadSprite(TextureKey::PALMTREE02, L"Texture\\ETC\\PalmTree\\PalmTree (2).png");
	D2DRenderManager::LoadSprite(TextureKey::PALMTREE03, L"Texture\\ETC\\PalmTree\\PalmTree (3).png");
	D2DRenderManager::LoadSprite(TextureKey::PALMTREE04, L"Texture\\ETC\\PalmTree\\PalmTree (4).png");

	//RANGE
	D2DRenderManager::LoadSprite(TextureKey::RANGE, L"Texture\\Bullet\\Range\\Range.png");

	//MAP TEXTURE
	D2DRenderManager::LoadSprite(TextureKey::GRASS_MAP2, L"Texture\\Grass.png");
	D2DRenderManager::LoadSprite(TextureKey::GRASS_MAP, L"Texture\\Grass.png");
	D2DRenderManager::LoadSprite(TextureKey::WATER_MAP, L"Texture\\Sand.png");
	D2DRenderManager::LoadSprite(TextureKey::BROOK_MAP, L"Texture\\Brook.png");
	D2DRenderManager::LoadSprite(TextureKey::VOLCANO_MAP, L"Texture\\Volcano.png");
	
	//WATERENVIRONMENT
	D2DRenderManager::LoadSprite(TextureKey::GRASS_WATER_ENVIRONMENT, L"Texture\\WATER.png");
	D2DRenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT, L"Texture\\WATER2.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_WATER_ENVIRONMENT, L"Texture\\Lava.png");


	//
	D2DRenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT01, L"Texture\\WATER1.png");
	D2DRenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT02, L"Texture\\WATER2.png");
	D2DRenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT03, L"Texture\\WATER3.png");

	D2DRenderManager::LoadSprite(TextureKey::FIRE_WATER_ENVIRONMENT01, L"Texture\\LAVA1.png");
	D2DRenderManager::LoadSprite(TextureKey::FIRE_WATER_ENVIRONMENT02, L"Texture\\LAVA2.png");
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
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_R_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (3).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_WALK_RD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (3).png");
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
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RU (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RU (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\R (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\R (2).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RD (1).png");
	D2DRenderManager::LoadSprite(TextureKey::CATER_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RD (2).png");

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

	// SKILL
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_D_01, L"Texture\\Player\\Grass\\01\\SKILL\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_D_02, L"Texture\\Player\\Grass\\01\\SKILL\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_LD_01, L"Texture\\Player\\Grass\\01\\SKILL\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_LD_02, L"Texture\\Player\\Grass\\01\\SKILL\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_L_01, L"Texture\\Player\\Grass\\01\\SKILL\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_L_02, L"Texture\\Player\\Grass\\01\\SKILL\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_LU_01, L"Texture\\Player\\Grass\\01\\SKILL\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_LU_02, L"Texture\\Player\\Grass\\01\\SKILL\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_U_01, L"Texture\\Player\\Grass\\01\\SKILL\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_U_02, L"Texture\\Player\\Grass\\01\\SKILL\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_RU_01, L"Texture\\Player\\Grass\\01\\SKILL\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_RU_02, L"Texture\\Player\\Grass\\01\\SKILL\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_R_01, L"Texture\\Player\\Grass\\01\\SKILL\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_R_02, L"Texture\\Player\\Grass\\01\\SKILL\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_RD_01, L"Texture\\Player\\Grass\\01\\SKILL\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG01_SKILL_RD_02, L"Texture\\Player\\Grass\\01\\SKILL\\RD\\1.png");

	// == PG01 END ==

	// == PG02 START ==
	// WALK
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_D_01, L"Texture\\Player\\Grass\\02\\WALK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_D_02, L"Texture\\Player\\Grass\\02\\WALK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_D_03, L"Texture\\Player\\Grass\\02\\WALK\\D\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_LD_01, L"Texture\\Player\\Grass\\02\\WALK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_LD_02, L"Texture\\Player\\Grass\\02\\WALK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_LD_03, L"Texture\\Player\\Grass\\02\\WALK\\LD\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_L_01, L"Texture\\Player\\Grass\\02\\WALK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_L_02, L"Texture\\Player\\Grass\\02\\WALK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_L_03, L"Texture\\Player\\Grass\\02\\WALK\\L\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_LU_01, L"Texture\\Player\\Grass\\02\\WALK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_LU_02, L"Texture\\Player\\Grass\\02\\WALK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_LU_03, L"Texture\\Player\\Grass\\02\\WALK\\LU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_U_01, L"Texture\\Player\\Grass\\02\\WALK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_U_02, L"Texture\\Player\\Grass\\02\\WALK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_U_03, L"Texture\\Player\\Grass\\02\\WALK\\U\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_RU_01, L"Texture\\Player\\Grass\\02\\WALK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_RU_02, L"Texture\\Player\\Grass\\02\\WALK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_RU_03, L"Texture\\Player\\Grass\\02\\WALK\\RU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_R_01, L"Texture\\Player\\Grass\\02\\WALK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_R_02, L"Texture\\Player\\Grass\\02\\WALK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_R_03, L"Texture\\Player\\Grass\\02\\WALK\\R\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_RD_01, L"Texture\\Player\\Grass\\02\\WALK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_RD_02, L"Texture\\Player\\Grass\\02\\WALK\\RD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_WALK_RD_03, L"Texture\\Player\\Grass\\02\\WALK\\RD\\2.png");

	// ATTACK
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_D_01, L"Texture\\Player\\Grass\\02\\ATTACK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_D_02, L"Texture\\Player\\Grass\\02\\ATTACK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_LD_01, L"Texture\\Player\\Grass\\02\\ATTACK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_LD_02, L"Texture\\Player\\Grass\\02\\ATTACK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_L_01, L"Texture\\Player\\Grass\\02\\ATTACK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_L_02, L"Texture\\Player\\Grass\\02\\ATTACK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_LU_01, L"Texture\\Player\\Grass\\02\\ATTACK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_LU_02, L"Texture\\Player\\Grass\\02\\ATTACK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_U_01, L"Texture\\Player\\Grass\\02\\ATTACK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_U_02, L"Texture\\Player\\Grass\\02\\ATTACK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_RU_01, L"Texture\\Player\\Grass\\02\\ATTACK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_RU_02, L"Texture\\Player\\Grass\\02\\ATTACK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_R_01, L"Texture\\Player\\Grass\\02\\ATTACK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_R_02, L"Texture\\Player\\Grass\\02\\ATTACK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_RD_01, L"Texture\\Player\\Grass\\02\\ATTACK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_ATTACK_RD_02, L"Texture\\Player\\Grass\\02\\ATTACK\\RD\\1.png");
	
	// SKILL
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_D_01, L"Texture\\Player\\Grass\\02\\SKILL\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_D_02, L"Texture\\Player\\Grass\\02\\SKILL\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_LD_01, L"Texture\\Player\\Grass\\02\\SKILL\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_LD_02, L"Texture\\Player\\Grass\\02\\SKILL\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_L_01, L"Texture\\Player\\Grass\\02\\SKILL\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_L_02, L"Texture\\Player\\Grass\\02\\SKILL\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_LU_01, L"Texture\\Player\\Grass\\02\\SKILL\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_LU_02, L"Texture\\Player\\Grass\\02\\SKILL\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_U_01, L"Texture\\Player\\Grass\\02\\SKILL\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_U_02, L"Texture\\Player\\Grass\\02\\SKILL\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_RU_01, L"Texture\\Player\\Grass\\02\\SKILL\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_RU_02, L"Texture\\Player\\Grass\\02\\SKILL\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_R_01, L"Texture\\Player\\Grass\\02\\SKILL\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_R_02, L"Texture\\Player\\Grass\\02\\SKILL\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_RD_01, L"Texture\\Player\\Grass\\02\\SKILL\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG02_SKILL_RD_02, L"Texture\\Player\\Grass\\02\\SKILL\\RD\\1.png");
	// == PG02 END ==

	// == PG03 START ==
	// WALK
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_D_01, L"Texture\\Player\\Grass\\03\\WALK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_D_02, L"Texture\\Player\\Grass\\03\\WALK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_D_03, L"Texture\\Player\\Grass\\03\\WALK\\D\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_LD_01, L"Texture\\Player\\Grass\\03\\WALK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_LD_02, L"Texture\\Player\\Grass\\03\\WALK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_LD_03, L"Texture\\Player\\Grass\\03\\WALK\\LD\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_L_01, L"Texture\\Player\\Grass\\03\\WALK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_L_02, L"Texture\\Player\\Grass\\03\\WALK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_L_03, L"Texture\\Player\\Grass\\03\\WALK\\L\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_LU_01, L"Texture\\Player\\Grass\\03\\WALK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_LU_02, L"Texture\\Player\\Grass\\03\\WALK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_LU_03, L"Texture\\Player\\Grass\\03\\WALK\\LU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_U_01, L"Texture\\Player\\Grass\\03\\WALK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_U_02, L"Texture\\Player\\Grass\\03\\WALK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_U_03, L"Texture\\Player\\Grass\\03\\WALK\\U\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_RU_01, L"Texture\\Player\\Grass\\03\\WALK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_RU_02, L"Texture\\Player\\Grass\\03\\WALK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_RU_03, L"Texture\\Player\\Grass\\03\\WALK\\RU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_R_01, L"Texture\\Player\\Grass\\03\\WALK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_R_02, L"Texture\\Player\\Grass\\03\\WALK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_R_03, L"Texture\\Player\\Grass\\03\\WALK\\R\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_RD_01, L"Texture\\Player\\Grass\\03\\WALK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_RD_02, L"Texture\\Player\\Grass\\03\\WALK\\RD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_WALK_RD_03, L"Texture\\Player\\Grass\\03\\WALK\\RD\\2.png");

	// ATTACK
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_D_01, L"Texture\\Player\\Grass\\03\\ATTACK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_D_02, L"Texture\\Player\\Grass\\03\\ATTACK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_LD_01, L"Texture\\Player\\Grass\\03\\ATTACK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_LD_02, L"Texture\\Player\\Grass\\03\\ATTACK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_L_01, L"Texture\\Player\\Grass\\03\\ATTACK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_L_02, L"Texture\\Player\\Grass\\03\\ATTACK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_LU_01, L"Texture\\Player\\Grass\\03\\ATTACK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_LU_02, L"Texture\\Player\\Grass\\03\\ATTACK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_U_01, L"Texture\\Player\\Grass\\03\\ATTACK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_U_02, L"Texture\\Player\\Grass\\03\\ATTACK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_RU_01, L"Texture\\Player\\Grass\\03\\ATTACK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_RU_02, L"Texture\\Player\\Grass\\03\\ATTACK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_R_01, L"Texture\\Player\\Grass\\03\\ATTACK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_R_02, L"Texture\\Player\\Grass\\03\\ATTACK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_RD_01, L"Texture\\Player\\Grass\\03\\ATTACK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_ATTACK_RD_02, L"Texture\\Player\\Grass\\03\\ATTACK\\RD\\1.png");
	
	// SKILL
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_D_01, L"Texture\\Player\\Grass\\03\\SKILL\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_D_02, L"Texture\\Player\\Grass\\03\\SKILL\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_LD_01, L"Texture\\Player\\Grass\\03\\SKILL\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_LD_02, L"Texture\\Player\\Grass\\03\\SKILL\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_L_01, L"Texture\\Player\\Grass\\03\\SKILL\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_L_02, L"Texture\\Player\\Grass\\03\\SKILL\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_LU_01, L"Texture\\Player\\Grass\\03\\SKILL\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_LU_02, L"Texture\\Player\\Grass\\03\\SKILL\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_U_01, L"Texture\\Player\\Grass\\03\\SKILL\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_U_02, L"Texture\\Player\\Grass\\03\\SKILL\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_RU_01, L"Texture\\Player\\Grass\\03\\SKILL\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_RU_02, L"Texture\\Player\\Grass\\03\\SKILL\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_R_01, L"Texture\\Player\\Grass\\03\\SKILL\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_R_02, L"Texture\\Player\\Grass\\03\\SKILL\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_RD_01, L"Texture\\Player\\Grass\\03\\SKILL\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PG03_SKILL_RD_02, L"Texture\\Player\\Grass\\03\\SKILL\\RD\\1.png");
	// == PG03 END ==

	// == PF01 START ==
	// WALK
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_D_01, L"Texture\\Player\\Fire\\01\\WALK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_D_02, L"Texture\\Player\\Fire\\01\\WALK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_D_03, L"Texture\\Player\\Fire\\01\\WALK\\D\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_LD_01, L"Texture\\Player\\Fire\\01\\WALK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_LD_02, L"Texture\\Player\\Fire\\01\\WALK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_LD_03, L"Texture\\Player\\Fire\\01\\WALK\\LD\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_L_01, L"Texture\\Player\\Fire\\01\\WALK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_L_02, L"Texture\\Player\\Fire\\01\\WALK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_L_03, L"Texture\\Player\\Fire\\01\\WALK\\L\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_LU_01, L"Texture\\Player\\Fire\\01\\WALK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_LU_02, L"Texture\\Player\\Fire\\01\\WALK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_LU_03, L"Texture\\Player\\Fire\\01\\WALK\\LU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_U_01, L"Texture\\Player\\Fire\\01\\WALK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_U_02, L"Texture\\Player\\Fire\\01\\WALK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_U_03, L"Texture\\Player\\Fire\\01\\WALK\\U\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_RU_01, L"Texture\\Player\\Fire\\01\\WALK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_RU_02, L"Texture\\Player\\Fire\\01\\WALK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_RU_03, L"Texture\\Player\\Fire\\01\\WALK\\RU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_R_01, L"Texture\\Player\\Fire\\01\\WALK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_R_02, L"Texture\\Player\\Fire\\01\\WALK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_R_03, L"Texture\\Player\\Fire\\01\\WALK\\R\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_RD_01, L"Texture\\Player\\Fire\\01\\WALK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_RD_02, L"Texture\\Player\\Fire\\01\\WALK\\RD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_WALK_RD_03, L"Texture\\Player\\Fire\\01\\WALK\\RD\\2.png");

	// ATTACK
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_D_01, L"Texture\\Player\\Fire\\01\\ATTACK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_LD_01, L"Texture\\Player\\Fire\\01\\ATTACK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_L_01, L"Texture\\Player\\Fire\\01\\ATTACK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_LU_01, L"Texture\\Player\\Fire\\01\\ATTACK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_U_01, L"Texture\\Player\\Fire\\01\\ATTACK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_RU_01, L"Texture\\Player\\Fire\\01\\ATTACK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_R_01, L"Texture\\Player\\Fire\\01\\ATTACK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_ATTACK_RD_01, L"Texture\\Player\\Fire\\01\\ATTACK\\RD\\0.png");

	// SKILL
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_D_01, L"Texture\\Player\\Fire\\01\\SKILL\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_D_02, L"Texture\\Player\\Fire\\01\\SKILL\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_LD_01, L"Texture\\Player\\Fire\\01\\SKILL\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_LD_02, L"Texture\\Player\\Fire\\01\\SKILL\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_L_01, L"Texture\\Player\\Fire\\01\\SKILL\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_L_02, L"Texture\\Player\\Fire\\01\\SKILL\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_LU_01, L"Texture\\Player\\Fire\\01\\SKILL\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_LU_02, L"Texture\\Player\\Fire\\01\\SKILL\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_U_01, L"Texture\\Player\\Fire\\01\\SKILL\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_U_02, L"Texture\\Player\\Fire\\01\\SKILL\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_RU_01, L"Texture\\Player\\Fire\\01\\SKILL\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_RU_02, L"Texture\\Player\\Fire\\01\\SKILL\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_R_01, L"Texture\\Player\\Fire\\01\\SKILL\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_R_02, L"Texture\\Player\\Fire\\01\\SKILL\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_RD_01, L"Texture\\Player\\Fire\\01\\SKILL\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF01_SKILL_RD_02, L"Texture\\Player\\Fire\\01\\SKILL\\RD\\1.png");
	// == PF01 END ==

	// == PF02 START ==
	// WALK
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_D_01, L"Texture\\Player\\Fire\\02\\WALK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_D_02, L"Texture\\Player\\Fire\\02\\WALK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_D_03, L"Texture\\Player\\Fire\\02\\WALK\\D\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_LD_01, L"Texture\\Player\\Fire\\02\\WALK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_LD_02, L"Texture\\Player\\Fire\\02\\WALK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_LD_03, L"Texture\\Player\\Fire\\02\\WALK\\LD\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_L_01, L"Texture\\Player\\Fire\\02\\WALK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_L_02, L"Texture\\Player\\Fire\\02\\WALK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_L_03, L"Texture\\Player\\Fire\\02\\WALK\\L\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_LU_01, L"Texture\\Player\\Fire\\02\\WALK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_LU_02, L"Texture\\Player\\Fire\\02\\WALK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_LU_03, L"Texture\\Player\\Fire\\02\\WALK\\LU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_U_01, L"Texture\\Player\\Fire\\02\\WALK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_U_02, L"Texture\\Player\\Fire\\02\\WALK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_U_03, L"Texture\\Player\\Fire\\02\\WALK\\U\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_RU_01, L"Texture\\Player\\Fire\\02\\WALK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_RU_02, L"Texture\\Player\\Fire\\02\\WALK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_RU_03, L"Texture\\Player\\Fire\\02\\WALK\\RU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_R_01, L"Texture\\Player\\Fire\\02\\WALK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_R_02, L"Texture\\Player\\Fire\\02\\WALK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_R_03, L"Texture\\Player\\Fire\\02\\WALK\\R\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_RD_01, L"Texture\\Player\\Fire\\02\\WALK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_RD_02, L"Texture\\Player\\Fire\\02\\WALK\\RD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_WALK_RD_03, L"Texture\\Player\\Fire\\02\\WALK\\RD\\2.png");

	// ATTACK
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_D_01, L"Texture\\Player\\Fire\\02\\ATTACK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_D_02, L"Texture\\Player\\Fire\\02\\ATTACK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_LD_01, L"Texture\\Player\\Fire\\02\\ATTACK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_LD_02, L"Texture\\Player\\Fire\\02\\ATTACK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_L_01, L"Texture\\Player\\Fire\\02\\ATTACK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_L_02, L"Texture\\Player\\Fire\\02\\ATTACK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_LU_01, L"Texture\\Player\\Fire\\02\\ATTACK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_LU_02, L"Texture\\Player\\Fire\\02\\ATTACK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_U_01, L"Texture\\Player\\Fire\\02\\ATTACK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_U_02, L"Texture\\Player\\Fire\\02\\ATTACK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_RU_01, L"Texture\\Player\\Fire\\02\\ATTACK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_RU_02, L"Texture\\Player\\Fire\\02\\ATTACK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_R_01, L"Texture\\Player\\Fire\\02\\ATTACK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_R_02, L"Texture\\Player\\Fire\\02\\ATTACK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_RD_01, L"Texture\\Player\\Fire\\02\\ATTACK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_ATTACK_RD_02, L"Texture\\Player\\Fire\\02\\ATTACK\\RD\\1.png");

	// SKILL
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_D_01, L"Texture\\Player\\Fire\\02\\SKILL\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_D_02, L"Texture\\Player\\Fire\\02\\SKILL\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_LD_01, L"Texture\\Player\\Fire\\02\\SKILL\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_LD_02, L"Texture\\Player\\Fire\\02\\SKILL\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_L_01, L"Texture\\Player\\Fire\\02\\SKILL\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_L_02, L"Texture\\Player\\Fire\\02\\SKILL\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_LU_01, L"Texture\\Player\\Fire\\02\\SKILL\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_LU_02, L"Texture\\Player\\Fire\\02\\SKILL\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_U_01, L"Texture\\Player\\Fire\\02\\SKILL\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_U_02, L"Texture\\Player\\Fire\\02\\SKILL\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_RU_01, L"Texture\\Player\\Fire\\02\\SKILL\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_RU_02, L"Texture\\Player\\Fire\\02\\SKILL\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_R_01, L"Texture\\Player\\Fire\\02\\SKILL\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_R_02, L"Texture\\Player\\Fire\\02\\SKILL\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_RD_01, L"Texture\\Player\\Fire\\02\\SKILL\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF02_SKILL_RD_02, L"Texture\\Player\\Fire\\02\\SKILL\\RD\\1.png");
	// == PF02 END ==

	// == PF03 START ==
	// WALK
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_D_01, L"Texture\\Player\\Fire\\03\\WALK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_D_02, L"Texture\\Player\\Fire\\03\\WALK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_D_03, L"Texture\\Player\\Fire\\03\\WALK\\D\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_LD_01, L"Texture\\Player\\Fire\\03\\WALK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_LD_02, L"Texture\\Player\\Fire\\03\\WALK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_LD_03, L"Texture\\Player\\Fire\\03\\WALK\\LD\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_L_01, L"Texture\\Player\\Fire\\03\\WALK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_L_02, L"Texture\\Player\\Fire\\03\\WALK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_L_03, L"Texture\\Player\\Fire\\03\\WALK\\L\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_LU_01, L"Texture\\Player\\Fire\\03\\WALK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_LU_02, L"Texture\\Player\\Fire\\03\\WALK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_LU_03, L"Texture\\Player\\Fire\\03\\WALK\\LU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_U_01, L"Texture\\Player\\Fire\\03\\WALK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_U_02, L"Texture\\Player\\Fire\\03\\WALK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_U_03, L"Texture\\Player\\Fire\\03\\WALK\\U\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_RU_01, L"Texture\\Player\\Fire\\03\\WALK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_RU_02, L"Texture\\Player\\Fire\\03\\WALK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_RU_03, L"Texture\\Player\\Fire\\03\\WALK\\RU\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_R_01, L"Texture\\Player\\Fire\\03\\WALK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_R_02, L"Texture\\Player\\Fire\\03\\WALK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_R_03, L"Texture\\Player\\Fire\\03\\WALK\\R\\2.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_RD_01, L"Texture\\Player\\Fire\\03\\WALK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_RD_02, L"Texture\\Player\\Fire\\03\\WALK\\RD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_WALK_RD_03, L"Texture\\Player\\Fire\\03\\WALK\\RD\\2.png");

	// ATTACK
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_D_01, L"Texture\\Player\\Fire\\03\\ATTACK\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_D_02, L"Texture\\Player\\Fire\\03\\ATTACK\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_LD_01, L"Texture\\Player\\Fire\\03\\ATTACK\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_LD_02, L"Texture\\Player\\Fire\\03\\ATTACK\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_L_01, L"Texture\\Player\\Fire\\03\\ATTACK\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_L_02, L"Texture\\Player\\Fire\\03\\ATTACK\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_LU_01, L"Texture\\Player\\Fire\\03\\ATTACK\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_LU_02, L"Texture\\Player\\Fire\\03\\ATTACK\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_U_01, L"Texture\\Player\\Fire\\03\\ATTACK\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_U_02, L"Texture\\Player\\Fire\\03\\ATTACK\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_RU_01, L"Texture\\Player\\Fire\\03\\ATTACK\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_RU_02, L"Texture\\Player\\Fire\\03\\ATTACK\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_R_01, L"Texture\\Player\\Fire\\03\\ATTACK\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_R_02, L"Texture\\Player\\Fire\\03\\ATTACK\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_RD_01, L"Texture\\Player\\Fire\\03\\ATTACK\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_ATTACK_RD_02, L"Texture\\Player\\Fire\\03\\ATTACK\\RD\\1.png");

	// SKILL
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_D_01, L"Texture\\Player\\Fire\\03\\SKILL\\D\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_D_02, L"Texture\\Player\\Fire\\03\\SKILL\\D\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_LD_01, L"Texture\\Player\\Fire\\03\\SKILL\\LD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_LD_02, L"Texture\\Player\\Fire\\03\\SKILL\\LD\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_L_01, L"Texture\\Player\\Fire\\03\\SKILL\\L\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_L_02, L"Texture\\Player\\Fire\\03\\SKILL\\L\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_LU_01, L"Texture\\Player\\Fire\\03\\SKILL\\LU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_LU_02, L"Texture\\Player\\Fire\\03\\SKILL\\LU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_U_01, L"Texture\\Player\\Fire\\03\\SKILL\\U\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_U_02, L"Texture\\Player\\Fire\\03\\SKILL\\U\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_RU_01, L"Texture\\Player\\Fire\\03\\SKILL\\RU\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_RU_02, L"Texture\\Player\\Fire\\03\\SKILL\\RU\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_R_01, L"Texture\\Player\\Fire\\03\\SKILL\\R\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_R_02, L"Texture\\Player\\Fire\\03\\SKILL\\R\\1.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_RD_01, L"Texture\\Player\\Fire\\03\\SKILL\\RD\\0.png");
	D2DRenderManager::LoadSprite(TextureKey::PF03_SKILL_RD_02, L"Texture\\Player\\Fire\\03\\SKILL\\RD\\1.png");
	// == PF03 END ==
}