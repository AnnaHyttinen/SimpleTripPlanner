#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
using namespace std;

bool planner = true;

void CreateDay() {
    char* name = new char[20];
    cout << "Type a preferred name for the day: ";
    while (cin) {
        cin.getline(name, sizeof(name));
        if (cin.peek() == '\n') {
            cin.clear(ios::eofbit);
        }
    }
    cin.clear();

    Day day(name);
    day.GetName();
    day.SwitchAction();
}

void MainMenu() {
    //see the statistics and make changes or
    CreateDay();
}

int main()
{
    MainMenu();
    
    
    return 0;
}






