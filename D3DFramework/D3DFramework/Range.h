#pragma once
#include "Bullet.h"
class Range : //TODO : pvp�� ���� ��� �߰��� �ʿ���
    public Bullet
{
public:
    Range();
    virtual ~Range();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    float Time[3];  // ������(�ð�) ��¿뵵

};