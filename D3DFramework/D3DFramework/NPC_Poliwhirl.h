#pragma once
#include "NPC.h"
class NPC_Poliwhirl :
	public NPC
{
private:
	NPC_Poliwhirl();
	NPC_Poliwhirl(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_Poliwhirl();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC��(��) ���� ��ӵ�
	virtual void OnEvent() override;
	static void ExpPotion();

public:
	//Create(��ġ����, �߾��� �ٶ󺸰� �Ұ��ΰ�, False������ ���⼭ ���⺤��);
	static NPC_Poliwhirl* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });
};


