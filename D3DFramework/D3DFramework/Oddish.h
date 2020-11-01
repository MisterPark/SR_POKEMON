#pragma once
#include "Monster.h"
class Oddish :
    public Character
{
public:
    Oddish();
    Oddish(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Oddish();
    
public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    void Attack(const Vector3& dir, const int& attackType);

public:
    static Oddish* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);

public:
    MonsterAI* monsterAI;
};

