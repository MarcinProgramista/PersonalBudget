#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>

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
};

#endif // FILEWITHUSERS_H
