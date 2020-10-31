#include "stdafx.h"
#include "Tree.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

Tree::Tree()
{
    startArray[0][0] = TextureKey::TREE02;
    anim->SetSprite(startArray[0][0], startArray[0][0]);
    float size = 1.f;
    transform->scale += {size, size, 0};
    offsetY = 1.f+size;
}


Tree::~Tree()
{
}

void Tree::Update()
{
    UpdateAnimation();
    OnTerrain();
    GameObject::Update();
    BillboardYaw();
}

void Tree::Render()
{
 
    Character::Render();
}


void Tree::UpdateAnimation()
{
    
    anim->SetSprite(startArray[0][0], startArray[0][0]);
}
