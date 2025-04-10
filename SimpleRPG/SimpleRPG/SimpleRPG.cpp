#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

int InputOption;
string InputString;
char InputChar;

// 清除畫面功能

void ClearScreen() {
#ifdef _WIN32
    system("cls");

#else
    system("clear");
#endif
}

//////////////////////////////////
/////////////玩家資料//////////////
//////////////////////////////////
enum Jobclass { // 玩家職業定義 
    Warrior,
    Paladin,
    Archer
};


struct Parameters { // 角色數值
    int Maxhealth;
    int attackPower;
    int magicPower;
    int defensePower;
    int speed;
    int health;
};

struct Player { //玩家結構
    string name;
    Jobclass job;
    Parameters stats;
};

Player createWarrior() { // 職業=戰士
    Player P;
    P.name = "戰士";
    P.job = Warrior;
    P.stats = { 600, 25, 10, 15, 10 }; //Hp, Atk, Mag, Def, Spd
    P.stats.health = P.stats.Maxhealth; // 初始化血量
    return P;
}

Player createPaladin() { // 職業=聖騎士
    Player P;
    P.name = "聖騎士";
    P.job = Paladin;
    P.stats = { 750, 15, 20, 20, 10 }; //MaxHp, Atk, Mag, Def, Spd
    P.stats.health = P.stats.Maxhealth; // 初始化血量
    return P;
}

Player createArcher() { // 職業=弓箭手
    Player P;
    P.name = "弓箭手";
    P.job = Archer;
    P.stats = { 500, 30, 15, 5, 15 }; //MaxHp, Atk, Mag, Def, Spd
    P.stats.health = P.stats.Maxhealth; // 初始化血量
    return P;
}


//////////////////////////////////
/////////////敵人資料//////////////
//////////////////////////////////

struct Enemy {
    string name;
    EnemyType type;
    Parameters stats;
};

enum EnemyType { // 敵人種類定義
    Goblin,
    Slime,
    Dragon
};

Enemy createGoblin() { // 敵人=哥布林
    Enemy E;
    E.name = "哥布林";
    E.type = Goblin;
    E.stats = { 150, 10, 5, 10 }; //Hp, Atk, Def, Spd
    return E;
}

Enemy createSlime() { // 敵人=史萊姆
    Enemy E;
    E.name = "史萊姆";
    E.type = Slime;
    E.stats = { 200, 5, 8, 8 }; //Hp, Atk, Def, Spd
    return E;
}

Enemy createDragon() { // 敵人=龍
    Enemy E;
    E.name = "龍";
    E.type = Dragon;
    E.stats = { 1000, 20, 20, 12 }; //Hp, Atk, Def, Spd
    return E;
}




//////////////////////////////////
/////////////遊戲流程//////////////
//////////////////////////////////

void displayMenu() { // 主選單
    cout << "歡迎來到簡單RPG" << endl;
    cout << "1. 開始遊戲" << endl;
    cout << "2. 載入遊戲" << endl;
    cout << "3. 退出" << endl;
    cout << "請輸入選項: ";
    cin >> InputOption;
}

void HandleMenuOption() { // 處理選單選項
    switch (InputOption)
    {
    case 1:
        StartGame;
        break;

    case 2:
        cout << "存檔功能尚未實裝:P" << endl;
        break;

    case 3:
        cout << "再見!" << endl;
        system("pause");
        return 0;
        break;

    default:
        cout << "無效選項，請再試一次" << endl;
        break;
    }
}

void NewGameName() { // 新遊戲名稱輸入
    cout << "新的遊戲開始" << endl;
    cout << "請輸入你的名字:" << endl;
    cin >> InputString;
    Player.name = InputString;
    cout << "你的名字是" << Player.name << "!" << endl;
}

void ChooseClass() { // 選擇職業
    cout << "請選擇你的職業:" << endl;
    cout << "1." << createWarrior().name << " 血量:" << createWarrior().stats.health << " 攻擊力:" << createWarrior().stats.attackPower << " 防禦力:" << createWarrior().stats.defensePower << " 速度:" << createWarrior().stats.speed << endl;
    cout << "2." << createPaladin().name << " 血量:" << createPaladin().stats.health << " 攻擊力:" << createPaladin().stats.attackPower << " 防禦力:" << createPaladin().stats.defensePower << " 速度:" << createPaladin().stats.speed << endl;
    cout << "3." << createArcher().name << " 血量:" << createArcher().stats.health << " 攻擊力:" << createArcher().stats.attackPower << " 防禦力:" << createArcher().stats.defensePower << " 速度:" << createArcher().stats.speed << endl;
    cout << "請輸入你的選擇: ";
    cin >> InputOption;

    switch (InputOption) {
    case 1:
        Player P = createWarrior();
        break;
    case 2:
        Player P = createPaladin();
        break;
    case 3:
        Player P = createArcher();
        break;
    default:
        cout << "無效選擇，請再試一次。" << endl;
        ChooseClass();
        break;
    }
}

