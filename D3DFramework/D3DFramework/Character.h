#pragma once
#include "GameObject.h"
#include "MonsterAI.h"
#include "Spawner.h"

class Skill;

enum class TYPE {
	BULBASAUR, IVYSAUR, VENUSAUR,
	CATERPIE, METAPOD, ODDISH, GLOOM, VILEPLUME, SCYTHER, BUTTERFREE,
	SQUIRTLE, WARTORTLE, BLASTOISE,
	PSYDUCK, GOLDUCK, POLIWAG, POLIWHIRL, POLIWRATH, JYNX, SUICUNE,
	CHARMANDER, CHARMELEON, CHARIZARD,
	GROWLITHE, ARCANINE, PONYTA, RAPIDASH, SLUGMA, MAGCARGO, GROUDON,
	DITTO,
	END
};

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
	virtual void Die() override;

	void CalcMoveTime();
	void CalcExp();

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
	void SetLV(const int& lv);
	void IncreaseEXP(const float& _exp) { stat.exp += _exp; }
	void LevelUp();
	void SetStatByLevel();
	void MoveForward();
	virtual void ChangeState(State nextState);

public:
	// ���ڷ� �־��� ���� ��°�� ��ų�� ��ȯ�մϴ�.
	float GetSkillCoolTime(int num);
	bool GetCanMove() { return canMove; }
	int GetSkillSetSize() { return skillSet.size(); }
	vector<Skill*> GetSkillSet() { return skillSet; }

	virtual bool Attack(const Vector3& dir, const int& attackType);
	void HealMyself(float _recovery);

public:
	void SetIncreaseAttack(const float& atk) { increaseAttack = atk; }
	void SetDefaultAttack(const float& atk) { defaultAttack = atk; }

public:
	float GetIncreaseAttack() const { return increaseAttack; }
	float GetDefaultAttack() const { return defaultAttack; }

public:
	static bool IsNotAlliance(GameObject* a, GameObject* b);
public:
	Spawner* spawner = nullptr;

	//Stat
	
	Pokemon number = Pokemon::None;
	TYPE type = TYPE::END;
    // ������ ����
    float offsetY;
	Vector3 direction = { 0,0,1 };
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	bool infoVisible = true;
	bool isInvincible = false;
	MonsterAI* monsterAI;

protected:
	vector<Skill*> skillSet;
	float healEffectStack;
	float moveStopTime;
	bool canMove;
	State oldState = State::IDLE;

	float increaseAttack = 0.f;
	float increaseMaxHp = 0.f;
	float increaseTotalExp = 30.f;

	float defaultAttack = 0.f;
	float defaultMaxHp = 0.f;
	float defaultTotalExp = 50.f;
};

