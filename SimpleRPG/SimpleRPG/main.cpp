#include "Main.h"

////////////////////////////////////////////////
///////////////�D�{��////////////////////////////
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
    cout << "�԰��}�l�I�����N���~��..." << endl;
    system("pause");
    ClearScreen();

    while (true) { // �i�J�԰��j��
        BattleOptions();
        if (InputOption == 1) {
            // �M�w����
            isPlayerFirstAttack();
            // ���a����μĤH����
            if (isPlayerFirstAttack()) { // �p�G���a����
                PlayerAttack();
                EnemyHpCheck();
                if (enemy.stats.health <= 0) {
                    victoryMessage();
                    break;
                }
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "�A���F�A�C������!" << endl;
                    break;
                }
            }
            else { // �ĤH����
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "�A���F�A�C������!" << endl;
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
                    cout << "�A���F�A�C������!" << endl;
                    break;
                }
            }
        }
        else if (InputOption == 2) {
            // �M�w����
            isPlayerFirstAttack();
            // ���a����μĤH����
            if (isPlayerFirstAttack()) { // ���a����
                PlayerHeal();
                EnemyAttack();
                if (player.stats.health <= 0) {
                    cout << "�A���F�A�C������!" << endl;
                    break;
                }
            }
            else { // �ĤH����
                EnemyAttack();
                PlayerHpCheck();
                if (player.stats.health <= 0) {
                    cout << "�A���F�A�C������!" << endl;
                    break;
                }
                PlayerHeal();
            }
        }
        else if (InputOption == 3) {
            //�d�ݪ��A
            cout << endl;
            cout << "����W��:" << player.name << endl;
            cout << "¾�~:" << player.name << endl;
            cout << "��q:" << player.stats.health << endl;
            cout << "�����O:" << player.stats.attackPower << endl;
            cout << "���m�O:" << player.stats.defensePower << endl;
            cout << "�t��:" << player.stats.speed << endl;
            cout << endl;
            cout << "�ĤH�W��:" << enemy.name << endl;
            cout << "��q:" << enemy.stats.health << endl;
            cout << "�����O:" << enemy.stats.attackPower << endl;
            cout << "���m�O:" << enemy.stats.defensePower << endl;
            cout << "�t��:" << enemy.stats.speed << endl;
        }
        else {
            cout << "�L�Ŀﶵ�A�ЦA�դ@��" << endl;
        }
    }

    return 0;
}
