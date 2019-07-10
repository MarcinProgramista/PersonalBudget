#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"


using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    char wybor;
    while (true)
    {
        if (personalBudget.isUserLogged()== false)
        {

        }
    }


    return 0;
}
