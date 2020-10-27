#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    enum class Status
    {
        MOVE, ATTACK, PLAYER_SEARCH, SKILL, END
    };
public:
    Monster();
    virtual ~Monster();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

	void SetTextureAngle();
	void SetSpriteWalk();
	void SetSpriteAttack();
protected:
    

protected:
    int Frame[3]; // 패턴판단
    float Time[5];  // 프레임(시간) 재는용도
    Status CurrentStatus = Status::END;
    Vector3 AttackDir;
    Vector3 MoveDir;

	Animation2D* ani;
	float Angle;
	int EnumKey;
	TextureKey TextureAttack;
	TextureKey TextureWALK;
    
};

