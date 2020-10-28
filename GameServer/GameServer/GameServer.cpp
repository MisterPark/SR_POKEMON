#include "stdafx.h"
#include "GameServer.h"

GameServer::GameServer()
{
}

GameServer::~GameServer()
{
}

void GameServer::OnAccept(SessionID sessionID)
{
	// 캐릭터 생성
	// 캐릭터 맵에 삽입
	// 캐릭터 주변의 애들에게 생성 알리는 패킷 만듬
	// 당사자에겐 센드 유니캐스트 내캐릭터 생성
	// 주변애들에겐 센드 브로드캐스트 (나 뺴고)
}

void GameServer::OnRecv(SessionID sessionID, BYTE msgType, Packet* pPacket)
{
	// 스위치(메세지 타입)
	// 메이크 패킷

}

void GameServer::OnSend()
{
}

void GameServer::OnDisconnect(SessionID sessionID)
{
}

