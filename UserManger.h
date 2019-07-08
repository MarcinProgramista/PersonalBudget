#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUers;
    User giveDataNewUser();
    int downloadIdNewUser();
    bool isTheLoingExist(string login);

public:
    UserManager(string nameFileWithUsers):fileWithUers(nameFileWithUsers){
        idLoggedUser = 0;
        users = fileWithUers.downloadUsersFromFile();
    };
    void registrationUser();
    void writeOutAllUsers();
};

#endif // USERMANAGER_H
