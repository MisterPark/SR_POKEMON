#include "stdafx.h"
#include "Light.h"

UINT uniqueLightIndex = 0;

Light::Light()
{
	Initialize();
}

Light::~Light()
{
	Release();
}

void Light::Initialize()
{
	ZeroMemory(&lightInfo, sizeof(D3DLIGHT9));

	// ����Ʈ ����
	// TODO : ���� /�ϴ��� �𷺼ųζ���Ʈ . ���Ŀ� ������� ������
	lightInfo.Type = D3DLIGHT_DIRECTIONAL;

	lightInfo.Diffuse = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	lightInfo.Specular = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	lightInfo.Ambient = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	lightInfo.Direction = Vector3(0.f, -1.f, 1.f);
	// �ε��� ����
	index = uniqueLightIndex;
	uniqueLightIndex++;

	D2DRenderManager::GetDevice()->SetLight(index, &lightInfo);
	D2DRenderManager::GetDevice()->LightEnable(index, TRUE);

	LightManager::RegisterObject(this);
}

void Light::Release()
{
	D2DRenderManager::GetDevice()->LightEnable(index, FALSE);
	LightManager::DisregisterObject(this);
}

void Light::Update()
{
}

void Light::Render()
{
}
