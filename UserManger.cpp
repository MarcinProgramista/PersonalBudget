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
            cout << "Wprowadzono 3 razy bledne haslo. "<< endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
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
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (isTheLoingExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
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
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
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
