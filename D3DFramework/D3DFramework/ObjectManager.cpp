#include "stdafx.h"
#include "ObjectManager.h"
#include "SkyBox.h"
#include "Cursor.h"
#include "RenderFilter.h"
#include "TargetInfoPanel.h"
#include "PlayerInfoPanel.h"

using namespace PKH;

PKH::ObjectManager* pObjectManager = nullptr;
int lastUid = 0;

PKH::ObjectManager::ObjectManager()
{
	
	Cursor::GetInstance();
	RenderFilter::GetInstance();
	TargetInfoPanel::GetInstance();
	PlayerInfoPanel::GetInstance();
}

PKH::ObjectManager::~ObjectManager()
{
	
	Cursor::Destroy();
	RenderFilter::Destroy();
	TargetInfoPanel::Destroy();
	PlayerInfoPanel::Destroy();
	Release();
}

ObjectManager * PKH::ObjectManager::GetInstance()
{
	if (pObjectManager == nullptr)
	{
		pObjectManager = new ObjectManager;
	}
	return pObjectManager;
}

void PKH::ObjectManager::Destroy()
{
	delete pObjectManager;
	pObjectManager = nullptr;
}

void PKH::ObjectManager::Release()
{
	auto& objList = pObjectManager->objectList;

	auto iter = objList.begin();
	auto end = objList.end();
	for (;iter!=end;++iter)
	{
		delete (*iter);
		*iter = nullptr;
	}
	objList.clear();
}


bool PKH::ObjectManager::DeleteObject(GameObject * _target)
{
	auto& objList = pObjectManager->objectList;
	
	auto target = find(objList.begin(), objList.end(), _target);
	if (target != objList.end())
	{
		_target->Die();
		return true;
	}
	return false;
}

void PKH::ObjectManager::DestroyAll()
{
	auto& objList = pObjectManager->objectList;

	for (auto& iter : objList)
	{
		iter->Die();
	}
}

void PKH::ObjectManager::AddObject(GameObject* _obj)
{
	pObjectManager->objectList.push_back(_obj);
}



void PKH::ObjectManager::Update()
{
	auto& objList = pObjectManager->objectList;
	for (auto& iter : objList)
	{
		if (!iter->isEnable) continue;
		iter->Update();
	}

	
	
	RenderFilter::GetInstance()->Update();
	TargetInfoPanel::GetInstance()->Update();
	PlayerInfoPanel::GetInstance()->Update();
	Cursor::GetInstance()->Update();
}

void PKH::ObjectManager::PostUpdate()
{
	GameObject* target = nullptr;

	auto& objList = pObjectManager->objectList;
	auto iter = objList.begin();
	auto end = objList.end();
	for (; iter != end;)
	{
		target = *iter;
		if (target->isDead)
		{
			iter = objList.erase(iter);
			delete target;
		}
		else
		{
			target->PostUpdate();
			++iter;
		}
	}

	
	
	
}

void PKH::ObjectManager::PreRender()
{

}

void PKH::ObjectManager::Render()
{
	

	pObjectManager->renderList.clear();

	Vector3 camPos = Camera::GetPosition();
	
	auto& objList = pObjectManager->objectList;
	for (auto& iter : objList)
	{
		if (!iter->isVisible)continue;
		if (iter->transform->position.x < camPos.x - dfCLIENT_WIDTH / 2) continue;
		if (iter->transform->position.y < camPos.y - dfCLIENT_HEIGHT / 2) continue;
		if (iter->transform->position.x > camPos.x + dfCLIENT_WIDTH + dfCLIENT_WIDTH / 2) continue;
		if (iter->transform->position.y > camPos.y + dfCLIENT_HEIGHT + dfCLIENT_HEIGHT / 2) continue;


		pObjectManager->renderList.push_back(iter);
	}

	// z값으로 정렬
	pObjectManager->renderList.sort(CompareZ);
	// 오브젝트 렌더링
	for (auto& obj : pObjectManager->renderList)
	{
		obj->Render();
	}
	
	
	
	// 디버그용
	//TimeManager::RenderFPS();
}

void PKH::ObjectManager::PostRender()
{
	auto& objList = pObjectManager->objectList;
	for (auto& iter : objList)
	{
		if (!iter->isEnable) continue;
		iter->PostRender();
	}

	RenderFilter::GetInstance()->Render();
	TargetInfoPanel::GetInstance()->Render();
	PlayerInfoPanel::GetInstance()->Render();
	Cursor::GetInstance()->Render();
}

bool PKH::ObjectManager::CompareY(GameObject* a, GameObject* b)
{
	return a->transform->position.y < b->transform->position.y;
}

bool PKH::ObjectManager::CompareZ(GameObject* a, GameObject* b)
{
	return a->transform->zOrder > b->transform->zOrder;
}

bool PKH::ObjectManager::IsVisibleCollider()
{
	return pObjectManager->isVisibleCollider;
}

void PKH::ObjectManager::SetVisibleCollider(bool _isVisible)
{
	pObjectManager->isVisibleCollider = _isVisible;
}
