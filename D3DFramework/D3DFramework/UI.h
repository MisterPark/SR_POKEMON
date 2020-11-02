#pragma once
#include "GameObject.h"
class UI :
    public GameObject
{
public:
    UI();
    virtual ~UI();

    virtual void Update() override;
    virtual void Render() override;

    // �� UI���� ������Ʈ ����� �� �� �ۼ�
    virtual void UpdateUI() {};

    void UpdateEvent();
    void ClearEvent();

    // �̺�Ʈ ������
    virtual void OnHover();
    virtual void OnLeave();
    virtual void OnLButtonDown();
    virtual void OnLButtonUp();
    virtual void OnClick();
    virtual void OnChangedText();
    

public:
    // ����� �ؽ�Ʈ (RW)
    wstring text;
    // �ؽ�Ʈ�� ����� local(offset)��ġ (RW) 
    Vector3 textOffsetPosition;
    // �ؽ�Ʈ�� ����� UI�ΰ�? (RW)
    bool textRenderFlag = false;
    TextureKey textureKey = TextureKey::NONE;
    int width = 0;
    int height = 0;

public:
    // �̺�Ʈ �ݹ� (RW)
    void (*Click)() = nullptr;
    void (*LButtonDown)() = nullptr;
    void (*LButtonUp)() = nullptr;
    void (*Hover)() = nullptr;
    void (*Leave)() = nullptr;
    void (*ChangedText)() = nullptr;

private:
    // �̺�Ʈ ���� 
    bool isHover = false;
    bool isLeave = false;
    bool isLButtonDown = false;

    wstring oldText;

};

