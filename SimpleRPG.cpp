#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

int InputOption;
string InputString;

void ClearScreen() {
    #ifdef_WIN32
        system("cls");
    
    #else
        system("clear")
}

struct Player {
    string name;
    struct parameters {
        int health;
        int attackPower;
        int defensePower;
        int speed;
    } parameters;

};

struct Enemy {
    string name;
    struct parameters {
        int health;
        int attackPower;
        int defensePower;
        int speed;
    } parameters;
};

// show main menu
void displayMenu() {
    cout << "Welcome to the Simple RPG!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
    cin >> InputOption ;
}

void HandleMenuOption() {
    switch (InputOption)
    {
    case 1 :
        StartGame;
        break;
    
    case 2 :
        cout << "Save/Load isn't ready yet :P" << endl;
        break;
    
    case 3 :
        cout << "Bye!" << endl;
        system("pause");
        return 0;
        break;

    default:
        cout << "Not an option, please try again" << endl;
        break;
    }
}

void StartGame() {
    ClearScreen;
    cout << "Start a new game" << endl;
    cout << "Enter your name:" << endl;
    cin >> InputString;
    Player.name = InputString;
}

void ChooseClass(){
    cout << "Choose your class:" << endl;
    cout << "1.Warrior HP:50 Atk:10 Def:5 Spd:10" << endl;
    cout << ""
}