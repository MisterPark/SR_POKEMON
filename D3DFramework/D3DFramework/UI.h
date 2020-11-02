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

    // 각 UI마다 업데이트 해줘야 할 것 작성
    virtual void UpdateUI() {};

    void UpdateEvent();
    void ClearEvent();

    // 이벤트 리스너
    virtual void OnHover();
    virtual void OnLeave();
    virtual void OnLButtonDown();
    virtual void OnLButtonUp();
    virtual void OnClick();
    virtual void OnChangedText();
    

public:
    // 출력할 텍스트 (RW)
    wstring text;
    // 텍스트를 출력할 local(offset)위치 (RW) 
    Vector3 textOffsetPosition;
    // 텍스트를 출력할 UI인가? (RW)
    bool textRenderFlag = false;
    TextureKey textureKey = TextureKey::NONE;
    int width = 0;
    int height = 0;

public:
    // 이벤트 콜백 (RW)
    void (*Click)() = nullptr;
    void (*LButtonDown)() = nullptr;
    void (*LButtonUp)() = nullptr;
    void (*Hover)() = nullptr;
    void (*Leave)() = nullptr;
    void (*ChangedText)() = nullptr;

private:
    // 이벤트 관련 
    bool isHover = false;
    bool isLeave = false;
    bool isLButtonDown = false;

    wstring oldText;

};

