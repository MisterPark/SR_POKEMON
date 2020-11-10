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
	Dialog::EnqueueText(L"잘했구나!");
	Dialog::EnqueueText(L"저기 저 캐터피를 사냥해보겠니?");
	Dialog::EnqueueText(L"(속성박스로 이동하세요.)");
	Dialog::EnqueueText(L"(속성박스로 이동하면 몬스터가 생성됩니다.)");
	Dialog::EnqueueText(L"(좌클릭으로 공격, 우클릭으로 스킬이 사용가능합니다.)");
	Dialog::Show();
}

void NPC_DoctorOh::Event2()
{
	Dialog::EnqueueText(L"꺼져 이년아");
	/*Dialog::EnqueueText(L"아직 사냥하지 못했나보구나.");*/
	Dialog::Show();
	/*SceneManager::LoadScene<Stage_Grass_01>();*/
}
