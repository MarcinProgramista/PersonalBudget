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
    xml.AddElem("Icome");
    xml.IntoElem();
    xml.AddElem("NumberOfRecord", HelperMethods::convertIntForString(income.getNumberOfRecord()));
    xml.AddElem("UserId", HelperMethods::convertIntForString(income.getUserId()));
    xml.AddElem("Date", HelperMethods::putDashesInDate(HelperMethods::convertIntForString(income.getDate())));
    xml.AddElem("Category", income.getCategory());
    xml.AddElem("Amount", HelperMethods::convertFloatForString(income.getAmount()));
    xml.Save(getNameFile());
}
