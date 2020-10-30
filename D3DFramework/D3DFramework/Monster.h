#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    
public:
    Monster();
    virtual ~Monster();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;


protected:
	Vector3 RandomDir();
	void Move();
	void PlayerSearch(float _range, float _rangeOut);

protected:
    int Frame[3]; // 패턴판단
    float Time[5];  // 프레임(시간) 재는용도
	Transform* PlayerTrans = nullptr;
	bool isSearch = false;
    
};

