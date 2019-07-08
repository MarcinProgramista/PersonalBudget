#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>

#include "HelperMethods.h"
#include "User.h"
#include "TextFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers: public TextFile
{
    CMarkup xml;
    User downloadUser();

public:
    FileWithUsers(string nameFileWithUsers):TextFile(nameFileWithUsers){};
    vector <User> downloadUsersFromFile();
    void addUserToFile(User user);
};

#endif // FILEWITHUSERS_H
