#include <iostream>
#include <windows.h>
#include "UserManger.h"


using namespace std;

int main()
{
    UserManager userManger("users.xml");

    userManger.registrationUser();

    userManger.writeOutAllUsers();
    return 0;
}
