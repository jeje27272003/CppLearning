#pragma once

#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "GlobalVariable.h"
#include "Dice.h"


// 所有BattleSystem.cpp用到的函式
void RandomDecideEnemy(std::mt19937& rng); // 隨機決定敵人
struct FirstAttackResult {
    bool isPlayerFirst;
    int playerTotalSpeed;
    int enemyTotalSpeed;
    std::vector<int> playerDices;
    std::vector<int> enemyDices;
};
FirstAttackResult isPlayerFirstAttack(std::mt19937& rng);
void PlayerAttack(); // 玩家攻擊
void EnemyAttack(); // 敵人攻擊
void PlayerHeal(); // 玩家恢復
void EnemyHpCheck(); // 檢查敵人血量
void PlayerHpCheck(); // 檢查玩家血量
