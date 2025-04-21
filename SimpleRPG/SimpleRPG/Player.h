#pragma once
#include "Common.h"
#include "GlobalVariable.h"


//////////////////////////////////
/////////////���a���//////////////
//////////////////////////////////

enum Jobclass { // ���a¾�~�w�q 
    Warrior,
    Paladin,
    Archer
};

struct PlayerParameters { // ����ƭ�
    int Maxhealth;
    int attackPower;
    int magicPower;
    int defensePower;
    int speed;
    int health;
};

struct Player { //���a���c
    string name = "";
    Jobclass job = Warrior;
    PlayerParameters stats = { 0, 0, 0, 0, 0, 0 };
};

void NewGameName(void); // �s�C���W�ٿ�J
void ChooseClass(void);// ���¾�~
bool ConfirmNameClass(bool isConfirmed); // �T�{����W�ٻP¾�~
Player createWarrior(); // ¾�~=�Ԥh
Player createPaladin(); // ¾�~=�t�M�h
Player createArcher(); // ¾�~=�}�b��