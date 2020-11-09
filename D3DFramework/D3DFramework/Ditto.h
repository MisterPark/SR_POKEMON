#pragma once
#include "Character.h"

class Ditto : public Character
{
public:
	Ditto();
	Ditto(const Vector3& pos, const Vector3& dir);
    virtual ~Ditto();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual void ChangeState(State nextState) override;
	void AnimSet();

public:
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Ditto* Create(const Vector3& pos, const Vector3& dir);
public:
	MonsterAI* monsterAI;
};

