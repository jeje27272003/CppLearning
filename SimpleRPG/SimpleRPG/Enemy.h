#pragma once
#include "Common.h"
#include "GlobalVariable.h"

//////////////////////////////////
/////////////�ĤH���//////////////
//////////////////////////////////

namespace Enemy
{

enum EnemyType { // �ĤH�����w�q
    Goblin,
    Slime,
    Dragon
};

struct EnemyParameters { // ����ƭ�
    int Maxhealth;
    int attackPower;
    int defensePower;
    int speed;
    int health;
};

struct EnemyData {
    std::string name = "";
    EnemyType type = Goblin;
    EnemyParameters stats = { 0, 0, 0, 0, 0 };
};
extern EnemyData enemy; // �ĤH�ܼ�

//�ŧiEnemy.cpp�禡
EnemyData createGoblin(); // �ĤH=�����L
EnemyData createSlime(); // �ĤH=�v�ܩi
EnemyData createDragon(); // �ĤH=�s

}// namespace Enemy����