#pragma once
#include "Common.h"
#include "GlobalVariable.h"
using namespace std;

//////////////////////////////////
/////////////敵人資料//////////////
//////////////////////////////////

namespace Enemy
{

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

struct EnemyData {
    string name = "";
    EnemyType type = Goblin;
    EnemyParameters stats = { 0, 0, 0, 0, 0 };
};
extern EnemyData enemy; // 敵人變數

//宣告Enemy.cpp函式
EnemyData createGoblin(); // 敵人=哥布林
EnemyData createSlime(); // 敵人=史萊姆
EnemyData createDragon(); // 敵人=龍

}// namespace Enemy結束