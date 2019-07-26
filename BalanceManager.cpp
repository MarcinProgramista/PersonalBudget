#include "BalanceManager.h"

void BalanceManager::addIncome()
 {
    Income income;
    system("cls");
    cout << " >>> ADD NEW INCOME <<<" << endl << endl;

    income = putDetailsNewIncome();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << "New income was added " << endl;
    system("pause");
}

Income BalanceManager::putDetailsNewIncome()
{
    Income income;

    income.setNumberOfRecord(fileWithIncomes.getIdLastNumberOfRecord()+1);

    fileWithIncomes.setIdLastNumberOfRecord(income.getNumberOfRecord());// tymczasowo!!!

    income.setUserId(ID_LOGGED_USER);

    income.setDate(takeTheDateFromUser());

    string category;
    cout << "Put the category: " ;
    category = HelperMethods::loadTheLine();
    income.setCategory(category);

    float amount;
    cout << "Put amount: ";
    cin >> amount;
    income.setAmount(amount);

    return income;
}

void BalanceManager::addExpense()
{
    Expense expense;
    system("cls");
    cout << " >>> ADD NEW EXPENSE <<<" << endl << endl;

    expense = putDetailsNewExpense();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);

    seeExpenses();

    cout << "New expense was added " << endl;
    system("pause");
}

Expense BalanceManager::putDetailsNewExpense()
{
    Expense expense;

    expense.setNumberOfRecord(fileWithExpenses.getIdLastNumberOfRecord()+1);
    fileWithExpenses.setIdLastNumberOfRecord(expense.getNumberOfRecord());

    expense.setUserId(ID_LOGGED_USER);

    expense.setDate(takeTheDateFromUser());

    string category;
    cout << "Put the category: " ;
    category = HelperMethods::loadTheLine();
    expense.setCategory(category);

    float amount;
    cout << "Put amount: ";
    cin >> amount;
    expense.setAmount(amount);

    return expense;
}

int BalanceManager::takeTheDateFromUser()
{
    char sign;
    string date;

    cout << "Choose option dates: "<< endl;
    cout << "1. Take date from today  " << endl;
    cout << "2. Take date from other day  " << endl;
    sign = HelperMethods::putTheSign();
    if (sign == '1')
    {
       return getTheDateFromSystem();
    }
    else if  (sign == '2')
    {
        do
        {
            cout << "Put date: ";
            date = HelperMethods::loadTheLine();
        }
        while (isDateCorrect(date) != true);
        return HelperMethods::convertStringForInt(removeDashFromDate(date));
    }
}

bool BalanceManager::isDateCorrect(string dateToCheck)
{
     if((dateToCheck[4] == 45) && (dateToCheck[7] == 45) )
    {
        return true;
    }
    else
    {
        cout << "Please type date with correct format: yyyy-mm-dd"  << endl;
        return false;
    }
}

string BalanceManager::removeDashFromDate(string dateToCheck)
{
    string dateWithoutDash;
    dateWithoutDash = dateToCheck.erase(4,1);
    dateWithoutDash = dateToCheck.erase(6,1);

    return dateWithoutDash;
}

int BalanceManager::getTheDateFromSystem()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    string year = HelperMethods::convertIntForString(now->tm_year + 1900);
    string month = HelperMethods::convertIntForString(now->tm_mon + 1);
    string day = HelperMethods::convertIntForString(now->tm_mday);

    if ( month.size() == 1)
        month = "0" + month;

    if ( day.size() == 1)
        day = "0" + day;

    return HelperMethods::convertStringForInt(year + month + day);
}

void BalanceManager::seeIncomes()
{
    for (int i = 0;  i < incomes.size(); i++)
    {
        cout << "Number of record:     " << incomes[i].getNumberOfRecord() << endl;
        cout << "Id logged user:       " << incomes[i].getUserId() << endl;
        cout << "Date:                 " << incomes[i].getDate() << endl;
        cout << "Category:             " << incomes[i].getCategory() << endl;
        cout << "Amount:               " << incomes[i].getAmount() << endl;
    }
    system("pause");
}

void BalanceManager::seeExpenses()
{
    for (int i = 0;  i < expenses.size(); i++)
    {
        cout << "Number of record:     " << expenses[i].getNumberOfRecord() << endl;
        cout << "Id logged user:       " << expenses[i].getUserId() << endl;
        cout << "Date:                 " << expenses[i].getDate() << endl;
        cout << "Category:             " << expenses[i].getCategory() << endl;
        cout << "Amount:               " << expenses[i].getAmount() << endl;
    }
    system("pause");

}
