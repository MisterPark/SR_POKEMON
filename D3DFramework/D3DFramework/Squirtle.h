#pragma once
#include "Character.h"

class Squirtle : public Character
{
public:
	Squirtle();
	Squirtle(const Vector3& pos, const Vector3& dir,int lv = 1);
	virtual ~Squirtle();

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
	static Squirtle* Create(const Vector3& pos, const Vector3& dir,int lv = 1);
};


