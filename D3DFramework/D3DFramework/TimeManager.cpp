#include "stdafx.h"
#include "TimeManager.h"

using namespace PKH;

PKH::TimeManager* pTime = nullptr;

PKH::TimeManager::TimeManager()
{
}

PKH::TimeManager::~TimeManager()
{
}

PKH::TimeManager* TimeManager::GetInstance()
{
    if (pTime == nullptr)
    {
        pTime = new TimeManager;
        Initialize();
    }
    return pTime;
}

void PKH::TimeManager::Destroy()
{
    if (pTime)
    {
        delete pTime;
        pTime = nullptr;
    }
}

void PKH::TimeManager::Initialize()
{
    if (QueryPerformanceFrequency(&pTime->frequency))
    {
        pTime->isUsedQueryPerformance = true;
    }
}

void PKH::TimeManager::Release()
{
}

bool PKH::TimeManager::SkipFrame()
{
    LARGE_INTEGER time;
    __int64 curTime;
    __int64 elapse; // 1프레임 경과시간(ms)

    QueryPerformanceCounter(&time);
    curTime = time.QuadPart;
    
    if (pTime->oldTime == 0)
    {
        pTime->oldTime = curTime;
        return false;
    }

    // 프레임당 걸린 시간 (마이크로세컨) -> 밀리세컨
    elapse = (curTime - pTime->oldTime) / (pTime->frequency.QuadPart / 1000);

    pTime->elapseSum += elapse;
    // 올드타임 갱신
    pTime->oldTime = curTime;
    // 델타타임 갱신 (초단위)
    pTime->deltaTime = float(elapse) / 1000;

    //프레임 카운트
    pTime->frameCount++;

    if (pTime->elapseSum >= 1000) // 1초 경과시
    {
        pTime->fps = pTime->frameCount;
        pTime->frameCount = 0;
        pTime->elapseSum = 0;
    }

    // 프레임당 초과/미만 시간 누적
    pTime->timeStack += elapse - pTime->targetFrame;

    if (pTime->timeStack >= pTime->targetFrame) // 느릴때
    {
        pTime->timeStack -= pTime->targetFrame;
        return true;
    }
    else // 빠를때
    {
        Sleep(abs(pTime->timeStack));
    }

    return false;
}

float PKH::TimeManager::GetFPS()
{
    return pTime->fps;
}

void PKH::TimeManager::SetFPS(float _fps)
{
    pTime->fps = _fps;
    pTime->targetFrame = 1000.f / _fps;
}

float PKH::TimeManager::DeltaTime()
{
    return pTime->deltaTime;
}

void PKH::TimeManager::RenderFPS()
{
}
