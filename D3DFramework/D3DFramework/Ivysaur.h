#pragma once
#include "Character.h"

class Ivysaur : public Character
{
public:
	Ivysaur();
	Ivysaur(const Vector3& pos, const Vector3& dir);
	virtual ~Ivysaur();

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
	static Ivysaur* Create(const Vector3& pos, const Vector3& dir);

};