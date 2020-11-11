#include "stdafx.h"
#include "LoadManager.h"

LoadManager* pLoadManager = nullptr;

LoadManager::LoadManager()
{
    Initialize();
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
    pLoadManager->hThread = (HANDLE)_beginthreadex(NULL, 0, LodingThread, pLoadManager, 0, nullptr);
}

void LoadManager::Release()
{
    WaitForSingleObject(pLoadManager->hThread, INFINITE);
    CloseHandle(pLoadManager->hThread);
}

unsigned int __stdcall LoadManager::LodingThread(void* arg)
{
    return 0;
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
