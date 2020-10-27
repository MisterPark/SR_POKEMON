#include "stdafx.h"
#include "TestScene.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "SkyBox.h"
#include "Player.h"
#include "CubeMan.h"
#include "Monster.h"
#include "Monster_Butterfree.h"
#include "Monster_Caterpie.h"
#include "Environment.h"
#include "TestObj.h"

void TestScene::OnLoaded()
{
	SkyBox::Show();
	ObjectManager::GetInstance()->CreateObject<Environment>();
	ObjectManager::GetInstance()->CreateObject<Player>();
	//ObjectManager::GetInstance()->CreateObject<CubeMan>();
	
	/*
	for (int i = 0; i < 20; i++) {
		GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Monster_Butterfree>();
		Obj->transform->position.x += i * 1;
		Obj->transform->position.z += i * 1;
	}
	GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Monster_Caterpie>();
	Obj->transform->position.x += 1;
	Obj->transform->position.z += 1;
	*/

	TestObj* test = dynamic_cast<TestObj*>(ObjectManager::GetInstance()->CreateObject<TestObj>());
	test->SetPos({ -1.f, 0.f, 1.f });
	test->SetDir({ 0.f, 0.f, 1.f });
	test->ChangeAnim(TestObj::IDLE, TestObj::D);
}

void TestScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TestScene::Update()
{

}
