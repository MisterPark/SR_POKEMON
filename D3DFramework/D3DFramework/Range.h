#pragma once
#include "Effect.h"
class Range : //TODO : pvp를 위해 기능 추가가 필요함
    public Effect
{
public:
    Range();
    virtual ~Range();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

private:
    float Time[3];  // 프레임(시간) 재는용도

};