#pragma once
#include "Monster.h"
class Monster_Butterfree :
    public Monster
{
public:
    Monster_Butterfree();
    virtual ~Monster_Butterfree();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
	void ButterfreeParttern();
    void RandomMovePattern();
	void SetTextureAngle();
    void Attack();
    
    void SetSpriteWork();
    void SetSpriteAttack();

private:
    Animation2D* ani;
    int EnumKey;
    float Angle;
};

