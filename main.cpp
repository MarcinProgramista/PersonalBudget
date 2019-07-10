#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"


using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    char choice;
    while (true)
    {
        if (personalBudget.isUserLogged()== false)
        {
            choice = personalBudget.chooseOpctionFromMainMenu();
        }
    }


    return 0;
}
