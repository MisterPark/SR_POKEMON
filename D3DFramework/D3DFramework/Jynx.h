#pragma once
#include "Monster.h"
class Jynx :
    public Character
{
public:
    Jynx();
    Jynx(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Jynx();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    void Attack(const Vector3& dir, const int& attackType);

public:
    static Jynx* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);

public:
    MonsterAI* monsterAI;

};

