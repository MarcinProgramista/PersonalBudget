#include "HelperMethods.h"

string HelperMethods::convertIntForString(int figure)
{
    ostringstream ss;
    ss << figure;
    string str = ss.str();
    return str;
}
