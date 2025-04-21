#pragma once

#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "GlobalVariable.h"


// 所有SystemFlow.cpp用到的函式
void ClearScreen(); // 清除畫面
void displayMenu(); // 顯示主選單
void HandleMenuOption(); // 處理選單選項
void StartBattleMessage(); // 開始戰鬥
void BattleOptions(); // 戰鬥選項
void victoryMessage(); // 勝利訊息
void defeatMessage(); // 失敗訊息