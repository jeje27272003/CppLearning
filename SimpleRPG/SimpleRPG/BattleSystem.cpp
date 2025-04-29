#include "BattleSystem.h"
using namespace GlobalVariable;
using namespace std;
using namespace Player;
using namespace Enemy;

///////////////////////////////////////////
//////////////戰鬥流程//////////////////////
///////////////////////////////////////////

void RandomDecideEnemy(std::mt19937& rng) { // 隨機決定敵人
	int enemyType = rollDice(1, 3, rng).rolls[0];

    switch (enemyType) {
    case 0:
        enemy = createGoblin();
        break;
    case 1:
        enemy = createSlime();
        break;
    case 2:
        enemy = createDragon();
        break;
    }
}


FirstAttackResult isPlayerFirstAttack(std::mt19937& rng) { // 決定先攻

    FirstAttackResult result;

    // 骰等同於速度值的6面骰加總決定玩家最終速度值
    auto playerFinalSpeed = rollDice(Player::player.stats.speed, 6, rng);
	auto enemyFinalSpeed = rollDice(Enemy::enemy.stats.speed, 6, rng);
	result.playerDices = playerFinalSpeed.rolls;
	result.enemyDices = enemyFinalSpeed.rolls;
	result.playerTotalSpeed = playerFinalSpeed.total();
	result.enemyTotalSpeed = enemyFinalSpeed.total();
	result.isPlayerFirst = (result.playerTotalSpeed >= result.enemyTotalSpeed); // 玩家速度大於等於敵人速度則玩家先攻
	return result;
    }

void PlayerAttack() { // 戰鬥計算公式
    int damageToEnemy = 0;
    int damageGuardFromPlayer = 0;
    int* PlayerDamageRecord = new int[player.stats.attackPower];
    int* EnemyDefRecord = new int[enemy.stats.attackPower];

    for (int i = 0; i < player.stats.attackPower; i++) { //根據攻擊力骰N個6面骰
        damageToEnemy += rand() % 6 + 1;
        PlayerDamageRecord[i] = rand() % 6 + 1;
    }
    cout << "輪到" << player.name << "攻擊!" << endl;
    cout << "你的攻擊總共是" << damageToEnemy << "!" << endl;
    cout << "攻擊詳細:";
    for (int i = 0; i < player.stats.attackPower; i++) {
        cout << PlayerDamageRecord[i];
        if (i < player.stats.attackPower - 1) cout << ",";
    }
    cout << endl;

    for (int i = 0; i < enemy.stats.attackPower; i++) { //根據防禦力骰N個4面骰
        damageGuardFromPlayer += rand() % 4 + 1;
        EnemyDefRecord[i] = rand() % 4 + 1;
    }
    cout << enemy.name << "防禦總共是" << damageGuardFromPlayer << "!" << endl;
    cout << "防禦詳細:";
    for (int i = 0; i < enemy.stats.attackPower; i++) {
        cout << EnemyDefRecord[i];
        if (i < enemy.stats.attackPower - 1) cout << ",";
    }
    cout << endl;

    // 計算實際傷害
    int actualDamageToEnemy = damageToEnemy - damageGuardFromPlayer;
    if (actualDamageToEnemy <= 0)
    {
        actualDamageToEnemy = 0; // 確保傷害不會小於0
    }
    cout << "對" << enemy.name << "造成" << actualDamageToEnemy << "傷害!" << endl;

    enemy.stats.health -= actualDamageToEnemy;
    if (enemy.stats.health < 0) enemy.stats.health = 0; // 確保生命值不會小於0
    cout << "敵人剩餘生命值: " << enemy.stats.health << "!" << endl;

    // 釋放動態分配的記憶體
    delete[] PlayerDamageRecord;
    delete[] EnemyDefRecord;

}

void EnemyAttack() { // 敵人攻擊
    int damageToPlayer = 0;
    int damageGuardFromEnemy = 0;
    int* PlayerDamageRecord = new int[player.stats.attackPower];
    int* EnemyDefRecord = new int[enemy.stats.attackPower];

    for (int i = 0; i < enemy.stats.attackPower; i++) { //根據攻擊力骰N個6面骰
        damageToPlayer += rand() % 6 + 1;
        EnemyDefRecord[i] = rand() % 6 + 1;
    }
    cout << "敵人的攻擊總共是" << damageToPlayer << "!" << endl;
    cout << "攻擊詳細:";
    for (int i = 0; i < enemy.stats.attackPower; i++) {
        cout << EnemyDefRecord[i];
        if (i < enemy.stats.attackPower - 1) cout << ",";
    }
    cout << endl;

    for (int i = 0; i < player.stats.attackPower; i++) { //根據防禦力骰N個4面骰
        damageGuardFromEnemy += rand() % 4 + 1;
        PlayerDamageRecord[i] = rand() % 4 + 1;
    }
    cout << "你的防禦總共是" << damageGuardFromEnemy << "!" << endl;
    cout << "防禦詳細:";
    for (int i = 0; i < player.stats.attackPower; i++) {
        cout << PlayerDamageRecord[i];
        if (i < player.stats.attackPower - 1) cout << ",";
    }
    cout << endl;


    // 計算實際傷害
    int actualDamageToPlayer = damageToPlayer - damageGuardFromEnemy;
    if (actualDamageToPlayer <= 0)
    {
        actualDamageToPlayer = 0; // 確保傷害不會小於0
    }
    cout << "對" << player.name << "造成" << actualDamageToPlayer << "傷害!" << endl;


    player.stats.health -= actualDamageToPlayer;
    cout << "玩家剩餘生命值: " << player.stats.health << "!" << endl;
    if (player.stats.health < 0) player.stats.health = 0; // 確保生命值不會小於0

    // 釋放動態分配的記憶體
    delete[] PlayerDamageRecord;
    delete[] EnemyDefRecord;
}

void PlayerHeal() { // 玩家恢復
    int healAmount = 0;
    int* HealRecord = new int[player.stats.magicPower];
    for (int i = 0; i < player.stats.magicPower; i++) { //根據魔法力骰N個6面骰
        healAmount += rand() % 6 + 1;
        HealRecord[i] = rand() % 6 + 1;
    }
    cout << "你恢復了" << healAmount << "生命值!" << endl;
    cout << "恢復詳細:";
    for (int i = 0; i < player.stats.magicPower; i++) {
        cout << HealRecord[i];
        if (i < player.stats.magicPower - 1) cout << ",";
    }
    cout << endl;

    player.stats.health += healAmount;
    cout << "玩家剩餘生命值: " << player.stats.health << "!" << endl;

    if (player.stats.health > player.stats.Maxhealth) player.stats.health = player.stats.Maxhealth; // 確保生命值不會超過上限
}

void EnemyHpCheck() { // 檢查敵人血量
    bool isEnemyDefeated = false;
    if (enemy.stats.health <= 0) {
        isEnemyDefeated = true;
        cout << "你擊敗了" << enemy.name << "!" << endl;
    }
    else {
        cout << enemy.name << "還活著!" << endl;
    }

}

void PlayerHpCheck() { // 檢查玩家血量
    bool isPlayerDefeated = false;
    if (player.stats.health <= 0) {
        isPlayerDefeated = true;
        cout << "你被" << enemy.name << "擊敗了!" << endl;
    }
    else {
        cout << player.name << "還活著!" << endl;
    }
}
