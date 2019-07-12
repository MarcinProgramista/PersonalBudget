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
    cout << "9. Finish work" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice : ";
    choose = HelperMethods::putTheSign();

    return choose;
}
