#pragma once
#include <iostream>
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
        char todo[50];
        cin.clear();
        cin.sync();
        cout << "Describe what you would like to do: (\"Today...\")\n";
        cin >> todo;
        cin.getline(todo, 50);
        
        String toDo(todo);
        insertToEnd(&toDo);
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

