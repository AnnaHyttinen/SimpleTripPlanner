#pragma once
#include <iostream>
#include <string>
using namespace std;

extern void ChangePlan();

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
    void RemoveDay() {
        int answer;
        days.Print();
        cout << "Which day would you like to remove?\n";
        cin >> answer;
        cin.ignore();
        days.Remove(answer);
        SeePlan();
    }
    void ReplaceDay() {
        int a;
        days.Print();
        cout << "Which day would you like to replace?" << endl;
        cin >> a;
        cin.ignore();
        Day d = days.GetReference(a);
        SwitchAction(d);
    }
    void SeePlan() {
        days.Print();
    }
};

void Plan::SwitchAction(Day& d) {
    d.GetName();
    cin.ignore();
    int answer = 0;
    d.Print();
    d.GetAcco();
    cout << "Would you like to: \n1 add an activity,\n2 remove an activity,\n";
    cout << "3 set an accommodation or\n4 nothing else for this day? Your input: ";
    cin >> answer;

    if (answer != 1 && answer != 2 && answer != 3 && answer != 4) {
        SwitchAction(d);
    }
    else {
        switch (answer) {
        case 1:
            d.WhatToDo();
            SwitchAction(d);
            break;
        case 2:
            d.RemoveToDo();
            SwitchAction(d);
            break;
        case 3:
            d.SetAcco();
            SwitchAction(d);
            break;
        case 4:
            int another;
            cin.ignore();
            cout << endl;
            cout << "1) create a new day,\n2) remove an existing day,\n3) replace an existing day,\n";
            cout << "4) see the plan or\n5) none of the above? Your input: ";
            cin >> another;
            cin.ignore();
            switch (another) {
            case 1:
                CreateDay();
                break;
            case 2:
                RemoveDay();
                SwitchAction(d);
                break;
            case 3:
                ReplaceDay();
                SwitchAction(d);
                break;
            case 4:
                SeePlan();
                SwitchAction(d);
                break;
            case 5:
                ChangePlan();
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
    day.GetName();
    SwitchAction(day);
}

void Plan::ListDays() {
    days.Print(); //printing an object
    cout << "You have created " << days.Number() << " days." << endl;
}

