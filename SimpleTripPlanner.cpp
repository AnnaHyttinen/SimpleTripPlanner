#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
#include <stdlib.h>
using namespace std;

LList<Plan> planList;

void CreatePlan() {
    string n;
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();

    Plan plan(n);
    planList.Push(plan);
    plan.GetName();
    //plan.ListDays();
    plan.CreateDay();
}

void ListPlan() {
    cout << "Available plans:\n";
    //printing objects from inside objects 
}

void ChangePlan() {
    int answer = 0;
    cout << "Type 1 to proceed or 2 to quit: ";
    cin >> answer;
    cin.ignore();
    if (answer == 2) { exit(0); }
    cout << "Available plans: " << endl;
    //planList.Print();
    cout << "Enter the number to open a plan, 0 to make a new plan or 100 to remove a plan: ";
    cin >> answer;
    cin.ignore();
    //OpenPlan()
    //CreatePlan()
    //RemovePlan()
}

void Menu() {
    int answer;
    cout << "1) Choose a plan 2) Quit\nYour input: ";
    cin >> answer;
    cin.ignore();
    switch (answer) {
    case 1:
        ListPlan();
        break;
    case 2:
        break;
    }
}

int main()
{
    cout << "*** Simple Trip Planner ***" << endl << endl;
    Vector<Plan> planList;
    int number = planList.Number();
    if (number == 0) {
        cout << "Let's create a new plan! " << endl;
        CreatePlan();
    }
    else {
        ChangePlan();
    }
    return 0;
}
