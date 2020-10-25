#include "stdafx.h"
#include "Rectangle.h"
#include "Color.h"

PKH::Rectangle::Rectangle()
{
	this->vertexCount = 4;
	this->triangleCount = 2;

	D2DRenderManager::GetDevice()->CreateVertexBuffer(
		vertexCount * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		Vertex::FVF,
		D3DPOOL_MANAGED,
		&vb,
		0);

	D2DRenderManager::GetDevice()->CreateIndexBuffer(
		triangleCount * 3 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&triangles,
		0);

	Vertex* vertices;
	vb->Lock(0, 0, (void**)&vertices, 0);

	vertices[0] = Vertex(-1.f, -1.f, 0.f, 0xFFFFFFFF, 0, 1);
	vertices[1] = Vertex(-1.f, 1.f, 0.f, 0xFFFFFFFF, 0, 0);
	vertices[2] = Vertex(1.f, 1.f, 0.f, 0xFFFFFFFF, 1, 0);
	vertices[3] = Vertex(1.f, -1.f, 0.f, 0xFFFFFFFF, 1, 1);
	vb->Unlock();

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
