#include "stdafx.h"
#include "Server.h"

Server::Server()
{
}

Server::~Server()
{
}

bool Server::Initialize()
{
	printf("Initializing...\n");
	int retval;
	//�ʱ�ȭ
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { return false; }
	// ����
	listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET) { printf("���� ���� �ʱ�ȭ ����\n"); return false; }
	// ���ε�
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVER_PORT);
	retval = bind(listenSocket, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) { printf("���ε� ����\n"); return false; }
	// ����
	retval = listen(listenSocket, SOMAXCONN);
	if (retval == SOCKET_ERROR) { printf("���� ����\n"); return false; }
	// �ͺ�
	u_long on = 1;
	retval = ioctlsocket(listenSocket, FIONBIO, &on);
	if (retval == SOCKET_ERROR) { printf("ioct ����\n"); return false; }

	printf("Running...\n");
	return true;
}

void Server::Release()
{
	//TODO:  DB�� ���� �� ������ ���� // ���� ��� ���� // ĳ���� ��λ��� ��û
	closesocket(listenSocket);
	WSACleanup();
}

void Server::Run()
{
	while (!isShutdown)
	{
		NetworkProcess();
		// ��ǲ
		// ���ӷ���
		// �����
	}

}

void Server::NetworkProcess()
{
	Session* pSession;
	SOCKET tableSocket[FD_SETSIZE];
	int sockCnt = 0;

	FD_SET rset;
	FD_SET wset;
	FD_ZERO(&rset);
	FD_ZERO(&wset);
	memset(tableSocket, INVALID_SOCKET, sizeof(SOCKET) * FD_SETSIZE);

	FD_SET(listenSocket, &rset);

	tableSocket[sockCnt] = listenSocket;
	sockCnt++;

	map<SOCKET, Session*>::iterator iter;
	for (iter = sessionMap.begin(); iter != sessionMap.end();)
	{
		pSession = iter->second;
		iter++;

		tableSocket[sockCnt] = pSession->socket;

		FD_SET(pSession->socket, &rset);

		if (pSession->sendQ.GetUseSize() > 0) { FD_SET(pSession->socket, &wset); }

		sockCnt++;

		if (FD_SETSIZE <= sockCnt)
		{
			Select(tableSocket, &rset, &wset);

			FD_ZERO(&rset);
			FD_ZERO(&wset);

			memset(tableSocket, INVALID_SOCKET, sizeof(SOCKET) * FD_SETSIZE);
			// �Ź� accept�� ����ó�� ������
			FD_SET(listenSocket, &rset);
			tableSocket[0] = listenSocket;
			sockCnt = 1;
		}
	}

	if (sockCnt > 0)
	{
		Select(tableSocket, &rset, &wset);
	}
}

void Server::Select(SOCKET* sockArr, FD_SET* readSet, FD_SET* writeSet)
{
	timeval time;
	int result, iter;
	bool bProcFlag;

	time.tv_sec = 0;
	time.tv_usec = 0;

	result = select(0, readSet, writeSet, 0, &time);

	if (result > 0)
	{
		for (iter = 0; iter < FD_SETSIZE && result > 0; iter++)
		{
			bProcFlag = true;
			if (sockArr[iter] == INVALID_SOCKET) { continue; }

			if (FD_ISSET(sockArr[iter], writeSet))
			{
				// ���� ����
				--result;
				bProcFlag = SendProcess(sockArr[iter]);
			}
			if (FD_ISSET(sockArr[iter], readSet))
			{
				--result;
				if (bProcFlag)
				{
					if (sockArr[iter] == listenSocket)
					{
						AcceptProcess();
					}
					else
					{
						RecvProcess(sockArr[iter]);
					}
				}
			}
		}
	}
	else if (result == SOCKET_ERROR)
	{
		printf("select error\n");
	}
}

