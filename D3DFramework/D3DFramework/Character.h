#pragma once
#include "GameObject.h"

enum class State
{
	IDLE, WALK, ATTACK, PLAYER_SEARCH, SKILL, HURT, END
};
enum DIR { D, LD, L, LU, U, RU, R, RD };
enum class Direction
{
	D, LD, L, LU, U, RU, R, RD, END
};

class Character :
    public GameObject
{
public:
    Character();
    virtual ~Character();
    // GameObject을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

    // GameObject을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;

	// 지형 타기
    void OnTerrain();
	// 카메라로 부터 텍스쳐 각도
	float GetAngleFromCamera();
	// 애니메이션 업데이트
	void UpdateAnimation();

public:
	void SetDir(const Vector3& dir);
	void SetMoveSpeed(const float& speed) { moveSpeed = speed; }
	void MoveForward();
	void ChangeState(State nextState);

public:
	int Hp;
	int Att;
    // 지형과 간격
    float offsetY;
	Vector3 direction;
	Animation2D* anim;
	State state = State::IDLE;
	DIR dir;

	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	
};

