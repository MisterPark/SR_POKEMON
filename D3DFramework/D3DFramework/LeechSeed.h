#pragma once
#include "Bullet.h"

class LeechSeed :
	public Bullet
{
public:
	LeechSeed();
	LeechSeed(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float speed, float lifeTime, float att);
	virtual ~LeechSeed();

public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnCollision(GameObject* target) override;
	virtual void CollideOnTerrain() override;

public:
	void NoInstallUpdate();
	void InstallUpdate();

public:
	static LeechSeed* Create(
		const Vector3& pos,
		const Vector3& size,
		float att,
		const Vector3& dir = {0.f, 0.f, 0.f},
		float speed = 0.f,
		float lifeTime = 3.f
	);

private:
	bool isInstall;
	bool isEndLifeTime;
	float installLifeTime;
	float initAttack;
	float tickTime;
	float accGravity;
};

