#pragma once


using namespace PKH;


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


		void SetPosition(Vector3 _vPos);

		template<class T>
		IComponent* AddComponent(const wstring& _key);

		IComponent* GetComponent(const wstring& _key);
		Transform* GetTransform() { return transform; } //����


	public:
		Transform* transform = nullptr;

		ObjectType type = ObjectType::NONE;
		float moveSpeed = 1.f;
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


