#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>

#include "UserManger.h"
#include "HelperMethods.h"

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget(string nameFileWithUsers):userManager(nameFileWithUsers)
    {

    };
    void writeOutAllUsers();
};

#endif // PERSONALBUDGET_H
