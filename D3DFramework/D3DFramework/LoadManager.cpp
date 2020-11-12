#include "stdafx.h"
#include "LoadManager.h"

LoadManager* pLoadManager = nullptr;

LoadManager::LoadManager()
{
	pRenderMgr = RenderManager::GetInstance();
	isFinish = false;
	percent = 0.f;
	text = L"";
}

LoadManager::~LoadManager()
{
    Release();
}

LoadManager* LoadManager::GetInstance()
{
    if (pLoadManager == nullptr)
    {
        pLoadManager = new LoadManager;
    }
    return pLoadManager;
}

void LoadManager::Destroy()
{
    if (pLoadManager)
    {
        delete pLoadManager;
        pLoadManager = nullptr;
    }
}

void LoadManager::Initialize()
{
	if (pLoadManager->hThread != INVALID_HANDLE_VALUE)
		CloseHandle(pLoadManager->hThread);
	pLoadManager->isFinish = false;
	pLoadManager->percent = 0.f;
	pLoadManager->text = L"";
}

void LoadManager::Release()
{
    //WaitForSingleObject(pLoadManager->hThread, INFINITE);
    CloseHandle(pLoadManager->hThread);
}

bool LoadManager::IsFinish()
{
    return pLoadManager->isFinish;
}

float LoadManager::GetProgress()
{
    return pLoadManager->percent;
}

wstring LoadManager::GetText()
{
    return pLoadManager->text;
}

unsigned int __stdcall LoadManager::LodingThread(void* arg)
{
    LoadManager* loadManager = (LoadManager*)arg;
    
    loadManager->LoadAll();
    
    return 0;
}

void LoadManager::LoadResources()
{
    pLoadManager->hThread = (HANDLE)_beginthreadex(NULL, 0, LodingThread, pLoadManager, 0, nullptr);

}

void LoadManager::LoadAll()
{
	
	pLoadManager->text = L"Loading Monster...";
	pLoadManager->percent = 0.f;
	pLoadManager->LoadMonsterSprite();
	pLoadManager->text = L"Loading Player...";
	pLoadManager->percent = 0.25f;
	pLoadManager->LoadPlayerSprite();
	pLoadManager->text = L"Loading NPC...";
	pLoadManager->percent = 0.5f;
	pLoadManager->LoadNPCSprite();
	pLoadManager->text = L"Loading ETC...";
	pLoadManager->percent = 0.75f;
	pLoadManager->LoadETCSprite();
    pLoadManager->text = L"Press Enter...";
    pLoadManager->percent = 1.f;
    pLoadManager->isFinish = true;
}

