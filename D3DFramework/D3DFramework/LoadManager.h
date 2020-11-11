#pragma once
#include <process.h>

class LoadManager
{
private:
	LoadManager();
	~LoadManager();

public:
	static LoadManager* GetInstance();
	static void Destroy();

	static void Initialize();
	static void Release();

public:
	static unsigned int __stdcall LodingThread(void* arg);

	static bool IsFinish();
	static float GetProgress();
	static wstring GetText();

private:
	HANDLE hThread = INVALID_HANDLE_VALUE;
	bool isFinish = false;
	float percent = 0.f;
	wstring text;

};

