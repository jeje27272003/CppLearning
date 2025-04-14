#pragma once
#include "Common.h"
#include "GlobalVariable.h"


//////////////////////////////////
/////////////敵人資料//////////////
//////////////////////////////////

enum EnemyType { // 敵人種類定義
    Goblin,
    Slime,
    Dragon
};

struct EnemyParameters { // 角色數值
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

extern Enemy enemy; // 敵人變數