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
    User giveDataNewUser();
    int downloadIdNewUser();
    bool isTheLoingExist(string login);

public:
    UzytkownikMenedzer(){
        idLoggedUser = 0;
    };
    void registrationUser();
    void writeOutAllUsers();
};

#endif // USERMANAGER_H
