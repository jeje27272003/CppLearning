// GlobalVariable.h

#pragma once
#include "Common.h"
#include "Player.h"
#include "Enemy.h"

namespace GlobalVariable {
	// 全域變數
	extern int InputOption; // 使用者輸入選項
	extern std::string InputString; // 使用者輸入字串
	extern char InputChar; // 使用者輸入字元
	extern Player player; // 玩家變數
	extern Enemy enemy; // 敵人變數
}