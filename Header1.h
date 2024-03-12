#pragma once
#include <iostream>
#include <string>
using namespace std;

class Day : public LList<string> {
private:
    string dayName;
    string accommodation;
    LList<string> toDo;
public:
    Day() {
        dayName = "";
        accommodation = "";
        LList<string> toDo;
    };
    Day(string name) : dayName(name) {
        accommodation = "";
        LList<string> toDo;
    }
    //Day(const Day& other) = delete;
    ~Day() {}
    void WhatToDo();
    void RemoveToDo();
    void GetAcco();
    void SetAcco();
    void GetName() { cout << "\t\"" << dayName << "\"" << endl; }
    void PrintDay();
    friend ostream& operator<<(ostream& stream, Day d);
};

ostream& operator<<(ostream& stream, Day d) {
    stream << d.dayName << endl;
    return stream;
}

void Day::WhatToDo() {
    toDo.Print();
    string thing;
    cout << "Describe what you would like to do: ";
    cin.ignore();
    getline(cin, thing);
    toDo.Push(thing);
    toDo.Print();
}

void Day::RemoveToDo() {
    if (toDo.Number() == 0) { cout << "No activities to remove. " << endl; }
    else {
        int answer;
        cout << "Which of these activities would you like to remove?\n";
        cin >> answer;
        cin.ignore();
        toDo.Remove(answer);
        toDo.Print();
    }
}

void Day::GetAcco() {
    if (accommodation == "") { cout << "Current accommodation: None" << endl << endl; }
    else{ cout << "Current accommodation: " << accommodation << endl << endl; }
}

void Day::SetAcco() {
    cout << "Set an accommodation: \n";
    cin.ignore();
    getline(cin, accommodation);
}

void Day::PrintDay() {
    cout << dayName << endl;
    toDo.Print(); //this is not coming out
    cout << endl << accommodation << endl;
}



