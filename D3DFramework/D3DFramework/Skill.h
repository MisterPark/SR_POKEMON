#pragma once
#include "SkillName.h"
#include "Character.h"

class Skill abstract
{
public:
	Skill();
	virtual ~Skill();

public:
	virtual void InitActiveTime() = 0;
	virtual void Update() = 0;
	void Active(Character* _character);
	void CalcActiveTime();

public:
	// Setter
	void SetIsActive(bool active) { isActive = active; }
	void SetNoneActive();

public:
	// Getter
	float GetCoolTime() { return coolTime; }
	bool GetIsActive() { return isActive; }
	float GetActiveTime() { return activeTime; }
	bool GetCanMove() { return canMove; }
	float GetMoveStopTime() { return moveStopTime; }

protected:
	Character* character = nullptr;
	float coolTime = 0.f;
	float activeTime = 0.f;
	float moveStopTime = 0.f;
	bool isActive = false;
	bool canMove = false;
};