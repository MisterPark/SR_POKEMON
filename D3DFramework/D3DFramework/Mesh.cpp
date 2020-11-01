#include "stdafx.h"
#include "Mesh.h"

using namespace PKH;

Mesh::Mesh()
{
	
}

Mesh::~Mesh()
{
	vb->Release();
	triangles->Release();
}

void PKH::Mesh::Render()
{
	if (gameObject == nullptr)return;

	Transform* transform = (Transform*)gameObject->GetComponent(L"Transform");

	LPDIRECT3DDEVICE9 device = D2DRenderManager::GetDevice();
	if (device)
	{
		Texture* texture = D2DRenderManager::GetTexture(textureKey);
		if (texture != nullptr)
		{
			device->SetTexture(0, texture->pTexture);
		}

		device->SetStreamSource(0, vb, 0, sizeof(Vertex));
		device->SetFVF(Vertex::FVF);
		device->SetIndices(triangles);


		device->SetTransform(D3DTS_WORLD, &transform->world);

		

		switch (blendMode)
		{
		case PKH::BlendMode::NONE:
			break;
		case PKH::BlendMode::ALPHA_BLEND:
			device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

			device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
			break;
		case PKH::BlendMode::ALPHA_TEST:
			device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

			device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
			device->SetRenderState(D3DRS_ALPHAREF, 0x00000088);
			device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
			break;
		default:
			break;
		}
		
		device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
		device->SetRenderState(D3DRS_LIGHTING, false);

		device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, vertexCount, 0, triangleCount);
	
		device->SetTexture(0, NULL);

		switch (blendMode)
		{
		case PKH::BlendMode::NONE:
			break;
		case PKH::BlendMode::ALPHA_BLEND:
			device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
			break;
		case PKH::BlendMode::ALPHA_TEST:
			device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
			device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
			break;
		default:
			break;
		}
		
	
	}
}

PKH::IComponent * PKH::Mesh::Clone()
{
	return new Mesh(*this);
}

UINT PKH::Mesh::GetVertexCount()
{
	return this->vertexCount;
}

IDirect3DVertexBuffer9 * PKH::Mesh::GetVertexBuffer()
{
	return vb;
}

void PKH::Mesh::SetColor(D3DCOLOR color)
{
	Vertex* vertices;
	vb->Lock(0, 0, (void**)&vertices, 0);
	for (int i = 0; i < vertexCount; i++)
	{
		vertices[i].color = color;
	}
	
	vb->Unlock();
}

void PKH::Mesh::SetTexture(PKH::TextureKey key)
{
	textureKey = key;
}

void PKH::Mesh::SetVertexPos(UINT index, const Vector3& pos)
{
	Vertex* vertices;
	vb->Lock(0, 0, (void**)&vertices, 0);
	vertices[index].x = pos.x;
	vertices[index].y = pos.y;
	vertices[index].z = pos.z;
	vb->Unlock();
}

void PKH::Mesh::SetUV(UINT index, float u, float v)
{
	Vertex* vertices;
	vb->Lock(0, 0, (void**)&vertices, 0);
	vertices[index].u = u;
	vertices[index].v = v;
	vb->Unlock();
}

void PKH::Mesh::SetBlendMode(BlendMode _mode)
{
	this->blendMode = _mode;
}
