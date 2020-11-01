#pragma once


using namespace PKH;

enum class State
{
	IDLE, WALK, ATTACK, PLAYER_SEARCH, SKILL, SKILL2, HURT, READY, END
};
enum class Direction
{
	D, LD, L, LU, U, RU, R, RD, END
};

namespace PKH
{
	class IComponent;

	enum class ObjectType
	{
		NONE,


		END
	};

	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize() = 0;
		virtual void Release() = 0;
		virtual void Update() = 0;
		virtual void Render();
		virtual void Die();
		virtual void OnCollision(GameObject* target);
		virtual void PostRender() {};

		// 방향으로 이동
		// 내부에서 정규화 해줌.
		void Move(Vector3 _direction);
		// 위치로 이동
		void MoveToTarget(Vector3 _target);
		// 타겟 따라가기
		void FollowTarget(const GameObject* _target);
		void FollowTarget(const Transform& _targetTransform);
		void FollowTarget(const Vector3& _targetPos);
		// 타겟 오브젝트 방향으로 회전
		void FaceTarget(const GameObject* _target);
		void FaceTarget(const Transform& _targetTransform);
		void FaceTarget(const Vector3& _targetPos);
		// 빌보드
		// GameObject::Update() 호출 후에 호출
		void Billboard();
		void BillboardYaw();

		void SetPosition(Vector3 _vPos);

		template<class T>
		IComponent* AddComponent(const wstring& _key);
		void ReleaseComponents();

		IComponent* GetComponent(const wstring& _key);
		Transform* GetTransform() const { return transform; } //수정


	public:
		Transform* transform = nullptr;
		float moveSpeed = 1.f;
		ObjectType type = ObjectType::NONE;
		bool isDead = false;
		bool isVisible = true;
		bool isEnable = true;
		bool isAlliance = true;
		

		map<wstring, PKH::IComponent*> components;

		
	};
	template<class T>
	inline IComponent* GameObject::AddComponent(const wstring & _key)
	{
		T* comp = new T;
		if (dynamic_cast<IComponent*>(comp) == nullptr)
		{
			delete comp;
			return nullptr;
		}

		comp->gameObject = this;
		components[_key] = comp;

		return comp;
	}
}


