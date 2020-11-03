#pragma once
#include "Character.h"
class Metapod :
	public Character
{
public:
	Metapod();
	Metapod(const Vector3& pos, const Vector3& scale, const Vector3& dir);
	virtual ~Metapod();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void Attack(const Vector3& dir, const int& attackType);

public:
	static Metapod* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);


public:
	MonsterAI* monsterAI;

};

