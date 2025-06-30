// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#define SCREEN_START1 300
#define SCREEN_START2 250
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800
#define DELTA Timer::GET()->GetElapsedTime()
#define PI 3.14
#define SCENE SceneManager::GET()

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define NOMINMAX
// Windows 헤더 파일
#include <windows.h>

using namespace std;


#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>


#include "frameWork/meth/vector2.h"
#include "frameWork/Utilitys/SingleTon.h"
#include "frameWork/Utilitys/Input.h"
#include "frameWork/Utilitys/Timer.h"
#include "utill/float2.h"
#include "Object/GameObject.h"
#include "Object/Circle.h"
#include "Object/skill.h"
#include "Object/Player.h"
#include "Object/Monster.h"
#include "Object/Bullet.h"
#include "Object/gauge.h"
#include "Object/Rect.h"
#include "UI/Butten.h"

#include "framework/Manager/BulletManger.h"
#include "framework/Manager/MonsterManager.h"
#include "Scene/Scene.h"
#include "frameWork/Manager/SceneManager.h"
#include "Scene/TitleScene.h"
#include "frameWork/Manager/GameManager.h"
#include "Scene/shootingScene.h"




extern HWND hWnd;
extern Vector2 mousePos;