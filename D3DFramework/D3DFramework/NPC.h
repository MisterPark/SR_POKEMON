#pragma once
#include "GameObject.h"
#include "QuestManager.h"
class NPC :
    public GameObject
{
public:
    NPC();
    virtual ~NPC();
    // GameObject을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;

    virtual void OnCollision(GameObject* target) override;
    virtual void OnEvent() = 0;

    void OnTerrain();
    // 카메라로 부터 텍스쳐 각도
    float GetAngleFromCamera();
    // 애니메이션 업데이트
    void UpdateAnimation();
    // 애니메이션 텍스쳐 설정
    void SetTexture(State _state, TextureKey _beginTextureKey, int _aniFrame, int _endFrame = -1);
    // 플레이어를 향하는 방향벡터 반환
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

