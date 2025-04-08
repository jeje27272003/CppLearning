#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

struct Player {
    string name;
    int health;
    int level;
    int experience;
    enum class classType { Swordman, Archer, Mage };
    classType playerClass;
    int attackPower;
    int defensePower;
    
};

struct Enemy {
    string name;
    int health;
    int damage;
};

// Function to display the main menu
void displayMenu() {
    cout << "Welcome to the Simple RPG!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}
