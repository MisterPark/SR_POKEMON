#pragma once
#include "GameObject.h"

class Effect :
	public GameObject
{
public:
	Effect();
	Effect(const Vector3& pos, const Vector3& scale, const Vector3& dir);
	virtual ~Effect();

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
	static Effect* Create(
		const Vector3& pos,
		const Vector3& scale,
		const Vector3& dir);

public:
	int att;
	bool isPlayer;
	Vector3 direction = { 0,0,1 };;
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
};

