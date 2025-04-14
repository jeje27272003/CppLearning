#include "Common.h"
#include "Player.h"
#include "GlobalVariable.h"

Player createWarrior() { // 職業=戰士
    player.name = "戰士";
    player.job = Warrior;
    player.stats = { 600, 25, 10, 15, 10 }; //Hp, Atk, Mag, Def, Spd
    player.stats.health = player.stats.Maxhealth; // 初始化血量
    return player;
}

Player createPaladin() { // 職業=聖騎士
    player.name = "聖騎士";
    player.job = Paladin;
    player.stats = { 750, 15, 20, 20, 10 }; //MaxHp, Atk, Mag, Def, Spd
    player.stats.health = player.stats.Maxhealth; // 初始化血量
    return player;
}

Player createArcher() { // 職業=弓箭手
    player.name = "弓箭手";
    player.job = Archer;
    player.stats = { 500, 30, 15, 5, 15 }; //MaxHp, Atk, Mag, Def, Spd
    player.stats.health = player.stats.Maxhealth; // 初始化血量
    return player;
}

void NewGameName() { // 新遊戲名稱輸入
    cout << "新的遊戲開始" << endl;
    cout << "請輸入你的名字:" << endl;
    //清空名字
    player.name = "";
    cin >> InputString;
    player.name = InputString;
    cout << "你的名字是" << player.name << "!" << endl;
}

void ChooseClass() { // 選擇職業
    while (true) { // 使用迴圈確保無效選擇會重跑
        cout << "請選擇你的職業:" << endl;
        cout << "1." << createWarrior().name << " 血量:" << createWarrior().stats.health << " 攻擊力:" << createWarrior().stats.attackPower << " 防禦力:" << createWarrior().stats.defensePower << " 速度:" << createWarrior().stats.speed << endl;
        cout << "2." << createPaladin().name << " 血量:" << createPaladin().stats.health << " 攻擊力:" << createPaladin().stats.attackPower << " 防禦力:" << createPaladin().stats.defensePower << " 速度:" << createPaladin().stats.speed << endl;
        cout << "3." << createArcher().name << " 血量:" << createArcher().stats.health << " 攻擊力:" << createArcher().stats.attackPower << " 防禦力:" << createArcher().stats.defensePower << " 速度:" << createArcher().stats.speed << endl;
        cout << "請輸入你的選擇: ";
        cin >> InputOption;

        switch (InputOption) {
        case 1:
            player = createWarrior();
            return; // 結束函式
        case 2:
            player = createPaladin();
            return; // 結束函式
        case 3:
            player = createArcher();
            return; // 結束函式
        default:
            cout << "無效選擇，請再試一次。" << endl;
            break; // 重新進入迴圈
        }
    }
}

bool ConfirmNameClass(bool isConfirmed) { // 確認角色名稱與職業
    cout << "你的名字是" << player.name << "，職業是" << player.name << "!" << endl;
    cout << "你的角色能力值:" << endl;
    cout << "血量:" << player.stats.health << endl;
    cout << "攻擊力:" << player.stats.attackPower << endl;
    cout << "防禦力:" << player.stats.defensePower << endl;
    cout << "速度:" << player.stats.speed << endl;
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

