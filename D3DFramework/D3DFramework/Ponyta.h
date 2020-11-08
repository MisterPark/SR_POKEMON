#pragma once
#include "Character.h"
class Ponyta :
    public Character
{
public:
    Ponyta();
    Ponyta(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Ponyta();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Ponyta* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    
public:
    MonsterAI* monsterAI;

};

