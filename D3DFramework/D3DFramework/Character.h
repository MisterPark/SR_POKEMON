#pragma once
#include "GameObject.h"
class Character :
    public GameObject
{
public:
    Character();
    virtual ~Character();
    // GameObject을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

    // GameObject을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;

    void OnTerrain();


public:
	int Hp;
	int Att;
	float Speed;
    // 지형과 간격
    float offsetY;
};

