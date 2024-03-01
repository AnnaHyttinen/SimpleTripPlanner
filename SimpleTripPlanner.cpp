#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
using namespace std;

bool planner = true;

void CreateDay() {
    string name;
    cout << "Type a preferred name for the day: ";
    getline(cin, name);
    cin.ignore();

    Day day(name);
    //needs to go to a linked list of plan, then multiple plans
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






