#include "Main.h"

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
    StartBattleMessage();
    cout << "戰鬥開始！按任意鍵繼續..." << endl;
    system("pause");
    ClearScreen();

    while (true) { // 進入戰鬥迴圈
        BattleOptions();
        if (InputOption == 1) {
            // 決定先攻
            isPlayerFirstAttack();
            // 玩家先攻或敵人先攻
            if (isPlayerFirstAttack()) { // 如果玩家先攻
                PlayerAttack();
                EnemyHpCheck();
                if (enemy.stats.health <= 0) {
                    victoryMessage();
                    break;
                }
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
            }
            else { // 敵人先攻
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }

                PlayerAttack();
                EnemyHpCheck();
                if (enemy.stats.health <= 0) {
                    victoryMessage();
                    break;
                }
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
            }
        }
        else if (InputOption == 2) {
            // 決定先攻
            isPlayerFirstAttack();
            // 玩家先攻或敵人先攻
            if (isPlayerFirstAttack()) { // 玩家先攻
                PlayerHeal();
                EnemyAttack();
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
            }
            else { // 敵人先攻
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "你死了，遊戲結束!" << endl;
                    break;
                }
                PlayerHeal();
            }
        }
        else if (InputOption == 3) {
            //查看狀態
            cout << endl;
            cout << "角色名稱:" << player.name << endl;
            cout << "職業:" << player.name << endl;
            cout << "血量:" << player.stats.health << endl;
            cout << "攻擊力:" << player.stats.attackPower << endl;
            cout << "防禦力:" << player.stats.defensePower << endl;
            cout << "速度:" << player.stats.speed << endl;
            cout << endl;
            cout << "敵人名稱:" << enemy.name << endl;
            cout << "血量:" << enemy.stats.health << endl;
            cout << "攻擊力:" << enemy.stats.attackPower << endl;
            cout << "防禦力:" << enemy.stats.defensePower << endl;
            cout << "速度:" << enemy.stats.speed << endl;
        }
        else {
            cout << "無效選項，請再試一次" << endl;
        }
    }

    return 0;
}
