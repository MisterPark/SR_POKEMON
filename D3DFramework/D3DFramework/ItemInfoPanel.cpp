#include "stdafx.h"
#include "ItemInfoPanel.h"
#include "Item.h"

ItemInfoPanel* pItemInfoPanel = nullptr;

ItemInfoPanel::ItemInfoPanel()
{
    Initialize();
}

ItemInfoPanel::~ItemInfoPanel()
{
    Release();
}

ItemInfoPanel* ItemInfoPanel::GetInstance()
{
    if (pItemInfoPanel == nullptr)
    {
        pItemInfoPanel = new ItemInfoPanel;
    }
    return pItemInfoPanel;
}

void ItemInfoPanel::Destroy()
{
    if (pItemInfoPanel)
    {
        delete pItemInfoPanel;
        pItemInfoPanel = nullptr;
    }
}

void ItemInfoPanel::Show()
{
    pItemInfoPanel->isVisible = true;
}

void ItemInfoPanel::Hide()
{
    pItemInfoPanel->isVisible = false;
}

Item* ItemInfoPanel::GetTarget()
{
    return pItemInfoPanel->target;
}

void ItemInfoPanel::SetTarget(Item* _item)
{
    pItemInfoPanel->target = _item;
}

void ItemInfoPanel::Initialize()
{
    transform->scale = { 4,3,3 };
}

void ItemInfoPanel::Release()
{
}

void ItemInfoPanel::Update()
{
    transform->position = Cursor::GetMousePos();
}

void ItemInfoPanel::Render()
{
    if (pItemInfoPanel->isVisible == false) return;
    if (pItemInfoPanel->target == nullptr) return;

    Vector3 renderPos;
    renderPos.x = transform->position.x - (transform->scale.x * 64);
    renderPos.y = transform->position.y - (transform->scale.y * 64);
    RenderManager::DrawUI(TextureKey::UI_BLACK_FILTER, renderPos, transform->scale, 0);

    int nameLen = target->name.length();
    int nameW = 20;
    // 패널 길이의 반 - 이름 길이의 반
    float nameOffsetX = (transform->scale.x * 32) - (nameLen * nameW *0.5f);
    RenderManager::DrawFont(target->name, renderPos.x+nameOffsetX, renderPos.y + 10, D3DCOLOR_ARGB(255, 255, 255, 255));

    RenderManager::DrawUI(target->anim->GetCurrentSprite(), renderPos, Vector3(2, 2, 2), 0);

    RenderManager::DrawFont(target->description, renderPos.x +10, renderPos.y + 70, D3DCOLOR_ARGB(255, 255, 255, 255));


    
}
