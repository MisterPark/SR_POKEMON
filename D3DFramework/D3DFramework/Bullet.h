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
	void AddToCollideList(GameObject* object);

public:
	// Setter
	void SetDir(const Vector3& dir) { D3DXVec3Normalize(&direction, &dir); }

public:
	// Getter
	const Vector3 GetDir() const { return direction; }
	bool IsInCollideList(const GameObject* object) const;

protected:
	Vector3 direction;
	Animation2D* anim;
	TextureKey startKey;
	TextureKey endKey;

	float lifeTime;
	float offsetY;
	float animDelay;

	bool isOnTerrain;
	bool isBillboard;
	bool isLoop;

	list<GameObject*> collideList;
};

