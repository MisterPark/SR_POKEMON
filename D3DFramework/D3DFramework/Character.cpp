#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	CollisionManager::RegisterObject(this);
}

Character::~Character()
{
	CollisionManager::DisregisterObject(this);
}

void Character::Update()
{
	GameObject::Update();
}

void Character::Render()
{
	GameObject::Render();
}
