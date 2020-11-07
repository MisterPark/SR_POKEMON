#pragma once
#include "AllCharacters.h"
class Groudon :
	public Character
{
public:
	Groudon();
	Groudon(const Vector3& pos, const Vector3& scale, const Vector3& dir);
	virtual ~Groudon();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Groudon* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);

public:
	MonsterAI* monsterAI;

};

