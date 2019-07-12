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
            switch (choice)
            {
            case '1':
                personalBudget.registrationUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such a option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }


    return 0;
}
