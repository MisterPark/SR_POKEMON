#include "stdafx.h"
#include "GameObject.h"
#include "IComponent.h"
#include "transform.h"

using namespace PKH;

PKH::GameObject::GameObject()
{
	transform = (Transform*)AddComponent<Transform>(L"Transform");
}

PKH::GameObject::~GameObject()
{
	ReleaseComponents();
}

void PKH::GameObject::Update()
{
	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

void PKH::GameObject::Render()
{
	if (isVisible == false) return;

	for (auto& comp : components)
	{
		Mesh* mesh = dynamic_cast<Mesh*>(comp.second);
		if (mesh == nullptr) continue;


		mesh->Render();
	}
}

void PKH::GameObject::Die()
{
	isDead = true;
}

void PKH::GameObject::OnCollision(GameObject* target)
{
	//switch (target->GetObjId()) {
	//case OBJ::BULLET: {

	//	}
	//	break;
	//}

	//default:
	//	break;
	//}

}


void PKH::GameObject::Move(Vector3 _direction)
{
	Vector3::Normalize(&_direction);
	transform->position.x += _direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.y += _direction.y * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += _direction.z * moveSpeed * TimeManager::DeltaTime();
}

void PKH::GameObject::MoveToTarget(Vector3 _target)
{
	Vector3 dir = _target - transform->position;
	Vector3::Normalize(&dir);
	transform->position.x += dir.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();
}

void PKH::GameObject::FollowTarget(const GameObject* _target)
{
	MoveToTarget(_target->transform->position);
}

void PKH::GameObject::FollowTarget(const Transform& _targetTransform)
{
	MoveToTarget(_targetTransform.position);
}

void PKH::GameObject::FollowTarget(const Vector3& _targetPos)
{
	MoveToTarget(_targetPos);
}

void PKH::GameObject::FaceTarget(const GameObject* _target)
{
	transform->LookAt(_target->transform->position);
}

void PKH::GameObject::FaceTarget(const Transform& _targetTransform)
{
	transform->LookAt(_targetTransform.position);
}

void PKH::GameObject::FaceTarget(const Vector3& _targetPos)
{
	transform->LookAt(_targetPos);
}

void PKH::GameObject::Billboard()
{
	D3DXMATRIX matScale, matView;
	D3DXMatrixIdentity(&matView);
	matView = Camera::GetViewMatrix();

	memset(&matView._41, 0, sizeof(D3DXVECTOR3));
	D3DXMatrixInverse(&matView, 0, &matView);

	D3DXVECTOR3 BillPos = transform->position;
	D3DXMatrixScaling(&matScale, transform->scale.x, transform->scale.y, transform->scale.z);

	

	//이동 부분
	memcpy(&matView._41, &BillPos, sizeof(D3DXVECTOR3));
	//이동부분을 반영해줍니다. 다시 좌표의 위치로 이동시켜주는 처리입니다.

	//D2DRenderManager::GetDevice()->SetTransform(D3DTS_WORLD, &matView);
	transform->world = matScale*matView;
}

void PKH::GameObject::SetPosition(Vector3 _vPos)
{
	transform->position = _vPos;
}

void PKH::GameObject::ReleaseComponents()
{
	auto iter = components.begin();
	auto end = components.end();
	for (; iter != end;++iter)
	{
		delete iter->second;
	}
	components.clear();
}

IComponent* PKH::GameObject::GetComponent(const wstring& _key)
{
	auto f = components.find(_key);
	if (f == components.end()) return nullptr;
	return f->second;
}

