#include "stdafx.h"
#include "LobbyWindow.h"

LobbyWindow* pLobby;

static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return pLobby->WndProc(hWnd, Msg, wParam, lParam);
}

LobbyWindow::LobbyWindow()
{
	
}

LobbyWindow::~LobbyWindow()
{
}

bool LobbyWindow::Create(HINSTANCE hInstance, int nCmdShow)
{
	pLobby = this;
	WNDCLASS WndClass;
	WndClass.cbClsExtra = WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = ::WndProc;
	WndClass.lpszClassName = title;
	WndClass.lpszMenuName = NULL;
	WndClass.style = 0;
	RegisterClass(&WndClass);
	hLobbyWnd = CreateWindowEx(WS_EX_CLIENTEDGE, title, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 300, 200, NULL, NULL, hInstance, NULL);

	this->hEdit = CreateWindow((LPCWSTR)L"edit", (LPCWSTR)L"127.0.0.1", WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 10, 150, 25, hLobbyWnd, (HMENU)EDIT1, hInstance, NULL);
	this->hButton1 = CreateWindow((LPCWSTR)L"button", (LPCWSTR)L"����", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		170, 10, 50, 25, hLobbyWnd, (HMENU)BUTTON1, hInstance, NULL);
	this->hButton2 = CreateWindow((LPCWSTR)L"button", (LPCWSTR)L"���", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		230, 10, 50, 25, hLobbyWnd, (HMENU)BUTTON2, hInstance, NULL);
	
	if (hLobbyWnd == NULL) { return false; }
	ShowWindow(hLobbyWnd, nCmdShow);
	UpdateWindow(hLobbyWnd);
	SetFocus(hLobbyWnd);

	return false;
}

LobbyWindow * LobbyWindow::GetInstance()
{
	static LobbyWindow lw;
	return &lw;
}

bool LobbyWindow::Run(void)
{
	MSG Msg;
	while (true)
	{
		if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
		{
			if (Msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		else
		{

		}
	}
	return tryToConnect;
}

LRESULT LobbyWindow::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_COMMAND:
	{
		switch (HIWORD(wParam))
		{
		case BN_CLICKED:
		{
			switch (LOWORD(wParam))
			{
			case BUTTON1:
				tryToConnect = true;
				GetWindowTextW(hEdit, serverIPtext, 64);
				DestroyWindow(hLobbyWnd);
				break;
			case BUTTON2:
				tryToConnect = false;
				DestroyWindow(hLobbyWnd);
				break;
				
			default:
				break;
			}
		}
		break;

		default:
			break;
		}
	}
	break;

	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}
