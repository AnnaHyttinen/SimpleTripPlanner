#pragma once
#include <iostream>
#include <string>
using namespace std;

class Day : public String, public LList<char*> {
private:
    char* dayName{};
    char* accommodation{};
    LList<char*> toDo;
public:
    Day(char* name) : dayName(name) { LList<char*> toDo; }
    ~Day() {
        delete[] dayName;
        delete[] accommodation;
        LList<char*> toDo;
    }
    void SwitchAction();
    void WhatToDo() {
        char thing[200];
        cout << "Describe what you would like to do: ";
        while (cin) {
            cin.getline(thing, sizeof(thing));
            if (cin.peek() == '\n') {
                cin.clear(ios::eofbit);
            }
        }
        toDo.insertToEnd(thing);
        toDo.Print();
    }
    void RemoveToDo() {
        int answer;
        cout << "Which of these activities would you like to remove?\n";
        Print();
        cin >> answer;
    }
    void SetAcco() {
        cout << "Type your idea for an accommodation for " << dayName << ": \n";
        cin >> accommodation;
    }
    void GetName() {
        cout << "This day is now called: " << dayName << endl;
    }
};

void Day:: SwitchAction() {
    int answer;
    Print();
    cout << "Would you like to: \n1 add an activity\n2 remove an activity\n";
    cout << "3 set an accommodation/n4 nothing else for " << this->dayName << "?\n";
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
            return;
            break;
        }
    }
}

