#pragma once
#include "GameObject.h"

class Character;

class TargetInfoPanel :
    public GameObject
{
private:
    TargetInfoPanel();
    virtual ~TargetInfoPanel();

public:
    static TargetInfoPanel* GetInstance();
    static void Destroy();

    static void Show();
    static void Hide();

    static void SetTarget(Character* _target);
	static Character* GetTarget();

    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;
    virtual void Render() override;


private:
    Character* target = nullptr;
    float activationTick = 0.f;
    float activationDuration = 5.f;
};

