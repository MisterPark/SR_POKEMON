#pragma once

//=======================================
//  STANDARD
//=======================================
#include <iostream>

#include <Windows.h>
#include <map>
#include <vector>
#include <set>
#include <list>

//=======================================
//  FMOD
//=======================================

#include "FMOD/fmod.h"

//=======================================
//  My Lib
//=======================================

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

using namespace std;
using namespace PKH;

extern HWND g_hwnd;