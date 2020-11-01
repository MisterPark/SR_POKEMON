#pragma once
#include "Monster.h"
class Scyther :
    public Character
{
public:
    Scyther();
    Scyther(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Scyther();

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    void Attack(const Vector3& dir, const int& attackType);

public:
    static Scyther* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);

public:
    MonsterAI* monsterAI;
};

