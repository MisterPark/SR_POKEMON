#include "stdafx.h"
#include "Monster_Butterfree.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Butterfree::Monster_Butterfree()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	TextureAttack = TextureKey::BUTTER_ATTACK_D_01;
	TextureWALK = TextureKey::BUTTER_WALK_D_01;
	anim->SetLoop(true);

	startArray[(int)State::WALK][(int)Direction::D] = TextureKey::BUTTER_WALK_D_01;
	endArray[(int)State::WALK][(int)Direction::D] = TextureKey::BUTTER_WALK_D_03;
	startArray[(int)State::WALK][(int)Direction::LD] = TextureKey::BUTTER_WALK_LD_01;
	endArray[(int)State::WALK][(int)Direction::LD] = TextureKey::BUTTER_WALK_LD_03;
	startArray[(int)State::WALK][(int)Direction::L] = TextureKey::BUTTER_WALK_L_01;
	endArray[(int)State::WALK][(int)Direction::L] = TextureKey::BUTTER_WALK_L_03;
	startArray[(int)State::WALK][(int)Direction::LU] = TextureKey::BUTTER_WALK_LU_01;
	endArray[(int)State::WALK][(int)Direction::LU] = TextureKey::BUTTER_WALK_LU_03;
	startArray[(int)State::WALK][(int)Direction::U] = TextureKey::BUTTER_WALK_U_01;
	endArray[(int)State::WALK][(int)Direction::U] = TextureKey::BUTTER_WALK_U_03;
	startArray[(int)State::WALK][(int)Direction::RU] = TextureKey::BUTTER_WALK_RU_01;
	endArray[(int)State::WALK][(int)Direction::RU] = TextureKey::BUTTER_WALK_RU_03;
	startArray[(int)State::WALK][(int)Direction::R] = TextureKey::BUTTER_WALK_R_01;
	endArray[(int)State::WALK][(int)Direction::R] = TextureKey::BUTTER_WALK_R_03;
	startArray[(int)State::WALK][(int)Direction::RD] = TextureKey::BUTTER_WALK_RD_01;
	endArray[(int)State::WALK][(int)Direction::RD] = TextureKey::BUTTER_WALK_RD_03;

	startArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::BUTTER_ATTACK_D_01;
	endArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::BUTTER_ATTACK_D_02;
	startArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::BUTTER_ATTACK_LD_01;
	endArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::BUTTER_ATTACK_LD_02;
	startArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::BUTTER_ATTACK_L_01;
	endArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::BUTTER_ATTACK_L_02;
	startArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::BUTTER_ATTACK_LU_01;
	endArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::BUTTER_ATTACK_LU_02;
	startArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::BUTTER_ATTACK_U_01;
	endArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::BUTTER_ATTACK_U_02;
	startArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::BUTTER_ATTACK_RU_01;
	endArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::BUTTER_ATTACK_RU_02;
	startArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::BUTTER_ATTACK_R_01;
	endArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::BUTTER_ATTACK_R_02;
	startArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::BUTTER_ATTACK_RD_01;
	endArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::BUTTER_ATTACK_RD_02;

	SetSpriteWalk();
	offsetY = 2.5f;
	Speed = 1.f;
	state = State::WALK;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Monster_Butterfree::~Monster_Butterfree()
{
}

void Monster_Butterfree::Update()
{
	ButterfreeParttern();
	SetTextureAngle();
	Monster::Update();

}

void Monster_Butterfree::Render()
{
	Monster::Render();
}

void Monster_Butterfree::ButterfreeParttern()
{

	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;



	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);




	if (state != State::PLAYER_SEARCH && Dist < 5.f) {
		state = State::PLAYER_SEARCH;
		//이곳에서 플레이어 향하는 방향벡터 정해주고
		//MoveDir = PlayerT->position - transform->position;
		direction.x = 1;
		direction.y = 0;
		direction.z = 1;
		D3DXVec3Normalize(&direction, &direction);
		direction *= 1.5f;
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		b->SetDir(direction.x, direction.z, direction.y);
		*(b->transform) = *transform;

		SetSpriteAttack();
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::IDLE) { // 이건 랜덤패턴 갖기전 대기상태
		state = (State)Random::Range(0, 1); // 패턴 나누어주는곳 (랜덤)

		if (state == State::WALK) {            // 이곳에서 패턴 레디
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}
		else if (state == State::ATTACK) {            // 이곳에서 패턴 레디
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			b->SetDir(direction.x, direction.z);
			*(b->transform) = *transform;
			/*b->transform->position.y += 0.5f;*/
			SetSpriteAttack();
		}
	}
	else if (state == State::WALK) {		//// 이곳부터 업데이트
		RandomMovePattern();
	}
	else if (state == State::ATTACK) {
		Attack();
	}
	else if (state == State::PLAYER_SEARCH) {
		Attack();
	}

}

void Monster_Butterfree::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * Speed * TimeManager::DeltaTime();
	transform->position.z += direction.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4번의 파닥거림 후
			Frame[0] = 0;
			state = State::IDLE;
		}
	}
}

void Monster_Butterfree::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		anim->SetDelay(0.2f);
		Time[0] = 0.f;
		state = State::IDLE;
		SetSpriteWalk();
	}
}

