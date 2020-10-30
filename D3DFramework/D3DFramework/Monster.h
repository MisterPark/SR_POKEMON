#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:

public:
    Monster();
    virtual ~Monster();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;


protected:
    //������ ���� ���� Vector3�� Normalize �ؼ� ��ȯ�մϴ�.
    Vector3 DirRandom();
    //Player �� ���� ���⺤�͸� Normalize �ؼ� ��ȯ�մϴ�.
    //���ڸ� true �� �ָ� Y�� ���� �ݿ��˴ϴ�.
    Vector3 DirFromPlayer(bool _posY = false);
    //direction �� x�� z�� ��ŭ �̵��մϴ�.
    //���ڸ� �־ ���ǵ尪�� �ѹ��� �� �� �ֽ��ϴ�.
    void Move(float _moveSpeed2 = 1.f);
    //Player ������ ���⺤�͸� ���ؼ� �̵��մϴ�. (direction �� ���� ����˴ϴ�.)
    //���ڸ� �־ ���ǵ尪�� �ѹ��� �� �� �ֽ��ϴ�.
    void MovePlayerFollow(float _moveSpeed2 = 1.f);
    //MoveRandomPattern(�ѹ� �����϶� �����̴½ð�, ������ Ƚ��, ���ǵ尪2)
    //Time[0], Frame[0] �����
    void MoveRandomPattern(float _moveTime, int _count, float _moveSpeed2 = 1.f);
    //PlayerSearch(PlayerŽ���Ÿ�, PlayerŽ���� ��ĥ�Ÿ�)
    //playerTrans, isSearch, disPlayer �� ���� ����˴ϴ�.
    //isSearch �� ����ɰ��, State::Ready �� ��� ����˴ϴ�.
    void PlayerSearch(float _range, float _rangeOut);

protected:
    int Frame[3]; // �����Ǵ�
    float Time[5];  // ������(�ð�) ��¿뵵
    Transform* playerTrans = nullptr;
    bool isSearch = false;
    float disPlayer = 0.f;

};

