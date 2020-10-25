#pragma once
#include "IComponent.h"
#include "Vector3.h"

namespace PKH
{
	class Transform : public IComponent
	{
	public:
		Transform();

		~Transform();

		virtual void Update();
		virtual IComponent* Clone() override;

		// ������ �� ȸ��
		void Rotate(Vector3 _axis, float _angle);
		// �ٶ󺸱�
		void LookAt(Transform _target, Vector3 _worldUp = Vector3::UP);
		void LookAt(Vector3 _target, Vector3 _worldUp = Vector3::UP);

		// ���� X�� ȸ��
		void RotatePitch(float _angle);
		// ���� Y�� ȸ��
		void RotateYaw(float _angle);
		// ���� Z�� ȸ��
		void RotateRoll(float _angle);

		// ���� X�� ȸ��
		void RotateX(float _angle);
		// ���� Y�� ȸ��
		void RotateY(float _angle);
		// ���� Z�� ȸ��
		void RotateZ(float _angle);

		Vector3* Get_Pos() { return &position; } //����

	public:
		Vector3 position{ 0.f,0.f,0.f };
		Vector3 eulerAngles{ 0.f,0.f,0.f };
		Vector3 scale{ 1.f,1.f,1.f };
		Quaternion rotation;

		Vector3 right = Vector3::RIGHT;
		Vector3 up = Vector3::UP;
		Vector3 look = Vector3::FORWARD;
		Matrix world;
	};
}


