#pragma once
#include "Character.h"

class Bulbasaur : public Character
{
public:
	Bulbasaur();
	Bulbasaur(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Bulbasaur();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual void Attack(const Vector3& dir) override;
	virtual void Skill(const Vector3& dir) override;

public:
	static Bulbasaur* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);
};