void ConfirmNameClass(bool isConfirmed) { // 確認角色名稱與職業
    cout << "你的名字是" << Player.name << "，職業是" << Player.name << "!" << endl;
    cout << "你的角色能力值:" << endl;
    cout << "血量:" << Player.stats.health << endl;
    cout << "攻擊力:" << Player.stats.attackPower << endl;
    cout << "防禦力:" << Player.stats.defensePower << endl;
    cout << "速度:" << Player.stats.speed << endl;
    cout << "是否以這樣的設定開始遊戲? (Y/N)" << endl;
    cin >> InputChar;
    if (InputChar == 'Y' || InputChar == 'y') {
        return true;
    }
    else {
        cout << "請重新設定角色" << endl;
        cout << "按任意鍵繼續..." << endl;
        system("pause");
        return false;
    }
}


///////////////////////////////////////////
//////////////戰鬥流程//////////////////////
///////////////////////////////////////////

void RandomDecideEnemy() { // 隨機決定敵人
    srand(time(0)); // 設定隨機種子
    int enemyType = rand() % 3; // 隨機選擇敵人類型
    switch (enemyType) {
    case 0:
        Enemy E = createGoblin();
        break;
    case 1:
        Enemy E = createSlime();
        break;
    case 2:
        Enemy E = createDragon();
        break;
    }
}

void StartBattleMessage(Enemy enemy) { // 開始戰鬥
    cout << "你遇到了一隻" << enemy.name << "!" << endl;
    cout << "敵人能力值:" << endl;
    cout << "血量:" << enemy.stats.health << endl;
    cout << "攻擊力:" << enemy.stats.attackPower << endl;
    cout << "防禦力:" << enemy.stats.defensePower << endl;
    cout << "速度:" << enemy.stats.speed << endl;
    cout << "戰鬥開始!" << endl;
}

void BattleOptions() { // 戰鬥選項
    cout << player.namer << "的血量:" << player.stats.health << endl;
    cout << enemy.name << "的血量:" << enemy.stats.health << endl;
    cout << "你的行動:" << endl;
    cout << "1. 攻擊" << endl;
    cout << "2. 恢復" << endl;
    cout << "請選擇你的行動: ";
    cin >> InputOption;
}

void DecideFirstAttack(Player player, Enemy enemy) { // 決定先攻
    // 先攻計算公式
    int playerSpeed = 0;
    int enemySpeed = 0;
    int PlayerSpeedRecord[player.stats.speed];
    int EnemySpeedRecord[enemy.stats.speed];
    bool isPlayerFirst = false;

    // 骰等同於速度值的6面骰加總決定玩家最終速度值
    for (int i = 0; i < player.stats.speed; i++) {
        PlayerSpeedRecord[i] = rand() % 6 + 1;
    }
    int finalPlayerSpeed = 0;
    for (int i = 0; i < player.stats.speed; i++) {
        finalPlayerSpeed += PlayerSpeedRecord[i];
    }
    cout << "玩家速度為: " << finalPlayerSpeed << endl;
    cout << "詳細:";
    for (int i = 0; i < player.stats.speed; i++) {
        cout << PlayerSpeedRecord[i];
        if (i < player.stats.speed - 1) cout << ",";
    }
    cout << endl;

    // 骰等同於速度值的6面骰加總決定敵人最終速度值
    for (int i = 0; i < enemy.stats.speed; i++) {
        EnemySpeedRecord[i] = rand() % 6 + 1;
    }
    int finalEnemySpeed = 0;
    for (int i = 0; i < enemy.stats.speed; i++) {
        finalEnemySpeed += EnemySpeedRecord[i];
    }
    cout << "敵人速度為: " << finalEnemySpeed << endl;
    cout << "詳細:";
    for (int i = 0; i < enemy.stats.speed; i++) {
        cout << EnemySpeedRecord[i];
        if (i < enemy.stats.speed - 1) cout << ",";
    }
    bool isPlayerFirst = (finalPlayerSpeed >= finalEnemySpeed);
    cout << (isPlayerFirst ? "玩家先攻!" : "敵人先攻!") << endl;
}

