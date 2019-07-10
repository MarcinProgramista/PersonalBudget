#include "PersonalBudget.h"

void PersonalBudget::writeOutAllUsers()
{
    userManager.writeOutAllUsers();
}

bool PersonalBudget::isUserLogged()
{
    if (userManager.getIdLoggedUser() > 0)
        return true;
    else
        return false;
}
