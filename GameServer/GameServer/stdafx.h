#pragma once

#pragma comment(lib,"ws2_32")
#pragma comment(lib,"winmm.lib")

#include <iostream>
#include <WinSock2.h>
#include <tchar.h>
#include <map>
#include <list>
using namespace std;


#include "Protocol.h"
#include "RingBuffer.h"
#include "Packet.h"
#include "PacketDefine.h"
#include "Sector.h"

#include "Server.h"
#include "GameServer.h"

