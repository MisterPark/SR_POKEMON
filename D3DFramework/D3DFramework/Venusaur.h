#pragma once
#include "Character.h"

class Venusaur : public Character
{
public:
	Venusaur();
	Venusaur(const Vector3& pos, const Vector3& dir,int lv = 1);
	virtual ~Venusaur();

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
	static Venusaur* Create(const Vector3& pos, const Vector3& dir,int lv = 1);

};