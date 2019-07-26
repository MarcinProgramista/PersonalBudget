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
