#pragma once

#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "GlobalVariable.h"
#include "Dice.h"


// �Ҧ�BattleSystem.cpp�Ψ쪺�禡
void RandomDecideEnemy(std::mt19937& rng); // �H���M�w�ĤH
struct FirstAttackResult {
    bool isPlayerFirst;
    int playerTotalSpeed;
    int enemyTotalSpeed;
    std::vector<int> playerDices;
    std::vector<int> enemyDices;
};
FirstAttackResult isPlayerFirstAttack(std::mt19937& rng);
void PlayerAttack(); // ���a����
void EnemyAttack(); // �ĤH����
void PlayerHeal(); // ���a��_
void EnemyHpCheck(); // �ˬd�ĤH��q
void PlayerHpCheck(); // �ˬd���a��q
