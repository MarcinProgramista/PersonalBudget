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

    income.setNumberOfRecord(fileWithIncomes.getIdLastNumberOfRecord()+1);

    fileWithIncomes.setIdLastNumberOfRecord(income.getNumberOfRecord());// tymczasowo!!!

    income.setUserId(ID_LOGGED_USER);

    income.setDate(takeTheDateFromUser());

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

    expense.setNumberOfRecord(fileWithExpenses.getIdLastNumberOfRecord()+1);
    fileWithExpenses.setIdLastNumberOfRecord(expense.getNumberOfRecord());

    expense.setUserId(ID_LOGGED_USER);

    expense.setDate(takeTheDateFromUser());

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
            date = checkingPositionDashesInDate(date);
        }
        while (isDateCorrect(date) != true);
        return HelperMethods::convertStringForInt(removeDashFromDate(date));
    }
}

string BalanceManager::checkingPositionDashesInDate(string dateToCheck)
{
    int longOfDate = dateToCheck.length();
    if (longOfDate == 10)
    {
        if ( dateToCheck[4] == 45 && dateToCheck[7] == 45)
            return dateToCheck;
    }
    else if (longOfDate == 9 )
    {
        if ( dateToCheck[4] == 45 && dateToCheck[7] == 45)
        {
            dateToCheck = dateToCheck.insert(8,"0");
            return dateToCheck;
        }
        else if ( dateToCheck[4] == 45 && dateToCheck[6] == 45)
        {
            dateToCheck = dateToCheck.insert(5,"0");
            return dateToCheck;
        }
    }
    else if (longOfDate == 8 )
    {
        if ( dateToCheck[4] == 45 && dateToCheck[6] == 45)
        {
            dateToCheck = dateToCheck.insert(5,"0");
            dateToCheck = dateToCheck.insert(8,"0");
            return dateToCheck;
        }
    }
}

bool BalanceManager::checkIfDateHasDigits(string dateToCheck)
{
    for (int i = 0; i < dateToCheck.length(); i++)
    {
        if (dateToCheck[i] > 57)
        {
            i =  dateToCheck.length();
            return true;
        }
    }
}

int BalanceManager::getYearFromDate(string dateToCheck)
{
    int year = HelperMethods::convertStringForInt(dateToCheck.erase(4,4));
    return year;
}

int BalanceManager::getMonthFromDate(string dateToCheck)
{
    int month;
    dateToCheck = dateToCheck.erase(0,4);
    month = HelperMethods::convertStringForInt(dateToCheck.erase(2,2));
     if (month > 12 )
        return 0;
    else
        return month;
}

int BalanceManager::getDayFromDate(string dateToCheck)
{
    int day;
    day = HelperMethods::convertStringForInt(dateToCheck.erase(0,6));
    if (day > 31 )
        return 0;
    else
        return day;
}

int BalanceManager::returnNumberDaysfromDate(string dateToCheck)
{
    switch(getMonthFromDate(dateToCheck))
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
    {

        if (((getYearFromDate(dateToCheck)%4 == 0) && (getYearFromDate(dateToCheck)%100 != 0)) || (getYearFromDate(dateToCheck)%400 == 0))
            return 29;
        else
            return 28;
    }
    break;

    default:
        return 0;
    }
}

string BalanceManager::getNameOfMonth(string dateToCheck)
{
    int monthFromDate = getMonthFromDate(dateToCheck);
    map<int,string> month;
    month[1] = "January";
    month[2] = "February";
    month[3] = "March";
    month[4] = "April";
    month[5] = "May";
    month[6] = "June";
    month[7] = "July";
    month[8] = "August";
    month[9] = "September";
    month[10] = "October";
    month[11] = "November";
    month[12] = "December";

    return month.find((int)monthFromDate) -> second;
}

