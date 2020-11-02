#pragma once
#include "Monster.h"
class Poliwag :
    public Character
{
public:
    Poliwag();
    Poliwag(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Poliwag();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    void Attack(const Vector3& dir, const int& attackType);

public:
    static Poliwag* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);

    virtual void OnCollision(GameObject* target) override;
public:
    MonsterAI* monsterAI;

};

