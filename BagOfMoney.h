#ifndef BAGOFMONEY_H
#define BAGOFMONEY_H
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class BagOfMoney
{
    int numberOfRecord;
    int userId;
    int date;
    string category;
    float amount;

public:
    BagOfMoney (int numberOfRecord = 0, int userId = 0, int date = 0, string category = "",  float amount = 0)
    {
        this -> numberOfRecord = numberOfRecord;
        this -> userId = userId;
        this -> date = date;
        this -> category = category;
        this -> amount = amount;
    }
    void setNumberOfRecord(int newNumberOfRecord);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setCategory(string newCategory);
    void setAmount(float newAmount);


    int getNumberOfRecord();
    int getUserId();
    int getDate();
    string getCategory();
    float getAmount();

    bool operator < (const BagOfMoney& str) const;
};

#endif
