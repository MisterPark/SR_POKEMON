#pragma once
#include "Bullet.h"
class Bullet_Tornado :
    public Bullet
{
public:
    Bullet_Tornado();
    virtual ~Bullet_Tornado();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    void RotateMove();

    float rotateMoveX = false;
    float rotateMoveZ = false;
    
	float spawnTimeGap;
	int Frame[2];
};