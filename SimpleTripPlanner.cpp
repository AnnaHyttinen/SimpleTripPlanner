#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
using namespace std;

bool planner = true;

void MainMenu() {
    string n = "Default plan";
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();
    Plan plan(n);
    plan.GetName();
    plan.CreateDay();
}

int main()
{
    while (planner = true) {
        MainMenu();
    }
    //also going to be a class
    //...because it contains a linked list of plans, of course
    //every time this program is started, it creates (or loads) a main menu
    return 0;
}






