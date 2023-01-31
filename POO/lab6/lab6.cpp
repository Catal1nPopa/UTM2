#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class institutieDeInvatamant
{  
    public:

    virtual void descrieri(){};
};


class prescolar : public institutieDeInvatamant
{
    int varsta;
    string name;
public:
    prescolar()
    {   
        name = "Mihai";
        varsta = 4;
    }
    void descrieri()
    {
        cout << "\nNume: "<<name << endl;
        cout << "\nVarsta: "<<varsta << "ani" <<endl;
    }

};

class liceu : public institutieDeInvatamant
{
    int varsta;
    string name;
public:
    liceu()
    {  
        name = "Grigore";
        varsta = 17;
    }
    void descrieri()
    {
        cout << "\nNume: "<<name << endl;
        cout << "\nVarsta: "<<varsta << "ani" << endl;
    }

};

class superioara : public institutieDeInvatamant
{
    int varsta;
    string name;
public:
    superioara()
    {   
        name = "Ion";
        varsta = 21; 
    }
    void descrieri()
    {
        cout << "\nNume: "<<name << endl;
        cout << "\nVarsta: "<<varsta << "ani"<< endl;
    }

};

int main()
{
    superioara *a = new superioara;
    liceu *b = new liceu;
    prescolar *c = new prescolar;
    institutieDeInvatamant *baza[3] = {a, b ,c};
    // liceu b();
    // prescolar c();
    
    // baza[0] = &a;
    baza[0]->descrieri();
    cout << "\n--------------------------------\n";
    
    // baza[1] = &b;
    baza[1] ->descrieri();
    cout << "\n--------------------------------\n";

    // baza[2] = &c;
    baza[2] ->descrieri();
    cout << "\n--------------------------------\n";

    return 0;
}
