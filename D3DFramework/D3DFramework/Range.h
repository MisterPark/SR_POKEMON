#pragma once
#include "Effect.h"
class Range : //TODO : pvp�� ���� ��� �߰��� �ʿ���
    public Effect
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