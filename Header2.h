#pragma once
#include <iostream>
#include <string>
using namespace std;

class Day : public String, public LList<String*> {
public:
    Day(char* name) : dayName(name) { LList<String*> toDoList; }
    ~Day() {
        delete[] dayName;
        delete[] accommodation;
    }
    void SwitchAction();
    void WhatToDo() {
        LList<char*> toDo;
        char thing[50];
        cout << "Describe what you would like to do: \n";
        while (cin) {
            cin >> thing;
            toDo.insertToEnd(thing);
            cout << thing;
            if (cin.peek() == '\n') {
                cin.clear(ios::eofbit);
            }
        }
        Print();
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
private:
    char* dayName{};
    char* accommodation{};
};

void Day:: SwitchAction() {
    int answer;
    Print();
    cout << "Would you like to add(1) or remove(2)an activity?";
    cin >> answer;
    if (answer != 1 && answer != 2) {
        cout << "How about setting an accommodation(3) or nothing else for " << dayName << "(4)?";
        cin >> answer;
    }
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

