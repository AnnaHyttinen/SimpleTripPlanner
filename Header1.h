#pragma once
#include <iostream>
#include <string>
using namespace std;

extern Vector<string> planList;
extern int budget;

class Day : public LList<string> {
private:
    string dayName;
    string accommodation;
    LList<string> toDo;
    int money;
public:
    Day() {
        dayName = "";
        accommodation = "";
        LList<string> toDo;
        money = 0;
    };
    Day(string name) : dayName(name) {
        planList.Push(name);
        accommodation = "";
        LList<string> toDo;
        money = 0;
    }
    ~Day() {}
    void WhatToDo();
    //void RemoveToDo();
    void GetAcco();
    void SetAcco();
    void SetMoney(int m);
    void GetName() { cout << "\t\"" << dayName << "\"" << endl; }
    friend ostream& operator<<(ostream& stream, Day d);
};

ostream& operator<<(ostream& stream, Day d) {
    stream << d.dayName;
    return stream;
}

void Day::WhatToDo() {
    toDo.Print();
    string thing;
    cout << "Describe what you would like to do: ";
    cin.ignore();
    getline(cin, thing);
    toDo.Push(thing);
    string extra = "\t";
    string better = extra + thing;
    planList.Push(better);
    toDo.Print();
}
/*
void Day::RemoveToDo() {
    if (toDo.Number() == 0) { cout << "No activities to remove. " << endl; }
    else {
        int answer;
        cout << "Which of these activities would you like to remove?\n";
        cin >> answer;
        cin.ignore();
        toDo.Remove(answer);
        planList.Remove(answer);
        toDo.Print();
    }
}
*/
void Day::GetAcco() {
    if (accommodation == "") { cout << "Current accommodation: None" << endl << endl; }
    else{ cout << "Current accommodation: " << accommodation << endl << endl; }
}

void Day::SetAcco() {
    cout << "Set an accommodation: \n";
    cin.ignore();
    getline(cin, accommodation);
    string a = "*** " + accommodation + " ***";
    planList.Push(a);
}

void Day::SetMoney(int m) {
    money += m;
    budget += m;
    planList.Push("Daily cost: " + to_string(m) + "\n");
}

