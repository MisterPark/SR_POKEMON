#include "stdafx.h"
#include "Psyduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Psyduck::Psyduck()
{
	SetTexture(State::WALK, TextureKey::PSY_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PSY_ATTACK2_D_01, 2);
	SetTexture(State::IDLE, TextureKey::PSY_WALK_D_01, 3);
	for (int i = 0; i < 8; i++)
	{
		endArray[(int)State::IDLE][(int)Direction::D + i] = (TextureKey)((int)endArray[(int)State::IDLE][(int)Direction::D + i] - 2);
	}
	transform->position.x = 10.f;
	anim->SetLoop(true);
	offsetY = 1.f;
	state = State::END;
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

	if (Dist < 5.f) {
		isSearch = true;
	}

	if (state==State::END&&!isSearch)
	{
		state = State::WALK;
		direction.x = -4.f + Random::Value(9) * 1.f;
		direction.z = -4.f + Random::Value(9) * 1.f;
	}
	if (state == State::WALK) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}

	
	if (isSearch)
	{
		state = State::ATTACK;
	}
	//if (state != State::END && Dist < 5.f) {
	//	state = State::END;
	//	direction = PlayerT->position - transform->position;

	//	D3DXVec3Normalize(&direction, &direction);

	//	/*Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	//	b->SetDir(direction.x, direction.z, direction.y);
	//	*(b->transform) = *transform;*/


	//	Time[0] = 0;
	//	Frame[0] = 0;
	//}
	//else if (state == State::END) { // �̰� �������� ������ ������
	//	state = (State)Random::Range(1, 2); // ���� �������ִ°� (����)

	//	if (state == State::WALK) {            // �̰����� ���� ����
	//		direction.x = -4.f + Random::Value(9) * 1.f;
	//		direction.z = -4.f + Random::Value(9) * 1.f;
	//	}
	//	else if (state == State::ATTACK) {            // �̰����� ���� ����
	//		direction.x = -4.f + Random::Value(9) * 1.f;
	//		direction.z = -4.f + Random::Value(9) * 1.f;
	//		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	//		b->SetDir(direction.x, direction.z);
	//		*(b->transform) = *transform;
	//		/*b->transform->position.y += 0.5f;*/

	//	}
	//}

	//else if (state == State::ATTACK) {
	//	Attack();
	//}

}

void Psyduck::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::END;
		}
	}
}

void Psyduck::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		anim->SetDelay(0.2f);
		Time[0] = 0.f;
		Frame[0] ++;
		if (Frame[0] == 4) {			
			Frame[0] = 0;
			state = State::END;
		}
	}
}

