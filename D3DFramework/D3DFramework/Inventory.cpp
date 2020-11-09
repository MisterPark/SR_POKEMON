#include "stdafx.h"
#include "Inventory.h"
#include "Item.h"

Inventory* pInventory = nullptr;

Inventory::Inventory()
{
    position = { 700,200,0 };
    isVisible = false;
    
}

Inventory::~Inventory()
{
    for (int i = 0; i < dfMAX_SLOT_COUNT; i++)
    {
        Item* item = pInventory->slots[i].GetItem();
        if (item == nullptr)continue;
        delete item;

        pInventory->slots[i].SetItem(nullptr);
    }
}

Inventory* Inventory::GetInstance()
{
    if (pInventory == nullptr)
    {
        pInventory = new Inventory;
    }
    return pInventory;
}

void Inventory::Destroy()
{
    if (pInventory)
    {
        delete pInventory;
        pInventory = nullptr;
    }
}

void Inventory::Show()
{
    pInventory->isVisible = true;
    Cursor::Show();
}

void Inventory::Show(bool on)
{
    pInventory->isVisible = on;
    if (on)
    {
        Cursor::Show();
    }
    else
    {
        Cursor::Hide();
    }
}

void Inventory::Hide()
{
    pInventory->isVisible = false;
    Cursor::Hide();
}

void Inventory::Update()
{
    pInventory->UpdateUI();

    for (int i = 0; i < dfMAX_SLOT_COUNT; i++)
    {
        pInventory->slots[i].Update();
    }
}

void Inventory::Render()
{
    if (pInventory->isVisible == false)return;
    D2DRenderManager::DrawUI(TextureKey::UI_BAG, pInventory->position, 0);

    for (int i = 0; i < dfMAX_SLOT_COUNT; i++)
    {
        pInventory->slots[i].Render();
    }
    
    
}

bool Inventory::Push(Item* item)
{
    Item* out = nullptr;
    for (int i = 0; i < dfMAX_SLOT_COUNT; i++)
    {
        if (pInventory->slots[i].GetItem() != nullptr) continue;

        pInventory->slots[i].SetItem(item);
        return true;
    }

    return false;
}

void Inventory::UpdateUI()
{
    Vector3 slotPosition = { position.x + 50, position.y + 100,0 };
    Vector3 slotOffset = slotPosition;

    int iter = 0;

    for (int i = 0; i < dfSLOT_ROW_COUNT; i++)
    {
        slotOffset.y = slotPosition.y + i * 40;

        for (int j = 0; j < dfSLOT_COL_COUNT; j++)
        {
            slotOffset.x = slotPosition.x + j * 40;

            slots[iter].position = slotOffset;
            iter++;
        }

    }
}
