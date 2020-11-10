#include "stdafx.h"
#include "Dialog.h"

Dialog* pDialog = nullptr;

Dialog::Dialog()
{
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

	if (readyText == currText) // 모두 출력 or 아무것도 없음
	{

		if (InputManager::GetKeyDown(VK_RETURN))
		{
			int count = textQ.size();
			if (count > 0) // 대기열에 있으면
			{
				currText = L"";
				readyText = textQ.front(); // 하나 뽑고
				textQ.pop();
				copyCount = 0;
				
			}
			else
			{
				currText = L"";
				readyText = L"";
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
	else // 출력 중
	{
		tick += TimeManager::DeltaTime();
		if (tick > delay)
		{
			tick = 0.f;

			int len = readyText.length();
			currText += readyText[copyCount];
			copyCount++;
		}

		if (InputManager::GetKeyDown(VK_RETURN))
		{
			currText = readyText;
		}
		
	}
	

}

void Dialog::Render()
{
	if (pDialog->isVisible == false) return;

	D2DRenderManager::DrawUI(TextureKey::UI_DIALOG, transform->position, 0);

	D2DRenderManager::DrawFont(currText, transform->position.x, transform->position.y, D3DCOLOR_ARGB(255, 0, 0, 0));
}

void Dialog::EnqueueText(const wstring & _text)
{
	if (pDialog->readyText == pDialog->currText)
	{
		pDialog->readyText = _text;
	}
	else
	{
		pDialog->textQ.push(_text);
	}
	
}

void Dialog::SetEndEvent(void(*Func)())
{
	pDialog->End = Func;
}

