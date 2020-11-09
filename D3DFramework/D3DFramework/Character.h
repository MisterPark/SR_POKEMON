#pragma once
#include "GameObject.h"
#include "MonsterAI.h"
#include "Spawner.h"

class Skill;

class Character :
    public GameObject
{
public:
    Character();
    virtual ~Character();
    // GameObject을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
	void RenderInfomation();

    // GameObject을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;

	virtual void OnCollision(GameObject* target) override;

	void CalcMoveTime();

	// 지형 타기
    void OnTerrain();
	// 카메라로 부터 텍스쳐 각도
	float GetAngleFromCamera();
	// 애니메이션 업데이트
	void UpdateAnimation();
	// 애니메이션 텍스쳐 설정
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);

public:
	void SetDir(const Vector3& dir);
	void SetMoveSpeed(const float& speed) { stat.moveSpeed = speed; }
	void MoveForward();
	virtual void ChangeState(State nextState);
	// 인자로 넣어준 숫자 번째의 스킬을 반환합니다.
	float GetSkillCoolTime(int num);
	bool GetCanMove() { return canMove; }
	int GetSkillSetSize() { return skillSet.size(); }
	vector<Skill*> GetSkillSet() { return skillSet; }

	virtual bool Attack(const Vector3& dir, const int& attackType);
	

public:
	static bool IsNotAlliance(GameObject* a, GameObject* b);
public:
	Spawner* spawner = nullptr;

	//Stat
	wstring name;
	Pokemon number = Pokemon::None;
    // 지형과 간격
    float offsetY;
	Vector3 direction = { 0,0,1 };
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	bool infoVisible = true;
	bool isInvincible = false;
	MonsterAI* monsterAI=nullptr;
protected:
	vector<Skill*> skillSet;
	float healEffectStack;
	float moveStopTime;
	bool canMove;
	State oldState = State::IDLE;
};

