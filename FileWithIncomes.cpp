#include "FileWithIncomes.h"

int FileWithIncomes::getIdLastNumberOfRecord()
{
    return idLastNumberOfRecord;
}

void FileWithIncomes::setIdLastNumberOfRecord(int newIdLastNumberOfRecord)
{
    idLastNumberOfRecord = newIdLastNumberOfRecord;
}

void FileWithIncomes::addIncomeToFile(Income income)
{
    bool fileExists = xml.Load(getNameFile());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("NumberOfRecord", HelperMethods::convertIntForString(income.getNumberOfRecord()));
    xml.AddElem("UserId", HelperMethods::convertIntForString(income.getUserId()));
    xml.AddElem("Date", HelperMethods::putDashesInDate(HelperMethods::convertIntForString(income.getDate())));
    xml.AddElem("Category", income.getCategory());
    xml.AddElem("Amount", HelperMethods::convertFloatForString(income.getAmount()));
    xml.Save(getNameFile());
}

 vector <Income> FileWithIncomes::loadIncomesLoggedUserFromFile(int idLoggedUser)
 {
    Income income;
    vector <Income> incomes;

    bool fileExists = xml.Load( getNameFile());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    MCD_STR buffor;
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        income = downloadIncome();
        if (income.getUserId() == idLoggedUser)
        {
            incomes.push_back(income);
        }
        xml.ResetMainPos();
        xml.FindElem("NumberOfRecord");
        buffor = xml.GetData();
        xml.OutOfElem();
    }

    idLastNumberOfRecord = atoi(buffor.c_str());

    xml.OutOfElem();
    xml.Save(getNameFile());


    return incomes;
 }

Income FileWithIncomes::downloadIncome()
{
    Income income;
    MCD_STR numberOfRecord, userId, date, category, amount;

    xml.IntoElem();
    xml.FindElem("NumberOfRecord");
    numberOfRecord = xml.GetData();
    income.setNumberOfRecord(atoi(numberOfRecord.c_str()));

    xml.FindElem("UserId");
    userId = xml.GetData();
    income.setUserId(atoi(userId.c_str()));

    xml.FindElem("Date");
    date = xml.GetData();
    date = HelperMethods::removeDashFromDate(date);
    income.setDate(atoi(date.c_str()));

    xml.FindElem("Category");
    category = xml.GetData();
    income.setCategory(category);

    xml.FindElem("Amount");
    amount = xml.GetData();
    amount = HelperMethods::checkAmount(amount);
    income.setAmount(atof(amount.c_str()));

    return income;
}
