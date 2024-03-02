#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
using namespace std;

bool planner = true;

class Menu {
public:
    void CreatePlan();

};

void Menu::CreatePlan() {
    string n = "Default plan";
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();

    Plan plan(n);
    plan.GetName();
    plan.ListDay();
    plan.CreateDay();
}

void MainMenu() {
    if (planner = false) {
        
    }
    else {
        cout << "*** Simple Trip Planner ***" << endl << endl;
        cout << "No previous data was found. Let's create a new plan! " << endl;
        Menu menu;
        menu.CreatePlan();
    }
}

int main()
{
    MainMenu();

    return 0;
}






