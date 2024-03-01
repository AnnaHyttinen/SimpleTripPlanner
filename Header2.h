#pragma once
#include <iostream>
#include <string>
using namespace std;

class Day : public String, public LList<char*> {
private:
    string dayName{};
    string accommodation{};
    LList<string> toDo;
public:
    Day(string name) : dayName(name) { LList<char*> toDo; }
    ~Day() {
        LList<char*> toDo;
    }
    void SwitchAction();
    void WhatToDo();
    void RemoveToDo() {
        int answer;
        cout << "Which of these activities would you like to remove?\n";
        cin >> answer;
        Print();
        SwitchAction();
    }
    void SetAcco() {
        cout << "Type your idea for an accommodation for " << dayName << ": \n";
        cin.ignore();
        getline(cin, accommodation);
    }
    void GetName() {
        cout << "This day is now called: " << dayName << endl;
    }
};

void Day:: SwitchAction() {
    int answer = 0;
    Print();
    cout << "Would you like to: \n1 add an activity,\n2 remove an activity,\n";
    cout << "3 set an accommodation or\n4 nothing else for this day?\n\n";
    cin >> answer;

    if (answer != 1 && answer != 2 && answer != 3 && answer != 4) {
        SwitchAction();
    }
    else {
        switch (answer) {
        case 1:
            WhatToDo();
            break;
        case 2:
            RemoveToDo();
            break;
        case 3:
            SetAcco();
            break;
        case 4:
            break;
        }
    }
}

void Day::WhatToDo() {
    string thing;
    cout << "Describe what you would like to do: ";
    cin.ignore();
    getline(cin, thing);

    toDo.Push(thing);
    toDo.Print();
    SwitchAction(); 
}