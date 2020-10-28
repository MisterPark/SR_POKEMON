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
#include "Bulbasaur.h"

#include "Psyduck.h"
#include "Vileplume.h"
#include "Metapod.h"
void TestScene::OnLoaded()
{
	SkyBox::Show();
	ObjectManager::GetInstance()->CreateObject<Environment>();

	Bulbasaur* playerCharacter = new Bulbasaur(Vector3(0.f, 0.f, 0.f), Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);
	Player* player = new Player(playerCharacter);
	ObjectManager::AddObject(player);

	//ObjectManager::GetInstance()->CreateObject<Player>();
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
	GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Metapod>();
	Obj->transform->position.x += 3;
	Obj->transform->position.z += 3;
	//Obj = ObjectManager::GetInstance()->CreateObject<Monster_Oddish>();
	//Obj->transform->position.x += 5;
	//Obj->transform->position.z += 5;

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
