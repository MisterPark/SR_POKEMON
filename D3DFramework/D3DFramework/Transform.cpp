#include "stdafx.h"
#include "transform.h"

using namespace PKH;

PKH::Transform::Transform()
{
}

PKH::Transform::~Transform()
{
}

void PKH::Transform::Update()
{
	world = world.identity;
	// ���Ϸ� �� 360�� ����
	eulerAngles.x = fmodf(eulerAngles.x, D3DXToRadian(360.f));
	eulerAngles.y = fmodf(eulerAngles.y, D3DXToRadian(360.f));
	eulerAngles.z = fmodf(eulerAngles.z, D3DXToRadian(360.f));
	
	

	// ���Ϸ��� -> ���ʹϾ�
	D3DXQuaternionRotationYawPitchRoll(&rotation, eulerAngles.y, eulerAngles.x, eulerAngles.z);
	D3DXQuaternionNormalize(&rotation, &rotation);

	// ���� ��ǥ ����
	right = Vector3::RIGHT;
	up = Vector3::UP;
	look = Vector3::FORWARD;

	Matrix matRot;
	D3DXMatrixRotationQuaternion(&matRot, &rotation);
	D3DXVec3TransformNormal(&right, &right, &matRot);
	D3DXVec3TransformNormal(&up, &up, &matRot);
	D3DXVec3TransformNormal(&look, &look, &matRot);

	Vector3::Normalize(&right);
	Vector3::Normalize(&up);
	Vector3::Normalize(&look);

	Matrix matTrans, matScale, matRotation;//, rotX, rotY, rotZ
	D3DXMatrixScaling(&matScale, scale.x, scale.y, scale.z);
	//D3DXMatrixRotationX(&rotX, transform->eulerAngles.x);
	//D3DXMatrixRotationY(&rotY, transform->eulerAngles.y);
	//D3DXMatrixRotationZ(&rotZ, transform->eulerAngles.z);
	D3DXMatrixRotationQuaternion(&matRotation, &rotation);
	D3DXMatrixTranslation(&matTrans, position.x, position.y, position.z);

	//world = matScale * rotX * rotY * rotZ * matTrans;
	world = matScale * matRotation * matTrans;
}

IComponent* PKH::Transform::Clone()
{
    return new Transform(*this);
}

void PKH::Transform::Rotate(Vector3 _axis, float _angle)
{
	Quaternion qRot;
	D3DXQuaternionRotationAxis(&qRot, &_axis, _angle);
	Vector3 euler = Quaternion::ToEulerAngles(qRot);
	eulerAngles = euler;
}

void PKH::Transform::LookAt(Transform _target, Vector3 _worldUp)
{
	
	Vector3 dir = _target.position - position;
	Quaternion qRot;
	Vector3 axis = Vector3::Cross(dir, _worldUp);
	float angle = acosf(Vector3::Dot(_worldUp.Normalized(), dir.Normalized()));
	D3DXQuaternionRotationAxis(&qRot, &axis, angle);
	Vector3 euler = Quaternion::ToEulerAngles(qRot);
	
	eulerAngles = euler;

}

void PKH::Transform::LookAt(Vector3 _target, Vector3 _worldUp)
{
	Vector3 dir = _target - position;
	Quaternion qRot;
	Vector3 axis = Vector3::Cross(dir, _worldUp);
	float angle = acosf(Vector3::Dot(_worldUp, dir.Normalized()));
	D3DXQuaternionRotationAxis(&qRot, &axis, angle);
	Vector3 euler = Quaternion::ToEulerAngles(qRot);

	eulerAngles = euler;
}

void PKH::Transform::RotatePitch(float _angle)
{
	Rotate(right, _angle);
}

void PKH::Transform::RotateYaw(float _angle)
{
	Rotate(up, _angle);
}

void PKH::Transform::RotateRoll(float _angle)
{
	Rotate(look, _angle);
}

void PKH::Transform::RotateX(float _angle)
{
	Rotate(Vector3::RIGHT, _angle);
}

void PKH::Transform::RotateY(float _angle)
{
	Rotate(Vector3::UP, _angle);
}

void PKH::Transform::RotateZ(float _angle)
{
	Rotate(Vector3::FORWARD, _angle);
}
