#pragma once
#include "Character.h"
class Magcargo :
    public Character
{
public:
    Magcargo();
    Magcargo(const Vector3& pos, const Vector3& dir,int lv = 1);
    virtual ~Magcargo();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;
    virtual void OnCollision(GameObject* target) override;

    void DeadAction();

public:
    static Magcargo* Create(const Vector3& pos, const Vector3& dir,int lv = 1);


};

