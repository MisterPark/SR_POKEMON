#include "stdafx.h"
#include "RenderFilter.h"
#include "Water.h"
#include "Rectangle.h"

RenderFilter* pRenderFilter = nullptr;

RenderFilter::RenderFilter()
{
    
}

RenderFilter::~RenderFilter()
{
}

RenderFilter* RenderFilter::GetInstance()
{
    if (pRenderFilter == nullptr)
    {
        pRenderFilter = new RenderFilter();
    }
    return pRenderFilter;
}

void RenderFilter::Destroy()
{
    if (pRenderFilter)
    {
        delete pRenderFilter;
        pRenderFilter = nullptr;
    }
}

void RenderFilter::Initialize()
{
}

void RenderFilter::Release()
{
}

void RenderFilter::Update()
{

}

void RenderFilter::Render()
{
    // TODO : 경훈 // 워터 필터 수정해야함.

    // 워터 필터
    GameObject* water = ObjectManager::GetInstance()->FindObject<Water>();
    if (water == nullptr) return;
    GameObject* playerChar = Player::GetInstance()->GetCharacter();
    if (playerChar == nullptr)return;

    Vector3 pos = playerChar->transform->position;
    pos.y = water->transform->position.y;
    
    Vector3 screenPos = Camera::WorldToScreenPoint(pos);
    float yPos = screenPos.y;

    if (Camera::GetInstance()->transform->position.y - 0.5f > water->transform->position.y) return;

    D2DRenderManager::DrawImage(TextureKey::BLUE_FILTER, 0, yPos, 100);
}

