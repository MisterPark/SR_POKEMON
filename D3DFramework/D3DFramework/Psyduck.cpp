#include "stdafx.h"
#include "Psyduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Psyduck::Psyduck()
{
	startArray[(int)State::WALK][(int)Direction::D] = TextureKey::PSY_WALK_D_01;
	endArray[(int)State::WALK][(int)Direction::D] = TextureKey::PSY_WALK_D_03;
	startArray[(int)State::WALK][(int)Direction::LD] = TextureKey::PSY_WALK_LD_01;
	endArray[(int)State::WALK][(int)Direction::LD] = TextureKey::PSY_WALK_LD_03;
	startArray[(int)State::WALK][(int)Direction::L] = TextureKey::PSY_WALK_L_01;
	endArray[(int)State::WALK][(int)Direction::L] = TextureKey::PSY_WALK_L_03;
	startArray[(int)State::WALK][(int)Direction::LU] = TextureKey::PSY_WALK_LU_01;
	endArray[(int)State::WALK][(int)Direction::LU] = TextureKey::PSY_WALK_LU_03;
	startArray[(int)State::WALK][(int)Direction::U] = TextureKey::PSY_WALK_U_01;
	endArray[(int)State::WALK][(int)Direction::U] = TextureKey::PSY_WALK_U_03;
	startArray[(int)State::WALK][(int)Direction::RU] = TextureKey::PSY_WALK_RU_01;
	endArray[(int)State::WALK][(int)Direction::RU] = TextureKey::PSY_WALK_RU_03;
	startArray[(int)State::WALK][(int)Direction::R] = TextureKey::PSY_WALK_R_01;
	endArray[(int)State::WALK][(int)Direction::R] = TextureKey::PSY_WALK_R_03;
	startArray[(int)State::WALK][(int)Direction::RD] = TextureKey::PSY_WALK_RD_01;
	endArray[(int)State::WALK][(int)Direction::RD] = TextureKey::PSY_WALK_RD_03;

	startArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::PSY_ATTACK2_D_01;
	endArray[(int)State::ATTACK][(int)Direction::D] = TextureKey::PSY_ATTACK2_D_02;
	startArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::PSY_ATTACK2_LD_01;
	endArray[(int)State::ATTACK][(int)Direction::LD] = TextureKey::PSY_ATTACK2_LD_02;
	startArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::PSY_ATTACK2_L_01;
	endArray[(int)State::ATTACK][(int)Direction::L] = TextureKey::PSY_ATTACK2_L_02;
	startArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::PSY_ATTACK2_LU_01;
	endArray[(int)State::ATTACK][(int)Direction::LU] = TextureKey::PSY_ATTACK2_LU_02;
	startArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::PSY_ATTACK2_U_01;
	endArray[(int)State::ATTACK][(int)Direction::U] = TextureKey::PSY_ATTACK2_U_02;
	startArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::PSY_ATTACK2_RU_01;
	endArray[(int)State::ATTACK][(int)Direction::RU] = TextureKey::PSY_ATTACK2_RU_02;
	startArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::PSY_ATTACK2_R_01;
	endArray[(int)State::ATTACK][(int)Direction::R] = TextureKey::PSY_ATTACK2_R_02;
	startArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::PSY_ATTACK2_RD_01;
	endArray[(int)State::ATTACK][(int)Direction::RD] = TextureKey::PSY_ATTACK2_RD_02;

	anim->SetLoop(true);
	offsetY = 1.f;
	state = State::WALK;
}

Psyduck::~Psyduck()
{
}

void Psyduck::Update()
{
	Pattern();
	Monster::Update();
}

void Psyduck::Render()
{
	Monster::Render();
}

void Psyduck::Pattern()
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;


	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);


	float radian1 = PlayerT->scale.x / 2;
	float radian2 = transform->scale.x / 2;


	if (state != State::ATTACK && Dist < radian1 + radian2 + 5.f) {
		state = State::ATTACK;
		//이곳에서 플레이어 향하는 방향벡터 정해주고
		//MoveDir = PlayerT->position - transform->position;
		direction.x = 1;
		direction.y = 0;
		direction.z = 1;
		D3DXVec3Normalize(&direction, &direction);

		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		b->SetDir(direction.x, direction.z, direction.y);
		*(b->transform) = *transform;

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
		}
	}
	else if (state == State::WALK) {		//// 이곳부터 업데이트
		MovePattern();
	}
	else if (state == State::ATTACK) {
		Attack();
	}

}

void Psyduck::MovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4번의 파닥거림 후
			Frame[0] = 0;
			state = State::IDLE;
		}
	}
}

void Psyduck::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		anim->SetDelay(0.2f);
		Time[0] = 0.f;
		state = State::IDLE;
	}
}
