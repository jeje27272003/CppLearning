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

extern Player player; // ���a�ܼ�
