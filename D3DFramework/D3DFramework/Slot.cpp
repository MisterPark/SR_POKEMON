#include "stdafx.h"
#include "Slot.h"
#include "Item.h"

Slot::Slot()
{
}

Slot::~Slot()
{
}

Item* Slot::GetItem()
{
    return item;
}

Item* Slot::SetItem(Item* inItem)
{
    Item* old = item;

    item = inItem;

    return old;
}

void Slot::Update()
{
}

void Slot::Render()
{
    D2DRenderManager::DrawUI(TextureKey::UI_SLOT, position, 0);

    if (item)
    {
        D2DRenderManager::DrawUI(item->anim->GetCurrentSprite(), Vector3(position.x + 3, position.y + 3, 0), 0);
    }
}
