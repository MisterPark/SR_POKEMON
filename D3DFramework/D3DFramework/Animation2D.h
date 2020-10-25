#pragma once
#include "IComponent.h"
namespace PKH{

class Animation2D :
    public IComponent
{
public:
    Animation2D();
    virtual ~Animation2D();
    virtual void Update();

    void SetSprite(TextureKey _startTexture, TextureKey _endTexture);
    void SetLoop(bool _isLoop);
    void SetDelay(float _delay);
    // IComponent을(를) 통해 상속됨
    virtual IComponent* Clone() override;
    
private:

    TextureKey startTexture;
    TextureKey currentTexture;
    TextureKey endTexture;

    float delay = 0.2f;
    float tick = 0.f;
    bool isLoop = false;

};
}
