#pragma once
#include "IComponent.h"

enum class MonsterType {
	BULBASAUR, IVYSAUR, VENUSAUR,
	CATERPIE, METAPOD, ODDISH, GLOOM, VILEPLUME, SCYTHER, BUTTERFREE,
	SQUIRTLE, WARTORTLE, BLASTOISE,
	PSYDUCK, GOLDUCK, POLIWAG, POLIWHIRL, POLIWRATH, JYNX, SUICUNE,
	CHARMANDER, CHARMELEON, CHARIZARD,
	GROWLITHE, ARCANINE, PONYTA, RAPIDASH, SLUGMA, MAGCARGO, GROUDON, DARKRAI,
	END
};

class MonsterAI :
    public IComponent
{
    // IComponent을(를) 통해 상속됨
public:
    MonsterAI();
    MonsterAI(const MonsterAI& rhs);
    virtual ~MonsterAI();

    virtual void Update();

    virtual MonsterAI* Clone() override;

    //랜덤한 값을 가진 Vector3를 Normalize 해서 반환합니다.
    Vector3 DirRandom();
	//스폰의 반경에서 랜덤한 위치를 가진 Vector3를 "spawnInPos"로 받고,
	// 그곳에 대한 방향벡터를 "direction" 으로 넣어줍니다.
	void SpawnInRandomPos();
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
    void MoveRandomPattern(float _moveSpeed2 = 1.f);
    //PlayerSearch(Player탐지거리, Player탐지를 놓칠거리)
    //playerTrans, isSearch, disPlayer 의 값은 변경됩니다.
    //isSearch 가 변경될경우, State::Ready 로 즉시 변경됩니다.
    void PlayerSearch(float _range, float _rangeOut);

    void LimitPosition();

    void Pattern();

    void MonsterIdle();
    void MonsterWalk();
    void MonsterAttack();
    void MonsterSkill();
    void MonsterSkill2();
    void MonsterSkill3();

    void SetType(MonsterType _type);
    // 0.Idle   1.Walk   2.Attack   3.Skill   4.Skill2
    void SetPatternRange(int _begin, int _end) { beginPattern = _begin; endPattern = _end; }

public:
    int Frame[5]; // 패턴판단
	// 프레임(시간) 재는용도
	// Time[1] = Attack CoolTime / Time[2] = Skill CoolTime / Time[3] = Skill2 CoolTime
	// Time[4] = Attack, Skill 등 유지하는 시간
    float Time[6];
    Transform* playerTrans = nullptr;
    bool isSearch = false;
    float disPlayer = 0.f;

    MonsterType type = MonsterType::END;
    bool readyPattern = true;
    int beginPattern = (int)State::IDLE;
    int endPattern = (int)State::END;
    //SearchRange[0]: 몬스터감지최소거리, SearchRange[3]: 몬스터가플레이어를놓칠거리
    float searchRange[4];
	Vector3 spawnInPos = { 0.f, 0.f, 0.f };
};

