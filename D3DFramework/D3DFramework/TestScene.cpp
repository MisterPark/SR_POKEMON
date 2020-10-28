#include "stdafx.h"
#include "TestScene.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "SkyBox.h"
#include "Player.h"
#include "CubeMan.h"
#include "Monster.h"
#include "Environment.h"
#include "TestObj.h"
#include "TitleScene.h"
#include "Butterfree.h"
#include "Psyduck.h"
void TestScene::OnLoaded()
{
	SkyBox::Show();
	ObjectManager::GetInstance()->CreateObject<Environment>();
	ObjectManager::GetInstance()->CreateObject<Player>();
	/*ObjectManager::GetInstance()->CreateObject<Psyduck>();*/

	ObjectManager::GetInstance()->CreateObject<Butterfree>();
	
	//for (int i = 0; i < 1; i++) {
	//	GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Monster_Butterfree>();
	//	Obj->transform->position.x += i * 1;
	//	Obj->transform->position.z += i * 1;
	//}
	//GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Monster_Caterpie>();
	//Obj->transform->position.x += 1;
	//Obj->transform->position.z += 1;
	//Obj = ObjectManager::GetInstance()->CreateObject<Monster_Metapod>();
	//Obj->transform->position.x += 3;
	//Obj->transform->position.z += 3;
	//Obj = ObjectManager::GetInstance()->CreateObject<Monster_Oddish>();
	//Obj->transform->position.x += 5;
	//Obj->transform->position.z += 5;
	//Obj = ObjectManager::GetInstance()->CreateObject<Monster_Vileplume>();
	//Obj->transform->position.x += 7;
	//Obj->transform->position.z += 3;

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
