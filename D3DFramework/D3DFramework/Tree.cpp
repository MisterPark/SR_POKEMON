#include "stdafx.h"
#include "Tree.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

Tree::Tree()
{
    isOnTerrain = true;
    anim->SetSprite(TextureKey::TREE05, TextureKey::TREE05);
    anim->SetLoop(false);
    float size = 0.f;
    transform->scale += {size, size, 0};
    offsetY = 1.f+size;
}


Tree::~Tree()
{
}

void Tree::Update()
{
    
    OnTerrain();
    Decoration::Update();
    BillboardYaw();
}

void Tree::Render()
{
 
    Decoration::Render();
}

void Tree::setTreeSprite(TextureKey _tree)
{
    anim->SetSprite(_tree,_tree);
    anim->SetLoop(false);
}

void Tree::Initialize()
{
}

void Tree::Release()
{
}
