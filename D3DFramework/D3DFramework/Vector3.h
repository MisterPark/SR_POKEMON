#pragma once
#include <d3dx9.h>

namespace PKH
{
	class Vector3 : public D3DXVECTOR3
	{
	public:
		Vector3();
		Vector3(D3DXVECTOR3 r);
		Vector3(POINT r);
		Vector3(float x, float y, float z);
		~Vector3();

		//=====================================
		// operator
		//=====================================

		using D3DXVECTOR3::operator const FLOAT*;
		using D3DXVECTOR3::operator FLOAT*;
		using D3DXVECTOR3::operator*;
		using D3DXVECTOR3::operator*=;
		using D3DXVECTOR3::operator+;
		using D3DXVECTOR3::operator+=;
		using D3DXVECTOR3::operator-;
		using D3DXVECTOR3::operator-=;
		using D3DXVECTOR3::operator/;
		using D3DXVECTOR3::operator/=;
		using D3DXVECTOR3::operator==;
		using D3DXVECTOR3::operator!=;

		bool operator==(const Vector3& other);
		bool operator!=(const Vector3& other);
		Vector3& operator=(const Vector3& rhs);
		
		//=====================================
		// Public Function
		//=====================================
		
		// ������ ���̸� ��ȯ�մϴ�.
		float Magnitude() const;
		// ������ ���̸� ��ȯ�մϴ�.
		float Length() const;
		// ������ ������ ������ ��ȯ�մϴ�.
		float SquareMagnitude() const;
		// �ش� ������ �������͸� ��ȯ�մϴ�.
		// ���� : 
		// �ش� ������ ���� �ٲ��� �ʽ��ϴ�.
		// �ش� ������ ���� �ٲٷ���
		// Vector3::Normalize() �� ����ϼ���.
		Vector3 Normalized() const;

		//=====================================
		// Static Function
		//=====================================

		// from ���� to ������ ���� ���մϴ�.
		// ���� Degree
		// ���� -180 ~ 180
		static float	Angle(const Vector3& from, const Vector3& to);
		// �� ������ ����
		static Vector3	Cross(const Vector3& lhs, const Vector3& rhs);
		// a�� b������ �Ÿ��� ��ȯ�մϴ�.
		static float	Distance(const Vector3& a, const Vector3& b);
		// �� ������ ����
		static float	Dot(const Vector3& lhs, const Vector3& rhs);
		// ���͸� Normalize �մϴ�.
		static void		Normalize(Vector3* outV);


		//=====================================
		// static variables
		//=====================================

		// (-1,0,0)
		static const Vector3 LEFT;
		// (1,0,0)
		static const Vector3 RIGHT;
		// (0,1,0)
		static const Vector3 UP;
		// (0,-1,0)
		static const Vector3 DOWN;
		// (0,0,1)
		static const Vector3 FORWARD;
		// (0,0,-1)
		static const Vector3 BACK;
		// (1,1,1)
		static const Vector3 ONE;
		// (0,0,0)
		static const Vector3 ZERO;
	};
	

	
}


