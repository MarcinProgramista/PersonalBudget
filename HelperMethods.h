#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class HelperMethods
{
public:
    static string convertIntForString(int  figure);
    static char putTheSign();
    static string loadTheLine();
    static int convertStringForInt(string number);
};
#endif
