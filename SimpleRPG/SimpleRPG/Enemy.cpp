#include "Enemy.h"

Enemy createGoblin() { // �ĤH=�����L
    enemy.name = "�����L";
    enemy.type = Goblin;
    enemy.stats = { 150, 10, 5, 10, 150 }; //Hp, Atk, Def, Spd
    enemy.stats.health = enemy.stats.Maxhealth; // ��l�Ʀ�q
    return enemy;
}

Enemy createSlime() { // �ĤH=�v�ܩi
    enemy.name = "�v�ܩi";
    enemy.type = Slime;
    enemy.stats = { 200, 5, 8, 8, 200 }; //Hp, Atk, Def, Spd
    enemy.stats.health = enemy.stats.Maxhealth; // ��l�Ʀ�q
    return enemy;
}

Enemy createDragon() { // �ĤH=�s
    enemy.name = "�s";
    enemy.type = Dragon;
    enemy.stats = { 1000, 20, 20, 12, 1000 }; //Hp, Atk, Def, Spd
    enemy.stats.health = enemy.stats.Maxhealth; // ��l�Ʀ�q
    return enemy;
}
