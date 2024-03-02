#pragma once
#include <iostream>
#include <string>
using namespace std;

class Day : public LList<string> {
private:
    string dayName{};
    string accommodation{};
    LList<string> toDo;
public:
    Day(string name) : dayName(name) { LList<string> toDo; }
    ~Day() {
        LList<string> toDo;
    }
    void SwitchAction();
    void WhatToDo();
    void RemoveToDo();
    void SetAcco();
    void GetName() { cout << "The day is: " << dayName << endl; }
    
};

void Day::SwitchAction() {
    int answer = 0;
    Print();
    cout << "Would you like to: \n1 add an activity,\n2 remove an activity,\n";
    cout << "3 set an accommodation or\n4 nothing else for this day? Your input: ";
    cin >> answer;
    cin.ignore();

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
    cout << endl << "Describe what you would like to do: ";
    cin.ignore();
    getline(cin, thing);

    toDo.Push(thing);
    toDo.Print();
    SwitchAction();
}

void Day::RemoveToDo() {
    int answer;
    cout << "Which of these activities would you like to remove?\n";
    cin.ignore();
    cin >> answer;
    toDo.Remove(answer);
    toDo.Print();
    SwitchAction();
}

void Day::SetAcco() {
    cout << "Type your idea for an accommodation for " << dayName << ": \n";
    cin.ignore();
    getline(cin, accommodation);
    SwitchAction();
}

