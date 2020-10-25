#pragma once
#include <d3dx9math.h>

namespace PKH
{
	class Matrix : public D3DXMATRIX
	{
	public:
		Matrix();
		Matrix(const D3DXMATRIX& r);
		~Matrix();

		using D3DXMATRIX::operator const FLOAT*;
		using D3DXMATRIX::operator FLOAT*;
		using D3DXMATRIX::operator*;
		using D3DXMATRIX::operator();
		using D3DXMATRIX::operator*=;
		using D3DXMATRIX::operator+;
		using D3DXMATRIX::operator+=;
		using D3DXMATRIX::operator-;
		using D3DXMATRIX::operator-=;
		using D3DXMATRIX::operator/;
		using D3DXMATRIX::operator/=;
		using D3DXMATRIX::operator==;
		using D3DXMATRIX::operator!=;
	
		// ������� ��ȯ�մϴ�.
		// Determinant : ��Ľ�
		// - ������� �������� ������	0
		// - ������� �����ϸ�			0�� �ƴ� ���� ��ȯ
		static Matrix Inverse(const Matrix& pMat, float* pOutDeterminant = nullptr);
		static Matrix LookAtLH(const Vector3& pos, const Vector3& target, const Vector3& up);
		static Matrix PerspectiveFovLH(float fovY, float aspect, float zn, float zf);


	public:
		static const Matrix identity;
	
	};
}


