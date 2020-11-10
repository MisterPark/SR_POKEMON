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

	// ���� Ÿ��
	void OnTerrain();
	// ī�޶�� ���� �ؽ��� ����
	float GetAngleFromCamera();
	// �ִϸ��̼� ������Ʈ
	void UpdateAnimation();
	// �ִϸ��̼� �ؽ��� ����
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

	//TODO ���� NPC������ü ����� �÷��̾���� �ش�NPC�� �����Ȳ�� �� �� �־����.
};


