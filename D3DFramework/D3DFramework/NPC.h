#pragma once
#include "GameObject.h"
#include "QuestManager.h"
class NPC :
    public GameObject
{
public:
    NPC();
    virtual ~NPC();
    // GameObject��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;

    virtual void OnCollision(GameObject* target) override;
    virtual void OnEvent() = 0;

    void OnTerrain();
    // ī�޶�� ���� �ؽ��� ����
    float GetAngleFromCamera();
    // �ִϸ��̼� ������Ʈ
    void UpdateAnimation();
    // �ִϸ��̼� �ؽ��� ����
    void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);
    // �÷��̾ ���ϴ� ���⺤�� ��ȯ
    Vector3 DirFromPlayer(bool _posY = false);
public:
    float offsetY = 0.f;
    Animation2D* anim = nullptr;
    bool animation = true;
    TextureKey startArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
    TextureKey endArray[MaxOfEnum<State>()][MaxOfEnum<Direction>()];
    State oldState = State::IDLE;
    State state = State::IDLE;
    Vector3 direction = { 0,0,1 };

    NpcName myName = NpcName::NPC_END;
};

