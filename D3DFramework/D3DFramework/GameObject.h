#pragma once


using namespace PKH;

enum class State
{
	IDLE, WALK, ATTACK, SKILL, SKILL2, SKILL3, HURT, READY, END
};
enum class Direction
{
	D, LD, L, LU, U, RU, R, RD, END
};

enum class Team
{
	NEUTRAL,PLAYERTEAM,MONSTERTEAM,END
};

namespace PKH
{
	class IComponent;


	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		
		virtual void Initialize() = 0;
		virtual void Release() = 0;
		virtual void Update() = 0;
		virtual void PostUpdate();
		virtual void Render();
		virtual void Die();
		virtual void OnCollision(GameObject* target);
		virtual void PostRender() {};

		// �������� �̵�
		// ���ο��� ����ȭ ����.
		void Move(Vector3 _direction);
		// ��ġ�� �̵�
		void MoveToTarget(Vector3 _target);
		// Ÿ�� ���󰡱�
		void FollowTarget(const GameObject* _target);
		void FollowTarget(const Transform& _targetTransform);
		void FollowTarget(const Vector3& _targetPos);
		// Ÿ�� ������Ʈ �������� ȸ��
		void FaceTarget(const GameObject* _target);
		void FaceTarget(const Transform& _targetTransform);
		void FaceTarget(const Vector3& _targetPos);
		// ������
		// GameObject::Update() ȣ�� �Ŀ� ȣ��
		void Billboard();
		void BillboardYaw();

		void AddToCollideList(GameObject* object);
		bool IsInCollideList(const GameObject* object) const;

		void SetPosition(Vector3 _vPos);

		template<class T>
		IComponent* AddComponent(const wstring& _key);
		void ReleaseComponents();

		IComponent* GetComponent(const wstring& _key);
		Transform* GetTransform() const { return transform; } //����
		STAT GetStat() const { return stat; }

		bool IsDead();

	public:
		Transform* transform = nullptr;
		STAT stat;
		Team team = Team::NEUTRAL;
		
		bool isVisible = true;
		bool isEnable = true;
		bool dontDestroy = false;
		
		map<wstring, PKH::IComponent*> components;
		list<GameObject*> collideList;
	protected:
		bool isDead = false;
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


