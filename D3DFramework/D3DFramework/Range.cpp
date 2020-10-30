#include "stdafx.h"
#include "Range.h"
#include "Rectangle.h"
#include "Player.h"
#include "Effect.h"

Range::Range()
{   //TODO : 불렛이 지형타는중
    SetTexture(State::IDLE, TextureKey::RANGE, 1);
    UpdateAnimation();
    state = State::IDLE;
    anim->SetLoop(true);
    anim->SetDelay(0.2f);


   

    for (int i = 0; i < 3; i++)
    {
        Time[i] = 0;
    }


    moveSpeed = 0.f;
}

Range::~Range()
{
}

void Range::Update()
{
    
    Effect::Update();

    /*transform->position += direction * moveSpeed * TimeManager::DeltaTime();;*/
    Time[0] += TimeManager::DeltaTime();
    if (Time[0] >= 1.f) {
        isDead = true;
    }

}

void Range::Render()
{
    Effect::Render();
}
