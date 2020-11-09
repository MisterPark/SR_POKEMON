#pragma once
#include "Character.h"
class Poliwrath :
    public Character
{
public:
    Poliwrath();
    Poliwrath(const Vector3& pos, const Vector3& dir);
    virtual ~Poliwrath();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Poliwrath* Create(const Vector3& pos, const Vector3& dir);

public:
    MonsterAI* monsterAI;

};

