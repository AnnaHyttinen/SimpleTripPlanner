#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
using namespace std;

bool planner = true;
LList<Plan> planList;

void CreatePlan() {
    string n;
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();

    Plan plan(n);
    planList.Push(plan);
    plan.GetName();
    plan.ListDays();
    plan.CreateDay();
}

void ListPlan() {
    //printing objects from inside objects etc. 
}

int main()
{
    LList<Plan> planList;
    while (planner = true) {
        cout << "*** Simple Trip Planner ***" << endl << endl;
        int number = planList.Number();
        if (number == 0) {
            cout << "No previous data was found. Let's create a new plan! " << endl;
            CreatePlan();
        }
        else {
            cout << "Available plans: " << endl;
            planList.Print();
            cout << "Choose an action: " << endl;
        }
    }
    return 0;
}






