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
    FileWithUsers fileWithUsers;
    User giveDataNewUser();
    int downloadIdNewUser();
    bool isTheLoingExist(string login);

public:
    UserManager(string nameFileWithUsers):fileWithUsers(nameFileWithUsers){
        idLoggedUser = 0;
        users = fileWithUsers.downloadUsersFromFile();
    };
    void registrationUser();
    void logInUser();
    void writeOutAllUsers();
    int getIdLoggedUser();
    void logOutUser();
};

#endif // USERMANAGER_H
