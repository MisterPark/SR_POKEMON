#pragma once
#include "Character.h"
#include "Animation2D.h"

class TestObj : public Character
{
public:
	enum STATE { IDLE, WALK, ATTACK, SKILL, HURT };
	enum DIR { D, LD, L, LU, U, RU, R, RD };

public:
    TestObj();
    virtual ~TestObj();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	void SetPos(const Vector3& pos);
	void SetDir(const Vector3& dir);
	void ChangeAnim(STATE state, DIR dir);
	void CalcDir();

private:
	void SetAnim();

private:
	Animation2D* anim;
	STATE curState;
	DIR curDir;
	Vector3 myDir;
};

