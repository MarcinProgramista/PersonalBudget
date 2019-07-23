#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
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
    int idLastNumberOfRecord;

 public:
    FileWithIncomes(string fileNameWithIncomes): TextFile(fileNameWithIncomes){
        idLastNumberOfRecord = 0;
    };
    int getIdLastNumberOfRecord();
    void setIdLastNumberOfRecord(int newIdLastNumberOfRecord);
    void addIncomeToFile(Income income);
};


#endif // FILEWITHINCOMES_H
