#pragma once
#include "GameObject.h"

class Bullet :
	public GameObject
{
public:
	Bullet();
	Bullet(const Vector3& pos, const Vector3& scale, const Vector3& dir, const bool& alliance = true);
	virtual ~Bullet();

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

	virtual void Initialize() override;
	virtual void Release() override;

	// 지형 타기
	void OnTerrain();
	// 카메라로 부터 텍스쳐 각도
	float GetAngleFromCamera();
	// 애니메이션 업데이트
	void UpdateAnimation();
	// 애니메이션 텍스쳐 설정
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);
	// 방향없는 애니메이션 텍스쳐 설정
	void SetAniTexture(State _state, TextureKey _beginTextureKey, int _aniFrame);

public:
	//플레이어를 향하는 방향벡터를 Normalize 하고 반환합니다.
	//인자가 false 일시 Y값은 제외합니다.
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