void LoadManager::LoadETCSprite()
{
	RenderManager::LoadSprite(TextureKey::SKY_U, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKY_D, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKY_L, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKY_R, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKY_F, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKY_B, L"Texture\\ETC\\Skybox\\SkyNormal\\SKYBOX_B.png");
	
	RenderManager::LoadSprite(TextureKey::SKYDAY_U, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY_D, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY_L, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY_R, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY_F, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY_B, L"Texture\\ETC\\Skybox\\SkyDay\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYDAY1_U, L"Texture\\ETC\\Skybox\\SkyDay1\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY1_D, L"Texture\\ETC\\Skybox\\SkyDay1\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY1_L, L"Texture\\ETC\\Skybox\\SkyDay1\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY1_R, L"Texture\\ETC\\Skybox\\SkyDay1\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY1_F, L"Texture\\ETC\\Skybox\\SkyDay1\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYDAY1_B, L"Texture\\ETC\\Skybox\\SkyDay1\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYNIGHT_U, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYNIGHT_D, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYNIGHT_L, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYNIGHT_R, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYNIGHT_F, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYNIGHT_B, L"Texture\\ETC\\Skybox\\SkyNight\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYBLUE_U, L"Texture\\ETC\\Skybox\\SkyBlue\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE_D, L"Texture\\ETC\\Skybox\\SkyBlue\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE_L, L"Texture\\ETC\\Skybox\\SkyBlue\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE_R, L"Texture\\ETC\\Skybox\\SkyBlue\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE_F, L"Texture\\ETC\\Skybox\\SkyBlue\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE_B, L"Texture\\ETC\\Skybox\\SkyBlue\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYBLUE1_U, L"Texture\\ETC\\Skybox\\SkyBlue1\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE1_D, L"Texture\\ETC\\Skybox\\SkyBlue1\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE1_L, L"Texture\\ETC\\Skybox\\SkyBlue1\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE1_R, L"Texture\\ETC\\Skybox\\SkyBlue1\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE1_F, L"Texture\\ETC\\Skybox\\SkyBlue1\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYBLUE1_B, L"Texture\\ETC\\Skybox\\SkyBlue1\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SPACE1_U, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SPACE1_D, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SPACE1_L, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SPACE1_R, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SPACE1_F, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SPACE1_B, L"Texture\\ETC\\Skybox\\Space1\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYFIRE1_U, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYFIRE1_D, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYFIRE1_L, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYFIRE1_R, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYFIRE1_F, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYFIRE1_B, L"Texture\\ETC\\Skybox\\SkyFire1\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYBEACH1_U, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH1_D, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH1_L, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH1_R, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH1_F, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH1_B, L"Texture\\ETC\\Skybox\\SkyBeach1\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::SKYBEACH2_U, L"Texture\\ETC\\Skybox\\SkyBeach2\\SKYBOX_U.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH2_D, L"Texture\\ETC\\Skybox\\SkyBeach2\\SKYBOX_D.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH2_L, L"Texture\\ETC\\Skybox\\SkyBeach2\\SKYBOX_L.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH2_R, L"Texture\\ETC\\Skybox\\SkyBeach2\\SKYBOX_R.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH2_F, L"Texture\\ETC\\Skybox\\SkyBeach2\\SKYBOX_F.png");
	RenderManager::LoadSprite(TextureKey::SKYBEACH2_B, L"Texture\\ETC\\Skybox\\SkyBeach2\\SKYBOX_B.png");

	RenderManager::LoadSprite(TextureKey::UI_ARROW, L"Texture\\UI\\KeyUI\\Arrow.png");
	RenderManager::LoadSprite(TextureKey::UI_LBUTTON, L"Texture\\UI\\KeyUI\\LButton.png");
	RenderManager::LoadSprite(TextureKey::UI_MBUTTON, L"Texture\\UI\\KeyUI\\MButton.png");
	RenderManager::LoadSprite(TextureKey::UI_RBUTTON, L"Texture\\UI\\KeyUI\\RButton.png");
	RenderManager::LoadSprite(TextureKey::UI_MOUSE, L"Texture\\UI\\KeyUI\\Mouse.png");
	RenderManager::LoadSprite(TextureKey::UI_RETURN, L"Texture\\UI\\KeyUI\\Return.png");
	RenderManager::LoadSprite(TextureKey::UI_SPACE, L"Texture\\UI\\KeyUI\\Space.png");
	RenderManager::LoadSprite(TextureKey::UI_I, L"Texture\\UI\\KeyUI\\I.png");
	RenderManager::LoadSprite(TextureKey::UI_F, L"Texture\\UI\\KeyUI\\F.png");
	//코인
	RenderManager::LoadSprite(TextureKey::RING_01, L"Texture\\UI\\Coin\\Ring_01.png");
	RenderManager::LoadSprite(TextureKey::RING_02, L"Texture\\UI\\Coin\\Ring_02.png");
	RenderManager::LoadSprite(TextureKey::RING_03, L"Texture\\UI\\Coin\\Ring_03.png");
	RenderManager::LoadSprite(TextureKey::RING_04, L"Texture\\UI\\Coin\\Ring_04.png");
	RenderManager::LoadSprite(TextureKey::RING_05, L"Texture\\UI\\Coin\\Ring_05.png");
	RenderManager::LoadSprite(TextureKey::RING_06, L"Texture\\UI\\Coin\\Ring_06.png");
	RenderManager::LoadSprite(TextureKey::RING_07, L"Texture\\UI\\Coin\\Ring_07.png");
	RenderManager::LoadSprite(TextureKey::RING_08, L"Texture\\UI\\Coin\\Ring_08.png");
	RenderManager::LoadSprite(TextureKey::RING_09, L"Texture\\UI\\Coin\\Ring_09.png");
	RenderManager::LoadSprite(TextureKey::RING_10, L"Texture\\UI\\Coin\\Ring_10.png");
	RenderManager::LoadSprite(TextureKey::RING_11, L"Texture\\UI\\Coin\\Ring_11.png");
	RenderManager::LoadSprite(TextureKey::RING_12, L"Texture\\UI\\Coin\\Ring_12.png");
	RenderManager::LoadSprite(TextureKey::RING_13, L"Texture\\UI\\Coin\\Ring_13.png");
	RenderManager::LoadSprite(TextureKey::RING_14, L"Texture\\UI\\Coin\\Ring_14.png");
	RenderManager::LoadSprite(TextureKey::RING_15, L"Texture\\UI\\Coin\\Ring_15.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_1, L"Texture\\UI\\Coin\\coinpoke1.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_2, L"Texture\\UI\\Coin\\coinpoke2.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_3, L"Texture\\UI\\Coin\\coinpoke3.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_4, L"Texture\\UI\\Coin\\coinpoke4.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_5, L"Texture\\UI\\Coin\\coinpoke5.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_6, L"Texture\\UI\\Coin\\coinpoke6.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_7, L"Texture\\UI\\Coin\\coinpoke7.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_8, L"Texture\\UI\\Coin\\coinpoke8.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_9, L"Texture\\UI\\Coin\\coinpoke9.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_10, L"Texture\\UI\\Coin\\coinpoke10.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_11, L"Texture\\UI\\Coin\\coinpoke11.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_12, L"Texture\\UI\\Coin\\coinpoke12.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_13, L"Texture\\UI\\Coin\\coinpoke13.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_14, L"Texture\\UI\\Coin\\coinpoke14.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_15, L"Texture\\UI\\Coin\\coinpoke13.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_16, L"Texture\\UI\\Coin\\coinpoke12.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_17, L"Texture\\UI\\Coin\\coinpoke11.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_18, L"Texture\\UI\\Coin\\coinpoke10.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_19, L"Texture\\UI\\Coin\\coinpoke9.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_20, L"Texture\\UI\\Coin\\coinpoke8.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_21, L"Texture\\UI\\Coin\\coinpoke7.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_22, L"Texture\\UI\\Coin\\coinpoke6.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_23, L"Texture\\UI\\Coin\\coinpoke5.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_24, L"Texture\\UI\\Coin\\coinpoke4.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_25, L"Texture\\UI\\Coin\\coinpoke3.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_26, L"Texture\\UI\\Coin\\coinpoke2.png");
	RenderManager::LoadSprite(TextureKey::COINPOKE_27, L"Texture\\UI\\Coin\\coinpoke1.png");

	//연기 (변신)
	RenderManager::LoadSprite(TextureKey::SMOKE_01, L"Texture\\Effect\\Smoke\\Smoke_01.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_02, L"Texture\\Effect\\Smoke\\Smoke_02.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_03, L"Texture\\Effect\\Smoke\\Smoke_03.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_04, L"Texture\\Effect\\Smoke\\Smoke_04.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_05, L"Texture\\Effect\\Smoke\\Smoke_05.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_06, L"Texture\\Effect\\Smoke\\Smoke_06.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_07, L"Texture\\Effect\\Smoke\\Smoke_07.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_08, L"Texture\\Effect\\Smoke\\Smoke_08.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_09, L"Texture\\Effect\\Smoke\\Smoke_09.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_10, L"Texture\\Effect\\Smoke\\Smoke_10.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_11, L"Texture\\Effect\\Smoke\\Smoke_11.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_12, L"Texture\\Effect\\Smoke\\Smoke_12.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_13, L"Texture\\Effect\\Smoke\\Smoke_13.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_14, L"Texture\\Effect\\Smoke\\Smoke_14.png");
	RenderManager::LoadSprite(TextureKey::SMOKE_15, L"Texture\\Effect\\Smoke\\Smoke_15.png");

	//속성
	RenderManager::LoadSprite(TextureKey::PROPERTY_FIRE, L"Texture\\ETC\\Property\\Fire (1).png");
	RenderManager::LoadSprite(TextureKey::PROPERTY_ICE, L"Texture\\ETC\\Property\\Ice (1).png");
	RenderManager::LoadSprite(TextureKey::PROPERTY_BUG, L"Texture\\ETC\\Property\\Bug (1).png");
	RenderManager::LoadSprite(TextureKey::PROPERTY_DARK, L"Texture\\ETC\\Property\\Dark (1).png");
	RenderManager::LoadSprite(TextureKey::PROPERTY_GRASS, L"Texture\\ETC\\Property\\Grass (1).png");
	RenderManager::LoadSprite(TextureKey::PROPERTY_WATER, L"Texture\\ETC\\Property\\Water (1).png");
	//포탈

	RenderManager::LoadSprite(TextureKey::PORTAL_01, L"Texture\\ETC\\Portal\\Portal (1).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_02, L"Texture\\ETC\\Portal\\Portal (2).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_03, L"Texture\\ETC\\Portal\\Portal (3).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_04, L"Texture\\ETC\\Portal\\Portal (4).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_05, L"Texture\\ETC\\Portal\\Portal (5).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_06, L"Texture\\ETC\\Portal\\Portal (6).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_07, L"Texture\\ETC\\Portal\\Portal (7).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_08, L"Texture\\ETC\\Portal\\Portal (8).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_09, L"Texture\\ETC\\Portal\\Portal (9).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_10, L"Texture\\ETC\\Portal\\Portal (10).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_11, L"Texture\\ETC\\Portal\\Portal (11).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_12, L"Texture\\ETC\\Portal\\Portal (12).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_13, L"Texture\\ETC\\Portal\\Portal (13).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_14, L"Texture\\ETC\\Portal\\Portal (14).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_15, L"Texture\\ETC\\Portal\\Portal (15).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_16, L"Texture\\ETC\\Portal\\Portal (16).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_17, L"Texture\\ETC\\Portal\\Portal (17).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_18, L"Texture\\ETC\\Portal\\Portal (18).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_19, L"Texture\\ETC\\Portal\\Portal (19).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_20, L"Texture\\ETC\\Portal\\Portal (20).png");
	RenderManager::LoadSprite(TextureKey::PORTAL_21, L"Texture\\ETC\\Portal\\Portal (21).png");


	//눈물총알
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_01, L"Texture\\Bullet\\Bullet_Tears01.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_02, L"Texture\\Bullet\\Bullet_Tears02.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_03, L"Texture\\Bullet\\Bullet_Tears03.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_04, L"Texture\\Bullet\\Bullet_Tears04.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_05, L"Texture\\Bullet\\Bullet_Tears05.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_06, L"Texture\\Bullet\\Bullet_Tears06.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_07, L"Texture\\Bullet\\Bullet_Tears07.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_08, L"Texture\\Bullet\\Bullet_Tears08.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_09, L"Texture\\Bullet\\Bullet_Tears09.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_10, L"Texture\\Bullet\\Bullet_Tears10.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_11, L"Texture\\Bullet\\Bullet_Tears11.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_12, L"Texture\\Bullet\\Bullet_Tears12.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_13, L"Texture\\Bullet\\Bullet_Tears13.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_14, L"Texture\\Bullet\\Bullet_Tears14.png");
	RenderManager::LoadSprite(TextureKey::BULLET_TEARS_15, L"Texture\\Bullet\\Bullet_Tears15.png");

	// 나뭇잎총알
	RenderManager::LoadSprite(TextureKey::BULLET_LEAF_01, L"Texture\\Player\\Bullet\\Leaf\\0.png");
	RenderManager::LoadSprite(TextureKey::BULLET_LEAF_02, L"Texture\\Player\\Bullet\\Leaf\\1.png");
	RenderManager::LoadSprite(TextureKey::BULLET_LEAF_03, L"Texture\\Player\\Bullet\\Leaf\\2.png");
	RenderManager::LoadSprite(TextureKey::BULLET_LEAF_04, L"Texture\\Player\\Bullet\\Leaf\\3.png");

	// 파이어 라운드
	RenderManager::LoadSprite(TextureKey::FIRE_ROUND_01, L"Texture\\Player\\Effect\\FireRound\\0.png");
	RenderManager::LoadSprite(TextureKey::FIRE_ROUND_02, L"Texture\\Player\\Effect\\FireRound\\1.png");
	RenderManager::LoadSprite(TextureKey::FIRE_ROUND_03, L"Texture\\Player\\Effect\\FireRound\\2.png");
	RenderManager::LoadSprite(TextureKey::FIRE_ROUND_04, L"Texture\\Player\\Effect\\FireRound\\3.png");
	RenderManager::LoadSprite(TextureKey::FIRE_ROUND_05, L"Texture\\Player\\Effect\\FireRound\\4.png");

	// 필드 파이어
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_01, L"Texture\\Player\\Effect\\FieldFire\\0.png");
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_02, L"Texture\\Player\\Effect\\FieldFire\\1.png");
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_03, L"Texture\\Player\\Effect\\FieldFire\\2.png");
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_04, L"Texture\\Player\\Effect\\FieldFire\\3.png");
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_05, L"Texture\\Player\\Effect\\FieldFire\\4.png");
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_06, L"Texture\\Player\\Effect\\FieldFire\\5.png");
	RenderManager::LoadSprite(TextureKey::FIELD_FIRE_07, L"Texture\\Player\\Effect\\FieldFire\\6.png");

	// 불덩이총알
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE_01, L"Texture\\Player\\Bullet\\Fire\\0.png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE_02, L"Texture\\Player\\Bullet\\Fire\\1.png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE_03, L"Texture\\Player\\Bullet\\Fire\\2.png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE_04, L"Texture\\Player\\Bullet\\Fire\\3.png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE_05, L"Texture\\Player\\Bullet\\Fire\\4.png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE_06, L"Texture\\Player\\Bullet\\Fire\\5.png");

	// 불 폭발
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_01, L"Texture\\Player\\Effect\\Explosion\\0.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_02, L"Texture\\Player\\Effect\\Explosion\\1.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_03, L"Texture\\Player\\Effect\\Explosion\\2.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_04, L"Texture\\Player\\Effect\\Explosion\\3.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_05, L"Texture\\Player\\Effect\\Explosion\\4.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_06, L"Texture\\Player\\Effect\\Explosion\\5.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_07, L"Texture\\Player\\Effect\\Explosion\\6.png");
	RenderManager::LoadSprite(TextureKey::FIRE_EXPLOSION_08, L"Texture\\Player\\Effect\\Explosion\\7.png");

	// 물대포총알
	RenderManager::LoadSprite(TextureKey::BULLET_WATER_01, L"Texture\\Player\\Bullet\\Water\\0.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER_02, L"Texture\\Player\\Bullet\\Water\\1.png");

	// X 클로
	RenderManager::LoadSprite(TextureKey::X_CLAW_01, L"Texture\\Player\\Effect\\XClaw\\0.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_02, L"Texture\\Player\\Effect\\XClaw\\1.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_03, L"Texture\\Player\\Effect\\XClaw\\2.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_04, L"Texture\\Player\\Effect\\XClaw\\3.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_05, L"Texture\\Player\\Effect\\XClaw\\4.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_06, L"Texture\\Player\\Effect\\XClaw\\5.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_07, L"Texture\\Player\\Effect\\XClaw\\6.png");
	RenderManager::LoadSprite(TextureKey::X_CLAW_08, L"Texture\\Player\\Effect\\XClaw\\7.png");

	// 메테오
	RenderManager::LoadSprite(TextureKey::METEOR_01, L"Texture\\Player\\Effect\\Meteor\\0.png");
	RenderManager::LoadSprite(TextureKey::METEOR_02, L"Texture\\Player\\Effect\\Meteor\\1.png");
	RenderManager::LoadSprite(TextureKey::METEOR_03, L"Texture\\Player\\Effect\\Meteor\\2.png");
	RenderManager::LoadSprite(TextureKey::METEOR_04, L"Texture\\Player\\Effect\\Meteor\\3.png");

	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_01, L"Texture\\Player\\Effect\\MeteorExplosion\\0.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_02, L"Texture\\Player\\Effect\\MeteorExplosion\\1.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_03, L"Texture\\Player\\Effect\\MeteorExplosion\\2.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_04, L"Texture\\Player\\Effect\\MeteorExplosion\\3.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_05, L"Texture\\Player\\Effect\\MeteorExplosion\\4.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_06, L"Texture\\Player\\Effect\\MeteorExplosion\\5.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_07, L"Texture\\Player\\Effect\\MeteorExplosion\\6.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_08, L"Texture\\Player\\Effect\\MeteorExplosion\\7.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_09, L"Texture\\Player\\Effect\\MeteorExplosion\\8.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_10, L"Texture\\Player\\Effect\\MeteorExplosion\\9.png");
	RenderManager::LoadSprite(TextureKey::METEOR_EXPLOSION_11, L"Texture\\Player\\Effect\\MeteorExplosion\\10.png");

	// 씨뿌리기
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_01, L"Texture\\Player\\Effect\\Seed\\0.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_02, L"Texture\\Player\\Effect\\LeechSeed\\0.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_03, L"Texture\\Player\\Effect\\LeechSeed\\1.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_04, L"Texture\\Player\\Effect\\LeechSeed\\2.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_05, L"Texture\\Player\\Effect\\LeechSeed\\3.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_06, L"Texture\\Player\\Effect\\LeechSeed\\4.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_07, L"Texture\\Player\\Effect\\LeechSeed\\5.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_08, L"Texture\\Player\\Effect\\LeechSeed\\6.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_09, L"Texture\\Player\\Effect\\LeechSeed\\7.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_10, L"Texture\\Player\\Effect\\LeechSeed\\8.png");
	RenderManager::LoadSprite(TextureKey::LEECH_SEED_11, L"Texture\\Player\\Effect\\LeechSeed\\9.png");

	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_01, L"Texture\\Player\\Effect\\LeechSeed\\9.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_02, L"Texture\\Player\\Effect\\LeechSeed\\8.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_03, L"Texture\\Player\\Effect\\LeechSeed\\7.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_04, L"Texture\\Player\\Effect\\LeechSeed\\6.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_05, L"Texture\\Player\\Effect\\LeechSeed\\5.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_06, L"Texture\\Player\\Effect\\LeechSeed\\4.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_07, L"Texture\\Player\\Effect\\LeechSeed\\3.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_08, L"Texture\\Player\\Effect\\LeechSeed\\2.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_09, L"Texture\\Player\\Effect\\LeechSeed\\1.png");
	RenderManager::LoadSprite(TextureKey::R_LEECH_SEED_10, L"Texture\\Player\\Effect\\LeechSeed\\0.png");

	// 꽃보라
	RenderManager::LoadSprite(TextureKey::PETAL_01, L"Texture\\Player\\Effect\\Petal\\0.png");
	RenderManager::LoadSprite(TextureKey::PETAL_02, L"Texture\\Player\\Effect\\Petal\\1.png");
	RenderManager::LoadSprite(TextureKey::PETAL_03, L"Texture\\Player\\Effect\\Petal\\2.png");
	RenderManager::LoadSprite(TextureKey::PETAL_04, L"Texture\\Player\\Effect\\Petal\\3.png");
	RenderManager::LoadSprite(TextureKey::PETAL_05, L"Texture\\Player\\Effect\\Petal\\4.png");
	RenderManager::LoadSprite(TextureKey::PETAL_06, L"Texture\\Player\\Effect\\Petal\\5.png");


	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_01, L"Texture\\Player\\Effect\\PetalBlizzard\\0.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_02, L"Texture\\Player\\Effect\\PetalBlizzard\\1.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_03, L"Texture\\Player\\Effect\\PetalBlizzard\\2.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_04, L"Texture\\Player\\Effect\\PetalBlizzard\\3.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_05, L"Texture\\Player\\Effect\\PetalBlizzard\\4.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_06, L"Texture\\Player\\Effect\\PetalBlizzard\\5.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_07, L"Texture\\Player\\Effect\\PetalBlizzard\\6.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_08, L"Texture\\Player\\Effect\\PetalBlizzard\\7.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_09, L"Texture\\Player\\Effect\\PetalBlizzard\\8.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_10, L"Texture\\Player\\Effect\\PetalBlizzard\\9.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_11, L"Texture\\Player\\Effect\\PetalBlizzard\\10.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_12, L"Texture\\Player\\Effect\\PetalBlizzard\\11.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_13, L"Texture\\Player\\Effect\\PetalBlizzard\\12.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_14, L"Texture\\Player\\Effect\\PetalBlizzard\\13.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_15, L"Texture\\Player\\Effect\\PetalBlizzard\\14.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_16, L"Texture\\Player\\Effect\\PetalBlizzard\\15.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_17, L"Texture\\Player\\Effect\\PetalBlizzard\\16.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_18, L"Texture\\Player\\Effect\\PetalBlizzard\\17.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_19, L"Texture\\Player\\Effect\\PetalBlizzard\\18.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_20, L"Texture\\Player\\Effect\\PetalBlizzard\\19.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_21, L"Texture\\Player\\Effect\\PetalBlizzard\\20.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_22, L"Texture\\Player\\Effect\\PetalBlizzard\\21.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_23, L"Texture\\Player\\Effect\\PetalBlizzard\\22.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_24, L"Texture\\Player\\Effect\\PetalBlizzard\\23.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_25, L"Texture\\Player\\Effect\\PetalBlizzard\\24.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EFFECT_26, L"Texture\\Player\\Effect\\PetalBlizzard\\25.png");

	RenderManager::LoadSprite(TextureKey::PETAL_EXPLOSION_01, L"Texture\\Player\\Effect\\PetalExplosion\\0.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EXPLOSION_02, L"Texture\\Player\\Effect\\PetalExplosion\\1.png");
	RenderManager::LoadSprite(TextureKey::PETAL_EXPLOSION_03, L"Texture\\Player\\Effect\\PetalExplosion\\2.png");

	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_01, L"Texture\\Player\\Effect\\LeafDissolve\\0.png");
	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_02, L"Texture\\Player\\Effect\\LeafDissolve\\1.png");
	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_03, L"Texture\\Player\\Effect\\LeafDissolve\\2.png");
	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_04, L"Texture\\Player\\Effect\\LeafDissolve\\3.png");
	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_05, L"Texture\\Player\\Effect\\LeafDissolve\\4.png");
	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_06, L"Texture\\Player\\Effect\\LeafDissolve\\5.png");
	RenderManager::LoadSprite(TextureKey::LEAF_DISSOLVE_07, L"Texture\\Player\\Effect\\LeafDissolve\\6.png");

	RenderManager::LoadSprite(TextureKey::YELLOW_FLASH_01, L"Texture\\Player\\Effect\\YellowFlash\\0.png");
	RenderManager::LoadSprite(TextureKey::YELLOW_FLASH_02, L"Texture\\Player\\Effect\\YellowFlash\\1.png");
	RenderManager::LoadSprite(TextureKey::YELLOW_FLASH_03, L"Texture\\Player\\Effect\\YellowFlash\\2.png");

	RenderManager::LoadSprite(TextureKey::FIRE_AURA_01, L"Texture\\Player\\Effect\\FireAura\\0.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_02, L"Texture\\Player\\Effect\\FireAura\\1.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_03, L"Texture\\Player\\Effect\\FireAura\\2.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_04, L"Texture\\Player\\Effect\\FireAura\\3.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_05, L"Texture\\Player\\Effect\\FireAura\\4.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_06, L"Texture\\Player\\Effect\\FireAura\\5.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_07, L"Texture\\Player\\Effect\\FireAura\\6.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_08, L"Texture\\Player\\Effect\\FireAura\\7.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_09, L"Texture\\Player\\Effect\\FireAura\\8.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_10, L"Texture\\Player\\Effect\\FireAura\\9.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_11, L"Texture\\Player\\Effect\\FireAura\\10.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_12, L"Texture\\Player\\Effect\\FireAura\\11.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_13, L"Texture\\Player\\Effect\\FireAura\\12.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_14, L"Texture\\Player\\Effect\\FireAura\\13.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_15, L"Texture\\Player\\Effect\\FireAura\\14.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_16, L"Texture\\Player\\Effect\\FireAura\\15.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_17, L"Texture\\Player\\Effect\\FireAura\\16.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_18, L"Texture\\Player\\Effect\\FireAura\\17.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_19, L"Texture\\Player\\Effect\\FireAura\\18.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_20, L"Texture\\Player\\Effect\\FireAura\\19.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_21, L"Texture\\Player\\Effect\\FireAura\\20.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_22, L"Texture\\Player\\Effect\\FireAura\\21.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_23, L"Texture\\Player\\Effect\\FireAura\\22.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_24, L"Texture\\Player\\Effect\\FireAura\\23.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_25, L"Texture\\Player\\Effect\\FireAura\\24.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_26, L"Texture\\Player\\Effect\\FireAura\\25.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_27, L"Texture\\Player\\Effect\\FireAura\\26.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_28, L"Texture\\Player\\Effect\\FireAura\\27.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_29, L"Texture\\Player\\Effect\\FireAura\\28.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_30, L"Texture\\Player\\Effect\\FireAura\\29.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_31, L"Texture\\Player\\Effect\\FireAura\\30.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_32, L"Texture\\Player\\Effect\\FireAura\\31.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_33, L"Texture\\Player\\Effect\\FireAura\\32.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_34, L"Texture\\Player\\Effect\\FireAura\\33.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_35, L"Texture\\Player\\Effect\\FireAura\\34.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_36, L"Texture\\Player\\Effect\\FireAura\\35.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_37, L"Texture\\Player\\Effect\\FireAura\\36.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_38, L"Texture\\Player\\Effect\\FireAura\\37.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_39, L"Texture\\Player\\Effect\\FireAura\\38.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_40, L"Texture\\Player\\Effect\\FireAura\\39.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_41, L"Texture\\Player\\Effect\\FireAura\\40.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_42, L"Texture\\Player\\Effect\\FireAura\\41.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_43, L"Texture\\Player\\Effect\\FireAura\\42.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_44, L"Texture\\Player\\Effect\\FireAura\\43.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_45, L"Texture\\Player\\Effect\\FireAura\\44.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_46, L"Texture\\Player\\Effect\\FireAura\\45.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_47, L"Texture\\Player\\Effect\\FireAura\\46.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_48, L"Texture\\Player\\Effect\\FireAura\\47.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_49, L"Texture\\Player\\Effect\\FireAura\\48.png");
	RenderManager::LoadSprite(TextureKey::FIRE_AURA_50, L"Texture\\Player\\Effect\\FireAura\\49.png");

	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_01, L"Texture\\Player\\Effect\\Bell\\0.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_02, L"Texture\\Player\\Effect\\Bell\\1.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_03, L"Texture\\Player\\Effect\\Bell\\2.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_04, L"Texture\\Player\\Effect\\Bell\\3.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_05, L"Texture\\Player\\Effect\\Bell\\4.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_06, L"Texture\\Player\\Effect\\Bell\\5.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_07, L"Texture\\Player\\Effect\\Bell\\6.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_08, L"Texture\\Player\\Effect\\Bell\\7.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_09, L"Texture\\Player\\Effect\\Bell\\8.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_10, L"Texture\\Player\\Effect\\Bell\\9.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_11, L"Texture\\Player\\Effect\\Bell\\10.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_12, L"Texture\\Player\\Effect\\Bell\\11.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_13, L"Texture\\Player\\Effect\\Bell\\12.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_14, L"Texture\\Player\\Effect\\Bell\\13.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_15, L"Texture\\Player\\Effect\\Bell\\14.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_16, L"Texture\\Player\\Effect\\Bell\\15.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_17, L"Texture\\Player\\Effect\\Bell\\16.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_18, L"Texture\\Player\\Effect\\Bell\\17.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_19, L"Texture\\Player\\Effect\\Bell\\18.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_20, L"Texture\\Player\\Effect\\Bell\\19.png");
	RenderManager::LoadSprite(TextureKey::BELL_EFFECT_21, L"Texture\\Player\\Effect\\Bell\\20.png");


	RenderManager::LoadSprite(TextureKey::POP_01, L"Texture\\ETC\\3Pop\\Pop (1).png");
	RenderManager::LoadSprite(TextureKey::POP_02, L"Texture\\ETC\\3Pop\\Pop (2).png");
	RenderManager::LoadSprite(TextureKey::POP_03, L"Texture\\ETC\\3Pop\\Pop (3).png");
	RenderManager::LoadSprite(TextureKey::POP_04, L"Texture\\ETC\\3Pop\\Pop (4).png");
	RenderManager::LoadSprite(TextureKey::POP_05, L"Texture\\ETC\\3Pop\\Pop (5).png");
	RenderManager::LoadSprite(TextureKey::POP_06, L"Texture\\ETC\\3Pop\\Pop (6).png");
	RenderManager::LoadSprite(TextureKey::POP_07, L"Texture\\ETC\\3Pop\\Pop (7).png");
	RenderManager::LoadSprite(TextureKey::POP_08, L"Texture\\ETC\\3Pop\\Pop (8).png");
	RenderManager::LoadSprite(TextureKey::POP_09, L"Texture\\ETC\\3Pop\\Pop (9).png");
	RenderManager::LoadSprite(TextureKey::POP_10, L"Texture\\ETC\\3Pop\\Pop (10).png");
	RenderManager::LoadSprite(TextureKey::POP_11, L"Texture\\ETC\\3Pop\\Pop (11).png");
	RenderManager::LoadSprite(TextureKey::POP_12, L"Texture\\ETC\\3Pop\\Pop (12).png");
	RenderManager::LoadSprite(TextureKey::POP_13, L"Texture\\ETC\\3Pop\\Pop (13).png");
	RenderManager::LoadSprite(TextureKey::POP_14, L"Texture\\ETC\\3Pop\\Pop (14).png");
	RenderManager::LoadSprite(TextureKey::POP_15, L"Texture\\ETC\\3Pop\\Pop (15).png");
	RenderManager::LoadSprite(TextureKey::POP_16, L"Texture\\ETC\\3Pop\\Pop (15).png");
	RenderManager::LoadSprite(TextureKey::POP_17, L"Texture\\ETC\\3Pop\\Pop (16).png");
	RenderManager::LoadSprite(TextureKey::POP_18, L"Texture\\ETC\\3Pop\\Pop (18).png");
	RenderManager::LoadSprite(TextureKey::POP_19, L"Texture\\ETC\\3Pop\\Pop (19).png");
	RenderManager::LoadSprite(TextureKey::POP_20, L"Texture\\ETC\\3Pop\\Pop (20).png");
	RenderManager::LoadSprite(TextureKey::POP_21, L"Texture\\ETC\\3Pop\\Pop (21).png");
	RenderManager::LoadSprite(TextureKey::POP_22, L"Texture\\ETC\\3Pop\\Pop (22).png");
	RenderManager::LoadSprite(TextureKey::POP_23, L"Texture\\ETC\\3Pop\\Pop (23).png");
	RenderManager::LoadSprite(TextureKey::POP_24, L"Texture\\ETC\\3Pop\\Pop (24).png");
	RenderManager::LoadSprite(TextureKey::POP_25, L"Texture\\ETC\\3Pop\\Pop (25).png");
	RenderManager::LoadSprite(TextureKey::POP_26, L"Texture\\ETC\\3Pop\\Pop (25).png");
	RenderManager::LoadSprite(TextureKey::POP_27, L"Texture\\ETC\\3Pop\\Pop (26).png");
	RenderManager::LoadSprite(TextureKey::POP_28, L"Texture\\ETC\\3Pop\\Pop (28).png");
	RenderManager::LoadSprite(TextureKey::POP_29, L"Texture\\ETC\\3Pop\\Pop (29).png");
	RenderManager::LoadSprite(TextureKey::POP_30, L"Texture\\ETC\\3Pop\\Pop (30).png");
	RenderManager::LoadSprite(TextureKey::POP_31, L"Texture\\ETC\\3Pop\\Pop (31).png");
	RenderManager::LoadSprite(TextureKey::POP_32, L"Texture\\ETC\\3Pop\\Pop (32).png");
	RenderManager::LoadSprite(TextureKey::POP_33, L"Texture\\ETC\\3Pop\\Pop (33).png");
	RenderManager::LoadSprite(TextureKey::POP_34, L"Texture\\ETC\\3Pop\\Pop (34).png");


	//몬스터 총알
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_01, L"Texture\\Bullet\\Bubble1\\Bubble1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_02, L"Texture\\Bullet\\Bubble1\\Bubble1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_03, L"Texture\\Bullet\\Bubble1\\Bubble1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_04, L"Texture\\Bullet\\Bubble1\\Bubble1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_05, L"Texture\\Bullet\\Bubble1\\Bubble1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_06, L"Texture\\Bullet\\Bubble1\\Bubble1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_07, L"Texture\\Bullet\\Bubble1\\Bubble1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_08, L"Texture\\Bullet\\Bubble1\\Bubble1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_09, L"Texture\\Bullet\\Bubble1\\Bubble1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_10, L"Texture\\Bullet\\Bubble1\\Bubble1 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_11, L"Texture\\Bullet\\Bubble1\\Bubble1 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_12, L"Texture\\Bullet\\Bubble1\\Bubble1 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_13, L"Texture\\Bullet\\Bubble1\\Bubble1 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_14, L"Texture\\Bullet\\Bubble1\\Bubble1 (14).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_15, L"Texture\\Bullet\\Bubble1\\Bubble1 (15).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_16, L"Texture\\Bullet\\Bubble1\\Bubble1 (16).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_17, L"Texture\\Bullet\\Bubble1\\Bubble1 (17).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_18, L"Texture\\Bullet\\Bubble1\\Bubble1 (18).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_19, L"Texture\\Bullet\\Bubble1\\Bubble1 (19).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_20, L"Texture\\Bullet\\Bubble1\\Bubble1 (20).png");
	RenderManager::LoadSprite(TextureKey::BULLET_BUBBLE1_21, L"Texture\\Bullet\\Bubble1\\Bubble1 (21).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_01, L"Texture\\Bullet\\Fire1\\Fire1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_02, L"Texture\\Bullet\\Fire1\\Fire1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_03, L"Texture\\Bullet\\Fire1\\Fire1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_04, L"Texture\\Bullet\\Fire1\\Fire1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_05, L"Texture\\Bullet\\Fire1\\Fire1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_06, L"Texture\\Bullet\\Fire1\\Fire1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_07, L"Texture\\Bullet\\Fire1\\Fire1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_08, L"Texture\\Bullet\\Fire1\\Fire1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_09, L"Texture\\Bullet\\Fire1\\Fire1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_10, L"Texture\\Bullet\\Fire1\\Fire1 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_11, L"Texture\\Bullet\\Fire1\\Fire1 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_12, L"Texture\\Bullet\\Fire1\\Fire1 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_13, L"Texture\\Bullet\\Fire1\\Fire1 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_14, L"Texture\\Bullet\\Fire1\\Fire1 (14).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_15, L"Texture\\Bullet\\Fire1\\Fire1 (15).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_16, L"Texture\\Bullet\\Fire1\\Fire1 (16).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_17, L"Texture\\Bullet\\Fire1\\Fire1 (17).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_18, L"Texture\\Bullet\\Fire1\\Fire1 (18).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_19, L"Texture\\Bullet\\Fire1\\Fire1 (19).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_20, L"Texture\\Bullet\\Fire1\\Fire1 (20).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_21, L"Texture\\Bullet\\Fire1\\Fire1 (21).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE1_22, L"Texture\\Bullet\\Fire1\\Fire1 (22).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_01, L"Texture\\Bullet\\Fire2\\Fire2 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_02, L"Texture\\Bullet\\Fire2\\Fire2 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_03, L"Texture\\Bullet\\Fire2\\Fire2 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_04, L"Texture\\Bullet\\Fire2\\Fire2 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_05, L"Texture\\Bullet\\Fire2\\Fire2 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_06, L"Texture\\Bullet\\Fire2\\Fire2 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_07, L"Texture\\Bullet\\Fire2\\Fire2 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE2_08, L"Texture\\Bullet\\Fire2\\Fire2 (8).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_01, L"Texture\\Bullet\\Fire3\\Fire3 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_02, L"Texture\\Bullet\\Fire3\\Fire3 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_03, L"Texture\\Bullet\\Fire3\\Fire3 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_04, L"Texture\\Bullet\\Fire3\\Fire3 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_05, L"Texture\\Bullet\\Fire3\\Fire3 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_06, L"Texture\\Bullet\\Fire3\\Fire3 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_07, L"Texture\\Bullet\\Fire3\\Fire3 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_08, L"Texture\\Bullet\\Fire3\\Fire3 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_09, L"Texture\\Bullet\\Fire3\\Fire3 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_10, L"Texture\\Bullet\\Fire3\\Fire3 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_11, L"Texture\\Bullet\\Fire3\\Fire3 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE3_12, L"Texture\\Bullet\\Fire3\\Fire3 (12).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_01, L"Texture\\Bullet\\Fire4\\Fire4 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_02, L"Texture\\Bullet\\Fire4\\Fire4 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_03, L"Texture\\Bullet\\Fire4\\Fire4 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_04, L"Texture\\Bullet\\Fire4\\Fire4 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_05, L"Texture\\Bullet\\Fire4\\Fire4 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_06, L"Texture\\Bullet\\Fire4\\Fire4 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_07, L"Texture\\Bullet\\Fire4\\Fire4 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_08, L"Texture\\Bullet\\Fire4\\Fire4 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_09, L"Texture\\Bullet\\Fire4\\Fire4 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_10, L"Texture\\Bullet\\Fire4\\Fire4 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_11, L"Texture\\Bullet\\Fire4\\Fire4 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_12, L"Texture\\Bullet\\Fire4\\Fire4 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIRE4_13, L"Texture\\Bullet\\Fire4\\Fire4 (13).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_01, L"Texture\\Bullet\\FireEtc1\\FireBomb (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_02, L"Texture\\Bullet\\FireEtc1\\FireBomb (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_03, L"Texture\\Bullet\\FireEtc1\\FireBomb (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_04, L"Texture\\Bullet\\FireEtc1\\FireBomb (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_05, L"Texture\\Bullet\\FireEtc1\\FireBomb (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_06, L"Texture\\Bullet\\FireEtc1\\FireBomb (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_07, L"Texture\\Bullet\\FireEtc1\\FireBomb (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_08, L"Texture\\Bullet\\FireEtc1\\FireBomb (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_09, L"Texture\\Bullet\\FireEtc1\\FireBomb (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_10, L"Texture\\Bullet\\FireEtc1\\FireBomb (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_11, L"Texture\\Bullet\\FireEtc1\\FireBomb (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREBOMB_12, L"Texture\\Bullet\\FireEtc1\\FireBomb (12).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_01, L"Texture\\Bullet\\FireWall1\\FireWall1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_02, L"Texture\\Bullet\\FireWall1\\FireWall1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_03, L"Texture\\Bullet\\FireWall1\\FireWall1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_04, L"Texture\\Bullet\\FireWall1\\FireWall1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_05, L"Texture\\Bullet\\FireWall1\\FireWall1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_06, L"Texture\\Bullet\\FireWall1\\FireWall1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_07, L"Texture\\Bullet\\FireWall1\\FireWall1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_08, L"Texture\\Bullet\\FireWall1\\FireWall1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_09, L"Texture\\Bullet\\FireWall1\\FireWall1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_10, L"Texture\\Bullet\\FireWall1\\FireWall1 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_11, L"Texture\\Bullet\\FireWall1\\FireWall1 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_12, L"Texture\\Bullet\\FireWall1\\FireWall1 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_13, L"Texture\\Bullet\\FireWall1\\FireWall1 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL1_14, L"Texture\\Bullet\\FireWall1\\FireWall1 (14).png");

	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_01, L"Texture\\Bullet\\Ice1\\Ice1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_02, L"Texture\\Bullet\\Ice1\\Ice1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_03, L"Texture\\Bullet\\Ice1\\Ice1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_04, L"Texture\\Bullet\\Ice1\\Ice1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_05, L"Texture\\Bullet\\Ice1\\Ice1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_06, L"Texture\\Bullet\\Ice1\\Ice1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_07, L"Texture\\Bullet\\Ice1\\Ice1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_08, L"Texture\\Bullet\\Ice1\\Ice1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_09, L"Texture\\Bullet\\Ice1\\Ice1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_10, L"Texture\\Bullet\\Ice1\\Ice1 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_11, L"Texture\\Bullet\\Ice1\\Ice1 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_12, L"Texture\\Bullet\\Ice1\\Ice1 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_13, L"Texture\\Bullet\\Ice1\\Ice1 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_14, L"Texture\\Bullet\\Ice1\\Ice1 (14).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_15, L"Texture\\Bullet\\Ice1\\Ice1 (15).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_16, L"Texture\\Bullet\\Ice1\\Ice1 (15).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_17, L"Texture\\Bullet\\Ice1\\Ice1 (16).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_18, L"Texture\\Bullet\\Ice1\\Ice1 (18).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_19, L"Texture\\Bullet\\Ice1\\Ice1 (19).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_20, L"Texture\\Bullet\\Ice1\\Ice1 (20).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_21, L"Texture\\Bullet\\Ice1\\Ice1 (21).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_22, L"Texture\\Bullet\\Ice1\\Ice1 (22).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_23, L"Texture\\Bullet\\Ice1\\Ice1 (23).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_24, L"Texture\\Bullet\\Ice1\\Ice1 (24).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_25, L"Texture\\Bullet\\Ice1\\Ice1 (25).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_26, L"Texture\\Bullet\\Ice1\\Ice1 (25).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_27, L"Texture\\Bullet\\Ice1\\Ice1 (26).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_28, L"Texture\\Bullet\\Ice1\\Ice1 (28).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_29, L"Texture\\Bullet\\Ice1\\Ice1 (29).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_30, L"Texture\\Bullet\\Ice1\\Ice1 (30).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_31, L"Texture\\Bullet\\Ice1\\Ice1 (31).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_32, L"Texture\\Bullet\\Ice1\\Ice1 (32).png");
	RenderManager::LoadSprite(TextureKey::BULLET_ICE1_33, L"Texture\\Bullet\\Ice1\\Ice1 (33).png");

	RenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_01, L"Texture\\Bullet\\LClaw1\\LClaw1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_02, L"Texture\\Bullet\\LClaw1\\LClaw1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_03, L"Texture\\Bullet\\LClaw1\\LClaw1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_04, L"Texture\\Bullet\\LClaw1\\LClaw1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_05, L"Texture\\Bullet\\LClaw1\\LClaw1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_LCLAW1_06, L"Texture\\Bullet\\LClaw1\\LClaw1 (6).png");

	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_01, L"Texture\\Bullet\\Poision1\\Poison1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_02, L"Texture\\Bullet\\Poision1\\Poison1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_03, L"Texture\\Bullet\\Poision1\\Poison1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_04, L"Texture\\Bullet\\Poision1\\Poison1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_05, L"Texture\\Bullet\\Poision1\\Poison1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_06, L"Texture\\Bullet\\Poision1\\Poison1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_07, L"Texture\\Bullet\\Poision1\\Poison1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_08, L"Texture\\Bullet\\Poision1\\Poison1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_09, L"Texture\\Bullet\\Poision1\\Poison1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_10, L"Texture\\Bullet\\Poision1\\Poison1 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_11, L"Texture\\Bullet\\Poision1\\Poison1 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_12, L"Texture\\Bullet\\Poision1\\Poison1 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_13, L"Texture\\Bullet\\Poision1\\Poison1 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_14, L"Texture\\Bullet\\Poision1\\Poison1 (14).png");
	RenderManager::LoadSprite(TextureKey::BULLET_POISION1_15, L"Texture\\Bullet\\Poision1\\Poison1 (15).png");

	RenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_01, L"Texture\\Bullet\\RClaw1\\RClaw1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_02, L"Texture\\Bullet\\RClaw1\\RClaw1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_03, L"Texture\\Bullet\\RClaw1\\RClaw1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_04, L"Texture\\Bullet\\RClaw1\\RClaw1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_05, L"Texture\\Bullet\\RClaw1\\RClaw1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_RCLAW1_06, L"Texture\\Bullet\\RClaw1\\RClaw1 (6).png");

	RenderManager::LoadSprite(TextureKey::BULLET_WATER1_01, L"Texture\\Bullet\\Water1\\Water1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER1_02, L"Texture\\Bullet\\Water1\\Water1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER1_03, L"Texture\\Bullet\\Water1\\Water1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER1_04, L"Texture\\Bullet\\Water1\\Water1 (4).png");

	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_01, L"Texture\\Bullet\\Water2\\Water2 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_02, L"Texture\\Bullet\\Water2\\Water2 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_03, L"Texture\\Bullet\\Water2\\Water2 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_04, L"Texture\\Bullet\\Water2\\Water2 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_05, L"Texture\\Bullet\\Water2\\Water2 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_06, L"Texture\\Bullet\\Water2\\Water2 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_07, L"Texture\\Bullet\\Water2\\Water2 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_08, L"Texture\\Bullet\\Water2\\Water2 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_09, L"Texture\\Bullet\\Water2\\Water2 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_10, L"Texture\\Bullet\\Water2\\Water2 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_11, L"Texture\\Bullet\\Water2\\Water2 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_12, L"Texture\\Bullet\\Water2\\Water2 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_13, L"Texture\\Bullet\\Water2\\Water2 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_14, L"Texture\\Bullet\\Water2\\Water2 (14).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER2_15, L"Texture\\Bullet\\Water2\\Water2 (15).png");

	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_01, L"Texture\\Bullet\\Water1\\01.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_02, L"Texture\\Bullet\\Water1\\02.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_03, L"Texture\\Bullet\\Water1\\03.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_04, L"Texture\\Bullet\\Water1\\04.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_05, L"Texture\\Bullet\\Water1\\05.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_06, L"Texture\\Bullet\\Water1\\06.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_07, L"Texture\\Bullet\\Water1\\07.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_08, L"Texture\\Bullet\\Water1\\08.png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER3_09, L"Texture\\Bullet\\Water1\\09.png");

	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_01, L"Texture\\Bullet\\Water1\\Water_04 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_02, L"Texture\\Bullet\\Water1\\Water_04 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_03, L"Texture\\Bullet\\Water1\\Water_04 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_04, L"Texture\\Bullet\\Water1\\Water_04 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_05, L"Texture\\Bullet\\Water1\\Water_04 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_06, L"Texture\\Bullet\\Water1\\Water_04 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_07, L"Texture\\Bullet\\Water1\\Water_04 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATER4_08, L"Texture\\Bullet\\Water1\\Water_04 (8).png");

	//WEB
	RenderManager::LoadSprite(TextureKey::BULLET_WEB1_01, L"Texture\\Bullet\\Web1\\Web1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WEB1_02, L"Texture\\Bullet\\Web1\\Web1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WEB1_03, L"Texture\\Bullet\\Web1\\Web1 (3).png");

	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_01, L"Texture\\Bullet\\Wind1\\Wind1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_02, L"Texture\\Bullet\\Wind1\\Wind1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_03, L"Texture\\Bullet\\Wind1\\Wind1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_04, L"Texture\\Bullet\\Wind1\\Wind1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_05, L"Texture\\Bullet\\Wind1\\Wind1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_06, L"Texture\\Bullet\\Wind1\\Wind1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_07, L"Texture\\Bullet\\Wind1\\Wind1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_08, L"Texture\\Bullet\\Wind1\\Wind1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_09, L"Texture\\Bullet\\Wind1\\Wind1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_10, L"Texture\\Bullet\\Wind1\\Wind1 (10).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_11, L"Texture\\Bullet\\Wind1\\Wind1 (11).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_12, L"Texture\\Bullet\\Wind1\\Wind1 (12).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_13, L"Texture\\Bullet\\Wind1\\Wind1 (13).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_14, L"Texture\\Bullet\\Wind1\\Wind1 (14).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WIND1_15, L"Texture\\Bullet\\Wind1\\Wind1 (15).png");

	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_01, L"Texture\\Bullet\\Tornado1\\Tornado1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_02, L"Texture\\Bullet\\Tornado1\\Tornado1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_03, L"Texture\\Bullet\\Tornado1\\Tornado1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_04, L"Texture\\Bullet\\Tornado1\\Tornado1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_05, L"Texture\\Bullet\\Tornado1\\Tornado1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_06, L"Texture\\Bullet\\Tornado1\\Tornado1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_07, L"Texture\\Bullet\\Tornado1\\Tornado1 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_08, L"Texture\\Bullet\\Tornado1\\Tornado1 (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_09, L"Texture\\Bullet\\Tornado1\\Tornado1 (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO1_10, L"Texture\\Bullet\\Tornado1\\Tornado1 (10).png");

	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_01, L"Texture\\Bullet\\Explosion\\Explosion (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_02, L"Texture\\Bullet\\Explosion\\Explosion (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_03, L"Texture\\Bullet\\Explosion\\Explosion (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_04, L"Texture\\Bullet\\Explosion\\Explosion (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_05, L"Texture\\Bullet\\Explosion\\Explosion (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_06, L"Texture\\Bullet\\Explosion\\Explosion (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_07, L"Texture\\Bullet\\Explosion\\Explosion (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_08, L"Texture\\Bullet\\Explosion\\Explosion (8).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_09, L"Texture\\Bullet\\Explosion\\Explosion (9).png");
	RenderManager::LoadSprite(TextureKey::BULLET_EXPLOSION_10, L"Texture\\Bullet\\Explosion\\Explosion (10).png");

	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_01, L"Texture\\Bullet\\Tornado2\\Tornado2 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_02, L"Texture\\Bullet\\Tornado2\\Tornado2 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_03, L"Texture\\Bullet\\Tornado2\\Tornado2 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_04, L"Texture\\Bullet\\Tornado2\\Tornado2 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_05, L"Texture\\Bullet\\Tornado2\\Tornado2 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_06, L"Texture\\Bullet\\Tornado2\\Tornado2 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_07, L"Texture\\Bullet\\Tornado2\\Tornado2 (7).png");
	RenderManager::LoadSprite(TextureKey::BULLET_TORNADO2_08, L"Texture\\Bullet\\Tornado2\\Tornado2 (8).png");

	RenderManager::LoadSprite(TextureKey::BULLET_HEART1_01, L"Texture\\Bullet\\Heart1\\Heart (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_HEART1_02, L"Texture\\Bullet\\Heart1\\Heart (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_HEART1_03, L"Texture\\Bullet\\Heart1\\Heart (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_HEART1_04, L"Texture\\Bullet\\Heart1\\Heart (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_HEART1_05, L"Texture\\Bullet\\Heart1\\Heart (5).png");

	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_01, L"Texture\\Player\\Effect\\Synthesis\\Effect (1).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_02, L"Texture\\Player\\Effect\\Synthesis\\Effect (2).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_03, L"Texture\\Player\\Effect\\Synthesis\\Effect (3).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_04, L"Texture\\Player\\Effect\\Synthesis\\Effect (4).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_05, L"Texture\\Player\\Effect\\Synthesis\\Effect (5).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_06, L"Texture\\Player\\Effect\\Synthesis\\Effect (6).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_07, L"Texture\\Player\\Effect\\Synthesis\\Effect (7).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_08, L"Texture\\Player\\Effect\\Synthesis\\Effect (8).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_09, L"Texture\\Player\\Effect\\Synthesis\\Effect (9).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_10, L"Texture\\Player\\Effect\\Synthesis\\Effect (10).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_11, L"Texture\\Player\\Effect\\Synthesis\\Effect (11).png");
	RenderManager::LoadSprite(TextureKey::EFFECT_SYNTHESIS_12, L"Texture\\Player\\Effect\\Synthesis\\Effect (12).png");

	RenderManager::LoadSprite(TextureKey::BULLET_SYNTHESIS_01, L"Texture\\Player\\Effect\\Synthesis\\Synthesis (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_SYNTHESIS_02, L"Texture\\Player\\Effect\\Synthesis\\Synthesis (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_SYNTHESIS_03, L"Texture\\Player\\Effect\\Synthesis\\Synthesis (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_SYNTHESIS_04, L"Texture\\Player\\Effect\\Synthesis\\Synthesis (4).png");

	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_01, L"Texture\\Bullet\\FireBall1\\FireBall1 (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_02, L"Texture\\Bullet\\FireBall1\\FireBall1 (2).png");
	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_03, L"Texture\\Bullet\\FireBall1\\FireBall1 (3).png");
	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_04, L"Texture\\Bullet\\FireBall1\\FireBall1 (4).png");
	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_05, L"Texture\\Bullet\\FireBall1\\FireBall1 (5).png");
	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_06, L"Texture\\Bullet\\FireBall1\\FireBall1 (6).png");
	RenderManager::LoadSprite(TextureKey::BULLET_REDBALL1_07, L"Texture\\Bullet\\FireBall1\\FireBall1 (7).png");

	RenderManager::LoadSprite(TextureKey::BULLET_INVISIBLE_01, L"Texture\\Bullet\\Invisible\\Invisible (1).png");

	RenderManager::LoadSprite(TextureKey::BULLET_FIREWALL2_01, L"Texture\\Bullet\\FireWall2\\FireWall2 (1).png");

	RenderManager::LoadSprite(TextureKey::BULLET_WATERDROP1_01, L"Texture\\Bullet\\WaterDrop1\\WaterDrop (1).png");
	RenderManager::LoadSprite(TextureKey::BULLET_WATERDROP1_02, L"Texture\\Bullet\\WaterDrop1\\WaterDrop (2).png");

	RenderManager::LoadSprite(TextureKey::PORTRAIT_001, L"Texture\\ETC\\Portrait\\Portrait (1).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_002, L"Texture\\ETC\\Portrait\\Portrait (2).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_003, L"Texture\\ETC\\Portrait\\Portrait (3).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_004, L"Texture\\ETC\\Portrait\\Portrait (4).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_005, L"Texture\\ETC\\Portrait\\Portrait (5).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_006, L"Texture\\ETC\\Portrait\\Portrait (6).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_007, L"Texture\\ETC\\Portrait\\Portrait (7).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_008, L"Texture\\ETC\\Portrait\\Portrait (8).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_009, L"Texture\\ETC\\Portrait\\Portrait (9).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_010, L"Texture\\ETC\\Portrait\\Portrait (10).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_011, L"Texture\\ETC\\Portrait\\Portrait (11).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_012, L"Texture\\ETC\\Portrait\\Portrait (12).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_043, L"Texture\\ETC\\Portrait\\Portrait (43).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_044, L"Texture\\ETC\\Portrait\\Portrait (44).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_045, L"Texture\\ETC\\Portrait\\Portrait (45).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_054, L"Texture\\ETC\\Portrait\\Portrait (54).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_055, L"Texture\\ETC\\Portrait\\Portrait (55).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_058, L"Texture\\ETC\\Portrait\\Portrait (58).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_059, L"Texture\\ETC\\Portrait\\Portrait (59).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_060, L"Texture\\ETC\\Portrait\\Portrait (60).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_061, L"Texture\\ETC\\Portrait\\Portrait (61).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_062, L"Texture\\ETC\\Portrait\\Portrait (62).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_077, L"Texture\\ETC\\Portrait\\Portrait (77).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_078, L"Texture\\ETC\\Portrait\\Portrait (78).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_123, L"Texture\\ETC\\Portrait\\Portrait (123).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_124, L"Texture\\ETC\\Portrait\\Portrait (124).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_132, L"Texture\\ETC\\Portrait\\Portrait (132).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_218, L"Texture\\ETC\\Portrait\\Portrait (218).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_219, L"Texture\\ETC\\Portrait\\Portrait (219).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_245, L"Texture\\ETC\\Portrait\\Portrait (245).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_251, L"Texture\\ETC\\Portrait\\Portrait (251).png");
	RenderManager::LoadSprite(TextureKey::PORTRAIT_383, L"Texture\\ETC\\Portrait\\Portrait (383).png");

	RenderManager::LoadSprite(TextureKey::TREE01, L"Texture\\ETC\\Tree\\Tree (1).png");
	RenderManager::LoadSprite(TextureKey::TREE02, L"Texture\\ETC\\Tree\\Tree (2).png");
	RenderManager::LoadSprite(TextureKey::TREE03, L"Texture\\ETC\\Tree\\Tree (3).png");
	RenderManager::LoadSprite(TextureKey::TREE04, L"Texture\\ETC\\Tree\\Tree (4).png");
	RenderManager::LoadSprite(TextureKey::TREE05, L"Texture\\ETC\\Tree\\Tree (5).png");
	RenderManager::LoadSprite(TextureKey::TREE06, L"Texture\\ETC\\Tree\\Tree (6).png");

	RenderManager::LoadSprite(TextureKey::PALMTREE01, L"Texture\\ETC\\PalmTree\\PalmTree (1).png");
	RenderManager::LoadSprite(TextureKey::PALMTREE02, L"Texture\\ETC\\PalmTree\\PalmTree (2).png");
	RenderManager::LoadSprite(TextureKey::PALMTREE03, L"Texture\\ETC\\PalmTree\\PalmTree (3).png");
	RenderManager::LoadSprite(TextureKey::PALMTREE04, L"Texture\\ETC\\PalmTree\\PalmTree (4).png");

	RenderManager::LoadSprite(TextureKey::BLUECORAL01, L"Texture\\ETC\\Coral\\BlueCoral (1).png");
	RenderManager::LoadSprite(TextureKey::BLUECORAL02, L"Texture\\ETC\\Coral\\BlueCoral (2).png");
	RenderManager::LoadSprite(TextureKey::WHITECORAL01, L"Texture\\ETC\\Coral\\WhiteCoral (1).png");
	RenderManager::LoadSprite(TextureKey::WHITECORAL02, L"Texture\\ETC\\Coral\\WhiteCoral (1).png");
	RenderManager::LoadSprite(TextureKey::REDCORAL01, L"Texture\\ETC\\Coral\\RedCoral (1).png");
	RenderManager::LoadSprite(TextureKey::REDCORAL02, L"Texture\\ETC\\Coral\\RedCoral (1).png");
	RenderManager::LoadSprite(TextureKey::PURPLECORAL01, L"Texture\\ETC\\Coral\\PurpleCoral (1).png");
	RenderManager::LoadSprite(TextureKey::YELLOWCORAL01, L"Texture\\ETC\\Coral\\YellowCoral (1).png");

	//RANGE
	RenderManager::LoadSprite(TextureKey::RANGE, L"Texture\\Bullet\\Range\\Range.png");
	RenderManager::LoadSprite(TextureKey::WHITERANGE, L"Texture\\Bullet\\Range\\WhiteRange.png");
	RenderManager::LoadSprite(TextureKey::REDRANGE, L"Texture\\Bullet\\Range\\RedRange.png");
	RenderManager::LoadSprite(TextureKey::ORANGERANGE, L"Texture\\Bullet\\Range\\OrangeRange.png");
	RenderManager::LoadSprite(TextureKey::BLUERANGE, L"Texture\\Bullet\\Range\\BlueRange.png");
	RenderManager::LoadSprite(TextureKey::BLACKRANGE, L"Texture\\Bullet\\Range\\BlackRange.png");
	RenderManager::LoadSprite(TextureKey::RANGE2, L"Texture\\Bullet\\Range\\Range2.png");

	//MAP TEXTURE
	RenderManager::LoadSprite(TextureKey::GRASS_MAP2, L"Texture\\Map\\Tile\\Grass.png");
	RenderManager::LoadSprite(TextureKey::GRASS_MAP, L"Texture\\Map\\Tile\\Grass.png");
	RenderManager::LoadSprite(TextureKey::WATER_MAP, L"Texture\\Map\\Tile\\Sand.png");
	RenderManager::LoadSprite(TextureKey::BROOK_MAP, L"Texture\\Map\\Tile\\Brook.png");
	RenderManager::LoadSprite(TextureKey::VOLCANO_MAP, L"Texture\\Map\\Tile\\Volcano.png");

	//WATERENVIRONMENT
	RenderManager::LoadSprite(TextureKey::GRASS_WATER_ENVIRONMENT, L"Texture\\Map\\Tile\\DayWater.png");
	RenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT, L"Texture\\Map\\Tile\\BeachWater.png");
	RenderManager::LoadSprite(TextureKey::FIRE_WATER_ENVIRONMENT, L"Texture\\Map\\Tile\\Lava.png");


	//
	RenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT01, L"Texture\\Map\\Tile\\Water1.png");
	RenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT02, L"Texture\\Map\\Tile\\Water2.png");
	RenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT03, L"Texture\\Map\\Tile\\Water3.png");

	RenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT04, L"Texture\\Map\\Tile\\WaterWater1.png");
	/*RenderManager::LoadSprite(TextureKey::WATER_WATER_ENVIRONMENT05, L"Texture\\Map\\Tile\\Water3.png");*/

	RenderManager::LoadSprite(TextureKey::FIRE_WATER_ENVIRONMENT01, L"Texture\\Map\\Tile\\Lava1.png");
	RenderManager::LoadSprite(TextureKey::FIRE_WATER_ENVIRONMENT02, L"Texture\\Map\\Tile\\Lava2.png");

	RenderManager::LoadSprite(TextureKey::MONSTERBALL, L"Texture\\Monster\\MonsterBall.png");
}

