#pragma once

typedef unsigned long SessionID;

typedef struct Session
{
	SOCKET socket = INVALID_SOCKET;
	SOCKADDR_IN addrin = { 0, };
	DWORD sessionID = 0;

	RingBuffer sendQ;
	RingBuffer recvQ;

	DWORD trafficTick = 0; // 트래픽 체크용 틱
	DWORD trafficCount = 0; // 1초당 송신된 트래픽수
	DWORD trafficSecTick = 0; // 트래픽 카운트 1초확인용 틱
}Session;


enum class RecvResult : int
{
	Complete,
	NotReceivedAll,
	WrongMagicNumber,
	WrongEndCode,
	ErrorDequeue,
	ErrorPeek,

};

class Server
{
public:

	Server();
	virtual ~Server();

	bool Initialize();
	void Release();

	void Run();
	void NetworkProcess();
	void Select(SOCKET* sockArr, FD_SET* readSet, FD_SET* writeSet);

	void AcceptProcess();
	void RecvProcess(SOCKET socket);
	RecvResult PostRecvProcess(Session* pClient);
	bool SendProcess(SOCKET socket);

	void SendUnicast(Session* pSession, Packet* pPacket);
	void SendBroadcast(Session* pSession, Packet* pPacket);


	virtual void OnAccept(SessionID sessionID) = 0;
	virtual void OnRecv(SessionID sessionID, BYTE msgType, Packet* pPacket) = 0;
	virtual void OnSend() = 0;
	virtual void OnDisconnect(SessionID sessionID) = 0;

	//세션 관련 함수
	Session* CreateSession(SOCKET socket);
	Session* FindSession(SOCKET socket);
	SessionID AllocSessionKey();
	void DisconnectSession(SOCKET socket);


protected:
	SOCKET listenSocket = INVALID_SOCKET;
	map<SOCKET, Session*> sessionMap;
	SessionID uniqueKey = 0;
	bool isShutdown = false; // 서버 종료 플래그
};

