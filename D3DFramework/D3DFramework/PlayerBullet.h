#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet
{
public:
	enum Type { LEAF, FIRE };

public:
	PlayerBullet();
	PlayerBullet(const Vector3& pos, const Vector3& dir, const Type& type, const bool& isAlliance = true);
    virtual ~PlayerBullet();
    
public:
	void InitByType();
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

public:
	void CalcLifeTime();

private:
	Type bulletType;
	float lifeTime;
};