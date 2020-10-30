#pragma once
#include <Windows.h>
#include <iostream>

enum CHILD_ID
{
	EDIT1,
	BUTTON1,
	BUTTON2
};

class LobbyWindow
{
private:
	LobbyWindow();
	~LobbyWindow();
public:
	bool Create(HINSTANCE hInstance, int nCmdShow);
	static LobbyWindow* GetInstance();
	bool Run(void);
	LRESULT WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

private:
	bool tryToConnect = false;
	HWND hLobbyWnd;
	WCHAR title[64] = L"·Îºñ";

	HWND hEdit;
	HWND hButton1;
	HWND hButton2;

public:
	WCHAR serverIPtext[64];
};

