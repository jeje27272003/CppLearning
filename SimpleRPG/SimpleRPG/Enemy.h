#pragma once
#include "Common.h"
#include "GlobalVariable.h"


//////////////////////////////////
/////////////�ĤH���//////////////
//////////////////////////////////

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

struct Enemy {
    string name = "";
    EnemyType type = Goblin;
    EnemyParameters stats = { 0, 0, 0, 0, 0 };
};

//�ŧiEnemy.cpp�禡
Enemy createGoblin(); // �ĤH=�����L
Enemy createSlime(); // �ĤH=�v�ܩi
Enemy createDragon(); // �ĤH=�s
