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

void NewGameName(void); // 新遊戲名稱輸入
void ChooseClass(void);// 選擇職業
bool ConfirmNameClass(bool isConfirmed); // 確認角色名稱與職業
Player createWarrior(); // 職業=戰士
Player createPaladin(); // 職業=聖騎士
Player createArcher(); // 職業=弓箭手