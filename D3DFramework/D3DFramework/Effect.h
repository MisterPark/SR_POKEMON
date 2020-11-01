#pragma once
#include "GameObject.h"

class Effect:
	public GameObject
{
public:
	Effect();
	Effect(const Vector3 & pos, const Vector3& size, TextureKey start, TextureKey end, float delay, bool plane, bool isBillY, float radianY, bool loop, float lifeTime, bool isMove, float speed, const Vector3 & dir);
	virtual ~Effect();

public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	bool IsDie();

public:
	/*
	start : �ؽ��� ���� ����, end : �ؽ��� �� ����
	delay : �ִϸ��̼� ������ ������ ������ ��, plane : ���� ����Ʈ�� �� ������
	isBillY : billboardYaw�� ����� ������, loop : �ݺ��Ǵ� ����Ʈ����
	lifeTime : �ݺ��Ǵ� ����Ʈ��� �� �� ���� �����ϴ���, isMove : �����̴� ����Ʈ����
	speed : �����̴� �ӵ�, dir : �����̴� ����
	*/
	static Effect* Create(
		const Vector3& pos,
		const Vector3& size,
		TextureKey start,
		TextureKey end,
		float delay,
		bool plane = false,
		bool isBillY = true,
		float radianY = 0.f,
		bool loop = false,
		float lifeTime = 0.f,
		bool isMove = false,
		float speed = 0.f,
		const Vector3& dir = { 0.f, 0.f, 1.f }
	);

private:
	Animation2D* anim;
	Vector3 direction;

	float animSpeed;
	float lifeTime;

	TextureKey startKey;
	TextureKey endKey;

	bool isBillboardY;
	bool isMove;
	bool isLoop;
	bool isEnd;
	bool isPlane;
};