#include "stdafx.h"
#include "ItemInfoPanel.h"

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

void ItemInfoPanel::SetTarget(Item* _item)
{
    pItemInfoPanel->target = _item;
}

void ItemInfoPanel::Initialize()
{
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
    //if (pItemInfoPanel->target == nullptr) return;


    D2DRenderManager::DrawUI(TextureKey::UI_BLACK_FILTER, transform->position, transform->scale, 0);

}
