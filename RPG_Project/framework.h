// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#define SCREEN_START1 300
#define SCREEN_START2 250
#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 800
#define DELTA Timer::GET()->GetElapsedTime()

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define NOMINMAX
// Windows 헤더 파일
#include <windows.h>

using namespace std;
extern HWND hWnd;
extern POINT mousePos;
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>



#include "frameWork/Utilitys/SingleTon.h"
#include "frameWork/Utilitys/Input.h"
#include "frameWork/Utilitys/Timer.h"
#include "utill/float2.h"
#include "Object/Circle.h"
#include "Object/skill.h"
#include "Object/Player.h"
#include "Object/Monster.h"
#include "Object/Bullet.h"
#include "Object/gauge.h"
#include "Manager/BulletManger.h"
#include "Manager/MonsterManager.h"
#include "Scene/Scene.h"
#include "frameWork/GameManager.h"
#include "Scene/shootingScene.h"


