#pragma once
#include "Bullet.h"

class Blaze :
	public Bullet
{
public:
	Blaze();
	Blaze(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float lifeTime, float att);
	virtual ~Blaze();

public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnCollision(GameObject* target) override;

public:
	static Blaze* Create(
		const Vector3& pos,
		const Vector3& size,
		TextureKey start,
		TextureKey end,
		const Vector3& dir = {0.f, 0.f, 0.f},
		float speed = 0.f,
		float lifeTime = 3.f,
		float att = 2.f
	);
};

