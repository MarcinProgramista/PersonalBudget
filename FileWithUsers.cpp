#include "FileWithUsers.h"

vector <User> FileWithUsers::downloadUsersFromFile()
{
    User user;
    vector <User> users;

    bool fileExists = xml.Load( getNameFile());
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

void FileWithUsers::addUserToFile(User user)
{
    bool fileExists = xml.Load( getNameFile() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", HelperMethods::convertIntForString(user.getId()));
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.Save(getNameFile());
}

void FileWithUsers::saveAllUsersToFile(int idLoggedUser, string password)
{
    vector <User> users = downloadUsersFromFile();

    deleteFile(getNameFile());

    bool fileExists = xml.Load( getNameFile());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();

    for (int i = 0; i < users.size(); i++)
    {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", HelperMethods::convertIntForString(users[i].getId()));
        xml.AddElem("Login", users[i].getLogin());
        if (users[i].getId() == idLoggedUser )
        {
            xml.AddElem("Password", password);
        }
        else
        {
            xml.AddElem("Password", users[i].getPassword());
        }
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());
                    xml.OutOfElem();
    }
    xml.Save(getNameFile());
}

void FileWithUsers::deleteFile(string nameFileToDelete)
{
    if (remove(nameFileToDelete.c_str()) == 0) {}
    else
        cout << "There is no possible to delete file " << nameFileToDelete << endl;
}