void PlayerAttack(Player player, Enemy enemy) { // 戰鬥計算公式
    int damageToEnemy = 0;
    int damageGuardFromPlayer = 0;
    int PlayerDamageRecord[player.stats.attackPower];
    int EnemyDefRecord[enemy.stats.attackPower];

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

    for (int i = 0; i < enemy.stats.attackPower; i++) { //根據防禦力骰N個6面骰
        damageGuardFromPlayer += rand() % 6 + 1;
        EnemyDefRecord[i] = rand() % 6 + 1;
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
    cout << "對" << enemy.name << "造成" << actualDamageToEnemy << "傷害!" << endl;

    enemy.stats.health -= actualDamageToEnemy;
    if (enemy.stats.health < 0) enemy.stats.health = 0; // 確保生命值不會小於0
    cout << "敵人剩餘生命值: " << enemy.stats.health << "!" << endl;

}

void EnemyAttack(Player player, Enemy enemy) { // 敵人攻擊
    int damageToPlayer = 0;
    int damageGuardFromEnemy = 0;
    int PlayerDamageRecord[player.stats.attackPower];
    int EnemyDefRecord[enemy.stats.attackPower];

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

    for (int i = 0; i < player.stats.attackPower; i++) { //根據防禦力骰N個6面骰
        damageGuardFromEnemy += rand() % 6 + 1;
        PlayerDamageRecord[i] = rand() % 6 + 1;
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
    cout << "對" << player.name << "造成" << actualDamageToPlayer << "傷害!" << endl;


    player.stats.health -= actualDamageToPlayer;
    cout << "玩家剩餘生命值: " << player.stats.health << "!" << endl;
    if (player.stats.health < 0) player.stats.health = 0; // 確保生命值不會小於0
}

void PlayerHeal(Player player) { // 玩家恢復
    int healAmount = 0;
    int HealRecord[player.stats.magicPower];
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

    if (player.stats.health > 1000) player.stats.health = 1000; // 確保生命值不會超過上限
}

void EnemyHpCheck(Enemy enemy) { // 檢查敵人血量
    bool isEnemyDefeated = false;
    if (enemy.stats.health <= 0) {
        isEnemyDefeated = true;
        cout << "你擊敗了" << enemy.name << "!" << endl;
    }
    else {
        cout << enemy.name << "還活著!" << endl;
    }

}

void PlayerHpCheck(Player player) { // 檢查玩家血量
    bool isPlayerDefeated = false;
    if (player.stats.health <= 0) {
        isPlayerDefeated = true;
        cout << "你被" << enemy.name << "擊敗了!" << endl;
    }
    else {
        cout << player.name << "還活著!" << endl;
    }
}

void victoryMessage() { // 勝利訊息
    cout << "你獲勝了!" << endl;
    cout << "按任意鍵繼續..." << endl;
    system("pause");
}

////////////////////////////////////////////////
///////////////主程式////////////////////////////
////////////////////////////////////////////////

int main() {
    ClearScreen();
    displayMenu();
    HandleMenuOption();
    NewGameName();
    ChooseClass();
    ConfirmNameClass(true);
    RandomDecideEnemy();
    StartBattleMessage(enemy);
    DecideFirstAttack(player, enemy);
    cout << "戰鬥開始！按任意鍵繼續..." << endl;
    system("pause");

    while (true) { // 進入戰鬥迴圈
        ClearScreen();
        BattleOptions();
        if (InputOption == 1) {
            // 決定先攻
            DecideFirstAttack(player, enemy);
            // 玩家先攻或敵人先攻
            if (isPlayerFirst) { // 玩家先攻
                PlayerAttack(player, enemy);
                EnemyHpCheck(enemy);
                if (enemy.stats.health <= 0) {
                    victoryMessage();
                    break;
                }
                EnemyAttack(player, enemy);
                PlayerHpCheck(player);
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
            }
            else { // 敵人先攻
                EnemyAttack(player, enemy);
                PlayerHpCheck(player);
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }

                PlayerAttack(player, enemy);
                EnemyHpCheck(enemy);
                if (enemy.stats.health <= 0) {
                    victoryMessage();
                    break;
                }
                EnemyAttack(player, enemy);
                PlayerHpCheck(player);
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
            }
        }
        else if (InputOption == 2) {
            // 決定先攻
            DecideFirstAttack(player, enemy);
            // 玩家先攻或敵人先攻
            if (isPlayerFirst) { // 玩家先攻
                PlayerHeal(player);
                EnemyAttack(player, enemy);
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
            }
            else {
                EnemyAttack(player, enemy);
                PlayerHpCheck(player);
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
                PlayerHeal(player);
            }

        }
        else {
            cout << "無效選項，請再試一次" << endl;
        }
    }

    return 0;

}
}