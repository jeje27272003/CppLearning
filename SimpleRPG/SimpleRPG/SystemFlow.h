#pragma once

#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "GlobalVariable.h"


// �Ҧ�SystemFlow.cpp�Ψ쪺�禡
void ClearScreen(); // �M���e��
void displayMenu(); // ��ܥD���
void HandleMenuOption(); // �B�z���ﶵ
void StartBattleMessage(); // �}�l�԰�
void BattleOptions(); // �԰��ﶵ
void victoryMessage(); // �ӧQ�T��
void defeatMessage(); // ���ѰT��