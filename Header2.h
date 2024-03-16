#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern void PrintPlan();
extern bool cost;
int budget;

class Plan : public LList<Day> {
private:
    string planName;
    LList<Day> days;
public:
    Plan() {};
    Plan(string name) : planName(name) {}
    ~Plan() {};
    void SwitchAction(Day& d);
    void CreateDay();
    void ListDays();
    void GetName() { cout << "\t# " << planName << " #" << endl << endl; }
};

void Plan::SwitchAction(Day& d) {
    d.GetName();
    cin.ignore();
    int answer = 0;
    d.Print();
    d.GetAcco();
    cout << "Would you like to: \n1 add an activity,\n2 set an accommodation or\n3 no more activities for the day? Your input: ";
    cin >> answer;

    if (answer != 1 && answer != 2 && answer != 3) {
        SwitchAction(d);
    }
    else {
        switch (answer) {
        case 1:
            d.WhatToDo();
            SwitchAction(d);
            break;
        case 2:
            d.SetAcco();
            SwitchAction(d);
            break;
        case 3:
            if (cost == true) {
                int cash;
                cout << "Add estimated expenses for the day: ";
                cin >> cash;
                cin.ignore();
                d.SetMoney(cash);
            }
            int another;
            cin.ignore();
            cout << endl << "Select: " << endl;
            cout << "1) to create a new day, \n2) to see the plan or \n3) to quit? Your input: ";
            cin >> another;
            cin.ignore();
            if (another != 1 && another != 2 && another != 3) {
                SwitchAction(d);
            }
            switch (another) {
            case 1:
                CreateDay();
                break;
            case 2:
                cout << endl;
                PrintPlan();
                if (cost == true) {
                    cout << "Overall budget: " << budget << endl;
                    cout << "->->-> End of the plan. Now returning to the day:";
                }
                SwitchAction(d);
                break;
            case 3:
                if (cost == true) {
                    planList.Push("Overall budget: " + to_string(budget));
                }
                cout << "Saving to an external file..." << endl;
                ofstream File(planName + ".txt");
                string s = planList.PrintString();
                File << s;
                File.close();
                break;
            }
            break;
        }
    }
}

void Plan::CreateDay() {
    cout << "Amount of days in this plan: " << days.Number() << endl << endl;
    string name;
    cout << "Type a preferred name for the day: ";
    getline(cin, name);
    cin.ignore();

    Day day(name);
    days.Push(day);
    SwitchAction(day);
}

void Plan::ListDays() {
    days.Print(); //printing an object
    cout << "You have created " << days.Number() << " days." << endl;
}

