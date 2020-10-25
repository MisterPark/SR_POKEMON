#include "stdafx.h"
#include "Animation2D.h"

PKH::Animation2D::Animation2D()
{
}

PKH::Animation2D::~Animation2D()
{
}

void PKH::Animation2D::Update()
{
	if (nullptr == gameObject)
	{
		return;
	}
		

	tick += TimeManager::DeltaTime();
	if (tick > delay)
	{
		tick = 0;

		if (currentTexture == endTexture)
		{
			if (isLoop == true)
			{
				currentTexture = startTexture;
			}
			return;
		}
		int i = int(currentTexture);
		i++;
		
		currentTexture = (TextureKey)i;
		
	}
	Mesh* mesh = (Mesh*)gameObject->GetComponent(L"Mesh");
	mesh->SetTexture(currentTexture);

}

void PKH::Animation2D::SetSprite(TextureKey _startTexture, TextureKey _endTexture)
{
	startTexture = _startTexture;
	currentTexture = startTexture;
	endTexture = _endTexture;
	
}

void PKH::Animation2D::SetLoop(bool _isLoop)
{
	isLoop = _isLoop;
}

void PKH::Animation2D::SetDelay(float _delay)
{
	delay = _delay;
}

IComponent* PKH::Animation2D::Clone()
{
    return nullptr;
}
