#pragma once
#include "Decoration.h"

class Tree :
    public Decoration
{
public:
    Tree();
    virtual ~Tree();

    // Decoration��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;
    virtual void Render() override;

    
    void setTreeSprite(TextureKey _tree);





};

