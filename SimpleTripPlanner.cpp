#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
using namespace std;

void CreateDay() {
    char* name = new char[20];
    cout << "Type a preferred name for the day: ";
    cin >> name;
    /*while (cin) {
        cin.getline(name, sizeof(name));
        if (cin.peek() == '\n') {
            cin.clear(ios::eofbit);
        }
    }*/
    Day day(name);
    day.GetName();
    day.SwitchAction();
}

int main()
{
    CreateDay();
    
    return 0;
}






