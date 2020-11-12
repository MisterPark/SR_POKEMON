#pragma once
#include "NPC.h"
class NPC_DoctorOh :
	public NPC
{
private:
	NPC_DoctorOh();
	NPC_DoctorOh(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_DoctorOh();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC을(를) 통해 상속됨
	virtual void OnEvent() override;
	static void ExpPotion();

public:
	//Create(위치벡터, 중앙을 바라보게 할것인가, False였으면 여기서 방향벡터);
	static NPC_DoctorOh* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });

};


