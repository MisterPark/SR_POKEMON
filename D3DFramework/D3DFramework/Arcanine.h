#pragma once
#include "Character.h"
class Arcanine :
	public Character
{
public:
	Arcanine();
	Arcanine(const Vector3& pos, const Vector3& scale, const Vector3& dir);
	virtual ~Arcanine();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Arcanine* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);


public:
	MonsterAI* monsterAI;

};

