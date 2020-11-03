#include "stdafx.h"
#include "Coral.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

Coral::Coral()
{
    isOnTerrain = true;
    anim->SetSprite(TextureKey::BLUECORAL01, TextureKey::BLUECORAL01);
    anim->SetLoop(false);
    float size = -0.4f;
    transform->scale += {size, size, 0};
    offsetY = 1.f + size;
}


Coral::~Coral()
{
}

void Coral::Update()
{

    OnTerrain();
    Decoration::Update();
    BillboardYaw();
}

void Coral::Render()
{

    Decoration::Render();
}

void Coral::setCoralSprite(TextureKey _Coral)
{
    anim->SetSprite(_Coral, _Coral);
    anim->SetLoop(false);
}

void Coral::Initialize()
{
}

void Coral::Release()
{
}
