#pragma once
#include "Effect.h"
class Water : //TODO : pvp�� ���� ��� �߰��� �ʿ���
	public Effect
{
public:
	Water();
	virtual ~Water();
	// Character��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	float Time[3];  // ������(�ð�) ��¿뵵

};