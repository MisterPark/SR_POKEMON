#pragma once
#include "NPC.h"
class NPC_MiniBulbasaur :
	public NPC
{
private:
	NPC_MiniBulbasaur();
	NPC_MiniBulbasaur(const Vector3& pos, bool onCenterDir, const Vector3& dir);
	virtual ~NPC_MiniBulbasaur();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC을(를) 통해 상속됨
	virtual void OnEvent() override;


public:
	//Create(위치벡터, 중앙을 바라보게 할것인가, False였으면 여기서 방향벡터);
	static NPC_MiniBulbasaur* Create(const Vector3& pos, bool onCenterDir = true, const Vector3& dir = Vector3{ 24.f, 0.f, 24.f });

};


