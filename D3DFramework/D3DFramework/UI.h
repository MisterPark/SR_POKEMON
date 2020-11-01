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

    virtual void UpdateUI() {};

    void UpdateEvent();

    virtual void OnHover() = 0;
    virtual void OnLeave() = 0;
    virtual void OnLButtonDown() = 0;
    virtual void OnLButtonUp() = 0;
    virtual void OnLButtonClick() = 0;

public:
    wstring text;
    Vector3 textOffsetPosition;
    bool textRenderFlag = false;
    TextureKey textureKey = TextureKey::NONE;
    int width = 0;
    int height = 0;

private:
    // 이벤트 관련
    bool isHover = false;
    bool isLeave = false;
    bool isLButtonDown = false;
    bool isLButtonUp = false;
    bool isLButtonClick = false;

};

