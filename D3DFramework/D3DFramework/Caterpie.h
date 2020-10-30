#pragma once
#include "Monster.h"
class Caterpie :
	public Monster
{
public:
	Caterpie();
	virtual ~Caterpie();

	virtual void Update() override;
	virtual void Render() override;

private:
	void Pattern();
	void RandomMovePattern();
	void Attack(Transform* PlayerT);
	void CreateBullet(Transform* PlayerT);

	
	bool AttackDelay;
};

