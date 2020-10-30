#pragma once
#include "Monster.h"
class Vileplume :
    public Monster
{
public:
    Vileplume();
    virtual ~Vileplume();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void RandomMovePattern();
    void Attack(Transform* PlayerT);
    void CrossBullet();
	void XBullet();

	bool isSearch = false;
    bool AttackDelay;
};


