#include <conio.h>
#include <iostream>
using namespace std;


// a) vehicol,  camion - masina de teren

class vehicol
{
public:
    string name_autoturism;
    int putere;
    int an;
    vehicol()
    {
        cout << "\nNume autoturism: ";
        cin >> name_autoturism;
        // name_autoturism = " ";

        cout << "\nPutere: ";
        cin >> putere;
        // putere = 0;

        cout << "\nAnul de constructie: ";
        cin >> an;
        // an = 0;
    }

    void afisare1()
    {
        cout << "\nNume autoturism: " << name_autoturism << endl;
        cout << "\nPutere: " << putere << endl;
        cout << "\nAn: " << an << endl;
    }
};

class camion
{
public:
    string name_camion;
    int putere1;
    int an1;
    camion()
    {
        cout << "\nNume camion: ";
        cin >> name_camion;
        // name_autoturism = " ";

        cout << "\nPutere: ";
        cin >> putere1;
        // putere = 0;

        cout << "\nAnul de constructie: ";
        cin >> an1;
        // an = 0;
    }
    void afisare2()
    {
        cout << "\nCamion: " << name_camion << endl;
        cout << "\nPutere: " << putere1 << endl;
        cout << "\nAn: " << an1 << endl;
    }
};

class masina_de_teren : public vehicol, public camion
{
public:
    void afisare3()
    {
        cout << "\n//////////////////////////////////////";
        vehicol ::afisare1();
        cout << "\n";
        camion ::afisare2();
    }

    void mai_puternic()
    {
        if (putere > putere1)
        {
            cout << "\n---Cel mai puternic este autoturismul!---\n";
        }
        else if (putere < putere1)
        {
            cout << "\n---Cel mai puternic este camionul!---\n";
        }
        else
            cout << "\n---Au aceeasi putere!---\n";
    }
};

int main()
{
    masina_de_teren a;
    a.afisare3();
    a.mai_puternic();
    return 0;
}