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

    void OnTerrain();
	float GetAngleFromCamera();
	void SetTextureAngle();

	void UpdateAnimation();


public:
	int Hp;
	int Att;
	float Speed;
    // 지형과 간격
    float offsetY;
	Vector3 direction;
	Animation2D* anim;
	State state = State::IDLE;
	DIR dir;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	
};

