#include "FileWithUsers.h"

vector <User> FileWithUsers::downloadUsersFromFile()
{
    User user;
    vector <User> users;

    bool fileExists = xml.Load( "users.xml" );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        user = downloadUser();
        users.push_back(user);
    }
    xml.OutOfElem();

    return users;
}

User FileWithUsers::downloadUser()
{
    User user;
    MCD_STR id, login, password, name, surname;
    xml.IntoElem();
    xml.FindElem("UserId");
    id = xml.GetData();
    user.setId(atoi(id.c_str()));

    xml.FindElem("Login");
    login = xml.GetData();
    user.setLogin(login);

    xml.FindElem("Password");
    password = xml.GetData();
    user.setPassword(password);

    xml.FindElem("Name");
    name = xml.GetData();
    user.setName(name);

    xml.FindElem("Surname");
    surname = xml.GetData();
    user.setSurname(surname);

    xml.OutOfElem();

    return user;

}
