#pragma once
#include "NPC.h"
class NPC_Bulbasaur :
    public NPC
{
private:
	NPC_Bulbasaur();
	NPC_Bulbasaur(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_Bulbasaur();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC��(��) ���� ��ӵ�
	virtual void OnEvent() override;

	static void MetatoBulbasaur();

public:
	//Create(��ġ����, �߾��� �ٶ󺸰� �Ұ��ΰ�, False������ ���⼭ ���⺤��);
	static NPC_Bulbasaur* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });

};


