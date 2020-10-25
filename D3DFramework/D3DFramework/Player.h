#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{

public:
    Player();
    ~Player();


    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;


    

};

