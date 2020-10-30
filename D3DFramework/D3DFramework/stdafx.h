#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//=======================================
//  STANDARD
//=======================================
#include <iostream>

#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#include <Windows.h>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <string>

//=======================================
//  FMOD
//=======================================

#include "FMOD/fmod.h"

//=======================================
//  DEBUG
//=======================================

#ifdef _DEBUG

#include <iostream>
using namespace std;

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
#endif

//=======================================
//  Network
//=======================================



#include "Protocol.h"
#include "CRingBuffer.h"
#include "CPacket.h"
#include "Network.h"

//=======================================
//  My Lib
//=======================================

#include "Debug.h"
#include "Define.h"
#include "Functions.h"

#include"MemoryPool.h"
#include "Point.h"
#include "Vector3.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "transform.h"
#include "Color.h"
#include "Texture.h"
#include "Random.h"

#include "Vertex.h"
#include "Mesh.h"
#include "Triangle.h"


#include "SoundManager.h"
#include "MainGame.h"
#include "ObjectManager.h"
#include "D2DRenderManager.h"
#include "FileManager.h"

#include "CollisionManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

#include "Cursor.h"
#include "Camera.h"
#include "Texture.h"
#include "Animation2D.h"

#include "Player.h"

using namespace std;
using namespace PKH;

extern HWND g_hwnd;
extern HINSTANCE g_hInstance;