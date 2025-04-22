#include "SystemFlow.h"
using namespace GlobalVariable;
using namespace std;
using namespace Player;
using namespace Enemy;

// 清除畫面功能

void ClearScreen() {
#ifdef _WIN32
    system("cls");

#else
    system("clear");
#endif
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
    InputOption = 0; // 初始化選項
    cin >> InputOption;
}

void HandleMenuOption() { // 處理選單選項
    while (true)
    {
        switch (InputOption)
        {
        case 1:
            cout << "你選擇了開始新遊戲" << endl;
            return;

        case 2:
            cout << "存檔功能尚未實裝:P" << endl;
            break;

        case 3:
            cout << "再見!" << endl;
            exit(0); // 使用 exit(0) 來結束並關閉程式
            break;

        default:
            cout << "無效選項，請再試一次" << endl;
            displayMenu();
            break;
        }
    }

}

void StartBattleMessage() { // 開始戰鬥
    cout << "你遇到了一隻" << enemy.name << "!" << endl;
    cout << "敵人能力值:" << endl;
    cout << "血量:" << enemy.stats.health << endl;
    cout << "攻擊力:" << enemy.stats.attackPower << endl;
    cout << "防禦力:" << enemy.stats.defensePower << endl;
    cout << "速度:" << enemy.stats.speed << endl;
    cout << "戰鬥開始!" << endl;
}

void BattleOptions() { // 戰鬥選項
    cout << player.name << "的血量:" << player.stats.health << endl;
    cout << enemy.name << "的血量:" << enemy.stats.health << endl;
    cout << "你的行動:" << endl;
    cout << "1. 攻擊" << endl;
    cout << "2. 恢復" << endl;
    cout << "3. 查看狀態" << endl;
    cout << "請選擇你的行動: ";
    cin >> InputOption;
}

void victoryMessage() { // 勝利訊息
    cout << "你獲勝了!" << endl;
    cout << "按任意鍵繼續..." << endl;
    system("pause");
}

void defeatMessage() { // 失敗訊息
	cout << "你失敗了!" << endl;
	cout << "按任意鍵繼續..." << endl;
	system("pause");
}