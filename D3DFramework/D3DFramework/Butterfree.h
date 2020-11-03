#pragma once
#include "Character.h"
class Butterfree :
    public Character
{
public:
    Butterfree();
    Butterfree(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Butterfree();

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    void Attack(const Vector3& dir, const int& attackType);


private:
    //void Pattern();
    //void Attack();

public:
    static Butterfree* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);


public:
    MonsterAI* monsterAI;
};

