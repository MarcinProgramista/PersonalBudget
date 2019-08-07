#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"


using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml","incomes.xml","expenses.xml");
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
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.balanceFromCurrentMonth(choice);
                break;
            case '4':
                personalBudget.balanceFromLastMonth(choice);
                break;
            case '5':
                personalBudget.balanceFromChoosenPeriod(choice);
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
