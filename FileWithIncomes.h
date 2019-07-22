#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "TextFile.h"
#include "Income.h"
#include "HelperMethods.h"

using namespace std;

class FileWithIncomes: public TextFile
{
     int idLastNumberOfRecord;

 public:
    FileWithIncomes(string fileNameWithIncomes): TextFile(fileNameWithIncomes){
        idLastNumberOfRecord = 0;
    };
    int getIdLastNumberOfRecord();
    void setIdLastNumberOfRecord(int newIdLastNumberOfRecord);
};


#endif // FILEWITHINCOMES_H
