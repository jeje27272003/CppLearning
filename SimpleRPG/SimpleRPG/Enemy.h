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

//宣告Enemy.cpp函式
Enemy createGoblin(); // 敵人=哥布林
Enemy createSlime(); // 敵人=史萊姆
Enemy createDragon(); // 敵人=龍
