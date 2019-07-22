#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManger.h"
#include "HelperMethods.h"
#include "BalanceManager.h"

class PersonalBudget
{
    UserManager userManager;
    BalanceManager *balanceManager;
    const string FILE_NAME_WITH_INCOMES;

public:
    PersonalBudget(string nameFileWithUsers, string fileNameWithIncomes):userManager(nameFileWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes)
    {
        balanceManager = NULL;
    };
    ~PersonalBudget()
    {
        delete balanceManager;
        balanceManager = NULL;
    }
    void registrationUser();
    void logInUser();
    void logOutUser();
    void changePasswordLogged();
    void writeOutAllUsers();
    bool isUserLogged();
    void addIncome();
    char chooseOpctionFromMainMenu();
    char chooseOpctionFormUserMenu();
};

#endif // PERSONALBUDGET_H
