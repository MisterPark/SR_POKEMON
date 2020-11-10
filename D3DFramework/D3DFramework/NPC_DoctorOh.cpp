#include "stdafx.h"
#include "NPC_DoctorOh.h"
#include "Dialog.h"
#include "Stage_Grass_01.h"

NPC_DoctorOh::NPC_DoctorOh()
{
	name = L"세레비";
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
	Dialog::EnqueueText(L"난 오박사란다.", L"세레비", Pokemon::Celebi);
	Dialog::EnqueueText(L"세레비를 잡아오거라.", L"세레비", Pokemon::Celebi);
	Dialog::Show();
}

void NPC_DoctorOh::Event2()
{
	Dialog::EnqueueText(L"아직도 세레비를 잡지 못한것이냐.",L"세레비", Pokemon::Celebi);
	Dialog::Show();
	SceneManager::LoadScene<Stage_Grass_01>();
}
