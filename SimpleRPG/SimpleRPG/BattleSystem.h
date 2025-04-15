#pragma once

#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "GlobalVariable.h"


// 所有BattleSystem.cpp用到的函式
void RandomDecideEnemy(); // 隨機決定敵人
bool isPlayerFirstAttack(); // 決定先攻
void PlayerAttack(); // 玩家攻擊
void EnemyAttack(); // 敵人攻擊
void PlayerHeal(); // 玩家恢復
void EnemyHpCheck(); // 檢查敵人血量
void PlayerHpCheck(); // 檢查玩家血量
