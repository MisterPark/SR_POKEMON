#pragma once
#include "GameObject.h"

class Effect :
	public GameObject
{
public:
	Effect();
	Effect(const Vector3& pos, const Vector3& scale, const Vector3& dir);
	virtual ~Effect();

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	virtual void Initialize() override;
	virtual void Release() override;

	// 카메라로 부터 텍스쳐 각도
	float GetAngleFromCamera();
	// 애니메이션 업데이트
	void UpdateAnimation();
	// 애니메이션 텍스쳐 설정
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);
	// 방향없는 애니메이션 텍스쳐 설정
	void SetAniTexture(State _state, TextureKey _beginTextureKey, int _aniFrame);

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
	bool isBillboard = true;
	bool isMove = false;
	float isDeadTime = 0.f;
	Vector3 direction = { 0,0,1 };;
	Animation2D* anim = nullptr;
	State state = State::IDLE;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
};

