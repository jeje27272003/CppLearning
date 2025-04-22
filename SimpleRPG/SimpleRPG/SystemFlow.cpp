#include "SystemFlow.h"
using namespace GlobalVariable;
using namespace std;
using namespace Player;
using namespace Enemy;

// �M���e���\��

void ClearScreen() {
#ifdef _WIN32
    system("cls");

#else
    system("clear");
#endif
}



//////////////////////////////////
/////////////�C���y�{//////////////
//////////////////////////////////

void displayMenu() { // �D���
    cout << "�w��Ө�²��RPG" << endl;
    cout << "1. �}�l�C��" << endl;
    cout << "2. ���J�C��" << endl;
    cout << "3. �h�X" << endl;
    cout << "�п�J�ﶵ: ";
    InputOption = 0; // ��l�ƿﶵ
    cin >> InputOption;
}

void HandleMenuOption() { // �B�z���ﶵ
    while (true)
    {
        switch (InputOption)
        {
        case 1:
            cout << "�A��ܤF�}�l�s�C��" << endl;
            return;

        case 2:
            cout << "�s�ɥ\��|�����:P" << endl;
            break;

        case 3:
            cout << "�A��!" << endl;
            exit(0); // �ϥ� exit(0) �ӵ����������{��
            break;

        default:
            cout << "�L�Ŀﶵ�A�ЦA�դ@��" << endl;
            displayMenu();
            break;
        }
    }

}

void StartBattleMessage() { // �}�l�԰�
    cout << "�A�J��F�@��" << enemy.name << "!" << endl;
    cout << "�ĤH��O��:" << endl;
    cout << "��q:" << enemy.stats.health << endl;
    cout << "�����O:" << enemy.stats.attackPower << endl;
    cout << "���m�O:" << enemy.stats.defensePower << endl;
    cout << "�t��:" << enemy.stats.speed << endl;
    cout << "�԰��}�l!" << endl;
}

void BattleOptions() { // �԰��ﶵ
    cout << player.name << "����q:" << player.stats.health << endl;
    cout << enemy.name << "����q:" << enemy.stats.health << endl;
    cout << "�A�����:" << endl;
    cout << "1. ����" << endl;
    cout << "2. ��_" << endl;
    cout << "3. �d�ݪ��A" << endl;
    cout << "�п�ܧA�����: ";
    cin >> InputOption;
}

void victoryMessage() { // �ӧQ�T��
    cout << "�A��ӤF!" << endl;
    cout << "�����N���~��..." << endl;
    system("pause");
}

void defeatMessage() { // ���ѰT��
	cout << "�A���ѤF!" << endl;
	cout << "�����N���~��..." << endl;
	system("pause");
}