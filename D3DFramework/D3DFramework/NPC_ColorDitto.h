#pragma once
#include "NPC.h"
class NPC_ColorDitto :
    public NPC
{
private:
	NPC_ColorDitto();
	NPC_ColorDitto(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_ColorDitto();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC��(��) ���� ��ӵ�
	virtual void OnEvent() override;


public:
	//Create(��ġ����, �߾��� �ٶ󺸰� �Ұ��ΰ�, False������ ���⼭ ���⺤��);
	static NPC_ColorDitto* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });

};


