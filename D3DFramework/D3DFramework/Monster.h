#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    
public:
    Monster();
    virtual ~Monster();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;


protected:
	Vector3 RandomDir();
	void Move();
	void PlayerSearch(float _range, float _rangeOut);

protected:
    int Frame[3]; // �����Ǵ�
    float Time[5];  // ������(�ð�) ��¿뵵
	Transform* PlayerTrans = nullptr;
	bool isSearch = false;
    
};

