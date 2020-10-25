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
    __int64 elapse; // 1������ ����ð�(ms)

    QueryPerformanceCounter(&time);
    curTime = time.QuadPart;
    
    if (pTime->oldTime == 0)
    {
        pTime->oldTime = curTime;
        return false;
    }

    // �����Ӵ� �ɸ� �ð� (����ũ�μ���) -> �и�����
    elapse = (curTime - pTime->oldTime) / (pTime->frequency.QuadPart / 1000);

    pTime->elapseSum += elapse;
    // �õ�Ÿ�� ����
    pTime->oldTime = curTime;
    // ��ŸŸ�� ���� (�ʴ���)
    pTime->deltaTime = float(elapse) / 1000;

    //������ ī��Ʈ
    pTime->frameCount++;

    if (pTime->elapseSum >= 1000) // 1�� �����
    {
        pTime->fps = pTime->frameCount;
        pTime->frameCount = 0;
        pTime->elapseSum = 0;
    }

    // �����Ӵ� �ʰ�/�̸� �ð� ����
    pTime->timeStack += elapse - pTime->targetFrame;

    if (pTime->timeStack >= pTime->targetFrame) // ������
    {
        pTime->timeStack -= pTime->targetFrame;
        return true;
    }
    else // ������
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
