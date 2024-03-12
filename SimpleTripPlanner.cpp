#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

Vector<Plan> planList;

void CreatePlan() {
    string n;
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();

    Plan plan(n);
    planList.Push(plan);
    plan.GetName();
    plan.CreateDay();
}

int main()
{
    cout << "*** Simple Trip Planner ***" << endl << endl;

    CreatePlan();

    return 0;
}
