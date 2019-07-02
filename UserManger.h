#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"

using namespace std;

class UserManager
{
    int idLoggedUser;
    vector <User> users;
};

#endif // USERMANAGER_H
