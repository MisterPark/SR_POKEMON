#pragma once
#include "GameObject.h"
class Decoration : public GameObject
{
    public:
    Decoration();
    virtual ~Decoration();

    virtual void Update() override;
    virtual void Render() override;

    void OnTerrain();
protected:
    Animation2D* anim;
    TextureKey startKey;
    TextureKey endKey;
    float offsetY;
    bool isOnTerrain;
};

