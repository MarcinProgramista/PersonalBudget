#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"


using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    char choice;
    while (true)
    {
        if (personalBudget.isUserLogged()== false)
        {
            choice = personalBudget.chooseOpctionFromMainMenu();
            switch (choice)
            {
            case '1':
                personalBudget.registrationUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '8':
                exit(0);
                break;
            default:
                cout << endl << "There is no such a option in menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.chooseOpctionFormUserMenu();
            switch (choice)
            {
            case '1':
                //ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                //ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}
