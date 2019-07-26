#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "TextFile.h"
#include "Income.h"
#include "HelperMethods.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes: public TextFile
{
    CMarkup xml;
    Income downloadIncome();
    int idLastNumberOfRecord;

 public:
    FileWithIncomes(string fileNameWithIncomes): TextFile(fileNameWithIncomes){
        idLastNumberOfRecord = 0;
    };
    int getIdLastNumberOfRecord();
    void setIdLastNumberOfRecord(int newIdLastNumberOfRecord);
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesLoggedUserFromFile(int idLoggedUser);
};
#endif // FILEWITHINCOMES_H
