#include "stdafx.h"
#include "Cube.h"

PKH::Cube::Cube()
{
	this->vertexCount = 8;
	this->triangleCount = 12;
	
	RenderManager::LockDevice();
	RenderManager::GetDevice()->CreateVertexBuffer(
		vertexCount * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		Vertex::FVF,
		D3DPOOL_MANAGED,
		&vertexBuffer,
		0);

	RenderManager::GetDevice()->CreateIndexBuffer(
		triangleCount * 3 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&triangles,
		0);
	RenderManager::UnlockDevice();

	Vertex* vertices;
	vertexBuffer->Lock(0, 0, (void**)&vertices, 0);

	// ����
	vertices[0] = Vertex(Vector3(-1.0f, -1.0f, -1.0f), D3DCOLOR_XRGB(255, 0, 0),0,1);
	vertices[1] = Vertex(Vector3(-1.0f, 1.0f, -1.0f), D3DCOLOR_XRGB(0, 255, 0),0,0);
	vertices[2] = Vertex(Vector3(1.0f, 1.0f, -1.0f), D3DCOLOR_XRGB(0, 0, 255),1,0);
	vertices[3] = Vertex(Vector3(1.0f, -1.0f, -1.0f), D3DCOLOR_XRGB(255, 0, 255),1,1);

	// �ĸ�
	vertices[4] = Vertex(Vector3(-1.0f, -1.0f, 1.0f), D3DCOLOR_XRGB(255, 0, 0),1,1);
	vertices[5] = Vertex(Vector3(-1.0f, 1.0f, 1.0f), D3DCOLOR_XRGB(0, 255, 0),1,0);
	vertices[6] = Vertex(Vector3(1.0f, 1.0f, 1.0f), D3DCOLOR_XRGB(0, 0, 255),0,0);
	vertices[7] = Vertex(Vector3(1.0f, -1.0f, 1.0f), D3DCOLOR_XRGB(255, 0, 255),0,1);
	vertexBuffer->Unlock();

	WORD* indices = nullptr;
	triangles->Lock(0, 0, (void**)&indices, 0);
	// ��
	indices[0] = 0; indices[1] = 1; indices[2] = 3;
	indices[3] = 1; indices[4] = 2; indices[5] = 3;
	// ��
	indices[6] = 7; indices[7] = 6; indices[8] = 4;
	indices[9] = 6; indices[10] = 5; indices[11] = 4;
	// ��
	indices[12] = 4; indices[13] = 5; indices[14] = 0;
	indices[15] = 5; indices[16] = 1; indices[17] = 0;
	// ��
	indices[18] = 3; indices[19] = 2; indices[20] = 7;
	indices[21] = 2; indices[22] = 6; indices[23] = 7;
	// ��
	indices[24] = 1; indices[25] = 5; indices[26] = 2;
	indices[27] = 5; indices[28] = 6; indices[29] = 2;
	// ��
	indices[30] = 4; indices[31] = 0; indices[32] = 7;
	indices[33] = 0; indices[34] = 3; indices[35] = 7;
	triangles->Unlock();


}

PKH::Cube::~Cube()
{
}

void PKH::Cube::Update()
{

}


IComponent* PKH::Cube::Clone()
{
	return new Cube(*this);
}
