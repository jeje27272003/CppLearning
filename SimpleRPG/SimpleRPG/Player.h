#pragma once
#include "Common.h"
#include "GlobalVariable.h"

//////////////////////////////////
/////////////���a���//////////////
//////////////////////////////////

namespace Player {

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

    struct PlayerData { //���a���c
        std::string name = "";
        Jobclass job = Warrior;
        PlayerParameters stats = { 0, 0, 0, 0, 0, 0 };
    };
	extern PlayerData player; // ���a�ܼ�


void NewGameName(void); // �s�C���W�ٿ�J
void ChooseClass(void);// ���¾�~
bool ConfirmNameClass(bool isConfirmed); // �T�{����W�ٻP¾�~
PlayerData createWarrior(); // ¾�~=�Ԥh
PlayerData createPaladin(); // ¾�~=�t�M�h
PlayerData createArcher(); // ¾�~=�}�b��
}