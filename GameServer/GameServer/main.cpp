#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	timeBeginPeriod(1);
	setlocale(LC_ALL, "");

	GameServer server;
	
	if (!server.Initialize())
	{
		printf("네트워크 초기화 에러\n");
		return -1;
	}
	
	server.Run();

	server.Release();

	timeEndPeriod(1);
	return 0;
}