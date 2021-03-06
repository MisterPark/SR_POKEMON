#include "stdafx.h"
#include "RenderFilter.h"
#include "Water.h"
#include "Rectangle.h"

RenderFilter* pRenderFilter = nullptr;

RenderFilter::RenderFilter()
{
    //Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
    //mesh->SetBlendMode(BlendMode::ALPHA_BLEND);
    //mesh->SetTexture(TextureKey::BLUE_FILTER);
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

    // 워터필터,블루필터,렌더필터
    GameObject* water = ObjectManager::GetInstance()->FindObject<Water>();
    if (water == nullptr) return;
    GameObject* playerChar = Player::GetInstance()->GetCharacter();
    if (playerChar == nullptr)return;

    Vector3 dir = Camera::GetInstance()->transform->look.Normalized();
    Vector3 pos = playerChar->transform->position;
    pos.y = water->transform->position.y;
    
    Vector3 screenPos = Camera::WorldToScreenPoint(pos);
    float yPos = screenPos.y;

    float camY = Camera::GetInstance()->transform->position.y;
    if (camY - 0.7f > water->transform->position.y) return;

    if (yPos > dfCLIENT_HEIGHT)
    {
        yPos = 0;
    }
    RenderManager::DrawImage(TextureKey::UI_BLUE_FILTER, 0, yPos, 100);
    //GameObject::Render();
}

