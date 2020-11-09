#pragma once
#include "Character.h"

class Charmander : public Character
{
public:
	Charmander();
	Charmander(const Vector3& pos, const Vector3& dir);
    virtual ~Charmander();

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
	static Charmander* Create(const Vector3& pos, const Vector3& dir);
};

