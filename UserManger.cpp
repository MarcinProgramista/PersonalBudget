#include "UserManger.h"

int UserManager::getIdLoggedUser()
{
    return idLoggedUser;
}

void UserManager::registrationUser()
{
    User user = giveDataNewUser();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::logInUser()
{
    User user;
    string login = "", password = "";
    cout << endl << "Write login: ";
    login = HelperMethods::loadTheLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int amountOfTry = 3; amountOfTry > 0; amountOfTry--)
            {
                cout << "Give password. There remind : " << amountOfTry << " attempts : ";
                password = HelperMethods::loadTheLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    idLoggedUser = itr -> getId();
                    system("pause");
                    return;
                }
            }
            cout << "Three time put wrong password. "<< endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with such a login" << endl << endl;
    system("pause");
    return;
}

User UserManager::giveDataNewUser()
{
    User user;
    user.setId(downloadIdNewUser());
    string login;
    do
    {
        cout << "Give login: ";
        cin >> login;
        user.setLogin(login);
    } while (isTheLoingExist(user.getLogin()) == true);

    string password;
    cout << "Give password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Give name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Give surname: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

void UserManager::changePasswordLogged()
{
    if(idLoggedUser > 0)
    {
        string newPassword = "";
        cout << "Give new password: ";
        newPassword = HelperMethods::loadTheLine();
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if (itr -> getId() == idLoggedUser)
            {
                itr -> setPassword(newPassword);
                cout << "Password was changed." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveAllUsersToFile(idLoggedUser,newPassword);
    }
    else
    {
        cout << "To change password - you have to be logged in." << endl;
        system("pause");
    }
}

int UserManager::downloadIdNewUser()
{
if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isTheLoingExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "There is such a user with this login." << endl;
            return true;
        }
    }
    return false;
}


void UserManager::writeOutAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout <<  users[i].getId() << endl;
        cout <<  users[i].getLogin() << endl;
        cout <<  users[i].getPassword() << endl;
        cout <<  users[i].getName() << endl;
        cout <<  users[i].getSurname() << endl;
    }
}

void UserManager::logOutUser()
{
    idLoggedUser = 0;
}

bool UserManager::isUserLoggedIn()
{
    if (idLoggedUser > 0)
        return true;
    else
        return false;
}
