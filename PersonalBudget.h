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
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string nameFileWithUsers, string fileNameWithIncomes, string fileNameWithExpenses):userManager(nameFileWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
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
    void addExpense();
    char chooseOpctionFromMainMenu();
    char chooseOpctionFormUserMenu();
    void balanceFromCurrentMonth(char choice);
    void balanceFromLastMonth(char choice);
    void balanceFromChoosenPeriod(char choice);
};

#endif // PERSONALBUDGET_H
