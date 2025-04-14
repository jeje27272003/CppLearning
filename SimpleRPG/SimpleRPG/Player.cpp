#include "Common.h"
#include "Player.h"
#include "GlobalVariable.h"

Player createWarrior() { // ¾�~=�Ԥh
    player.name = "�Ԥh";
    player.job = Warrior;
    player.stats = { 600, 25, 10, 15, 10 }; //Hp, Atk, Mag, Def, Spd
    player.stats.health = player.stats.Maxhealth; // ��l�Ʀ�q
    return player;
}

Player createPaladin() { // ¾�~=�t�M�h
    player.name = "�t�M�h";
    player.job = Paladin;
    player.stats = { 750, 15, 20, 20, 10 }; //MaxHp, Atk, Mag, Def, Spd
    player.stats.health = player.stats.Maxhealth; // ��l�Ʀ�q
    return player;
}

Player createArcher() { // ¾�~=�}�b��
    player.name = "�}�b��";
    player.job = Archer;
    player.stats = { 500, 30, 15, 5, 15 }; //MaxHp, Atk, Mag, Def, Spd
    player.stats.health = player.stats.Maxhealth; // ��l�Ʀ�q
    return player;
}

void NewGameName() { // �s�C���W�ٿ�J
    cout << "�s���C���}�l" << endl;
    cout << "�п�J�A���W�r:" << endl;
    //�M�ŦW�r
    player.name = "";
    cin >> InputString;
    player.name = InputString;
    cout << "�A���W�r�O" << player.name << "!" << endl;
}

void ChooseClass() { // ���¾�~
    while (true) { // �ϥΰj��T�O�L�Ŀ�ܷ|���]
        cout << "�п�ܧA��¾�~:" << endl;
        cout << "1." << createWarrior().name << " ��q:" << createWarrior().stats.health << " �����O:" << createWarrior().stats.attackPower << " ���m�O:" << createWarrior().stats.defensePower << " �t��:" << createWarrior().stats.speed << endl;
        cout << "2." << createPaladin().name << " ��q:" << createPaladin().stats.health << " �����O:" << createPaladin().stats.attackPower << " ���m�O:" << createPaladin().stats.defensePower << " �t��:" << createPaladin().stats.speed << endl;
        cout << "3." << createArcher().name << " ��q:" << createArcher().stats.health << " �����O:" << createArcher().stats.attackPower << " ���m�O:" << createArcher().stats.defensePower << " �t��:" << createArcher().stats.speed << endl;
        cout << "�п�J�A�����: ";
        cin >> InputOption;

        switch (InputOption) {
        case 1:
            player = createWarrior();
            return; // �����禡
        case 2:
            player = createPaladin();
            return; // �����禡
        case 3:
            player = createArcher();
            return; // �����禡
        default:
            cout << "�L�Ŀ�ܡA�ЦA�դ@���C" << endl;
            break; // ���s�i�J�j��
        }
    }
}

bool ConfirmNameClass(bool isConfirmed) { // �T�{����W�ٻP¾�~
    cout << "�A���W�r�O" << player.name << "�A¾�~�O" << player.name << "!" << endl;
    cout << "�A�������O��:" << endl;
    cout << "��q:" << player.stats.health << endl;
    cout << "�����O:" << player.stats.attackPower << endl;
    cout << "���m�O:" << player.stats.defensePower << endl;
    cout << "�t��:" << player.stats.speed << endl;
    cout << "�O�_�H�o�˪��]�w�}�l�C��? (Y/N)" << endl;
    cin >> InputChar;
    if (InputChar == 'Y' || InputChar == 'y') {
        return true;
    }
    else {
        cout << "�Э��s�]�w����" << endl;
        cout << "�����N���~��..." << endl;
        system("pause");
        return false;
    }
}

