#include "Enemy.h"

Enemy createGoblin() { // 敵人=哥布林
    enemy.name = "哥布林";
    enemy.type = Goblin;
    enemy.stats = { 150, 10, 5, 10, 150 }; //Hp, Atk, Def, Spd
    enemy.stats.health = enemy.stats.Maxhealth; // 初始化血量
    return enemy;
}

Enemy createSlime() { // 敵人=史萊姆
    enemy.name = "史萊姆";
    enemy.type = Slime;
    enemy.stats = { 200, 5, 8, 8, 200 }; //Hp, Atk, Def, Spd
    enemy.stats.health = enemy.stats.Maxhealth; // 初始化血量
    return enemy;
}

Enemy createDragon() { // 敵人=龍
    enemy.name = "龍";
    enemy.type = Dragon;
    enemy.stats = { 1000, 20, 20, 12, 1000 }; //Hp, Atk, Def, Spd
    enemy.stats.health = enemy.stats.Maxhealth; // 初始化血量
    return enemy;
}
