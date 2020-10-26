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
	void ButterfreeParttern();
    void RandomMovePattern();
	void SetTextureAngle();

    void Attack();

private:
    Animation2D* ani;
};

