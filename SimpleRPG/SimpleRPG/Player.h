#pragma once
#include "Common.h"
#include "GlobalVariable.h"


//////////////////////////////////
/////////////玩家資料//////////////
//////////////////////////////////

enum Jobclass { // 玩家職業定義 
    Warrior,
    Paladin,
    Archer
};

struct PlayerParameters { // 角色數值
    int Maxhealth;
    int attackPower;
    int magicPower;
    int defensePower;
    int speed;
    int health;
};

struct Player { //玩家結構
    string name = "";
    Jobclass job = Warrior;
    PlayerParameters stats = { 0, 0, 0, 0, 0, 0 };
};

extern Player player; // 玩家變數
