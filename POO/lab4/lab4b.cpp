#include <conio.h>
#include <iostream>
using namespace std;

class element_chimic
{
protected:
    int num_elements = 3;

    string name_element;
    string simbol;
    int numar_ordine;
    string serie_chimica;
    int densitate;
    int grupa;
    int perioada;

public:
    element_chimic()
    {
        for (int i = 0; i < num_elements; i++)
        {
            name_element = "Fier";
            simbol = "Fe";
            numar_ordine = 26;
            serie_chimica = "Metal";
            densitate = 7860;
            grupa = 8;
            perioada = 4;
        }
    }

    void citire()
    {
        for (int i = 0; i < num_elements; i++)
        {
            cout << "\nIntroduceti numele elementului: \n";
            name_element = "Fier";

            cout << "\nIntroduceti simbolul: \n";
            simbol = "Fe";

            cout << "\nIntroduceti numarul de ordine: \n";
            numar_ordine = 26;

            cout << "\nSeria chimica: \n";
            serie_chimica = "Metal";

            cout << "\nDensitatea: \n";
            densitate = 7860;

            cout << "\nGrupa: \n";
            grupa = 8;

            cout << "\nPerioada: \n";
            perioada = 4;
        }
    }

    void afisare()
    {
        cout << "\nDenumirea elementului: " << name_element;
        cout << "\nSimbolul: " << simbol;
        cout << "\nNumarul de ordine: " << numar_ordine;
        cout << "\nSeria chimica: " << serie_chimica;
        cout << "\nDensitatea elementului: " << densitate;
        cout << "\nGrupa: " << grupa;
        cout << "\nPerioada: " << perioada << endl;
    }
};

class medicamente : public element_chimic
{
protected:
public:
    void baza()
    {
        for (int i = 0; i < num_elements; i++)
        {
            afisare();
        }
    }
};

int main()
{
    medicamente a1;
    a1.baza();
}

//  Definiţi clasa element chimic, care conţine informaţia despre denumirea elementului şi
//  proprietăţile ei chimice. Determinaţi clasa medicamente, care conţine diferite elemente
//  chimice şi diferite cantităţi. Determinaţi constructorii, funcţiile fluxului de ieşire şi
//  alte funcţii necesare