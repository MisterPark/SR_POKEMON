#pragma once
#include "GameObject.h"

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
	void RenderName();

    // GameObject��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;

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
	void SetIsEnemy(const bool& _isEnemy) { isEnemy = _isEnemy; }
	bool GetIsEnemy() const { return isEnemy; }
	void SetMoveSpeed(const float& speed) { moveSpeed = speed; }
	void MoveForward();
	void ChangeState(State nextState);
	// ���ڷ� �־��� ���� ��°�� ��ų�� ��ȯ�մϴ�.
	Skill* GetSkillCollTime(int skillNumber);

	virtual void Attack(const Vector3& dir, const int& attackType);

public:
	wstring name;
	float hp;
	float att;
    // ������ ����
    float offsetY;
	Vector3 direction = { 0,0,1 };
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];

protected:
	vector<Skill*> skillSet;
	bool isEnemy;
};

