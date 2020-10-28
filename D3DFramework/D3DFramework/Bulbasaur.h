#pragma once
#include "PlayerCharacter.h"

class Bulbasaur : public PlayerCharacter
{
public:
	Bulbasaur();
	Bulbasaur(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Bulbasaur();

public:
	void Init();

public:
	virtual void Attack(const Vector3& dir) override;
	virtual void Skill(const Vector3& dir) override;

public:
	static Bulbasaur* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);
};

