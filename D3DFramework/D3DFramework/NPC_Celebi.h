#pragma once
#include "NPC.h"

class NPC_Celebi :
	public NPC
{
private:
	NPC_Celebi();
	NPC_Celebi(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_Celebi();

public:
	virtual void Initialize() override;
	virtual void Update() override;


	// NPC��(��) ���� ��ӵ�
	virtual void OnEvent() override;


public:
	//Create(��ġ����, �߾��� �ٶ󺸰� �Ұ��ΰ�, False������ ���⼭ ���⺤��);
	static NPC_Celebi* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });

};


