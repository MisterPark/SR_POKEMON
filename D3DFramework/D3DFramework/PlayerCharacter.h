#pragma once
#include "Character.h"

class PlayerCharacter : public Character
{
public:
	PlayerCharacter();
    virtual ~PlayerCharacter();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual void Attack(const Vector3& dir);
	virtual void Skill(const Vector3& dir);
};

