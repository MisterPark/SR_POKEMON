#include "stdafx.h"
#include "NPC_DoctorOh.h"
#include "Dialog.h"
#include "Stage_Grass_01.h"

NPC_DoctorOh::NPC_DoctorOh()
{
	name = L"������";
	transform->scale = { 0.5f,0.5f, 0.5f };
	offsetY = 0.5f;
	anim->SetSprite(TextureKey::NPC_DOCTOR_OH, TextureKey::NPC_DOCTOR_OH);
}

NPC_DoctorOh::~NPC_DoctorOh()
{
}

void NPC_DoctorOh::OnEvent()
{
	if (!helloFlag)
	{
		HelloWorld();
		helloFlag = true;
	}
	else
	{
		Event2();
	}
}

void NPC_DoctorOh::HelloWorld()
{
	Dialog::EnqueueText(L"�� ���ڻ����.", L"������", Pokemon::Celebi);
	Dialog::EnqueueText(L"������ ��ƿ��Ŷ�.", L"������", Pokemon::Celebi);
	Dialog::Show();
}

void NPC_DoctorOh::Event2()
{
	Dialog::EnqueueText(L"������ ������ ���� ���Ѱ��̳�.",L"������", Pokemon::Celebi);
	Dialog::Show();
	SceneManager::LoadScene<Stage_Grass_01>();
}
