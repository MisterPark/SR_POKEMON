#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    enum class Status
    {
        MOVE, ATTACK, PLAYER_SEARCH, SKILL, END
    };
public:
    Monster();
    virtual ~Monster();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

protected:
    void OnTerrain();

protected:
    int Frame[3]; // �����Ǵ�
    float Time[5];  // ������(�ð�) ��¿뵵
    Status CurrentStatus = Status::END;
    Vector3 MoveDir;
    float floating;
};