bool BalanceManager::isDateCorrect(string dateToCheck)
{
    dateToCheck = removeDashFromDate(dateToCheck);
     if(checkIfDateHasDigits(dateToCheck))
    {
        cout << "Please type date with correct format: yyyy-mm-dd,exp 2019-01-02"  << endl;
        return false;
    }
    else if (getMonthFromDate(dateToCheck) == 0 && getDayFromDate(dateToCheck) == 0)
    {
        cout << "Month is not between 1 and 12, please put correct month"  << endl;
        cout << "Day is not between 1 and 31, please put correct day"  << endl;
        return false;
    }
    else if (getMonthFromDate(dateToCheck) == 0 && getDayFromDate(dateToCheck) != 0)
    {
         cout << "Month is not between 1 and 12, please put correct month"  << endl;
        return false;
    }
    else if (getMonthFromDate(dateToCheck) != 0 && getDayFromDate(dateToCheck) == 0)
    {
        cout << "Day is not between 1 and 31, please put correct day"  << endl;
        return false;
    }
    else if (returnNumberDaysfromDate(dateToCheck)< getDayFromDate(dateToCheck))
    {
        cout << getNameOfMonth(dateToCheck) <<" doesn't have, so many days "<< endl;
        return false;
    }
    else
        return true;
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

string  BalanceManager::putDashesToDate(string date)
{
    date = date.insert(4,"-");
    date = date.insert(7,"-");

    return date;
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

float BalanceManager::seeChoosenLinesFromIcomes()
{
    float sumAmountIncomes = 0;
    for (int i = 0;  i < incomes.size(); i++)
    {
        int monthFromSystem = getMonthFromDate(HelperMethods::convertIntForString(getTheDateFromSystem()));
        int monthItemFromVector = getMonthFromDate(HelperMethods::convertIntForString(incomes[i].getDate()));
        int yearFromSystem = getYearFromDate(HelperMethods::convertIntForString(getTheDateFromSystem()));
        int yearItemFromVector = getYearFromDate(HelperMethods::convertIntForString(incomes[i].getDate()));
        if((monthFromSystem == monthItemFromVector) && (yearFromSystem == yearItemFromVector))
        {
            cout << " " << putDashesToDate(HelperMethods::convertIntForString(incomes[i].getDate())) << "    " << incomes[i].getCategory();
            string category = incomes[i].getCategory();
            for (int j = 0 ; j < 24 - category.length(); j++)
                cout << " ";
            cout << incomes[i].getAmount()  << endl;
            sumAmountIncomes+= incomes[i].getAmount();
        }
    }
    cout << endl << "               SUM INCOMES:" << sumAmountIncomes << endl << endl;
    return sumAmountIncomes;
}

void BalanceManager::seeBalanceFromCurrentMonth()
{
    system("cls");
    sortIncomesAndExpenses();
    headerIncomes();
    float sumIcomes = seeChoosenLinesFromIcomes();
    headerExpenses();
    float sumExpenses = seeChoosenLinesFromExpenses();
    cout << "BALANCE b:" << sumIcomes << " - " << sumExpenses << " = " << sumIcomes - sumExpenses << endl;
    system("pause");
}

float BalanceManager::seeChoosenLinesFromExpenses()
{
    float sumAmountExpenses = 0;
    for (int i = 0;  i < expenses.size(); i++)
    {
        int monthFromSystem = getMonthFromDate(HelperMethods::convertIntForString(getTheDateFromSystem()));
        int monthItemFromVector = getMonthFromDate(HelperMethods::convertIntForString(expenses[i].getDate()));
        int yearFromSystem = getYearFromDate(HelperMethods::convertIntForString(getTheDateFromSystem()));
        int yearItemFromVector = getYearFromDate(HelperMethods::convertIntForString(expenses[i].getDate()));
        if((monthFromSystem == monthItemFromVector) && (yearFromSystem == yearItemFromVector))
        {
            cout << " " << putDashesToDate(HelperMethods::convertIntForString(expenses[i].getDate())) << "    " << expenses[i].getCategory();
            string category = expenses[i].getCategory();
            for (int j = 0 ; j < 24 - category.length(); j++)
                cout << " ";
            cout << expenses[i].getAmount()  << endl;
            sumAmountExpenses+= expenses[i].getAmount();
        }
    }
    cout << endl << "               SUM EXPENSES:" << sumAmountExpenses << endl << endl;
    return sumAmountExpenses;
}


