#pragma once
#include "Character.h"
class Gloom :
    public Character
{
public:
    Gloom();
    Gloom(const Vector3& pos ,const Vector3& dir);
    virtual ~Gloom();

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Gloom* Create(const Vector3& pos, const Vector3& dir);


public:
    MonsterAI* monsterAI;
};

