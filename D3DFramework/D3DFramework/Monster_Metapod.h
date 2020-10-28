#pragma once
#include "Monster.h"
class Monster_Metapod :
	public Monster
{
public:
	Monster_Metapod();
	virtual ~Monster_Metapod();

	virtual void Update() override;
	virtual void Render() override;


private:
	void Pattern();
	void RandomMovePattern();

};

