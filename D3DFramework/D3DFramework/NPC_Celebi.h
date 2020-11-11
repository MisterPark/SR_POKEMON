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

	// NPC��(��) ���� ��ӵ�
	virtual void OnEvent() override;


public:
	static NPC_Celebi* Create(const Vector3& pos);


	//TODO ���� NPC������ü ����� �÷��̾���� �ش�NPC�� �����Ȳ�� �� �� �־����.
};


