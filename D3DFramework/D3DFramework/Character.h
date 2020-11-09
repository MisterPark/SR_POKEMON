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
    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
	void RenderInfomation();

    // GameObject��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;

	virtual void OnCollision(GameObject* target) override;

	void CalcMoveTime();

	// ���� Ÿ��
    void OnTerrain();
	// ī�޶�� ���� �ؽ��� ����
	float GetAngleFromCamera();
	// �ִϸ��̼� ������Ʈ
	void UpdateAnimation();
	// �ִϸ��̼� �ؽ��� ����
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);

public:
	void SetDir(const Vector3& dir);
	void SetMoveSpeed(const float& speed) { stat.moveSpeed = speed; }
	void MoveForward();
	virtual void ChangeState(State nextState);
	// ���ڷ� �־��� ���� ��°�� ��ų�� ��ȯ�մϴ�.
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
    // ������ ����
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

