#include "UserManger.h"

void UserManager::registrationUser()
{
    User user = giveDataNewUser();
    users.push_back(user);
    //fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
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
