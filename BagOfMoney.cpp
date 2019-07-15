#include "BagOfMoney.h"

void BagOfMoney::setNumberOfRecord(int newNumberOfRecord)
{
     if(newNumberOfRecord >= 0)
        numberOfRecord = newNumberOfRecord;
}

void BagOfMoney::setUserId(int newUserId)
{
    if(newUserId >= 0)
        userId = newUserId;
}

void BagOfMoney::setDate(int newDate)
{
    date = newDate;
}

void BagOfMoney::setCategory(string newCategory)
{
    category = newCategory;
}

void BagOfMoney::setAmount(float newAmount)
{
    amount = newAmount;
}

int BagOfMoney::getNumberOfRecord()
{
     return numberOfRecord;
}

int BagOfMoney::getUserId()
{
    return userId;
}

int BagOfMoney::getDate()
{
    return date;
}

string BagOfMoney::getCategory()
{
    return category;
}

float BagOfMoney::getAmount()
{
    return amount;
}
