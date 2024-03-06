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
    Day() {};
    Day(string name) : dayName(name) {}
    ~Day() {
         LList<string> toDo; // ?
    }
    void WhatToDo();
    void RemoveToDo();
    void SetAcco();
    void GetName() { cout << "\t\"" << dayName << "\"" << endl; }
    friend ostream& operator<<(ostream& stream, Day d);
};

ostream& operator<<(ostream& stream, Day d) {
    stream << d.dayName << endl;
    return stream;
}

void Day::WhatToDo() {
    cout << "You have " << toDo.Number() << " items on your to-do-list." << endl;
    string thing;
    cout << endl << "Describe what you would like to do: ";
    cin.ignore();
    getline(cin, thing);
    toDo.Push(thing);
    toDo.Print();
}

void Day::RemoveToDo() {
    int answer;
    cout << "Which of these activities would you like to remove?\n";
    cin.ignore();
    cin >> answer;
    toDo.Remove(answer);
    toDo.Print();
}

void Day::SetAcco() {
    cout << "Type your idea for an accommodation for " << dayName << ": \n";
    cin.ignore();
    getline(cin, accommodation);
}

