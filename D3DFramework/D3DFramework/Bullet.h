#pragma once
#include "GameObject.h"

class Bullet abstract : public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	// ���� Ÿ��
	void OnTerrain();
	void CalcLifeTime();

public:
	//�÷��̾ ���ϴ� ���⺤�͸� Normalize �ϰ� ��ȯ�մϴ�.
	//���ڰ� false �Ͻ� Y���� �����մϴ�.
	Vector3 PlayerSearchDir(bool PosY = true);
	Vector3 MonsterSearchDir(bool PosY, float SearchRange);
	void MoveForward();
	void MoveForwardExceptY();
	//�Ѿ��� ���� �������ݴϴ�.
	void SetTeam(Team _team);
public:
	// Setter
	void SetDir(const Vector3& dir) { D3DXVec3Normalize(&direction, &dir); }
	void SetInitAttack(float initattack) { initAttack = initattack; attack = initAttack;}

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

	bool isOnTerrain;
	bool isBillboard;
	bool isLoop;
};

