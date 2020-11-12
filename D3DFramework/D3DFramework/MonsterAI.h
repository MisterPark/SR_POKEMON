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
    // IComponent��(��) ���� ��ӵ�
public:
    MonsterAI();
    MonsterAI(const MonsterAI& rhs);
    virtual ~MonsterAI();

    virtual void Update();

    virtual MonsterAI* Clone() override;

    //������ ���� ���� Vector3�� Normalize �ؼ� ��ȯ�մϴ�.
    Vector3 DirRandom();
	//������ �ݰ濡�� ������ ��ġ�� ���� Vector3�� "spawnInPos"�� �ް�,
	// �װ��� ���� ���⺤�͸� "direction" ���� �־��ݴϴ�.
	void SpawnInRandomPos();
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
    void MoveRandomPattern(float _moveSpeed2 = 1.f);
    //PlayerSearch(PlayerŽ���Ÿ�, PlayerŽ���� ��ĥ�Ÿ�)
    //playerTrans, isSearch, disPlayer �� ���� ����˴ϴ�.
    //isSearch �� ����ɰ��, State::Ready �� ��� ����˴ϴ�.
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
    int Frame[5]; // �����Ǵ�
	// ������(�ð�) ��¿뵵
	// Time[1] = Attack CoolTime / Time[2] = Skill CoolTime / Time[3] = Skill2 CoolTime
	// Time[4] = Attack, Skill �� �����ϴ� �ð�
    float Time[6];
    Transform* playerTrans = nullptr;
    bool isSearch = false;
    float disPlayer = 0.f;

    MonsterType type = MonsterType::END;
    bool readyPattern = true;
    int beginPattern = (int)State::IDLE;
    int endPattern = (int)State::END;
    //SearchRange[0]: ���Ͱ����ּҰŸ�, SearchRange[3]: ���Ͱ��÷��̾��ĥ�Ÿ�
    float searchRange[4];
	Vector3 spawnInPos = { 0.f, 0.f, 0.f };
};

