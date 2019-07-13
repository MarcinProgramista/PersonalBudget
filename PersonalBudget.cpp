#include "PersonalBudget.h"

void PersonalBudget::writeOutAllUsers()
{
    userManager.writeOutAllUsers();
}

void PersonalBudget::registrationUser()
{
    userManager.registrationUser();
}

void PersonalBudget::logInUser()
{
    userManager.logInUser();
}

bool PersonalBudget::isUserLogged()
{
    if (userManager.getIdLoggedUser() > 0)
        return true;
    else
        return false;
}

char PersonalBudget::chooseOpctionFromMainMenu()
{
    char choose;

    system("cls");
    cout << "    >>>  MAIN MENU  <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log in" << endl;
    cout << "8. Finish work" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice : ";
    choose = HelperMethods::putTheSign();

    return choose;
}

char PersonalBudget::chooseOpctionFormUserMenu()
{
    char choose;

    system("cls");
    cout << " >>> USERS'S MENU <<<" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from this month" << endl;
    cout << "4. Balance from last month" << endl;
    cout << "5. Balance from choosen period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change the password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = HelperMethods::putTheSign();

    return choose;
}