void Server::AcceptProcess()
{
	SOCKADDR_IN addrin;
	int addrlen = sizeof(addrin);
	SOCKET client_sock;
	WCHAR ipaddr[16];
	DWORD len = 16;

	client_sock = accept(listenSocket, (SOCKADDR*)&addrin, &addrlen);
	if (client_sock == INVALID_SOCKET)
	{
		wprintf(L"���Ʈ ����\n");
		return;
	}

	Session* session = CreateSession(client_sock);
	if (session == nullptr)
	{
		wprintf(L"���� ���� ����\n");
		closesocket(client_sock);
		return;
	}
	session->addrin = addrin;

	sessionMap.insert(pair<SOCKET, Session*>(client_sock, session));

	WSAAddressToString((SOCKADDR*)&addrin, sizeof(addrin), NULL, ipaddr, &len);

	wprintf(L"����� - %s [����:%d]\n", ipaddr, (int)client_sock);

	OnAccept(session->sessionID);
}

void Server::RecvProcess(SOCKET socket)
{
	Session* pSession;
	int result;
	RecvResult recvResult;

	pSession = FindSession(socket);
	if (pSession == nullptr) { return; }

	//���������� ���� �޽��� Ÿ��
	pSession->trafficTick = timeGetTime();

	result = recv(pSession->socket, pSession->recvQ.GetRearBufferPtr(), pSession->recvQ.GetEnqSize(), 0);
	if (result == SOCKET_ERROR || result == 0)
	{
		closesocket(pSession->socket);
		DisconnectSession(socket);
		return;
	}
	else if (result > 0)
	{
		pSession->recvQ.MoveRear(result);
		for (;;)
		{
			recvResult = PostRecvProcess(pSession);
			switch (recvResult)
			{
			case RecvResult::Complete:
				// ��Ŷ �Ѱ� �ϼ� ���� ����
				break;
			case RecvResult::NotReceivedAll:
				// �ϼ����� ���� ��Ŷ
				return;
			case RecvResult::WrongMagicNumber:
				wprintf(L"/////////RecvProcess() ��Ŷ ���� [������ȣ : %d]\n", (int)socket);
				return;
			case RecvResult::WrongEndCode:
				wprintf(L"/////////RecvProcess() ��Ŷ ���� [������ȣ : %d]\n", (int)socket);
				return;
			case RecvResult::ErrorDequeue:
				wprintf(L"/////////RecvProcess() ��Ŷ ���� [������ȣ : %d]\n", (int)socket);
				return;
			case RecvResult::ErrorPeek:
				wprintf(L"/////////RecvProcess() ��Ŷ ���� [������ȣ : %d]\n", (int)socket);
				return;
			default:
				wprintf(L"///////RecvProcess() ���ǵ��� ���� ����� ���� [������ȣ : %d]\n", (int)socket);
				break;
			}
		}

		
	}

}

RecvResult Server::PostRecvProcess(Session* pSession)
{
	PACKET_HEADER header;
	ENDCODE endcode;
	Packet pack;
	int recvQSize = pSession->recvQ.GetUseSize();
	int ret;

	// ��� �̻� �޾Ҵ°�?
	if (recvQSize < sizeof(header)) { return RecvResult::NotReceivedAll; }
	// ��� �̾ƺ���
	ret = pSession->recvQ.Peek((char*)&header, sizeof(header));
	if (ret != sizeof(header)) { return RecvResult::ErrorPeek; }
	// �����ѹ� Ȯ��
	if (header.byCode != dfNETWORK_PACKET_CODE)
	{
		printf("�����ѹ� Ʋ��\n"); return RecvResult::WrongMagicNumber;
	}
	// ��ü ��Ŷ�� ��� �޾����°�
	if ((u_int)pSession->recvQ.GetUseSize() < sizeof(header) + header.bySize + 1) { return RecvResult::NotReceivedAll; }
	// �׷��ٸ� ����� �̹̻̾����� ����
	pSession->recvQ.MoveFront(sizeof(header));
	// ����ȭ�� ���̷ε� ��ť
	ret = pSession->recvQ.Dequeue(pack.GetWritePtr(), header.bySize);
	if (ret != header.bySize) { printf("recv ��ť ����\n"); return RecvResult::ErrorDequeue; }
	// �����ڵ� ��ť
	ret = pSession->recvQ.Dequeue((char*)&endcode, sizeof(endcode));
	if (ret != sizeof(endcode)) { wprintf(L"recv ��ť ����\n"); return RecvResult::ErrorDequeue; }
	// �����ڵ� üũ
	if (endcode != dfNETWORK_PACKET_END) { return RecvResult::WrongEndCode; }

	// ����ȭ ����Ʈ���� �̵�
	pack.MoveWritePos(header.bySize);

	OnRecv(pSession->sessionID, header.byType, &pack);

	return RecvResult::Complete; // ��Ŷ 1�� ó�� �Ϸ�, ���� ����
}

