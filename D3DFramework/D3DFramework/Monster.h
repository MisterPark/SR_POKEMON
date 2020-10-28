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

	void SetTextureAngle();
	void SetSpriteWalk();
	void SetSpriteAttack();
protected:
    

protected:
    int Frame[3]; // �����Ǵ�
    float Time[5];  // ������(�ð�) ��¿뵵


	int EnumKey;
	TextureKey TextureAttack;
	TextureKey TextureWALK;
    
};

