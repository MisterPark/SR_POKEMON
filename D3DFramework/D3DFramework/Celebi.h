#pragma once

class Celebi :
	public GameObject
{
public:
	Celebi();
	Celebi(const Vector3& pos);
	virtual ~Celebi();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	// 지형 타기
	void OnTerrain();
	// 카메라로 부터 텍스쳐 각도
	float GetAngleFromCamera();
	// 애니메이션 업데이트
	void UpdateAnimation();
	// 애니메이션 텍스쳐 설정
	void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);

	virtual void OnCollision(GameObject* target) override;

public:
	static Celebi* Create(const Vector3& pos);

private:
	float offsetY;
	Animation2D* anim = nullptr;
	TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
	State oldState = State::IDLE;
	State state = State::IDLE;
	Vector3 direction = { 0,0,1 };

	//TODO 따로 NPC상위객체 만들고 플레이어에서도 해당NPC의 진행상황을 알 수 있어야함.
};


