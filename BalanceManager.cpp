#include "BalanceManager.h"

void  BalanceManager:: sortIncomesAndExpenses()
{
    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());
}

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
    Date date;
    income.setNumberOfRecord(fileWithIncomes.getIdLastNumberOfRecord()+1);

    fileWithIncomes.setIdLastNumberOfRecord(income.getNumberOfRecord());// tymczasowo!!!

    income.setUserId(ID_LOGGED_USER);

    income.setDate(date.takeTheDateFromUser());

    string category;
    cout << "Put the category: " ;
    category = HelperMethods::loadTheLine();
    income.setCategory(category);

    string amount;
    cout << "Put amount: ";
    cin >> amount;
    amount = HelperMethods::checkAmount(amount);
    income.setAmount(atof(amount.c_str()));

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

    cout << "New expense was added " << endl;
    system("pause");
}

Expense BalanceManager::putDetailsNewExpense()
{
    Expense expense;
    Date date;
    expense.setNumberOfRecord(fileWithExpenses.getIdLastNumberOfRecord()+1);
    fileWithExpenses.setIdLastNumberOfRecord(expense.getNumberOfRecord());

    expense.setUserId(ID_LOGGED_USER);

    expense.setDate(date.takeTheDateFromUser());

    string category;
    cout << "Put the category: " ;
    category = HelperMethods::loadTheLine();
    expense.setCategory(category);

    string amount;
    cout << "Put amount: ";
    cin >> amount;
    amount = HelperMethods::checkAmount(amount);
    expense.setAmount(atof(amount.c_str()));

    return expense;
}

void BalanceManager::headerIncomes()
{
    cout << "***************************************************" << endl;
    cout << "*                  INCOMES                        *" << endl;
    cout << "***************************************************" << endl;
    cout << "*     DATE    *    Category           *  AMOUNT   *" << endl;
    cout << "***************************************************" << endl;
}
void BalanceManager::headerExpenses()
{
    cout << "***************************************************" << endl;
    cout << "*                 EXPENSES                        *" << endl;
    cout << "***************************************************" << endl;
    cout << "*     DATE    *    Category           *  AMOUNT   *" << endl;
    cout << "***************************************************" << endl;
}

float BalanceManager::writeOutExpenses(int i, float sumAmountExpenses)
{
    Date date;
    cout << " " << date.putDashesToDate(HelperMethods::convertIntForString(expenses[i].getDate())) << "    " << expenses[i].getCategory();
    string category = expenses[i].getCategory();
    for (int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";
    cout << expenses[i].getAmount()  << endl;
    sumAmountExpenses+= expenses[i].getAmount();
    return sumAmountExpenses;
}

float BalanceManager::writeOutIncomes(int i, float sumAmountIncomes)
{
    Date date;
    cout << " " << date.putDashesToDate(HelperMethods::convertIntForString(incomes[i].getDate())) << "    " << incomes[i].getCategory();
    string category = incomes[i].getCategory();
    for (int j = 0 ; j < 24 - category.length(); j++)
        cout << " ";
    cout << incomes[i].getAmount()  << endl;
    sumAmountIncomes+= incomes[i].getAmount();
    return sumAmountIncomes;
}

float BalanceManager::seeChoosenLinesFromIcomes(char choice, int dateFrom,int dateTill )
{
    float sumAmountIncomes = 0;
    for (int i = 0;  i < incomes.size(); i++)
    {
        if((incomes[i].getDate() >= dateFrom ) && (incomes[i].getDate() <= dateTill) )
        {
            sumAmountIncomes = writeOutIncomes(i,sumAmountIncomes);
        }
    }
    cout << endl << "               SUM INCOMES:" << sumAmountIncomes << endl << endl;
    return sumAmountIncomes;
}

float BalanceManager::seeChoosenLinesFromExpenses(char choice, int dateFrom,int dateTill )
{
    float sumAmountExpenses = 0;
    for (int i = 0;  i < expenses.size(); i++)
    {
        if((expenses[i].getDate() >= dateFrom ) && (expenses[i].getDate() <= dateTill) )
        {
            sumAmountExpenses = writeOutExpenses(i,sumAmountExpenses);
        }
    }
    cout << endl << "               SUM EXPENSES:" << sumAmountExpenses << endl << endl;
    return sumAmountExpenses;
}

void BalanceManager::seeBalance(char choice)
{
    system("cls");
    Date date;
    sortIncomesAndExpenses();
    int dateFrom = date.setStartDate(choice);
    int dateTill = date.setEndDate(choice);
    system("cls");

    headerIncomes();
    float sumIncomes = seeChoosenLinesFromIcomes(choice, dateFrom, dateTill);

    headerExpenses();
    float sumExpenses = seeChoosenLinesFromExpenses(choice, dateFrom, dateTill);

    cout << "BALANCE: " << sumIncomes << " - " << sumExpenses << " = " << sumIncomes - sumExpenses << endl;

    system("pause");
}
