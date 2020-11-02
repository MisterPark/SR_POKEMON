#include "stdafx.h"
#include "Bullet_Tornado.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Bullet_Tornado::Bullet_Tornado()
{   //TODO : 불렛이 지형타는중
	/*SetAniTexture(State::IDLE, TextureKey::BULLET_TORNADO1_01, 10);*/
	anim->SetSprite(TextureKey::BULLET_TORNADO2_01, TextureKey::BULLET_TORNADO2_08);
	anim->SetLoop(true);
	anim->SetDelay(0.05f);

	transform->scale = { 0.9f, 1.8f, 0.9f };

	transform->scale.x = 0.9f;
	transform->scale.y = 1.8f;
	transform->scale.z = 0.9f;

	lifeTime = 6.f;
	spawnTimeGap = 0.8f;
	moveSpeed = 2.f;

	rotateMoveX = 1.f;
	rotateMoveZ = 0.f;
	isOnTerrain = true;
	offsetY = 1.8f;
	Frame[0] = 0;
	Frame[1] = 0;
}

Bullet_Tornado::~Bullet_Tornado()
{
}

void Bullet_Tornado::Update()
{
	Bullet::Update();

	RotateMove();

	spawnTimeGap -= TimeManager::DeltaTime();

	if (0.f >= spawnTimeGap) direction = PlayerSearchDir(false);
}

void Bullet_Tornado::Render()
{
	Bullet::Render();
}

void Bullet_Tornado::OnCollision(GameObject* target)
{
	// Coll
}

void Bullet_Tornado::RotateMove() {
	transform->position.x += rotateMoveX * 1.5f *TimeManager::DeltaTime();
	transform->position.z += rotateMoveZ * 1.5f * TimeManager::DeltaTime();

	if (Frame[1] == 0 && rotateMoveX > 1.f) {
		rotateMoveX += 0.1f;
	}
	else if (Frame[1] == 1 && rotateMoveX < -1.f) {
		rotateMoveX -= 0.1f;
	}
	if (Frame[0] == 0 && rotateMoveZ > 1.f) {
		rotateMoveZ += 0.1f;
	}
	else if (Frame[0] == 1 && rotateMoveZ < -1.f) {
		rotateMoveZ -= 0.1f;
	}

	if (Frame[1] == 0) {
		rotateMoveX += 0.1f;
	}
	else if (Frame[1] == 1) {
		rotateMoveX -= 0.1f;
	}
	if (Frame[0] == 0) {
		rotateMoveZ += 0.1f;
	}
	else if (Frame[0] == 1) {
		rotateMoveZ -= 0.1f;
	}

	/*
	if (Frame[1] == 0 && rotateMoveX > 1.f) {
		Frame[1] = 1;
	}
	else if (Frame[1] == 1 && rotateMoveX < -1.f) {
		Frame[1] = 0;
	}
	if (Frame[2] == 0 && rotateMoveZ > 1.f) {
		Frame[2] = 1;
	}
	else if (Frame[2] == 1 && rotateMoveZ < -1.f) {
		Frame[2] = 0;
	}

	if (Frame[1] == 0) {
		rotateMoveX += 0.1f;
	}
	else if (Frame[1] == 1) {
		rotateMoveX -= 0.1f;
	}
	if (Frame[2] == 0) {
		rotateMoveZ += 0.1f;
	}
	else if (Frame[2] == 1) {
		rotateMoveZ -= 0.1f;
	}
	*/

}
