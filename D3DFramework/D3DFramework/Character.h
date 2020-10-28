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
    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

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
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame);


public:
	int Hp;
	int Att;
	float Speed;
    // ������ ����
    float offsetY;
	Vector3 direction;
	Animation2D* anim;
	State state = State::IDLE;
	DIR dir;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	
};

