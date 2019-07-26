#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H
#include "Income.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

class BalanceManager
{
    const int ID_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Income putDetailsNewIncome();
    Expense putDetailsNewExpense();

    bool isDateCorrect(string dateToCheck);
    string removeDashFromDate(string dateToCheck);
    int getTheDateFromSystem();
    int takeTheDateFromUser();

public:
    BalanceManager(string fileNameWithIncomes,string fileNameWithExpenses, int idLoggedUser)
    : fileWithIncomes(fileNameWithIncomes),fileWithExpenses(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser)
    {
        incomes = fileWithIncomes.loadIncomesLoggedUserFromFile(ID_LOGGED_USER);
        expenses = fileWithExpenses.loadExpensesLoggedUserFromFile(ID_LOGGED_USER);
    };

    void addIncome();
    void addExpense();
    void seeIncomes();
    void seeExpenses();
};
#endif // BALANCEMANAGER_H
