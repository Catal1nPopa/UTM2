#include <conio.h>
#include <iostream>
using namespace std;


// b) automobil-vehicol, camoion-masina de teren

class automobil
{
    public:
    string name;
    int pret;
    
    void citire()
    {
        cout << "\nDenumirea: ";
        cin >> name;

        cout << "\nPretul: ";
        cin >> pret; 
    }

    void afisare()
    {
        cout << "\nDenumirea: " << name;
        cout << "\nPretul: " << pret;
    }

};

class vehicol : public automobil
{
    public:
    void citire1()
    {
        cout << "\n-----------Vehicol-------------- \n";
        automobil :: citire();
       // automobil :: afisare();
    }
};

class camion : public automobil
{
    public:
    void citire2()
    {
        cout << "\n--------------Camion----------- \n";
        automobil :: citire();
        //automobil :: afisare();
    }

};

class masina_de_teren : public vehicol, public camion
{
    public:
    void afisare3()
    {
        vehicol :: citire1();
        camion :: citire2();

        cout << "\n---------------Masini----------- \n";
        cout << "\n---Vehicol---\n";
        vehicol :: afisare();
        cout << "\n\n---Camion---\n";
        camion :: afisare();
    }

};

int main()
{
    masina_de_teren a;
    a.afisare3();
    return 0;
}

