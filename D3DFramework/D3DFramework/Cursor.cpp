#include "stdafx.h"
#include "Cursor.h"

PKH::Cursor* pCursor = nullptr;

PKH::Cursor::Cursor()
{
    
}

PKH::Cursor::~Cursor()
{
}

Cursor* PKH::Cursor::GetInstance()
{
    if (pCursor == nullptr)
    {
        pCursor = new Cursor();
    }
    return pCursor;
}

void PKH::Cursor::Destroy()
{
    if (pCursor)
    {
        delete pCursor;
        pCursor = nullptr;
    }
}

Vector3 PKH::Cursor::GetMousePos()
{
    Vector3 pos;
    POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(g_hwnd, &pt);
    pos.x = pt.x;
    pos.y = pt.y;
    return pos;
}

void PKH::Cursor::Show()
{
    if (pCursor->isVisible) return;

    pCursor->isVisible = true;
    ShowCursor(TRUE);
}

void PKH::Cursor::Show(bool on)
{
    pCursor->isVisible = on;
}

void PKH::Cursor::Hide()
{
    if (pCursor->isVisible == false) return;

    pCursor->isVisible = false;
    ShowCursor(FALSE);
}

void PKH::Cursor::Update()
{
    if (isEnable == false)return;
    transform->position = GetMousePos();
}

void PKH::Cursor::Render()
{
    if (isVisible == false)return;
    D2DRenderManager::DrawSprite(TextureKey::UI_CURSOR_TARGET, *transform, 0);
}

void PKH::Cursor::Initialize()
{
}

void PKH::Cursor::Release()
{
}

bool PKH::Cursor::IsVisible()
{
    return pCursor->isVisible;
}
