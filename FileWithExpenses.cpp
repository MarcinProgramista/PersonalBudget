#include "FileWithExpenses.h"

int FileWithExpenses::getIdLastNumberOfRecord()
{
    return idLastNumberOfRecord;
}

void FileWithExpenses::setIdLastNumberOfRecord(int newIdLastNumberOfRecord)
{
    idLastNumberOfRecord = newIdLastNumberOfRecord;
}

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    bool fileExists = xml.Load(getNameFile());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("NumberOfRecord", HelperMethods::convertIntForString(expense.getNumberOfRecord()));
    xml.AddElem("UserId", HelperMethods::convertIntForString(expense.getUserId()));
    xml.AddElem("Date", HelperMethods::putDashesInDate(HelperMethods::convertIntForString(expense.getDate())));
    xml.AddElem("Category", expense.getCategory());
    xml.AddElem("Amount", HelperMethods::convertFloatForString(expense.getAmount()));
    xml.Save(getNameFile());
}

vector <Expense> FileWithExpenses::loadExpensesLoggedUserFromFile(int idLoggedUser)
{
    Expense expense;
    vector <Expense> expenses;

    bool fileExists = xml.Load( getNameFile());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    MCD_STR buffor;
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        expense = downloadExpense();
        if (expense.getUserId() == idLoggedUser)
        {
            expenses.push_back(expense);
        }
        xml.ResetMainPos();
        xml.FindElem("NumberOfRecord");
        buffor = xml.GetData();
        xml.OutOfElem();
    }

    idLastNumberOfRecord = atoi(buffor.c_str());

    xml.OutOfElem();
    xml.Save(getNameFile());

    for (int i = 0;  i < expenses.size(); i++)
    {
        cout << "Number of record:     " << expenses[i].getNumberOfRecord() << endl;
        cout << "Id logged user:       " << expenses[i].getUserId() << endl;
        cout << "Date:                 " << expenses[i].getDate() << endl;
        cout << "Category:             " << expenses[i].getCategory() << endl;
        cout << "Amount:               " << expenses[i].getAmount() << endl;
    }

    system("pause");
    return expenses;
}

Expense FileWithExpenses::downloadExpense()
{
    Expense expense;
    MCD_STR numberOfRecord, userId, date, category, amount;

    xml.IntoElem();
    xml.FindElem("NumberOfRecord");
    numberOfRecord = xml.GetData();
    expense.setNumberOfRecord(atoi(numberOfRecord.c_str()));

    xml.FindElem("UserId");
    userId = xml.GetData();
    expense.setUserId(atoi(userId.c_str()));

    xml.FindElem("Date");
    date = xml.GetData();
    date = HelperMethods::removeDashFromDate(date);
    expense.setDate(atoi(date.c_str()));

    xml.FindElem("Category");
    category = xml.GetData();
    expense.setCategory(category);

    xml.FindElem("Amount");
    amount = xml.GetData();
    expense.setAmount(atof(amount.c_str()));

    return expense;
}
