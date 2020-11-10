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
	animation = false;
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
	Dialog::EnqueueText(L"���߱���!");
	Dialog::EnqueueText(L"���� �� ĳ���Ǹ� ����غ��ڴ�?");
	Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���.)");
	Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
	Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");
	Dialog::Show();
}

void NPC_DoctorOh::Event2()
{
	Dialog::EnqueueText(L"���� �̳��");
	/*Dialog::EnqueueText(L"���� ������� ���߳�������.");*/
	Dialog::Show();
	/*SceneManager::LoadScene<Stage_Grass_01>();*/
}
