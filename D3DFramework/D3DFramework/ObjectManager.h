#pragma once
#include "GameObject.h"

using namespace std;

namespace PKH
{
	class ObjectManager
	{
	private:
		ObjectManager();
		~ObjectManager();
	public:
		static ObjectManager* GetInstance();
		static void Destroy();
		static void Release();

		template<class T>
		GameObject* CreateObject();

		static bool DeleteObject(GameObject* _target);
		static void DestroyAll();

		template<class T>
		GameObject* FindObject();

		template<class T>
		void FindObjectList(list<GameObject*>& outList);

		template<class TargetType>
		TargetType* GetNearestObject( GameObject* _self);
		template<class TargetType>
		TargetType* GetNearestObject( GameObject* _self, bool (*Func)(GameObject*, GameObject*));

		static void AddObject(GameObject* _obj);
		static void RemoveObject(GameObject* _obj);

		
		static void Update();
		static void PostUpdate();
		static void PreRender();
		static void Render();
		static void PostRender();

		static bool CompareY(GameObject* a, GameObject* b);
		static bool CompareZ(GameObject* a, GameObject* b);

		static bool IsVisibleCollider();
		static void SetVisibleCollider(bool _isVisible);

	private:

		list<GameObject*> objectList;
		list<GameObject*> renderList;
		bool isVisibleCollider = false;
	};


	template<class T>
	inline GameObject * ObjectManager::CreateObject()
	{
		T* pObj = new T();
		GameObject* obj = dynamic_cast<GameObject*>(pObj);
		if (obj == nullptr)
		{
			return nullptr;
		}
		objectList.push_back(obj);

		return obj;
	}

	template<class T>
	inline GameObject* ObjectManager::FindObject()
	{
		for (auto& iter : objectList)
		{
			if (dynamic_cast<T*>(iter) == nullptr) continue;

			return iter;
		}
		
		return nullptr;
	}

	template<class T>
	inline void ObjectManager::FindObjectList(list<GameObject*>& outList)
	{
		for (auto& iter : objectList)
		{
			if (dynamic_cast<T*>(iter) == nullptr) continue;

			outList.push_back(iter);
		}
	}

	template<class TargetType>
	inline TargetType* ObjectManager::GetNearestObject(GameObject* _self)
	{
		TargetType* target = nullptr;
		TargetType* comparand = nullptr;

		for (auto& iter : objectList)
		{
			if (dynamic_cast<TargetType*>(iter) == nullptr) continue;

			if (target == nullptr)
			{
				target = *iter;
				continue;
			}

			comparand = *iter;

			float targetDist = Vector3::Distance(_self->transform->position, target->transform->position);
			float compDist = Vector3::Distance(_self->transform->position, comparand->transform->position);


			if (compDist < targetDist)
			{
				target = comparand;
			}
		}

		
		return target;
	}

	template<class TargetType>
	inline TargetType* ObjectManager::GetNearestObject(GameObject* _self, bool(*Func)(GameObject*, GameObject*))
	{
		TargetType* target = nullptr;
		TargetType* comparand = nullptr;

		for (auto iter : objectList)
		{
			if (dynamic_cast<TargetType*>(iter) == nullptr) continue;
			GameObject* iterObj = iter;
			if (Func(_self, iterObj) == false) continue;

			if (target == nullptr)
			{
				target = (TargetType*)iterObj;
				continue;
			}

			comparand = (TargetType*)iterObj;

			float targetDist = Vector3::Distance(_self->transform->position, target->transform->position);
			float compDist = Vector3::Distance(_self->transform->position, comparand->transform->position);


			if (compDist < targetDist)
			{
				target = comparand;
			}
		}


		return target;
	}


}

