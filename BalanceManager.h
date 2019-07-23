#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H
#include "Income.h"
#include "FileWithIncomes.h"
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
    FileWithIncomes fileWithIncomes;
    Income putDetailsNewIncome();
    bool isDateCorrect(string dateToCheck);
    string removeDashFromDate(string dateToCheck);
    int getTheDateFromSystem();
    int takeTheDateFromUser();

public:
    BalanceManager(string fileNameWithIncomes, int idLoggedUser)
    : fileWithIncomes(fileNameWithIncomes), ID_LOGGED_USER(idLoggedUser)
    {
        incomes = fileWithIncomes.loadIncomesLoggedUserFromFile(ID_LOGGED_USER);
    };

    void addIncome();
    void seeIncomes();
};
#endif // BALANCEMANAGER_H
