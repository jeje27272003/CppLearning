#include "BattleSystem.h"
using namespace GlobalVariable;

///////////////////////////////////////////
//////////////�԰��y�{//////////////////////
///////////////////////////////////////////

void RandomDecideEnemy() { // �H���M�w�ĤH
    srand(static_cast<unsigned int>(time(0))); // �]�w�H���ؤl
    int enemyType = rand() % 3; // �H����ܼĤH����
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


bool isPlayerFirstAttack() { // �M�w����
    // ����p�⤽��
    int playerSpeed = 0;
    int enemySpeed = 0;
    int* PlayerSpeedRecord = new int[player.stats.speed]; // �ʺA���t�}�C�H�s�x��l���G
    int* EnemySpeedRecord = new int[enemy.stats.speed]; // �ʺA���t�}�C�H�s�x��l���G
    bool isPlayerFirst = false;

    // �뵥�P��t�׭Ȫ�6����[�`�M�w���a�̲׳t�׭�
    for (int i = 0; i < player.stats.speed; i++) {
        PlayerSpeedRecord[i] = rand() % 6 + 1;
    }
    int finalPlayerSpeed = 0;
    for (int i = 0; i < player.stats.speed; i++) {
        finalPlayerSpeed += PlayerSpeedRecord[i];
    }
    cout << "���a�t�׬�: " << finalPlayerSpeed << endl;
    cout << "�Բ�:";
    for (int i = 0; i < player.stats.speed; i++) {
        cout << PlayerSpeedRecord[i];
        if (i < player.stats.speed - 1) cout << ",";
    }
    cout << endl;

    // �뵥�P��t�׭Ȫ�6����[�`�M�w�ĤH�̲׳t�׭�
    for (int i = 0; i < enemy.stats.speed; i++) {
        EnemySpeedRecord[i] = rand() % 6 + 1;
    }
    int finalEnemySpeed = 0;
    for (int i = 0; i < enemy.stats.speed; i++) {
        finalEnemySpeed += EnemySpeedRecord[i];
    }
    cout << "�ĤH�t�׬�: " << finalEnemySpeed << endl;
    cout << "�Բ�:";
    for (int i = 0; i < enemy.stats.speed; i++) {
        cout << EnemySpeedRecord[i];
        if (i < enemy.stats.speed - 1) cout << ",";
    }
    isPlayerFirst = (finalPlayerSpeed >= finalEnemySpeed);
    cout << (isPlayerFirst ? "���a����!" : "�ĤH����!") << endl;
    // ����ʺA���t���O����
    delete[] PlayerSpeedRecord;
    delete[] EnemySpeedRecord;
    return isPlayerFirst;
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
