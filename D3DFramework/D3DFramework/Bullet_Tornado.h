#pragma once
#include "Bullet.h"
class Bullet_Tornado :
    public Bullet
{
public:
    Bullet_Tornado();
    virtual ~Bullet_Tornado();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    void RotateMove();

    float rotateMoveX = false;
    float rotateMoveZ = false;
    
	float spawnTimeGap;
	float damageTime;
	int Frame[2];
	float soundDelay = 0.f;
};