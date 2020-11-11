#pragma once
#include "NPC.h"

class NPC_Celebi :
	public NPC
{
public:
	NPC_Celebi();
	NPC_Celebi(const Vector3& pos);
	virtual ~NPC_Celebi();

public:
	virtual void Initialize() override;
	virtual void Update() override;

	// NPC을(를) 통해 상속됨
	virtual void OnEvent() override;


public:
	static NPC_Celebi* Create(const Vector3& pos);


	//TODO 따로 NPC상위객체 만들고 플레이어에서도 해당NPC의 진행상황을 알 수 있어야함.
};


