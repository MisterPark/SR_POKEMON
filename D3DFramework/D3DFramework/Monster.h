#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:

public:
    Monster();
    virtual ~Monster();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;


protected:
    //랜덤한 값을 가진 Vector3를 Normalize 해서 반환합니다.
    Vector3 DirRandom();
    //Player 를 향한 방향벡터를 Normalize 해서 반환합니다.
    //인자를 true 로 주면 Y값 까지 반영됩니다.
    Vector3 DirFromPlayer(bool _posY = false);
    //direction 의 x와 z값 만큼 이동합니다.
    //인자를 넣어서 스피드값을 한번더 줄 수 있습니다.
    void Move(float _moveSpeed2 = 1.f);
    //Player 까지의 방향벡터를 구해서 이동합니다. (direction 의 값도 변경됩니다.)
    //인자를 넣어서 스피드값을 한번더 줄 수 있습니다.
    void MovePlayerFollow(float _moveSpeed2 = 1.f);
    //MoveRandomPattern(한번 움직일때 움직이는시간, 움직일 횟수, 스피드값2)
    //Time[0], Frame[0] 사용중
    void MoveRandomPattern(float _moveTime, int _count, float _moveSpeed2 = 1.f);
    //PlayerSearch(Player탐지거리, Player탐지를 놓칠거리)
    //playerTrans, isSearch, disPlayer 의 값은 변경됩니다.
    //isSearch 가 변경될경우, State::Ready 로 즉시 변경됩니다.
    void PlayerSearch(float _range, float _rangeOut);

protected:
    int Frame[3]; // 패턴판단
    float Time[5];  // 프레임(시간) 재는용도
    Transform* playerTrans = nullptr;
    bool isSearch = false;
    float disPlayer = 0.f;

};

