#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

Vector<string> planList;
bool cost;

void PrintPlan() {
    planList.Print();
}

void CreatePlan() {
    string e;
    cout << "Press y to include money to the plan. ";
    getline(cin, e);
    cin.ignore();
    if (e == "y") cost = true;
    else cost = false;

    string n;
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();

    Plan plan(n);
    plan.GetName();
    plan.CreateDay();
}

int main()
{
    cout << "*** Simple Trip Planner ***" << endl << endl;

    CreatePlan();

    return 0;
}