void LoadManager::LoadMonsterSprite()
{
	//캐터피
	//이동
	RenderManager::LoadSprite(TextureKey::CATER_WALK_D_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_D_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_D_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_LD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_LD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_LD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_L_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_L_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_L_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_LU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_LU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_LU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_U_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_U_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_U_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_R_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RU_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_R_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_WALK_RD_03, L"Texture\\Monster\\Grass\\Caterpie\\WALK\\RD (3).png");
	//공격								   		
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_D_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_D_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_L_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_L_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_U_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_U_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_R_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_R_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::CATER_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Caterpie\\ATTACK\\RD (2).png");

	//버터플
	//이동
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_D_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_D_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_D_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_LD_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_LD_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_LD_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_L_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_L_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_L_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_LU_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_LU_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_LU_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_U_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_U_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_U_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_RU_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_R_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_01, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_02, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_WALK_RD_03, L"Texture\\Monster\\Grass\\Butterfree\\WALK\\RD (3).png");


	//공격
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_D_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_D_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_L_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_L_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_U_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_U_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_R_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_R_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::BUTTER_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Butterfree\\ATTACK\\RD (2).png");


	//세레비
	//이동
	RenderManager::LoadSprite(TextureKey::CELE_WALK_D_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_D_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_D_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_LD_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_LD_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_LD_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_L_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_L_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_L_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_LU_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_LU_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_LU_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_U_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_U_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_U_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_RU_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_RU_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_RU_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_R_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_R_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_R_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_RD_01, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_RD_02, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::CELE_WALK_RD_03, L"Texture\\Monster\\Grass\\Celebe\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::CELE_HURT_D_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\D (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_LD_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_L_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\L (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_LU_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_U_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\U (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_RU_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_R_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\R (1).png");
	RenderManager::LoadSprite(TextureKey::CELE_HURT_RD_01, L"Texture\\Monster\\Grass\\Celebe\\HURT\\RD (1).png");
	//단데기
	//이동
	RenderManager::LoadSprite(TextureKey::META_WALK_D_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_D_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_D_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_LD_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_LD_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_LD_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_L_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_L_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_L_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_LU_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_LU_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_LU_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_U_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_U_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_U_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_RU_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_RU_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_RU_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_R_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_R_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_R_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_RD_01, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_RD_02, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::META_WALK_RD_03, L"Texture\\Monster\\Grass\\Metapod\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::META_ATTACK_D_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_L_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_U_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_R_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::META_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Metapod\\ATTACK\\RD (1).png");


	//뚜벅쵸
	//이동
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_D_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_D_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_D_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_LD_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_LD_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_LD_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_L_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_L_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_L_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_LU_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_LU_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_LU_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_U_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_U_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_U_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_RU_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_RU_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_RU_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_R_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_R_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_R_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_RD_01, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_RD_02, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_WALK_RD_03, L"Texture\\Monster\\Grass\\Oddish\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_D_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_D_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_L_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_L_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_U_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_U_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_R_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_R_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::ODDI_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Oddish\\ATTACK\\RD (2).png");

	//냄새꼬
	//이동
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_D_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\D\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_D_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\D\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_D_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\D\\D (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_LD_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\LD\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_LD_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\LD\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_LD_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\LD\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_L_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\L\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_L_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\L\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_L_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\L\\L (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_LU_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\LU\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_LU_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\LU\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_LU_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\LU\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_U_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\U\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_U_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\U\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_U_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\U\\U (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_RU_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\RU\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_RU_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\RU\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_RU_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\RU\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_R_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\R\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_R_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\R\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_R_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\R\\R (3).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_RD_01, L"Texture\\Monster\\Grass\\Gloom\\WALK\\RD\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_RD_02, L"Texture\\Monster\\Grass\\Gloom\\WALK\\RD\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_WALK_RD_03, L"Texture\\Monster\\Grass\\Gloom\\WALK\\RD\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_D_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\D\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_D_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\D\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\LD\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\LD\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_L_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\L\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_L_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\L\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\LU\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\LU\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_U_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\U\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_U_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\U\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\RU\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\RU\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_R_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\R\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_R_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\R\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\RD\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GLOOM_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Gloom\\ATTACK\\RD\\RD (2).png");
	//스라크
	//이동
	RenderManager::LoadSprite(TextureKey::SCY_WALK_D_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_D_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_D_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_LD_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_LD_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_LD_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_L_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_L_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_L_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_LU_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_LU_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_LU_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_U_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_U_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_U_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_RU_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_RU_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_RU_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_R_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_R_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_R_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_RD_01, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_RD_02, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_WALK_RD_03, L"Texture\\Monster\\Grass\\Scyther\\WALK\\RD (3).png");
	//공격
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_D_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_D_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_L_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_L_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_U_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_U_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_R_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_R_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::SCY_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Scyther\\ATTACK\\RD (2).png");
	//라플레시아
	//이동
	RenderManager::LoadSprite(TextureKey::VILE_WALK_D_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_D_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_D_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_LD_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_LD_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_LD_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_L_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_L_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_L_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_LU_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_LU_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_LU_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_U_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_U_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_U_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_RU_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_RU_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_RU_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_R_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_R_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_R_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_RD_01, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_RD_02, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_WALK_RD_03, L"Texture\\Monster\\Grass\\Vileplume\\WALK\\RD (3).png");
	//공격								   
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_D_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_D_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_LD_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_LD_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_L_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_L_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_LU_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_LU_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_U_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_U_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_RU_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_RU_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_R_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_R_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_RD_01, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::VILE_ATTACK_RD_02, L"Texture\\Monster\\Grass\\Vileplume\\ATTACK\\RD (2).png");
	//수속성
	//골덕
	//이동
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_D_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_D_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_D_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_LD_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_LD_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_LD_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_L_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_L_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_L_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_LU_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_LU_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_LU_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_U_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_U_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_U_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_RU_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_RU_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_RU_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_R_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_R_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_R_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_RD_01, L"Texture\\Monster\\Water\\Golduck\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_RD_02, L"Texture\\Monster\\Water\\Golduck\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_WALK_RD_03, L"Texture\\Monster\\Water\\Golduck\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_D_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_D_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LD_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LD_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_L_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_L_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LU_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_LU_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_U_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_U_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RU_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RU_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_R_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_R_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RD_01, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GOLD_ATTACK_RD_02, L"Texture\\Monster\\Water\\Golduck\\ATTACK\\RD (2).png");
	//루주라
	//이동
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_D_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_D_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_D_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_LD_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_LD_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_LD_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_L_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_L_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_L_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_LU_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_LU_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_LU_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_U_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_U_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_U_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_RU_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_RU_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_RU_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_R_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_R_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_R_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_RD_01, L"Texture\\Monster\\Water\\Jynx\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_RD_02, L"Texture\\Monster\\Water\\Jynx\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_WALK_RD_03, L"Texture\\Monster\\Water\\Jynx\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_D_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_D_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LD_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LD_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_L_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_L_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LU_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_LU_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_U_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_U_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RU_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RU_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_R_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_R_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RD_01, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::JYNX_ATTACK_RD_02, L"Texture\\Monster\\Water\\Jynx\\ATTACK\\RD (2).png");

	//발챙이
	//이동
	RenderManager::LoadSprite(TextureKey::WAG_WALK_D_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_D_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_D_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_LD_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_LD_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_LD_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_L_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_L_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_L_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_LU_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_LU_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_LU_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_U_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_U_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_U_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_RU_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_RU_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_RU_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_R_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_R_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_R_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_RD_01, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_RD_02, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::WAG_WALK_RD_03, L"Texture\\Monster\\Water\\Poliwag\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_D_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_LD_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_L_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_LU_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_U_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_RU_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_R_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::WAG_ATTACK_RD_01, L"Texture\\Monster\\Water\\Poliwag\\ATTACK\\RD (1).png");

	////수륙챙이
	////이동
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_D_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\D\\D (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_D_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\D\\D (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_D_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\D\\D (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_LD_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\LD\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_LD_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\LD\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_LD_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\LD\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_L_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\L\\L (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_L_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\L\\L (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_L_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\L\\L (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_LU_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\LU\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_LU_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\LU\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_LU_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\LU\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_U_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\U\\U (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_U_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\U\\U (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_U_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\U\\U (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_RU_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\RU\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_RU_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\RU\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_RU_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\RU\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_R_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\R\\R (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_R_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\R\\R (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_R_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\R\\R (3).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_RD_01, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\RD\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_RD_02, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\RD\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_WALK_RD_03, L"Texture\\Monster\\Water\\Poliwhirl\\WALK\\RD\\RD (3).png");

	//공격								   	 
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_D_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\D\\D (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_D_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\D\\D (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_LD_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\LD\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_LD_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\LD\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_L_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\L\\L (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_L_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\L\\L (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_LU_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\LU\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_LU_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\LU\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_U_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\U\\U (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_U_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\U\\U (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_RU_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\RU\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_RU_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\RU\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_R_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\R\\R (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_R_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\R\\R (2).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_RD_01, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\RD\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::WHIRL_ATTACK_RD_02, L"Texture\\Monster\\Water\\Poliwhirl\\ATTACK\\RD\\RD (2).png");

	//강챙이
	//이동
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_D_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_D_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_D_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_LD_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_LD_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_LD_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_L_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_L_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_L_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_LU_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_LU_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_LU_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_U_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_U_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_U_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_RU_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_RU_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_RU_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_R_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_R_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_R_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_RD_01, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_RD_02, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_WALK_RD_03, L"Texture\\Monster\\Water\\Poliwrath\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_D_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_D_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LD_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LD_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_L_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_L_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LU_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_LU_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_U_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_U_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RU_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RU_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_R_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_R_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RD_01, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::WRATH_ATTACK_RD_02, L"Texture\\Monster\\Water\\Poliwrath\\ATTACK\\RD (2).png");

	//고라파덕
	//이동
	RenderManager::LoadSprite(TextureKey::PSY_WALK_D_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_D_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_D_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_LD_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_LD_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_LD_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_L_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_L_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_L_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_LU_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_LU_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_LU_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_U_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_U_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_U_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RU_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RU_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RU_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_R_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_R_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_R_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RD_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RD_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RD_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_D_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_D_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_LD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_LD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_L_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_L_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_LU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_LU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_U_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_U_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RU_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RU_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RU_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_R_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_R_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_R_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RD_01, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RD_02, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_WALK_RD_03, L"Texture\\Monster\\Water\\Psyduck\\WALK\\RD (3).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_RU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_RU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_R_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_R_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_RD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK_RD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK\\RD (2).png");
	//공격2
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_D_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\D (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_D_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\D (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_L_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\L (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_L_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\L (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_LU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_U_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\U (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_U_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\U (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RU_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RU_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_R_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\R (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_R_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\R (2).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RD_01, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::PSY_ATTACK2_RD_02, L"Texture\\Monster\\Water\\Psyduck\\ATTACK2\\RD (2).png");
	//스이쿤
	//이동
	RenderManager::LoadSprite(TextureKey::SUI_WALK_D_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_D_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_D_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_LD_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_LD_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_LD_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_L_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_L_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_L_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_LU_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_LU_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_LU_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_U_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_U_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_U_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_RU_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_RU_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_RU_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_R_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_R_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_R_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_RD_01, L"Texture\\Monster\\Water\\Suicune\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_RD_02, L"Texture\\Monster\\Water\\Suicune\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_WALK_RD_03, L"Texture\\Monster\\Water\\Suicune\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_D_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_D_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_LD_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_LD_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_L_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_L_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_LU_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_LU_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_U_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_U_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_RU_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_RU_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_R_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_R_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_RD_01, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::SUI_ATTACK_RD_02, L"Texture\\Monster\\Water\\Suicune\\ATTACK\\RD (2).png");
	//화속성
	//윈디
	//이동
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_D_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_D_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_D_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_LD_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_LD_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_LD_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_L_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_L_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_L_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_LU_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_LU_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_LU_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_U_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_U_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_U_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_RU_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_RU_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_RU_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_R_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_R_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_R_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_RD_01, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_RD_02, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_WALK_RD_03, L"Texture\\Monster\\Fire\\Arcanine\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_D_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_D_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_L_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_L_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_U_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_U_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_R_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_R_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::ARCA_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Arcanine\\ATTACK\\RD (2).png");
	//그란돈
	//이동
	RenderManager::LoadSprite(TextureKey::GROU_WALK_D_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_D_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_D_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_LD_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_LD_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_LD_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_L_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_L_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_L_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_LU_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_LU_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_LU_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_U_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_U_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_U_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_RU_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_RU_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_RU_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_R_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_R_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_R_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_RD_01, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_RD_02, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_WALK_RD_03, L"Texture\\Monster\\Fire\\Groudon\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_D_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_D_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_L_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_L_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_U_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_U_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_R_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_R_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GROU_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Groudon\\ATTACK\\RD (2).png");
	//가디
	//이동
	RenderManager::LoadSprite(TextureKey::GROW_WALK_D_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_D_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_D_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_LD_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_LD_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_LD_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_L_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_L_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_L_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_LU_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_LU_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_LU_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_U_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_U_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_U_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_RU_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_RU_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_RU_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_R_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_R_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_R_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_RD_01, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_RD_02, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_WALK_RD_03, L"Texture\\Monster\\Fire\\Growlithe\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_D_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_D_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_L_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_L_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_U_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_U_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_R_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_R_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::GROW_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Growlithe\\ATTACK\\RD (2).png");
	//마그카르고
	//이동
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_D_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_D_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_D_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_LD_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_LD_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_LD_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_L_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_L_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_L_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_LU_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_LU_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_LU_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_U_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_U_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_U_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_RU_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_RU_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_RU_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_R_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_R_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_R_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_RD_01, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_RD_02, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_WALK_RD_03, L"Texture\\Monster\\Fire\\Magcargo\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_D_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_D_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_L_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_L_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_U_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_U_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_R_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_R_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::MAGCA_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Magcargo\\ATTACK\\RD (2).png");
	//포니타
	//이동
	RenderManager::LoadSprite(TextureKey::PONY_WALK_D_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_D_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_D_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_LD_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_LD_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_LD_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_L_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_L_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_L_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_LU_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_LU_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_LU_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_U_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_U_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_U_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_RU_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_RU_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_RU_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_R_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_R_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_R_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_RD_01, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_RD_02, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_WALK_RD_03, L"Texture\\Monster\\Fire\\Ponyta\\WALK\\RD (3).png");
	//공격								   	 PONY
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_D_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_D_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_L_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_L_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_U_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_U_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_R_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_R_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::PONY_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Ponyta\\ATTACK\\RD (2).png");
	//날쌩마
	//이동
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_D_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_D_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_D_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_LD_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_LD_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_LD_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_L_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_L_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_L_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_LU_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_LU_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_LU_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_U_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_U_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_U_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_RU_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_RU_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_RU_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_R_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_R_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_R_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_RD_01, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_RD_02, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_WALK_RD_03, L"Texture\\Monster\\Fire\\Rapidash\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_D_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_D_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_L_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_L_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_U_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_U_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_R_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_R_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::RAPID_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Rapidash\\ATTACK\\RD (2).png");
	//마그마그
	//이동
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_D_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_D_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_D_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\D (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_LD_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_LD_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_LD_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LD (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_L_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_L_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_L_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\L (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_LU_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_LU_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_LU_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\LU (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_U_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_U_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_U_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\U (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_RU_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_RU_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_RU_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RU (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_R_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_R_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_R_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\R (3).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_RD_01, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_RD_02, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RD (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_WALK_RD_03, L"Texture\\Monster\\Fire\\Slugma\\WALK\\RD (3).png");
	//공격								   	 
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_D_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\D (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_D_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\D (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LD_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LD (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LD_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LD (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_L_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\L (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_L_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\L (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LU_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LU (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_LU_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\LU (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_U_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\U (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_U_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\U (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RU_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RU (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RU_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RU (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_R_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\R (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_R_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\R (2).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RD_01, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RD (1).png");
	RenderManager::LoadSprite(TextureKey::SLUG_ATTACK_RD_02, L"Texture\\Monster\\Fire\\Slugma\\ATTACK\\RD (2).png");
}

void LoadManager::LoadPlayerSprite()
{
	// == PG01 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PG01_WALK_D_01, L"Texture\\Player\\Grass\\01\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_D_02, L"Texture\\Player\\Grass\\01\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_D_03, L"Texture\\Player\\Grass\\01\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_LD_01, L"Texture\\Player\\Grass\\01\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_LD_02, L"Texture\\Player\\Grass\\01\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_LD_03, L"Texture\\Player\\Grass\\01\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_L_01, L"Texture\\Player\\Grass\\01\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_L_02, L"Texture\\Player\\Grass\\01\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_L_03, L"Texture\\Player\\Grass\\01\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_LU_01, L"Texture\\Player\\Grass\\01\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_LU_02, L"Texture\\Player\\Grass\\01\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_LU_03, L"Texture\\Player\\Grass\\01\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_U_01, L"Texture\\Player\\Grass\\01\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_U_02, L"Texture\\Player\\Grass\\01\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_U_03, L"Texture\\Player\\Grass\\01\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_RU_01, L"Texture\\Player\\Grass\\01\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_RU_02, L"Texture\\Player\\Grass\\01\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_RU_03, L"Texture\\Player\\Grass\\01\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_R_01, L"Texture\\Player\\Grass\\01\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_R_02, L"Texture\\Player\\Grass\\01\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_R_03, L"Texture\\Player\\Grass\\01\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_RD_01, L"Texture\\Player\\Grass\\01\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_RD_02, L"Texture\\Player\\Grass\\01\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_WALK_RD_03, L"Texture\\Player\\Grass\\01\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_D_01, L"Texture\\Player\\Grass\\01\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_D_02, L"Texture\\Player\\Grass\\01\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_LD_01, L"Texture\\Player\\Grass\\01\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_LD_02, L"Texture\\Player\\Grass\\01\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_L_01, L"Texture\\Player\\Grass\\01\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_L_02, L"Texture\\Player\\Grass\\01\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_LU_01, L"Texture\\Player\\Grass\\01\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_LU_02, L"Texture\\Player\\Grass\\01\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_U_01, L"Texture\\Player\\Grass\\01\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_U_02, L"Texture\\Player\\Grass\\01\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_RU_01, L"Texture\\Player\\Grass\\01\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_RU_02, L"Texture\\Player\\Grass\\01\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_R_01, L"Texture\\Player\\Grass\\01\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_R_02, L"Texture\\Player\\Grass\\01\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_RD_01, L"Texture\\Player\\Grass\\01\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_ATTACK_RD_02, L"Texture\\Player\\Grass\\01\\ATTACK\\RD\\1.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_D_01, L"Texture\\Player\\Grass\\01\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_D_02, L"Texture\\Player\\Grass\\01\\SKILL\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_LD_01, L"Texture\\Player\\Grass\\01\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_LD_02, L"Texture\\Player\\Grass\\01\\SKILL\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_L_01, L"Texture\\Player\\Grass\\01\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_L_02, L"Texture\\Player\\Grass\\01\\SKILL\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_LU_01, L"Texture\\Player\\Grass\\01\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_LU_02, L"Texture\\Player\\Grass\\01\\SKILL\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_U_01, L"Texture\\Player\\Grass\\01\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_U_02, L"Texture\\Player\\Grass\\01\\SKILL\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_RU_01, L"Texture\\Player\\Grass\\01\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_RU_02, L"Texture\\Player\\Grass\\01\\SKILL\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_R_01, L"Texture\\Player\\Grass\\01\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_R_02, L"Texture\\Player\\Grass\\01\\SKILL\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_RD_01, L"Texture\\Player\\Grass\\01\\SKILL\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG01_SKILL_RD_02, L"Texture\\Player\\Grass\\01\\SKILL\\RD\\1.png");

	// == PG01 END ==

	// == PG02 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PG02_WALK_D_01, L"Texture\\Player\\Grass\\02\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_D_02, L"Texture\\Player\\Grass\\02\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_D_03, L"Texture\\Player\\Grass\\02\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_LD_01, L"Texture\\Player\\Grass\\02\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_LD_02, L"Texture\\Player\\Grass\\02\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_LD_03, L"Texture\\Player\\Grass\\02\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_L_01, L"Texture\\Player\\Grass\\02\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_L_02, L"Texture\\Player\\Grass\\02\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_L_03, L"Texture\\Player\\Grass\\02\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_LU_01, L"Texture\\Player\\Grass\\02\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_LU_02, L"Texture\\Player\\Grass\\02\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_LU_03, L"Texture\\Player\\Grass\\02\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_U_01, L"Texture\\Player\\Grass\\02\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_U_02, L"Texture\\Player\\Grass\\02\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_U_03, L"Texture\\Player\\Grass\\02\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_RU_01, L"Texture\\Player\\Grass\\02\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_RU_02, L"Texture\\Player\\Grass\\02\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_RU_03, L"Texture\\Player\\Grass\\02\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_R_01, L"Texture\\Player\\Grass\\02\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_R_02, L"Texture\\Player\\Grass\\02\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_R_03, L"Texture\\Player\\Grass\\02\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_RD_01, L"Texture\\Player\\Grass\\02\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_RD_02, L"Texture\\Player\\Grass\\02\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_WALK_RD_03, L"Texture\\Player\\Grass\\02\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_D_01, L"Texture\\Player\\Grass\\02\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_D_02, L"Texture\\Player\\Grass\\02\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_LD_01, L"Texture\\Player\\Grass\\02\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_LD_02, L"Texture\\Player\\Grass\\02\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_L_01, L"Texture\\Player\\Grass\\02\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_L_02, L"Texture\\Player\\Grass\\02\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_LU_01, L"Texture\\Player\\Grass\\02\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_LU_02, L"Texture\\Player\\Grass\\02\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_U_01, L"Texture\\Player\\Grass\\02\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_U_02, L"Texture\\Player\\Grass\\02\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_RU_01, L"Texture\\Player\\Grass\\02\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_RU_02, L"Texture\\Player\\Grass\\02\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_R_01, L"Texture\\Player\\Grass\\02\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_R_02, L"Texture\\Player\\Grass\\02\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_RD_01, L"Texture\\Player\\Grass\\02\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_ATTACK_RD_02, L"Texture\\Player\\Grass\\02\\ATTACK\\RD\\1.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_D_01, L"Texture\\Player\\Grass\\02\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_D_02, L"Texture\\Player\\Grass\\02\\SKILL\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_LD_01, L"Texture\\Player\\Grass\\02\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_LD_02, L"Texture\\Player\\Grass\\02\\SKILL\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_L_01, L"Texture\\Player\\Grass\\02\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_L_02, L"Texture\\Player\\Grass\\02\\SKILL\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_LU_01, L"Texture\\Player\\Grass\\02\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_LU_02, L"Texture\\Player\\Grass\\02\\SKILL\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_U_01, L"Texture\\Player\\Grass\\02\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_U_02, L"Texture\\Player\\Grass\\02\\SKILL\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_RU_01, L"Texture\\Player\\Grass\\02\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_RU_02, L"Texture\\Player\\Grass\\02\\SKILL\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_R_01, L"Texture\\Player\\Grass\\02\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_R_02, L"Texture\\Player\\Grass\\02\\SKILL\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_RD_01, L"Texture\\Player\\Grass\\02\\SKILL\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG02_SKILL_RD_02, L"Texture\\Player\\Grass\\02\\SKILL\\RD\\1.png");
	// == PG02 END ==

	// == PG03 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PG03_WALK_D_01, L"Texture\\Player\\Grass\\03\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_D_02, L"Texture\\Player\\Grass\\03\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_D_03, L"Texture\\Player\\Grass\\03\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_LD_01, L"Texture\\Player\\Grass\\03\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_LD_02, L"Texture\\Player\\Grass\\03\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_LD_03, L"Texture\\Player\\Grass\\03\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_L_01, L"Texture\\Player\\Grass\\03\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_L_02, L"Texture\\Player\\Grass\\03\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_L_03, L"Texture\\Player\\Grass\\03\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_LU_01, L"Texture\\Player\\Grass\\03\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_LU_02, L"Texture\\Player\\Grass\\03\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_LU_03, L"Texture\\Player\\Grass\\03\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_U_01, L"Texture\\Player\\Grass\\03\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_U_02, L"Texture\\Player\\Grass\\03\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_U_03, L"Texture\\Player\\Grass\\03\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_RU_01, L"Texture\\Player\\Grass\\03\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_RU_02, L"Texture\\Player\\Grass\\03\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_RU_03, L"Texture\\Player\\Grass\\03\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_R_01, L"Texture\\Player\\Grass\\03\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_R_02, L"Texture\\Player\\Grass\\03\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_R_03, L"Texture\\Player\\Grass\\03\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_RD_01, L"Texture\\Player\\Grass\\03\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_RD_02, L"Texture\\Player\\Grass\\03\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_WALK_RD_03, L"Texture\\Player\\Grass\\03\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_D_01, L"Texture\\Player\\Grass\\03\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_D_02, L"Texture\\Player\\Grass\\03\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_LD_01, L"Texture\\Player\\Grass\\03\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_LD_02, L"Texture\\Player\\Grass\\03\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_L_01, L"Texture\\Player\\Grass\\03\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_L_02, L"Texture\\Player\\Grass\\03\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_LU_01, L"Texture\\Player\\Grass\\03\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_LU_02, L"Texture\\Player\\Grass\\03\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_U_01, L"Texture\\Player\\Grass\\03\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_U_02, L"Texture\\Player\\Grass\\03\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_RU_01, L"Texture\\Player\\Grass\\03\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_RU_02, L"Texture\\Player\\Grass\\03\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_R_01, L"Texture\\Player\\Grass\\03\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_R_02, L"Texture\\Player\\Grass\\03\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_RD_01, L"Texture\\Player\\Grass\\03\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_ATTACK_RD_02, L"Texture\\Player\\Grass\\03\\ATTACK\\RD\\1.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_D_01, L"Texture\\Player\\Grass\\03\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_D_02, L"Texture\\Player\\Grass\\03\\SKILL\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_LD_01, L"Texture\\Player\\Grass\\03\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_LD_02, L"Texture\\Player\\Grass\\03\\SKILL\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_L_01, L"Texture\\Player\\Grass\\03\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_L_02, L"Texture\\Player\\Grass\\03\\SKILL\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_LU_01, L"Texture\\Player\\Grass\\03\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_LU_02, L"Texture\\Player\\Grass\\03\\SKILL\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_U_01, L"Texture\\Player\\Grass\\03\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_U_02, L"Texture\\Player\\Grass\\03\\SKILL\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_RU_01, L"Texture\\Player\\Grass\\03\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_RU_02, L"Texture\\Player\\Grass\\03\\SKILL\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_R_01, L"Texture\\Player\\Grass\\03\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_R_02, L"Texture\\Player\\Grass\\03\\SKILL\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_RD_01, L"Texture\\Player\\Grass\\03\\SKILL\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PG03_SKILL_RD_02, L"Texture\\Player\\Grass\\03\\SKILL\\RD\\1.png");
	// == PG03 END ==

	// == PF01 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PF01_WALK_D_01, L"Texture\\Player\\Fire\\01\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_D_02, L"Texture\\Player\\Fire\\01\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_D_03, L"Texture\\Player\\Fire\\01\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_LD_01, L"Texture\\Player\\Fire\\01\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_LD_02, L"Texture\\Player\\Fire\\01\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_LD_03, L"Texture\\Player\\Fire\\01\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_L_01, L"Texture\\Player\\Fire\\01\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_L_02, L"Texture\\Player\\Fire\\01\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_L_03, L"Texture\\Player\\Fire\\01\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_LU_01, L"Texture\\Player\\Fire\\01\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_LU_02, L"Texture\\Player\\Fire\\01\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_LU_03, L"Texture\\Player\\Fire\\01\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_U_01, L"Texture\\Player\\Fire\\01\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_U_02, L"Texture\\Player\\Fire\\01\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_U_03, L"Texture\\Player\\Fire\\01\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_RU_01, L"Texture\\Player\\Fire\\01\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_RU_02, L"Texture\\Player\\Fire\\01\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_RU_03, L"Texture\\Player\\Fire\\01\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_R_01, L"Texture\\Player\\Fire\\01\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_R_02, L"Texture\\Player\\Fire\\01\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_R_03, L"Texture\\Player\\Fire\\01\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_RD_01, L"Texture\\Player\\Fire\\01\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_RD_02, L"Texture\\Player\\Fire\\01\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_WALK_RD_03, L"Texture\\Player\\Fire\\01\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_D_01, L"Texture\\Player\\Fire\\01\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_LD_01, L"Texture\\Player\\Fire\\01\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_L_01, L"Texture\\Player\\Fire\\01\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_LU_01, L"Texture\\Player\\Fire\\01\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_U_01, L"Texture\\Player\\Fire\\01\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_RU_01, L"Texture\\Player\\Fire\\01\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_R_01, L"Texture\\Player\\Fire\\01\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_ATTACK_RD_01, L"Texture\\Player\\Fire\\01\\ATTACK\\RD\\0.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_D_01, L"Texture\\Player\\Fire\\01\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_D_02, L"Texture\\Player\\Fire\\01\\SKILL\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_LD_01, L"Texture\\Player\\Fire\\01\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_LD_02, L"Texture\\Player\\Fire\\01\\SKILL\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_L_01, L"Texture\\Player\\Fire\\01\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_L_02, L"Texture\\Player\\Fire\\01\\SKILL\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_LU_01, L"Texture\\Player\\Fire\\01\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_LU_02, L"Texture\\Player\\Fire\\01\\SKILL\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_U_01, L"Texture\\Player\\Fire\\01\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_U_02, L"Texture\\Player\\Fire\\01\\SKILL\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_RU_01, L"Texture\\Player\\Fire\\01\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_RU_02, L"Texture\\Player\\Fire\\01\\SKILL\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_R_01, L"Texture\\Player\\Fire\\01\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_R_02, L"Texture\\Player\\Fire\\01\\SKILL\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_RD_01, L"Texture\\Player\\Fire\\01\\SKILL\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF01_SKILL_RD_02, L"Texture\\Player\\Fire\\01\\SKILL\\RD\\1.png");
	// == PF01 END ==

	// == PF02 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PF02_WALK_D_01, L"Texture\\Player\\Fire\\02\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_D_02, L"Texture\\Player\\Fire\\02\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_D_03, L"Texture\\Player\\Fire\\02\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_LD_01, L"Texture\\Player\\Fire\\02\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_LD_02, L"Texture\\Player\\Fire\\02\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_LD_03, L"Texture\\Player\\Fire\\02\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_L_01, L"Texture\\Player\\Fire\\02\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_L_02, L"Texture\\Player\\Fire\\02\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_L_03, L"Texture\\Player\\Fire\\02\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_LU_01, L"Texture\\Player\\Fire\\02\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_LU_02, L"Texture\\Player\\Fire\\02\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_LU_03, L"Texture\\Player\\Fire\\02\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_U_01, L"Texture\\Player\\Fire\\02\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_U_02, L"Texture\\Player\\Fire\\02\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_U_03, L"Texture\\Player\\Fire\\02\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_RU_01, L"Texture\\Player\\Fire\\02\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_RU_02, L"Texture\\Player\\Fire\\02\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_RU_03, L"Texture\\Player\\Fire\\02\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_R_01, L"Texture\\Player\\Fire\\02\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_R_02, L"Texture\\Player\\Fire\\02\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_R_03, L"Texture\\Player\\Fire\\02\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_RD_01, L"Texture\\Player\\Fire\\02\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_RD_02, L"Texture\\Player\\Fire\\02\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_WALK_RD_03, L"Texture\\Player\\Fire\\02\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_D_01, L"Texture\\Player\\Fire\\02\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_D_02, L"Texture\\Player\\Fire\\02\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_LD_01, L"Texture\\Player\\Fire\\02\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_LD_02, L"Texture\\Player\\Fire\\02\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_L_01, L"Texture\\Player\\Fire\\02\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_L_02, L"Texture\\Player\\Fire\\02\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_LU_01, L"Texture\\Player\\Fire\\02\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_LU_02, L"Texture\\Player\\Fire\\02\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_U_01, L"Texture\\Player\\Fire\\02\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_U_02, L"Texture\\Player\\Fire\\02\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_RU_01, L"Texture\\Player\\Fire\\02\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_RU_02, L"Texture\\Player\\Fire\\02\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_R_01, L"Texture\\Player\\Fire\\02\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_R_02, L"Texture\\Player\\Fire\\02\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_RD_01, L"Texture\\Player\\Fire\\02\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_ATTACK_RD_02, L"Texture\\Player\\Fire\\02\\ATTACK\\RD\\1.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_D_01, L"Texture\\Player\\Fire\\02\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_D_02, L"Texture\\Player\\Fire\\02\\SKILL\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_LD_01, L"Texture\\Player\\Fire\\02\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_LD_02, L"Texture\\Player\\Fire\\02\\SKILL\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_L_01, L"Texture\\Player\\Fire\\02\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_L_02, L"Texture\\Player\\Fire\\02\\SKILL\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_LU_01, L"Texture\\Player\\Fire\\02\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_LU_02, L"Texture\\Player\\Fire\\02\\SKILL\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_U_01, L"Texture\\Player\\Fire\\02\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_U_02, L"Texture\\Player\\Fire\\02\\SKILL\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_RU_01, L"Texture\\Player\\Fire\\02\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_RU_02, L"Texture\\Player\\Fire\\02\\SKILL\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_R_01, L"Texture\\Player\\Fire\\02\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_R_02, L"Texture\\Player\\Fire\\02\\SKILL\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_RD_01, L"Texture\\Player\\Fire\\02\\SKILL\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF02_SKILL_RD_02, L"Texture\\Player\\Fire\\02\\SKILL\\RD\\1.png");
	// == PF02 END ==

	// == PF03 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PF03_WALK_D_01, L"Texture\\Player\\Fire\\03\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_D_02, L"Texture\\Player\\Fire\\03\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_D_03, L"Texture\\Player\\Fire\\03\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_LD_01, L"Texture\\Player\\Fire\\03\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_LD_02, L"Texture\\Player\\Fire\\03\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_LD_03, L"Texture\\Player\\Fire\\03\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_L_01, L"Texture\\Player\\Fire\\03\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_L_02, L"Texture\\Player\\Fire\\03\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_L_03, L"Texture\\Player\\Fire\\03\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_LU_01, L"Texture\\Player\\Fire\\03\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_LU_02, L"Texture\\Player\\Fire\\03\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_LU_03, L"Texture\\Player\\Fire\\03\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_U_01, L"Texture\\Player\\Fire\\03\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_U_02, L"Texture\\Player\\Fire\\03\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_U_03, L"Texture\\Player\\Fire\\03\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_RU_01, L"Texture\\Player\\Fire\\03\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_RU_02, L"Texture\\Player\\Fire\\03\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_RU_03, L"Texture\\Player\\Fire\\03\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_R_01, L"Texture\\Player\\Fire\\03\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_R_02, L"Texture\\Player\\Fire\\03\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_R_03, L"Texture\\Player\\Fire\\03\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_RD_01, L"Texture\\Player\\Fire\\03\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_RD_02, L"Texture\\Player\\Fire\\03\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_WALK_RD_03, L"Texture\\Player\\Fire\\03\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_D_01, L"Texture\\Player\\Fire\\03\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_D_02, L"Texture\\Player\\Fire\\03\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_LD_01, L"Texture\\Player\\Fire\\03\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_LD_02, L"Texture\\Player\\Fire\\03\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_L_01, L"Texture\\Player\\Fire\\03\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_L_02, L"Texture\\Player\\Fire\\03\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_LU_01, L"Texture\\Player\\Fire\\03\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_LU_02, L"Texture\\Player\\Fire\\03\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_U_01, L"Texture\\Player\\Fire\\03\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_U_02, L"Texture\\Player\\Fire\\03\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_RU_01, L"Texture\\Player\\Fire\\03\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_RU_02, L"Texture\\Player\\Fire\\03\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_R_01, L"Texture\\Player\\Fire\\03\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_R_02, L"Texture\\Player\\Fire\\03\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_RD_01, L"Texture\\Player\\Fire\\03\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_ATTACK_RD_02, L"Texture\\Player\\Fire\\03\\ATTACK\\RD\\1.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_D_01, L"Texture\\Player\\Fire\\03\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_D_02, L"Texture\\Player\\Fire\\03\\SKILL\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_LD_01, L"Texture\\Player\\Fire\\03\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_LD_02, L"Texture\\Player\\Fire\\03\\SKILL\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_L_01, L"Texture\\Player\\Fire\\03\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_L_02, L"Texture\\Player\\Fire\\03\\SKILL\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_LU_01, L"Texture\\Player\\Fire\\03\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_LU_02, L"Texture\\Player\\Fire\\03\\SKILL\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_U_01, L"Texture\\Player\\Fire\\03\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_U_02, L"Texture\\Player\\Fire\\03\\SKILL\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_RU_01, L"Texture\\Player\\Fire\\03\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_RU_02, L"Texture\\Player\\Fire\\03\\SKILL\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_R_01, L"Texture\\Player\\Fire\\03\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_R_02, L"Texture\\Player\\Fire\\03\\SKILL\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_RD_01, L"Texture\\Player\\Fire\\03\\SKILL\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PF03_SKILL_RD_02, L"Texture\\Player\\Fire\\03\\SKILL\\RD\\1.png");
	// == PF03 END ==

	// == PW01 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PW01_WALK_D_01, L"Texture\\Player\\Water\\01\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_D_02, L"Texture\\Player\\Water\\01\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_D_03, L"Texture\\Player\\Water\\01\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_LD_01, L"Texture\\Player\\Water\\01\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_LD_02, L"Texture\\Player\\Water\\01\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_LD_03, L"Texture\\Player\\Water\\01\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_L_01, L"Texture\\Player\\Water\\01\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_L_02, L"Texture\\Player\\Water\\01\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_L_03, L"Texture\\Player\\Water\\01\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_LU_01, L"Texture\\Player\\Water\\01\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_LU_02, L"Texture\\Player\\Water\\01\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_LU_03, L"Texture\\Player\\Water\\01\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_U_01, L"Texture\\Player\\Water\\01\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_U_02, L"Texture\\Player\\Water\\01\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_U_03, L"Texture\\Player\\Water\\01\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_RU_01, L"Texture\\Player\\Water\\01\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_RU_02, L"Texture\\Player\\Water\\01\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_RU_03, L"Texture\\Player\\Water\\01\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_R_01, L"Texture\\Player\\Water\\01\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_R_02, L"Texture\\Player\\Water\\01\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_R_03, L"Texture\\Player\\Water\\01\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_RD_01, L"Texture\\Player\\Water\\01\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_RD_02, L"Texture\\Player\\Water\\01\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_WALK_RD_03, L"Texture\\Player\\Water\\01\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_D_01, L"Texture\\Player\\Water\\01\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_D_02, L"Texture\\Player\\Water\\01\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_D_03, L"Texture\\Player\\Water\\01\\ATTACK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_LD_01, L"Texture\\Player\\Water\\01\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_LD_02, L"Texture\\Player\\Water\\01\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_LD_03, L"Texture\\Player\\Water\\01\\ATTACK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_L_01, L"Texture\\Player\\Water\\01\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_L_02, L"Texture\\Player\\Water\\01\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_L_03, L"Texture\\Player\\Water\\01\\ATTACK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_LU_01, L"Texture\\Player\\Water\\01\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_LU_02, L"Texture\\Player\\Water\\01\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_LU_03, L"Texture\\Player\\Water\\01\\ATTACK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_U_01, L"Texture\\Player\\Water\\01\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_U_02, L"Texture\\Player\\Water\\01\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_U_03, L"Texture\\Player\\Water\\01\\ATTACK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_RU_01, L"Texture\\Player\\Water\\01\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_RU_02, L"Texture\\Player\\Water\\01\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_RU_03, L"Texture\\Player\\Water\\01\\ATTACK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_R_01, L"Texture\\Player\\Water\\01\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_R_02, L"Texture\\Player\\Water\\01\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_R_03, L"Texture\\Player\\Water\\01\\ATTACK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_RD_01, L"Texture\\Player\\Water\\01\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_RD_02, L"Texture\\Player\\Water\\01\\ATTACK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW01_ATTACK_RD_03, L"Texture\\Player\\Water\\01\\ATTACK\\RD\\2.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_D_01, L"Texture\\Player\\Water\\01\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_LD_01, L"Texture\\Player\\Water\\01\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_L_01, L"Texture\\Player\\Water\\01\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_LU_01, L"Texture\\Player\\Water\\01\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_U_01, L"Texture\\Player\\Water\\01\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_RU_01, L"Texture\\Player\\Water\\01\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_R_01, L"Texture\\Player\\Water\\01\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW01_SKILL_RD_01, L"Texture\\Player\\Water\\01\\SKILL\\RD\\0.png");

	// == PW01 END ==

	// == PW02 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PW02_WALK_D_01, L"Texture\\Player\\Water\\02\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_D_02, L"Texture\\Player\\Water\\02\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_D_03, L"Texture\\Player\\Water\\02\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_LD_01, L"Texture\\Player\\Water\\02\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_LD_02, L"Texture\\Player\\Water\\02\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_LD_03, L"Texture\\Player\\Water\\02\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_L_01, L"Texture\\Player\\Water\\02\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_L_02, L"Texture\\Player\\Water\\02\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_L_03, L"Texture\\Player\\Water\\02\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_LU_01, L"Texture\\Player\\Water\\02\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_LU_02, L"Texture\\Player\\Water\\02\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_LU_03, L"Texture\\Player\\Water\\02\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_U_01, L"Texture\\Player\\Water\\02\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_U_02, L"Texture\\Player\\Water\\02\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_U_03, L"Texture\\Player\\Water\\02\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_RU_01, L"Texture\\Player\\Water\\02\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_RU_02, L"Texture\\Player\\Water\\02\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_RU_03, L"Texture\\Player\\Water\\02\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_R_01, L"Texture\\Player\\Water\\02\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_R_02, L"Texture\\Player\\Water\\02\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_R_03, L"Texture\\Player\\Water\\02\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_RD_01, L"Texture\\Player\\Water\\02\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_RD_02, L"Texture\\Player\\Water\\02\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_WALK_RD_03, L"Texture\\Player\\Water\\02\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_D_01, L"Texture\\Player\\Water\\02\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_D_02, L"Texture\\Player\\Water\\02\\ATTACK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_LD_01, L"Texture\\Player\\Water\\02\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_LD_02, L"Texture\\Player\\Water\\02\\ATTACK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_L_01, L"Texture\\Player\\Water\\02\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_L_02, L"Texture\\Player\\Water\\02\\ATTACK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_LU_01, L"Texture\\Player\\Water\\02\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_LU_02, L"Texture\\Player\\Water\\02\\ATTACK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_U_01, L"Texture\\Player\\Water\\02\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_U_02, L"Texture\\Player\\Water\\02\\ATTACK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_RU_01, L"Texture\\Player\\Water\\02\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_RU_02, L"Texture\\Player\\Water\\02\\ATTACK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_R_01, L"Texture\\Player\\Water\\02\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_R_02, L"Texture\\Player\\Water\\02\\ATTACK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_RD_01, L"Texture\\Player\\Water\\02\\ATTACK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_ATTACK_RD_02, L"Texture\\Player\\Water\\02\\ATTACK\\RD\\1.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_D_01, L"Texture\\Player\\Water\\02\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_LD_01, L"Texture\\Player\\Water\\02\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_L_01, L"Texture\\Player\\Water\\02\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_LU_01, L"Texture\\Player\\Water\\02\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_U_01, L"Texture\\Player\\Water\\02\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_RU_01, L"Texture\\Player\\Water\\02\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_R_01, L"Texture\\Player\\Water\\02\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW02_SKILL_RD_01, L"Texture\\Player\\Water\\02\\SKILL\\RD\\0.png");

	// == PW02 END ==

	// == PW03 START ==
	// WALK
	RenderManager::LoadSprite(TextureKey::PW03_WALK_D_01, L"Texture\\Player\\Water\\03\\WALK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_D_02, L"Texture\\Player\\Water\\03\\WALK\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_D_03, L"Texture\\Player\\Water\\03\\WALK\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_LD_01, L"Texture\\Player\\Water\\03\\WALK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_LD_02, L"Texture\\Player\\Water\\03\\WALK\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_LD_03, L"Texture\\Player\\Water\\03\\WALK\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_L_01, L"Texture\\Player\\Water\\03\\WALK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_L_02, L"Texture\\Player\\Water\\03\\WALK\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_L_03, L"Texture\\Player\\Water\\03\\WALK\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_LU_01, L"Texture\\Player\\Water\\03\\WALK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_LU_02, L"Texture\\Player\\Water\\03\\WALK\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_LU_03, L"Texture\\Player\\Water\\03\\WALK\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_U_01, L"Texture\\Player\\Water\\03\\WALK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_U_02, L"Texture\\Player\\Water\\03\\WALK\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_U_03, L"Texture\\Player\\Water\\03\\WALK\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_RU_01, L"Texture\\Player\\Water\\03\\WALK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_RU_02, L"Texture\\Player\\Water\\03\\WALK\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_RU_03, L"Texture\\Player\\Water\\03\\WALK\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_R_01, L"Texture\\Player\\Water\\03\\WALK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_R_02, L"Texture\\Player\\Water\\03\\WALK\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_R_03, L"Texture\\Player\\Water\\03\\WALK\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_RD_01, L"Texture\\Player\\Water\\03\\WALK\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_RD_02, L"Texture\\Player\\Water\\03\\WALK\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::PW03_WALK_RD_03, L"Texture\\Player\\Water\\03\\WALK\\RD\\2.png");

	// ATTACK
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_D_01, L"Texture\\Player\\Water\\03\\ATTACK\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_LD_01, L"Texture\\Player\\Water\\03\\ATTACK\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_L_01, L"Texture\\Player\\Water\\03\\ATTACK\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_LU_01, L"Texture\\Player\\Water\\03\\ATTACK\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_U_01, L"Texture\\Player\\Water\\03\\ATTACK\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_RU_01, L"Texture\\Player\\Water\\03\\ATTACK\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_R_01, L"Texture\\Player\\Water\\03\\ATTACK\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_ATTACK_RD_01, L"Texture\\Player\\Water\\03\\ATTACK\\RD\\0.png");

	// SKILL
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_D_01, L"Texture\\Player\\Water\\03\\SKILL\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_LD_01, L"Texture\\Player\\Water\\03\\SKILL\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_L_01, L"Texture\\Player\\Water\\03\\SKILL\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_LU_01, L"Texture\\Player\\Water\\03\\SKILL\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_U_01, L"Texture\\Player\\Water\\03\\SKILL\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_RU_01, L"Texture\\Player\\Water\\03\\SKILL\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_R_01, L"Texture\\Player\\Water\\03\\SKILL\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::PW03_SKILL_RD_01, L"Texture\\Player\\Water\\03\\SKILL\\RD\\0.png");

	// == PW03 END ==

	RenderManager::LoadSprite(TextureKey::DITTO_WALK_D_01, L"Texture\\Player\\Ditto\\D\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_D_02, L"Texture\\Player\\Ditto\\D\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_D_03, L"Texture\\Player\\Ditto\\D\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_LD_01, L"Texture\\Player\\Ditto\\LD\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_LD_02, L"Texture\\Player\\Ditto\\LD\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_LD_03, L"Texture\\Player\\Ditto\\LD\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_L_01, L"Texture\\Player\\Ditto\\L\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_L_02, L"Texture\\Player\\Ditto\\L\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_L_03, L"Texture\\Player\\Ditto\\L\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_LU_01, L"Texture\\Player\\Ditto\\LU\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_LU_02, L"Texture\\Player\\Ditto\\LU\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_LU_03, L"Texture\\Player\\Ditto\\LU\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_U_01, L"Texture\\Player\\Ditto\\U\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_U_02, L"Texture\\Player\\Ditto\\U\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_U_03, L"Texture\\Player\\Ditto\\U\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_RU_01, L"Texture\\Player\\Ditto\\RU\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_RU_02, L"Texture\\Player\\Ditto\\RU\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_RU_03, L"Texture\\Player\\Ditto\\RU\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_R_01, L"Texture\\Player\\Ditto\\R\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_R_02, L"Texture\\Player\\Ditto\\R\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_R_03, L"Texture\\Player\\Ditto\\R\\2.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_RD_01, L"Texture\\Player\\Ditto\\RD\\0.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_RD_02, L"Texture\\Player\\Ditto\\RD\\1.png");
	RenderManager::LoadSprite(TextureKey::DITTO_WALK_RD_03, L"Texture\\Player\\Ditto\\RD\\2.png");

	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_D_01, L"Texture\\Player\\Ditto\\D\\Color_D (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_D_02, L"Texture\\Player\\Ditto\\D\\Color_D (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_D_03, L"Texture\\Player\\Ditto\\D\\Color_D (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_LD_01, L"Texture\\Player\\Ditto\\LD\\Color_LD (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_LD_02, L"Texture\\Player\\Ditto\\LD\\Color_LD (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_LD_03, L"Texture\\Player\\Ditto\\LD\\Color_LD (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_L_01, L"Texture\\Player\\Ditto\\L\\Color_L (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_L_02, L"Texture\\Player\\Ditto\\L\\Color_L (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_L_03, L"Texture\\Player\\Ditto\\L\\Color_L (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_LU_01, L"Texture\\Player\\Ditto\\LU\\Color_LU (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_LU_02, L"Texture\\Player\\Ditto\\LU\\Color_LU (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_LU_03, L"Texture\\Player\\Ditto\\LU\\Color_LU (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_U_01, L"Texture\\Player\\Ditto\\U\\Color_U (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_U_02, L"Texture\\Player\\Ditto\\U\\Color_U (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_U_03, L"Texture\\Player\\Ditto\\U\\Color_U (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_RU_01, L"Texture\\Player\\Ditto\\RU\\Color_RU (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_RU_02, L"Texture\\Player\\Ditto\\RU\\Color_RU (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_RU_03, L"Texture\\Player\\Ditto\\RU\\Color_RU (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_R_01, L"Texture\\Player\\Ditto\\R\\Color_R (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_R_02, L"Texture\\Player\\Ditto\\R\\Color_R (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_R_03, L"Texture\\Player\\Ditto\\R\\Color_R (3).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_RD_01, L"Texture\\Player\\Ditto\\RD\\Color_RD (1).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_RD_02, L"Texture\\Player\\Ditto\\RD\\Color_RD (2).png");
	RenderManager::LoadSprite(TextureKey::DITTOR_WALK_RD_03, L"Texture\\Player\\Ditto\\RD\\Color_RD (3).png");

	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_D_01, L"Texture\\Player\\Ditto\\D\\Color_D (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_D_02, L"Texture\\Player\\Ditto\\D\\Color_D (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_D_03, L"Texture\\Player\\Ditto\\D\\Color_D (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_LD_01, L"Texture\\Player\\Ditto\\LD\\Color_LD (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_LD_02, L"Texture\\Player\\Ditto\\LD\\Color_LD (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_LD_03, L"Texture\\Player\\Ditto\\LD\\Color_LD (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_L_01, L"Texture\\Player\\Ditto\\L\\Color_L (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_L_02, L"Texture\\Player\\Ditto\\L\\Color_L (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_L_03, L"Texture\\Player\\Ditto\\L\\Color_L (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_LU_01, L"Texture\\Player\\Ditto\\LU\\Color_LU (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_LU_02, L"Texture\\Player\\Ditto\\LU\\Color_LU (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_LU_03, L"Texture\\Player\\Ditto\\LU\\Color_LU (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_U_01, L"Texture\\Player\\Ditto\\U\\Color_U (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_U_02, L"Texture\\Player\\Ditto\\U\\Color_U (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_U_03, L"Texture\\Player\\Ditto\\U\\Color_U (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_RU_01, L"Texture\\Player\\Ditto\\RU\\Color_RU (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_RU_02, L"Texture\\Player\\Ditto\\RU\\Color_RU (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_RU_03, L"Texture\\Player\\Ditto\\RU\\Color_RU (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_R_01, L"Texture\\Player\\Ditto\\R\\Color_R (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_R_02, L"Texture\\Player\\Ditto\\R\\Color_R (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_R_03, L"Texture\\Player\\Ditto\\R\\Color_R (9).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_RD_01, L"Texture\\Player\\Ditto\\RD\\Color_RD (7).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_RD_02, L"Texture\\Player\\Ditto\\RD\\Color_RD (8).png");
	RenderManager::LoadSprite(TextureKey::DITTOY_WALK_RD_03, L"Texture\\Player\\Ditto\\RD\\Color_RD (9).png");

	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_D_01, L"Texture\\Player\\Ditto\\D\\Color_D (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_D_02, L"Texture\\Player\\Ditto\\D\\Color_D (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_D_03, L"Texture\\Player\\Ditto\\D\\Color_D (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_LD_01, L"Texture\\Player\\Ditto\\LD\\Color_LD (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_LD_02, L"Texture\\Player\\Ditto\\LD\\Color_LD (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_LD_03, L"Texture\\Player\\Ditto\\LD\\Color_LD (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_L_01, L"Texture\\Player\\Ditto\\L\\Color_L (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_L_02, L"Texture\\Player\\Ditto\\L\\Color_L (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_L_03, L"Texture\\Player\\Ditto\\L\\Color_L (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_LU_01, L"Texture\\Player\\Ditto\\LU\\Color_LU (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_LU_02, L"Texture\\Player\\Ditto\\LU\\Color_LU (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_LU_03, L"Texture\\Player\\Ditto\\LU\\Color_LU (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_U_01, L"Texture\\Player\\Ditto\\U\\Color_U (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_U_02, L"Texture\\Player\\Ditto\\U\\Color_U (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_U_03, L"Texture\\Player\\Ditto\\U\\Color_U (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_RU_01, L"Texture\\Player\\Ditto\\RU\\Color_RU (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_RU_02, L"Texture\\Player\\Ditto\\RU\\Color_RU (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_RU_03, L"Texture\\Player\\Ditto\\RU\\Color_RU (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_R_01, L"Texture\\Player\\Ditto\\R\\Color_R (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_R_02, L"Texture\\Player\\Ditto\\R\\Color_R (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_R_03, L"Texture\\Player\\Ditto\\R\\Color_R (12).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_RD_01, L"Texture\\Player\\Ditto\\RD\\Color_RD (10).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_RD_02, L"Texture\\Player\\Ditto\\RD\\Color_RD (11).png");
	RenderManager::LoadSprite(TextureKey::DITTOG_WALK_RD_03, L"Texture\\Player\\Ditto\\RD\\Color_RD (12).png");

	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_D_01, L"Texture\\Player\\Ditto\\D\\Color_D (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_D_02, L"Texture\\Player\\Ditto\\D\\Color_D (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_D_03, L"Texture\\Player\\Ditto\\D\\Color_D (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_LD_01, L"Texture\\Player\\Ditto\\LD\\Color_LD (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_LD_02, L"Texture\\Player\\Ditto\\LD\\Color_LD (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_LD_03, L"Texture\\Player\\Ditto\\LD\\Color_LD (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_L_01, L"Texture\\Player\\Ditto\\L\\Color_L (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_L_02, L"Texture\\Player\\Ditto\\L\\Color_L (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_L_03, L"Texture\\Player\\Ditto\\L\\Color_L (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_LU_01, L"Texture\\Player\\Ditto\\LU\\Color_LU (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_LU_02, L"Texture\\Player\\Ditto\\LU\\Color_LU (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_LU_03, L"Texture\\Player\\Ditto\\LU\\Color_LU (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_U_01, L"Texture\\Player\\Ditto\\U\\Color_U (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_U_02, L"Texture\\Player\\Ditto\\U\\Color_U (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_U_03, L"Texture\\Player\\Ditto\\U\\Color_U (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_RU_01, L"Texture\\Player\\Ditto\\RU\\Color_RU (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_RU_02, L"Texture\\Player\\Ditto\\RU\\Color_RU (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_RU_03, L"Texture\\Player\\Ditto\\RU\\Color_RU (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_R_01, L"Texture\\Player\\Ditto\\R\\Color_R (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_R_02, L"Texture\\Player\\Ditto\\R\\Color_R (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_R_03, L"Texture\\Player\\Ditto\\R\\Color_R (15).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_RD_01, L"Texture\\Player\\Ditto\\RD\\Color_RD (13).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_RD_02, L"Texture\\Player\\Ditto\\RD\\Color_RD (14).png");
	RenderManager::LoadSprite(TextureKey::DITTOB_WALK_RD_03, L"Texture\\Player\\Ditto\\RD\\Color_RD (15).png");

}

void LoadManager::LoadNPCSprite()
{
	RenderManager::LoadSprite(TextureKey::NPC_DOCTOR_OH, L"Texture\\NPC\\doctorO.png");
}


