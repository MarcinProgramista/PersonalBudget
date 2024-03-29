#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H
#include "Income.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Date.h"
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <iostream>
#include <map>
#include <windows.h>
#include <cstdlib>

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

    void headerIncomes();
    void headerExpenses();
    float seeChoosenLinesFromIcomes(char choice, int dateFrom,int dateTill);
    float seeChoosenLinesFromExpenses(char choice, int dateFrom,int dateTill);
    void sortIncomesAndExpenses();
    float writeOutExpenses(int i, float sumAmountExpenses);
    float writeOutIncomes(int i, float sumAmountIncomes);

public:
    BalanceManager(string fileNameWithIncomes,string fileNameWithExpenses, int idLoggedUser)
    : fileWithIncomes(fileNameWithIncomes),fileWithExpenses(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser)
    {
        incomes = fileWithIncomes.loadIncomesLoggedUserFromFile(ID_LOGGED_USER);
        expenses = fileWithExpenses.loadExpensesLoggedUserFromFile(ID_LOGGED_USER);
    };

    void addIncome();
    void addExpense();
    void seeBalance(char choice);
};
#endif // BALANCEMANAGER_H
