#include "stdafx.h"
#include "Bullet_Water.h"
#include "Rectangle.h"
#include "Player.h"

Bullet_Water::Bullet_Water()
{
    Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
    Animation2D* ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

    //anim->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
    anim->SetSprite(TextureKey::BULLET_TEARS_01, TextureKey::BULLET_TEARS_01);
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

    for (int i = 0; i < 3; i++)
    {
        Time[i] = 0;
    }

    transform->scale.x *= 0.5f;
    transform->scale.y *= 0.5f;
    transform->scale.z *= 0.5f;
}

Bullet_Water::~Bullet_Water()
{
}

void Bullet_Water::Update()
{

    Character::Update();

    transform->position += MoveDir * 3.f * TimeManager::DeltaTime();;


    Time[0] += TimeManager::DeltaTime();
    if (Time[0] >= 5.f) {
        isDead = true;
    }
    Billboard();
}

void Bullet_Water::Render()
{
    Character::Render();
}

void Bullet_Water::OnCollision(GameObject* target)
{
    if (target->isAlliance == this->isAlliance) {
        return;
    }

    //if (dynamic_cast<Player*>(target)) {
       //몬스터와 충돌 이벤트
    isDead = true;
    //}
}