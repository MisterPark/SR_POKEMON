#pragma once
#include "Monster.h"
class Scyther :
    public Monster
{
public:
    Scyther();
    virtual ~Scyther();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    void Parttern();
    void SkillBullet();
    void Skill2Bullet();
};

