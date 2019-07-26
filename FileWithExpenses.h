#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "TextFile.h"
#include "Expense.h"
#include "HelperMethods.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses: public TextFile
{
    CMarkup xml;
    int idLastNumberOfRecord;
   // Income downloadIncome();


 public:
    FileWithExpenses(string fileNameWithExpenses): TextFile(fileNameWithExpenses){
        idLastNumberOfRecord = 0;
    };
   int getIdLastNumberOfRecord();
   void setIdLastNumberOfRecord(int newIdLastNumberOfRecord);
   void addExpenseToFile(Expense expense);
   // vector <Income> loadIncomesLoggedUserFromFile(int idLoggedUser);
};


#endif
