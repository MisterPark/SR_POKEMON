#pragma once
#include "GameObject.h"
class FieldFire :
	public GameObject
{
public:
	FieldFire();
	FieldFire(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float lifeTime, float att);
	virtual ~FieldFire();

public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnCollision(GameObject* target) override;

public:
	void CalcLifeTime();
	void ChangeState(State nextState);
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame);
	float GetAtt() { return att; }

public:
	static FieldFire* Create(
		const Vector3& pos,
		const Vector3& size,
		TextureKey start,
		TextureKey end,
		const Vector3& dir = {0.f, 0.f, 0.f},
		float speed = 0.f,
		float lifeTime = 3.f,
		float att = 2.f
	);

private:
	Animation2D* anim;
	Vector3 direction;
	TextureKey startArray[MaxOfEnum<State>()];
	TextureKey endArray[MaxOfEnum<State>()];
	float lifeTime;
	State state;
	float att;
};
