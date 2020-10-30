#include "stdafx.h"
#include "TestScene.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "SkyBox.h"
#include "CubeMan.h"
#include "Monster.h"
#include "Environment.h"
#include "TestObj.h"
#include "TitleScene.h"
#include "Butterfree.h"

#include "Bulbasaur.h"
#include "Ivysaur.h"
#include "Venusaur.h"

#include "Charmander.h"

#include "Metapod.h"
#include "Caterpie.h"
#include "Oddish.h"
#include "Vileplume.h"

#include "Psyduck.h"
#include "Poliwag.h"
#include "Psyduck.h"
#include "Poliwrath.h"
#include "Metapod.h"
#include "Oddish.h"
#include "Scyther.h"
#include "Jynx.h"
#include "Suicune.h"
#include "Golduck.h"

#include "Water.h"

void TestScene::OnLoaded()
{
	SkyBox::Show();
	ObjectManager::GetInstance()->CreateObject<Environment>();
	ObjectManager::GetInstance()->CreateObject<Water>();
	Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);
	
	Player::GetInstance()->SetCharacter(playerCharacter);

	//ObjectManager::GetInstance()->CreateObject<Player>();
	ObjectManager::GetInstance()->CreateObject<Psyduck>();

	/*ObjectManager::GetInstance()->CreateObject<Butterfree>();*/
	
	//for (int i = 0; i < 1; i++) {
	//	GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Caterpie>();
	//	Obj->transform->position.x += i * 1;
	//	Obj->transform->position.z += i * 1;
	//}
	//GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Monster_Caterpie>();
	//Obj->transform->position.x += 1;
	//Obj->transform->position.z += 1;
	/*GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Metapod>();
	Obj->transform->position.x += 3;
	Obj->transform->position.z += 3;
	Obj = ObjectManager::GetInstance()->CreateObject<Oddish>();
	Obj->transform->position.x += 5;
	Obj->transform->position.z += 5;*/

	/*for (int i = 0; i < 10; ++i)
	{*//*
	*/
	GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Poliwrath>();
	Obj->transform->position.x += 7;
	Obj->transform->position.z += 7;
	/*
	Obj = ObjectManager::GetInstance()->CreateObject<Vileplume>();
	Obj->transform->position.x += 7;
	Obj->transform->position.z += 7;*/
	/*}*/
	//TestObj* test = dynamic_cast<TestObj*>(ObjectManager::GetInstance()->CreateObject<TestObj>());
	//test->SetPos({ -1.f, 0.f, 1.f });
	//test->SetDir({ 1.f, 0.f, 0.f });
	//test->ChangeAnim(TestObj::IDLE, TestObj::R);
}

void TestScene::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	ObjectManager::DestroyAll();
}

void TestScene::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
}
