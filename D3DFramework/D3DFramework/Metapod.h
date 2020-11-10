#pragma once
#include "Character.h"
class Metapod :
	public Character
{
public:
	Metapod();
	Metapod(const Vector3& pos, const Vector3& dir,int lv = 1);
	virtual ~Metapod();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
	static Metapod* Create(const Vector3& pos, const Vector3& dir,int lv = 1);

};

