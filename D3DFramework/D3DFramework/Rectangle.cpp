#include "stdafx.h"
#include "Rectangle.h"
#include "Color.h"

PKH::Rectangle::Rectangle()
{
	this->vertexCount = 4;
	this->triangleCount = 2;

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

	vertices[0] = Vertex(Vector3(-1.f, -1.f, 0.f), 0xFFFFFFFF, 0, 1);
	vertices[1] = Vertex(Vector3(-1.f, 1.f, 0.f), 0xFFFFFFFF, 0, 0);
	vertices[2] = Vertex(Vector3(1.f, 1.f, 0.f), 0xFFFFFFFF, 1, 0);
	vertices[3] = Vertex(Vector3(1.f, -1.f, 0.f), 0xFFFFFFFF, 1, 1);
	vertexBuffer->Unlock();

	WORD* indices = nullptr;
	triangles->Lock(0, 0, (void**)&indices, 0);
	indices[0] = 0; indices[1] = 1; indices[2] = 3;
	indices[3] = 1; indices[4] = 2; indices[5] = 3;
	triangles->Unlock();


}

PKH::Rectangle::~Rectangle()
{
	
}

void PKH::Rectangle::Update()
{
}


IComponent* PKH::Rectangle::Clone()
{
	return new Rectangle(*this);
}
