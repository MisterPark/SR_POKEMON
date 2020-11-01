#pragma once
#include "Character.h"
#include "MonsterAI.h"
class Monster
    //public Character
{
public:
    Monster();
    virtual ~Monster();

public:
    //static Monster* GetInstance();
    //static void Destroy();

public:
    void Update();
    //void SetGameObject(GameObject* _obj) { gameObject = _obj; }

private:
    void Initialize();
    void Release();
    //virtual void Render() override;


protected:
    MonsterAI monsterAI;
    //Monster* monster;


};

