#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"


using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    char wybor;

    personalBudget.writeOutAllUsers();

    return 0;
}
