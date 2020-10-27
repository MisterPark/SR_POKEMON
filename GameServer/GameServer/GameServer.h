#pragma once
#include "Server.h"



typedef struct Character
{
	Session* pSession = nullptr;
	SessionID sessionID = 0;

    // ��Ÿ �÷��̾����� �ʿ��� ������

}Character;

class GameServer :
    public Server
{
public:
    GameServer();
    virtual ~GameServer();

    virtual void OnAccept(SessionID sessionID) override;
    virtual void OnRecv(SessionID sessionID, BYTE msgType, Packet* pPacket) override;
    virtual void OnSend() override;
    virtual void OnDisconnect(SessionID sessionID) override;

   
    map<SessionID, Character*> characterMap;
};

