#pragma once

#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "GlobalVariable.h"


// �Ҧ�BattleSystem.cpp�Ψ쪺�禡
void RandomDecideEnemy(); // �H���M�w�ĤH
bool isPlayerFirstAttack(); // �M�w����
void PlayerAttack(); // ���a����
void EnemyAttack(); // �ĤH����
void PlayerHeal(); // ���a��_
void EnemyHpCheck(); // �ˬd�ĤH��q
void PlayerHpCheck(); // �ˬd���a��q
