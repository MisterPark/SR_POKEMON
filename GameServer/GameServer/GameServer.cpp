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
	// ĳ���� ����
	// ĳ���� �ʿ� ����
	// ĳ���� �ֺ��� �ֵ鿡�� ���� �˸��� ��Ŷ ����
	// ����ڿ��� ���� ����ĳ��Ʈ ��ĳ���� ����
	// �ֺ��ֵ鿡�� ���� ��ε�ĳ��Ʈ (�� ����)
}

void GameServer::OnRecv(SessionID sessionID, BYTE msgType, Packet* pPacket)
{
	// ����ġ(�޼��� Ÿ��)
	// ����ũ ��Ŷ

}

void GameServer::OnSend()
{
}

void GameServer::OnDisconnect(SessionID sessionID)
{
}

