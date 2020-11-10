#pragma once
#include "GameObject.h"
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
    virtual void Render() override;

    virtual void OnCollision(GameObject* target) override;

    void OnTerrain();


public:
    float offsetY = 0.f;
};
