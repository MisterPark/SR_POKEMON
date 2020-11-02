#pragma once
#include "GameObject.h"

class Bullet :
	public GameObject
{
public:
	Bullet();
	Bullet(const Vector3& pos, const Vector3& scale, const Vector3& dir, const bool& alliance = true);
	virtual ~Bullet();

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

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
	// ������� �ִϸ��̼� �ؽ��� ����
	void SetAniTexture(State _state, TextureKey _beginTextureKey, int _aniFrame);

public:
	//�÷��̾ ���ϴ� ���⺤�͸� Normalize �ϰ� ��ȯ�մϴ�.
	//���ڰ� false �Ͻ� Y���� �����մϴ�.
	Vector3 PlayerSearchDir(bool PosY = true);
	Vector3 MonsterSearchDir(bool PosY, float SearchRange);
	void SetDir(const Vector3& dir);
	void SetMoveSpeed(const float& speed) { moveSpeed = speed; }
	void MoveForward();
	void MoveForwardExceptY();
	void ChangeState(State nextState);
	static Bullet* Create(
		const Vector3& pos,
		const Vector3& scale,
		const Vector3& dir,
		const bool& isPlayer = true);

public:
	int Frame[3];
	float Time[3];
	int att;
	float isDeadTime = 0.f;
	bool isOnTerrain = false;
	float offsetY = 0.f;
	bool isBillboard = true;
	Vector3 direction = { 0.f ,0.f ,0.f };
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
};

