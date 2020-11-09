#pragma once
#include "Character.h"
class Scyther :
    public Character
{
public:
    Scyther();
    Scyther(const Vector3& pos, const Vector3& dir);
    virtual ~Scyther();

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	virtual void ChangeState(State nextState) override;
	void AnimSet();

public:
    static Scyther* Create(const Vector3& pos, const Vector3& dir);


public:
    MonsterAI* monsterAI;
};