bool Server::SendProcess(SOCKET socket)
{
	Session* pSession;
	int result;
	int sendSize;

	pSession = FindSession(socket);
	if (NULL == pSession) { return false; }

	sendSize = pSession->sendQ.GetDeqSize();

	if (sendSize <= 0) { return true; }

	result = send(pSession->socket, pSession->sendQ.GetFrontBufferPtr(), sendSize, 0);
	if (result == SOCKET_ERROR)
	{
		DWORD err = WSAGetLastError();
		if (WSAEWOULDBLOCK == err)
		{
			wprintf(L"Socket WouldBlock - ���� : %d\n", (int)socket);
			return false;
		}
		wprintf(L"Socket Error - [���� : %d] [�����ڵ� : %d]\n", (int)socket, err);
		closesocket(pSession->socket);
		DisconnectSession(socket);
		return false;
	}
	else
	{
		// �۽��۾� �Ϸ�
		// ��Ŷ ������ �ƴ϶�, ������ۿ� ����Ϸ� ps. �츮 ���۰� �ƴ϶� TCP �������
		pSession->sendQ.MoveFront(result);
		OnSend();
	}
	return true;
}

void Server::SendUnicast(Session* pSession, Packet* pPacket)
{
	if (pSession == NULL)
	{
		printf("SendUnicast Client is NULL\n");
		return;
	}
	pSession->sendQ.Enqueue((char*)pPacket->GetReadPtr(), pPacket->GetPacketSize());
}

void Server::SendBroadcast(Session* pSession, Packet* pPacket)
{
	Session* other;
	map<SOCKET, Session*>::iterator iter;
	for (iter = sessionMap.begin(); iter != sessionMap.end(); ++iter)
	{
		other = iter->second;
		if (other == pSession) { continue; }
		SendUnicast(other, pPacket);
	}
}

Session* Server::CreateSession(SOCKET socket)
{
	Session* session = new Session;
	if (session == NULL)
	{
		wprintf(L"���� ���� �� - �޸� ���� new ����\n");
		return nullptr;
	}

	session->socket = socket;
	session->sessionID = AllocSessionKey();
	session->trafficTick = timeGetTime();

	return session;
}

Session* Server::FindSession(SOCKET socket)
{
	Session* result;
	SOCKET key = socket;
	map<SOCKET, Session*>::iterator iter;
	iter = sessionMap.find(key);
	if (iter == sessionMap.end())
	{
		return nullptr;
	}
	else
	{
		result = iter->second;
		return result;
	}
}

DWORD Server::AllocSessionKey()
{
	return uniqueKey++;
}

void Server::DisconnectSession(SOCKET socket)
{
	WCHAR ipaddr[16];
	DWORD len = 16;

	Session* target = FindSession(socket);
	if (target == nullptr)
	{
		// TODO : ����� ����
		closesocket(socket);
		return;
	}

	OnDisconnect(target->sessionID);

	WSAAddressToString((SOCKADDR*)&target->addrin, sizeof(SOCKADDR_IN), NULL, ipaddr, &len);
	wprintf(L"�������� - %s [����ID:%d]\n", ipaddr, target->sessionID);

	delete target;
	target = nullptr;
	sessionMap.erase(socket);

	closesocket(socket);
}


