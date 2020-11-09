#pragma once
#include "Bullet.h"

class PetalBlizzard :
	public Bullet
{
public:
	PetalBlizzard();
	PetalBlizzard(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float att);
	virtual ~PetalBlizzard();

public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnCollision(GameObject* target) override;
	virtual void CollideOnTerrain() override;

public:
	static PetalBlizzard* Create(
		const Vector3& pos,
		const Vector3& size,
		const Vector3& dir,
		float att
	);

private:
	float initAttack;
	float readyDieTime;
	bool isDeadAnimation;
	bool isReadyToDie;
};

