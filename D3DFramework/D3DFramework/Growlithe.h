#pragma once
#include "Character.h"
class Growlithe :
	public Character
{
public:
	Growlithe();
	Growlithe(const Vector3& pos, const Vector3& dir);
	virtual ~Growlithe();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Growlithe* Create(const Vector3& pos, const Vector3& dir);


public:
	MonsterAI* monsterAI;

};

