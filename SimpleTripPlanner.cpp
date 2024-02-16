#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
using namespace std;

void CreateDay() {
    char* name = new char[10];
    cout << "Type a preferred name for the day:\n";
    cin >> name;
    Day day(name);
    day.GetName();
    day.SwitchAction();
}

int main()
{
    CreateDay();
    
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






