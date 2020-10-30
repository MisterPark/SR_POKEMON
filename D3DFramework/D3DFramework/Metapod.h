#pragma once
#include "Monster.h"
class Metapod :
	public Monster
{
public:
	Metapod();
	virtual ~Metapod();

	virtual void Update() override;
	virtual void Render() override;


private:
	void Pattern();
	

};

