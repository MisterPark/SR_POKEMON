#pragma once
#include "Character.h"

class Ivysaur : public Character
{
public:
	Ivysaur();
	Ivysaur(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Ivysaur();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual void Attack(const Vector3& dir) override;
	virtual void Skill(const Vector3& dir) override;

public:
	static Ivysaur* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);
};
