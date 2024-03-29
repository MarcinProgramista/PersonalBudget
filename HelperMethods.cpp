#include "HelperMethods.h"

string HelperMethods::convertIntForString(int figure)
{
    ostringstream ss;
    ss << figure;
    string str = ss.str();
    return str;
}

int HelperMethods::convertStringForInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}


string HelperMethods::loadTheLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char HelperMethods::putTheSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "It is no single sign. Put again sign." << endl;
    }
    return sign;
}

string HelperMethods::removeDashFromDate(string dateToCheck)
{
    string dateWithoutDash;
    dateWithoutDash = dateToCheck.erase(4,1);
    dateWithoutDash = dateToCheck.erase(6,1);

    return dateWithoutDash;
}

string HelperMethods::putDashesInDate(string dateWithoutDashes)
{
    dateWithoutDashes.insert(4,"-");
    dateWithoutDashes.insert(7,"-");

    return dateWithoutDashes;
}

string HelperMethods::convertFloatForString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::checkAmount(string floatNumber)
{
    for (int i = 0; i < floatNumber.length(); i++)
    {
        if (floatNumber[i] == 44)
        {
            floatNumber[i] = 46;
        }
    }
    return floatNumber;
}
