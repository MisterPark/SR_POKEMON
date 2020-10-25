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
	//초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) { return false; }
	// 소켓
	listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET) { printf("리슨 소켓 초기화 에러\n"); return false; }
	// 바인드
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(SERVER_PORT);
	retval = bind(listenSocket, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) { printf("바인드 에러\n"); return false; }
	// 리슨
	retval = listen(listenSocket, SOMAXCONN);
	if (retval == SOCKET_ERROR) { printf("리슨 에러\n"); return false; }
	// 넌블럭
	u_long on = 1;
	retval = ioctlsocket(listenSocket, FIONBIO, &on);
	if (retval == SOCKET_ERROR) { printf("ioct 에러\n"); return false; }

	printf("Running...\n");
	return true;
}

void Server::Release()
{
	//TODO:  DB에 저장 등 마무리 할일 // 세션 모두 삭제 // 캐릭터 모두삭제 요청
	closesocket(listenSocket);
	WSACleanup();
}

void Server::Run()
{
	while (!isShutdown)
	{
		NetworkProcess();
		// 인풋
		// 게임로직
		// 모니터
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
			// 매번 accept로 접속처리 빠르게
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
				// 여기 수정
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
		wprintf(L"억셉트 에러\n");
		return;
	}

	Session* session = CreateSession(client_sock);
	if (session == nullptr)
	{
		wprintf(L"세션 생성 실패\n");
		closesocket(client_sock);
		return;
	}
	session->addrin = addrin;

	sessionMap.insert(pair<SOCKET, Session*>(client_sock, session));

	WSAAddressToString((SOCKADDR*)&addrin, sizeof(addrin), NULL, ipaddr, &len);

	wprintf(L"연결됨 - %s [소켓:%d]\n", ipaddr, (int)client_sock);

	OnAccept(session->sessionID);
}

void Server::RecvProcess(SOCKET socket)
{
	Session* pSession;
	int result;
	RecvResult recvResult;

	pSession = FindSession(socket);
	if (pSession == nullptr) { return; }

	//마지막으로 받은 메시지 타임
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
				// 패킷 한개 완성 루프 유도
				break;
			case RecvResult::NotReceivedAll:
				// 완성되지 않은 패킷
				return;
			case RecvResult::WrongMagicNumber:
				wprintf(L"/////////RecvProcess() 패킷 에러 [유저번호 : %d]\n", (int)socket);
				return;
			case RecvResult::WrongEndCode:
				wprintf(L"/////////RecvProcess() 패킷 에러 [유저번호 : %d]\n", (int)socket);
				return;
			case RecvResult::ErrorDequeue:
				wprintf(L"/////////RecvProcess() 패킷 에러 [유저번호 : %d]\n", (int)socket);
				return;
			case RecvResult::ErrorPeek:
				wprintf(L"/////////RecvProcess() 패킷 에러 [유저번호 : %d]\n", (int)socket);
				return;
			default:
				wprintf(L"///////RecvProcess() 정의되지 않은 결과값 에러 [유저번호 : %d]\n", (int)socket);
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

	// 헤더 이상 받았는가?
	if (recvQSize < sizeof(header)) { return RecvResult::NotReceivedAll; }
	// 헤더 뽑아보고
	ret = pSession->recvQ.Peek((char*)&header, sizeof(header));
	if (ret != sizeof(header)) { return RecvResult::ErrorPeek; }
	// 매직넘버 확인
	if (header.byCode != dfNETWORK_PACKET_CODE)
	{
		printf("매직넘버 틀림\n"); return RecvResult::WrongMagicNumber;
	}
	// 전체 패킷이 모두 받아졌는가
	if ((u_int)pSession->recvQ.GetUseSize() < sizeof(header) + header.bySize + 1) { return RecvResult::NotReceivedAll; }
	// 그렇다면 헤더는 이미뽑았으니 제외
	pSession->recvQ.MoveFront(sizeof(header));
	// 직렬화에 페이로드 디큐
	ret = pSession->recvQ.Dequeue(pack.GetWritePtr(), header.bySize);
	if (ret != header.bySize) { printf("recv 디큐 에러\n"); return RecvResult::ErrorDequeue; }
	// 엔드코드 디큐
	ret = pSession->recvQ.Dequeue((char*)&endcode, sizeof(endcode));
	if (ret != sizeof(endcode)) { wprintf(L"recv 디큐 에러\n"); return RecvResult::ErrorDequeue; }
	// 엔드코드 체크
	if (endcode != dfNETWORK_PACKET_END) { return RecvResult::WrongEndCode; }

	// 직렬화 롸이트포스 이동
	pack.MoveWritePos(header.bySize);

	OnRecv(pSession->sessionID, header.byType, &pack);

	return RecvResult::Complete; // 패킷 1개 처리 완료, 루프 유도
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
			wprintf(L"Socket WouldBlock - 소켓 : %d\n", (int)socket);
			return false;
		}
		wprintf(L"Socket Error - [소켓 : %d] [에러코드 : %d]\n", (int)socket, err);
		closesocket(pSession->socket);
		DisconnectSession(socket);
		return false;
	}
	else
	{
		// 송신작업 완료
		// 패킷 전송이 아니라, 센드버퍼에 복사완료 ps. 우리 버퍼가 아니라 TCP 센드버퍼
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
		wprintf(L"세션 생성 중 - 메모리 부족 new 실패\n");
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
		// TODO : 디버그 에러
		closesocket(socket);
		return;
	}

	OnDisconnect(target->sessionID);

	WSAAddressToString((SOCKADDR*)&target->addrin, sizeof(SOCKADDR_IN), NULL, ipaddr, &len);
	wprintf(L"연결종료 - %s [세션ID:%d]\n", ipaddr, target->sessionID);

	delete target;
	target = nullptr;
	sessionMap.erase(socket);

	closesocket(socket);
}


