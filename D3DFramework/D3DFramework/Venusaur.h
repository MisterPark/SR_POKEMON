#pragma once
#include "Character.h"

class Venusaur : public Character
{
public:
	Venusaur();
	Venusaur(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    virtual ~Venusaur();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Venusaur* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);
};

