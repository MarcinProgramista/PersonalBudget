#include <iostream>
#include <stdlib.h>
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
            case '8':
                exit(0);
                break;
            default:
                cout << endl << "There is no such a option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.chooseOpctionFormUserMenu();
            switch (choice)
            {
            case '1':
                {
                    float d;
                    string a = "265.56";
                    d = atof(a.c_str());
                    cout << d / 2 << endl;
                    system("pause");
                }
                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                personalBudget.changePasswordLogged();
                break;
            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }
    return 0;
}
