#pragma once
#include "Common.h"
#include "GlobalVariable.h"

//////////////////////////////////
/////////////玩家資料//////////////
//////////////////////////////////

namespace Player {

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

    struct PlayerData { //玩家結構
        std::string name = "";
        Jobclass job = Warrior;
        PlayerParameters stats = { 0, 0, 0, 0, 0, 0 };
    };
	extern PlayerData player; // 玩家變數


void NewGameName(void); // 新遊戲名稱輸入
void ChooseClass(void);// 選擇職業
bool ConfirmNameClass(bool isConfirmed); // 確認角色名稱與職業
PlayerData createWarrior(); // 職業=戰士
PlayerData createPaladin(); // 職業=聖騎士
PlayerData createArcher(); // 職業=弓箭手
}