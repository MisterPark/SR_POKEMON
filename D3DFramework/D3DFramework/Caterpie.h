#pragma once
#include "Character.h"
class Caterpie :
	public Character
{
public:
	Caterpie();
	Caterpie(const Vector3& pos, const Vector3& dir,int lv = 1);
	virtual ~Caterpie();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Caterpie* Create(const Vector3& pos, const Vector3& dir,int lv = 1);

};

