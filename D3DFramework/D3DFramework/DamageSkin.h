#pragma once
#include "UI.h"
class DamageSkin :
    public UI
{
public:
    DamageSkin();
    virtual ~DamageSkin();
    // UI을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void UpdateUI() override;
    virtual void Update() override;
    virtual void Render() override;


public:
    void SetDamage(int _damage);

private:
    int damage = 0;
    float lifeTick = 0.f;
    float lifeTime = 1.5f;
};

