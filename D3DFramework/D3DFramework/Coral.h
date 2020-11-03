#pragma once
#include "Decoration.h"

class Coral :
    public Decoration
{
public:
    Coral();
    virtual ~Coral();

    // Decoration��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;
    virtual void Render() override;


    void setCoralSprite(TextureKey _Coral);





};

