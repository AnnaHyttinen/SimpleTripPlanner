#pragma once
#include <iostream>
#include <string>
using namespace std;

class Plan : public LList<char*> {
private:
    string planName;
    LList<Day> days;
public:
    Plan(string name) : planName(name) { LList<Day> days; }
    ~Plan() { LList<Day> days; } // is this how it is destroyed?
    void CreateDay() {
        string name;
        cout << "Type a preferred name for the day: ";
        getline(cin, name);
        cin.ignore();

        Day day(name);
        days.Push(day);
        day.GetName();
        day.SwitchAction();
    }
    void GetName() { cout << "\t# " << planName << " #" << endl << endl; }
};

