#pragma once
#include "GameObject.h"

class Bullet abstract : public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	// 지형 타기
	void OnTerrain();

	// 라이프타임 계산
	void CalcLifeTime();

	// 총알이 지형에 부딪혔을때의 처리
	virtual void CollideOnTerrain();

public:
	//플레이어를 향하는 방향벡터를 Normalize 하고 반환합니다.
	//인자가 false 일시 Y값은 제외합니다.
	Vector3 PlayerSearchDir(bool PosY = true);
	Vector3 MonsterSearchDir(bool PosY, float SearchRange);
	void MoveForward();
	void MoveForwardExceptY();
	//총알의 팀을 설정해줍니다.
	void SetTeam(Team _team);
public:
	// Setter
	void SetDir(const Vector3& dir) { D3DXVec3Normalize(&direction, &dir); }
	void SetInitAttack(float initattack) { initAttack = initattack; stat.attack = initAttack;}

public:
	// Getter
	const Vector3 GetDir() const { return direction; }

protected:
	Vector3 direction;
	Animation2D* anim;
	TextureKey startKey;
	TextureKey endKey;

	float lifeTime;
	float offsetY;
	float animDelay;
	float initAttack;

	bool isCollideOnTerrain;
	bool isOnTerrain;
	bool isBillboard;
	bool isLoop;
};

