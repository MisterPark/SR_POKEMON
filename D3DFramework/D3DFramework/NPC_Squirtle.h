#pragma once
#include "NPC.h"
class NPC_Squirtle :
    public NPC
{
private:
	NPC_Squirtle();
	NPC_Squirtle(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_Squirtle();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC��(��) ���� ��ӵ�
	virtual void OnEvent() override;
	
	static void MetatoSquirtle();
	static void MetatoWartortle();
	static void MetatoBlastoise();
	static void SummonCaterpie();
public:
	//Create(��ġ����, �߾��� �ٶ󺸰� �Ұ��ΰ�, False������ ���⼭ ���⺤��);
	static NPC_Squirtle* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });

};


