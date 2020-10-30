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

	// ī�޶�� ���� �ؽ��� ����
	float GetAngleFromCamera();
	// �ִϸ��̼� ������Ʈ
	void UpdateAnimation();
	// �ִϸ��̼� �ؽ��� ����
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);

public:
	void SetDir(const Vector3& dir);
	void SetMoveSpeed(const float& speed) { moveSpeed = speed; }
	void MoveForward();
	void ChangeState(State nextState);
	static Bullet* Create(
		const Vector3& pos,
		const Vector3& scale,
		const Vector3& dir,
		const bool& isPlayer = true);

public:
	int att;
	bool isBillboard = true;
	Vector3 direction = { 0,0,1 };
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
};

