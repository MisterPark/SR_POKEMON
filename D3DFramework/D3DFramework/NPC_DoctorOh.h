#pragma once
#include "NPC.h"
class NPC_DoctorOh :
    public NPC
{
public:
    NPC_DoctorOh();
    virtual ~NPC_DoctorOh();



    // NPC��(��) ���� ��ӵ�
    virtual void OnEvent() override;

    static void HelloWorld();
    static void Event2();

public:
    bool helloFlag = false;

};

