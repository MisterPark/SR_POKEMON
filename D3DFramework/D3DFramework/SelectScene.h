#pragma once
#include "IScene.h"

using namespace PKH;

class SelectScene : public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

	static void StartRotateChar();
	static void CancelRotateChar();
	static void ChangeNext();
	static void ChangePrev();
	static void SelectCharacter();


	static Character* selectedPoke;
	Character* pokeA = nullptr;
	Character* pokeB = nullptr;
	Character* pokeC = nullptr;

	static bool isClickedRotateButton;
	static float rotationAngle;
	static Pokemon selectedIndex;
};

