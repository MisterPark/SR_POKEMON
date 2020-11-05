#pragma once
#include "UI.h"
class DamageSkin :
    public UI
{
public:
    DamageSkin();
    virtual ~DamageSkin();
    // UI��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void UpdateUI() override;
    virtual void Update() override;
    virtual void Render() override;


public:
    void SetDamage(int _damage);
	void SetColor(D3DCOLOR _color);

private:
    int damage = 0;
    float lifeTick = 0.f;
    float lifeTime = 1.5f;
	D3DCOLOR color = D3DCOLOR_XRGB(200, 0, 0);
};

