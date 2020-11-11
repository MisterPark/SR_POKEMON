#pragma once

namespace PKH
{
	class Vertex
	{
	public:
		Vertex(Vector3 _pos, D3DCOLOR _color, float _u, float _v);

		Vector3 pos;
		Vector3 normal;
		D3DCOLOR color;
		float u;
		float v;

		static const DWORD FVF;
	};
	class VertexColor
	{
	public:
		VertexColor(float _x, float _y, float _z, D3DCOLOR _color);

		float x;
		float y;
		float z;
		D3DCOLOR color;

		static const DWORD FVF; //�÷����� ���ؽ� ���� = �������� ���ؽ� ���� = Ŀ���� ���ؽ�
	};
	

	class VertexUV
	{
	public:
		VertexUV(float _x, float _y, float _z, float _u, float _v);

		float x;
		float y;
		float z;
		float u;
		float v;

		static const DWORD FVF; 
	};

	typedef	struct tagIndex16
	{
		unsigned short	_0, _1, _2;

	}INDEX16;

	typedef	struct tagIndex32
	{
		unsigned long	_0, _1, _2;

	}INDEX32;
}
