#include "stdafx.h"
#include "Dialog.h"

Dialog* pDialog = nullptr;

Dialog::Dialog()
{
	transform->position.x = 112;
	transform->position.y = 284;

	isVisible = false;
}

Dialog::~Dialog()
{
}

Dialog * Dialog::GetInstance()
{
	if (pDialog == nullptr)
	{
		pDialog = new Dialog;
	}
	return pDialog;
}

void Dialog::Destroy()
{
	if (pDialog)
	{
		delete pDialog;
		pDialog = nullptr;
	}
}

void Dialog::Initialize()
{
}

void Dialog::Release()
{
}

void Dialog::Show()
{
	pDialog->isVisible = true;
}

void Dialog::Hide()
{
	pDialog->isVisible = false;
}

void Dialog::Update()
{
	if (pDialog->isVisible == false) return;

	if (element.text == currText) // ��� ��� or �ƹ��͵� ����
	{

		if (InputManager::GetKeyDown(VK_RETURN))
		{
			int count = textQ.size();
			if (count > 0) // ��⿭�� ������
			{
				currText = L"";
				element = textQ.front(); // �ϳ� �̰�
				textQ.pop();
				copyCount = 0;
				
			}
			else
			{
				currText = L"";
				element.name = L"";
				element.text = L"";
				element.number = Pokemon::None;
				copyCount = 0;
				Hide();
				if (End != nullptr)
				{
					End();
					End = nullptr;
				}
					

			}
		}
		
	}
	else // ��� ��
	{
		tick += TimeManager::DeltaTime();
		if (tick > delay)
		{
			tick = 0.f;

			int len = element.text.length();
			currText += element.text[copyCount];
			copyCount++;
			SoundManager::PlayOverlapSound(L"Message.wav", SoundChannel::EFFECT, 0.5f, 0.1f);
		}

		if (InputManager::GetKeyDown(VK_RETURN))
		{
			currText = element.text;
			SoundManager::PlayOverlapSound(L"Skip.wav", SoundChannel::EFFECT, 0.5f);
		}
		
	}
	

}

void Dialog::Render()
{
	if (pDialog->isVisible == false) return;

	// ��ȭâ
	RenderManager::DrawUI(TextureKey::UI_DIALOG, transform->position, 0);
	

	// �ؽ�Ʈ
	Vector3 textPos = transform->position;
	textPos.x += 128;
	textPos.y += 50;
	int len = element.text.length() * 10;
	RenderManager::DrawFont(currText, textPos.x , textPos.y, D3DCOLOR_ARGB(255, 0, 0, 0));

	// �� ���
	Vector3 imgPos = transform->position;
	int pokeNumber = (int)element.number;
	int generation = GetPokemonGeneration(element.number);

	// �׸��� ��ġ ���� (����, ��)
	if (element.isLeft== false)
	{
		imgPos.x += 800 - 128;
	}

	// ��
	if (generation == 1)
	{
		RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, imgPos, pokeNumber - 1);
	}
	else if (generation == 2)
	{
		pokeNumber -= (int)Pokemon::Mew;
		pokeNumber += 27;//�ȳ� ����
		RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_2ND, imgPos, pokeNumber - 1);
	}
	else
	{
		pokeNumber -= (int)Pokemon::Celebi;
		RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_3RD, imgPos, pokeNumber - 1);
	}

	// �̸�
	int nameLen = element.name.length() * 10;
	Vector3 namePos = imgPos;
	namePos.x += nameLen;
	namePos.y += 150;
	RenderManager::DrawFont(element.name, namePos.x, namePos.y, D3DCOLOR_ARGB(255, 0, 0, 0));
}

void Dialog::EnqueueText(const wstring& _text, bool isLeft)
{
	if (pDialog->textQ.empty() && pDialog->element.text == pDialog->currText)
	{
		pDialog->element.text = _text;
		pDialog->element.isLeft = isLeft;
	}
	else
	{
		DialogElement elem;
		elem.text = _text;
		elem.isLeft = isLeft;
		pDialog->textQ.push(elem);
	}
	
}

void Dialog::EnqueueText(const wstring& _text, const wstring& name, Pokemon number, bool isLeft)
{
	if (pDialog->textQ.empty() && pDialog->element.text == pDialog->currText)
	{
		pDialog->element.text = _text;
		pDialog->element.name = name;
		pDialog->element.number = number;
		pDialog->element.isLeft = isLeft;
	}
	else
	{
		DialogElement elem;
		elem.text = _text;
		elem.name = name;
		elem.number = number;
		elem.isLeft = isLeft;
		pDialog->textQ.push(elem);
	}
}

void Dialog::EnqueueText(const DialogElement& elem)
{
	if (pDialog->textQ.empty() && pDialog->element.text == pDialog->currText)
	{
		pDialog->element = elem;
	}
	else
	{
		pDialog->textQ.push(elem);
	}
}

void Dialog::SetEndEvent(void(*Func)())
{
	pDialog->End = Func;
}

