#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include <string.h>
using namespace std;

bool planner = true;
class Plan : public LList<char*> {
private:
    string planName;
    LList<Day> days;
public:
    Plan(string name) : planName(name) { LList<Day> days; }
    ~Plan() { LList<Day> days; } // is this how it is destroyed?
    void CreateDay() {
        string name;
        cout << "Type a preferred name for the day: ";
        getline(cin, name);
        cin.ignore();

        Day day(name);
        days.Push(day);
        day.GetName();
        day.SwitchAction();
    }
    void GetName() { cout << "\t# " << planName << " #" << endl << endl; }
};


void MainMenu() {
    string n = "Default plan";
    cout << "Give a name for your plan: ";
    getline(cin, n);
    cin.ignore();
    Plan plan(n);
    plan.GetName();
    plan.CreateDay();
}

int main()
{
    //also going to be a class:
    MainMenu();
    //...because it contains a linked list of plans, of course
    //every time this program is started, it creates (or loads) a main menu
    return 0;
}






