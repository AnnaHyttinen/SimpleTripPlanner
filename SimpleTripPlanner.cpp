#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
using namespace std;

class Day: public String, public LList<String*> {
public:
    Day() { 
        LList<String*> toDoList;
        cout << "What would you like to call this new day? ";
        cin >> dayName;
        cout << "You selected a fine name: " << dayName << endl;
    }
    ~Day() {
        delete[] dayName;
        delete[] accommodation;
    }
    void SwitchAction() { 
        int answer;
        ListActivity();
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
    void WhatToDo() {
        String toDo;
        cout << "What would you like to do?";
        cin >> toDo;
        insertToEnd(&toDo);
    }
    void RemoveToDo() {
        int answer;
        cout << "Which activity would you like to remove?\n";
        ListActivity();
        cin >> answer;
    }
    void SetAcco() {
        cout << "Do you have an idea about an accommodation for " << dayName << "?";
        cin >> accommodation;
    }
    void ListActivity() {
        Print();
    }
private:
    char* dayName{};
    char* accommodation{};
};

int main()
{
    Day day;
    day.SwitchAction();
    /*
    String toDo1 = "Swim with the dolphins.";
    cout << toDo1 << endl;
    cout << &toDo1 << endl; //the String pointer
    
    String toDo2 = "Run in the flower fields.";
    String toDo3 = "Have a cake.";

    LList<String*> toDoList1;
    toDoList1.insertToEnd(&toDo1).insertToEnd(&toDo2).insertToEnd(&toDo3);
    toDoList1.Print();

    String hotel1 = "Oceanside hotel";
    cout << hotel1 << endl;
    */
    return 0;
}






