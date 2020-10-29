#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet
{
public:
	PlayerBullet();
	PlayerBullet(const Vector3& pos, const Vector3& scale, const Vector3& dir, const int& type, const bool& isAlliance = true);
    virtual ~PlayerBullet();
    
public:
	void Init();
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
	int bulletType;
};