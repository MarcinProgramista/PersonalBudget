#include <iostream>
#include <windows.h>
#include "UserManger.h"


using namespace std;

int main()
{
    UserManager userManger;
    userManger.registrationUser();
    userManger.registrationUser();
    userManger.writeOutAllUsers();
    return 0;
}
