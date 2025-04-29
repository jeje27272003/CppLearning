#include "BattleSystem.h"
using namespace GlobalVariable;
using namespace std;
using namespace Player;
using namespace Enemy;

///////////////////////////////////////////
//////////////�԰��y�{//////////////////////
///////////////////////////////////////////

void RandomDecideEnemy(std::mt19937& rng) { // �H���M�w�ĤH
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


FirstAttackResult isPlayerFirstAttack(std::mt19937& rng) { // �M�w����

    FirstAttackResult result;

    // �뵥�P��t�׭Ȫ�6����[�`�M�w���a�̲׳t�׭�
    auto playerFinalSpeed = rollDice(Player::player.stats.speed, 6, rng);
	auto enemyFinalSpeed = rollDice(Enemy::enemy.stats.speed, 6, rng);
	result.playerDices = playerFinalSpeed.rolls;
	result.enemyDices = enemyFinalSpeed.rolls;
	result.playerTotalSpeed = playerFinalSpeed.total();
	result.enemyTotalSpeed = enemyFinalSpeed.total();
	result.isPlayerFirst = (result.playerTotalSpeed >= result.enemyTotalSpeed); // ���a�t�פj�󵥩�ĤH�t�׫h���a����
	return result;
    }

void PlayerAttack() { // �԰��p�⤽��
    int damageToEnemy = 0;
    int damageGuardFromPlayer = 0;
    int* PlayerDamageRecord = new int[player.stats.attackPower];
    int* EnemyDefRecord = new int[enemy.stats.attackPower];

    for (int i = 0; i < player.stats.attackPower; i++) { //�ھڧ����O��N��6����
        damageToEnemy += rand() % 6 + 1;
        PlayerDamageRecord[i] = rand() % 6 + 1;
    }
    cout << "����" << player.name << "����!" << endl;
    cout << "�A�������`�@�O" << damageToEnemy << "!" << endl;
    cout << "�����Բ�:";
    for (int i = 0; i < player.stats.attackPower; i++) {
        cout << PlayerDamageRecord[i];
        if (i < player.stats.attackPower - 1) cout << ",";
    }
    cout << endl;

    for (int i = 0; i < enemy.stats.attackPower; i++) { //�ھڨ��m�O��N��4����
        damageGuardFromPlayer += rand() % 4 + 1;
        EnemyDefRecord[i] = rand() % 4 + 1;
    }
    cout << enemy.name << "���m�`�@�O" << damageGuardFromPlayer << "!" << endl;
    cout << "���m�Բ�:";
    for (int i = 0; i < enemy.stats.attackPower; i++) {
        cout << EnemyDefRecord[i];
        if (i < enemy.stats.attackPower - 1) cout << ",";
    }
    cout << endl;

    // �p���ڶˮ`
    int actualDamageToEnemy = damageToEnemy - damageGuardFromPlayer;
    if (actualDamageToEnemy <= 0)
    {
        actualDamageToEnemy = 0; // �T�O�ˮ`���|�p��0
    }
    cout << "��" << enemy.name << "�y��" << actualDamageToEnemy << "�ˮ`!" << endl;

    enemy.stats.health -= actualDamageToEnemy;
    if (enemy.stats.health < 0) enemy.stats.health = 0; // �T�O�ͩR�Ȥ��|�p��0
    cout << "�ĤH�Ѿl�ͩR��: " << enemy.stats.health << "!" << endl;

    // ����ʺA���t���O����
    delete[] PlayerDamageRecord;
    delete[] EnemyDefRecord;

}

void EnemyAttack() { // �ĤH����
    int damageToPlayer = 0;
    int damageGuardFromEnemy = 0;
    int* PlayerDamageRecord = new int[player.stats.attackPower];
    int* EnemyDefRecord = new int[enemy.stats.attackPower];

    for (int i = 0; i < enemy.stats.attackPower; i++) { //�ھڧ����O��N��6����
        damageToPlayer += rand() % 6 + 1;
        EnemyDefRecord[i] = rand() % 6 + 1;
    }
    cout << "�ĤH�������`�@�O" << damageToPlayer << "!" << endl;
    cout << "�����Բ�:";
    for (int i = 0; i < enemy.stats.attackPower; i++) {
        cout << EnemyDefRecord[i];
        if (i < enemy.stats.attackPower - 1) cout << ",";
    }
    cout << endl;

    for (int i = 0; i < player.stats.attackPower; i++) { //�ھڨ��m�O��N��4����
        damageGuardFromEnemy += rand() % 4 + 1;
        PlayerDamageRecord[i] = rand() % 4 + 1;
    }
    cout << "�A�����m�`�@�O" << damageGuardFromEnemy << "!" << endl;
    cout << "���m�Բ�:";
    for (int i = 0; i < player.stats.attackPower; i++) {
        cout << PlayerDamageRecord[i];
        if (i < player.stats.attackPower - 1) cout << ",";
    }
    cout << endl;


    // �p���ڶˮ`
    int actualDamageToPlayer = damageToPlayer - damageGuardFromEnemy;
    if (actualDamageToPlayer <= 0)
    {
        actualDamageToPlayer = 0; // �T�O�ˮ`���|�p��0
    }
    cout << "��" << player.name << "�y��" << actualDamageToPlayer << "�ˮ`!" << endl;


    player.stats.health -= actualDamageToPlayer;
    cout << "���a�Ѿl�ͩR��: " << player.stats.health << "!" << endl;
    if (player.stats.health < 0) player.stats.health = 0; // �T�O�ͩR�Ȥ��|�p��0

    // ����ʺA���t���O����
    delete[] PlayerDamageRecord;
    delete[] EnemyDefRecord;
}

void PlayerHeal() { // ���a��_
    int healAmount = 0;
    int* HealRecord = new int[player.stats.magicPower];
    for (int i = 0; i < player.stats.magicPower; i++) { //�ھ��]�k�O��N��6����
        healAmount += rand() % 6 + 1;
        HealRecord[i] = rand() % 6 + 1;
    }
    cout << "�A��_�F" << healAmount << "�ͩR��!" << endl;
    cout << "��_�Բ�:";
    for (int i = 0; i < player.stats.magicPower; i++) {
        cout << HealRecord[i];
        if (i < player.stats.magicPower - 1) cout << ",";
    }
    cout << endl;

    player.stats.health += healAmount;
    cout << "���a�Ѿl�ͩR��: " << player.stats.health << "!" << endl;

    if (player.stats.health > player.stats.Maxhealth) player.stats.health = player.stats.Maxhealth; // �T�O�ͩR�Ȥ��|�W�L�W��
}

void EnemyHpCheck() { // �ˬd�ĤH��q
    bool isEnemyDefeated = false;
    if (enemy.stats.health <= 0) {
        isEnemyDefeated = true;
        cout << "�A���ѤF" << enemy.name << "!" << endl;
    }
    else {
        cout << enemy.name << "�٬���!" << endl;
    }

}

void PlayerHpCheck() { // �ˬd���a��q
    bool isPlayerDefeated = false;
    if (player.stats.health <= 0) {
        isPlayerDefeated = true;
        cout << "�A�Q" << enemy.name << "���ѤF!" << endl;
    }
    else {
        cout << player.name << "�٬���!" << endl;
    }
}
