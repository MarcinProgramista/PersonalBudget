#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <windows.h>
#include "BagOfMoney.h"
#include "UserManger.h"

using namespace std;

class Income: public BagOfMoney
{


public:
    Income(int numberOfRecord = 0, int userId = 0, int date = 0, string category = "",  float amount = 0)
    :BagOfMoney (numberOfRecord, userId, date, category, amount)
    {
       // idLastNumberOfRecord = 0;
    };



};

#endif
