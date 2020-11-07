#pragma once
#include "Bullet.h"

class Meteor :
	public Bullet
{
public:
	Meteor();
	Meteor(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float speed, float lifeTime, float att);
	virtual ~Meteor();

public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnCollision(GameObject* target) override;
	virtual void CollideOnTerrain() override;

public:
	static Meteor* Create(
		const Vector3& pos,
		const Vector3& size,
		float att,
		const Vector3& dir = {0.f, 0.f, 0.f},
		float speed = 0.f,
		float lifeTime = 3.f
	);
};

