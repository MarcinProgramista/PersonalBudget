#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManger.h"
#include "HelperMethods.h"

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget(string nameFileWithUsers):userManager(nameFileWithUsers)
    {

    };
    void registrationUser();
    void logInUser();
    void logOutUser();
    void writeOutAllUsers();
    bool isUserLogged();
    char chooseOpctionFromMainMenu();
    char chooseOpctionFormUserMenu();
};

#endif // PERSONALBUDGET_H
