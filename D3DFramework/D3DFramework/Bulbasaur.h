#pragma once
#include "Character.h"

class Bulbasaur : public Character
{
public:
	Bulbasaur();
	Bulbasaur(const Vector3& pos, const Vector3& dir);
	virtual ~Bulbasaur();

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
	static Bulbasaur* Create(const Vector3& pos, const Vector3& dir);

};