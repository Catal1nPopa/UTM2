#include <conio.h>
#include <iostream>
using namespace std;

// bauturi, alimente - magazin

class bauturi
{
public:
    string name_bautura;
    int price_bautura;
    bauturi()
    {
        cout << "\nIntroduceti denumirea bauturii: \n";
        cin >> name_bautura;

        cout << "\nIntroduceti pretul: \n";
        cin >> price_bautura;
    }

    void afisare1()
    {
        cout << "\nDenumirea bauturii: \n" << name_bautura;
        cout << "\nPretul bauturii: \n" << price_bautura;
    }
};

class alimente
{
public:
    string name_alimente;
    int price_alimente;

    alimente()
    {
        cout << "\nIntroduceti denumirea produsului: \n";
        cin >> name_alimente;

        cout << "\nIntroduceti pretul: \n";
        cin >> price_alimente;
    }

    void afisare2()
    {
        cout << "\nDenumirea produsului: \n" << name_alimente;
        cout << "\nPretul produsului: \n" << price_alimente;
    }
};

class magazin : public bauturi, public alimente
{
public:

    void afisare3()
    {
        cout << "\n---------------Magazin----------- \n";
        cout << "\n---Bautura---\n";
        bauturi :: afisare1();
        cout << "\n\n---Alimente---\n";
        alimente :: afisare2();
    }

    void mai_scump()
    {
        if (price_alimente > price_bautura)
            {
                cout << "\n Mai scump este alimentul!";
            }
        if (price_alimente < price_bautura)
            {
                cout << "\nMai scump este bautura!";
            }
        else
            {
                cout << "\nAu acelasi pret!";
            }
    }
};

int main()
{
    magazin a;
    a.afisare3();
    cout << "\n\n";
    a.mai_scump();

    return 0;
}