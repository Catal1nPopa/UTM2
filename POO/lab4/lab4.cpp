#include <iostream>
#include <string>
using namespace std;

class transport
{
protected:
    int num = 0;
    int num_transport;
    int num_elicoptere;

public:
    transport()
    {
        num_transport = 10;
        num_elicoptere = 20;
    }

    transport(int n)
    {
        num_transport = n;
        num_elicoptere = n;
    }

    void transport1()
    {
        int t = num_elicoptere * num_transport;
        cout << "\nNumarul de trasport este: " << t;
    }

    transport(transport &clone)
    {
        num_elicoptere = clone.num_elicoptere;
        num_transport = clone.num_transport;
    }

    transport& operator = (const transport& c);
};

transport &transport :: operator=(const transport &c)
{
    num_elicoptere = c.num_elicoptere;
    num_transport = c.num_transport;
}

class transport_aerian : public transport
{

public:
    void transport_aerian_afisare()
    {
        cout << "\nNumarul de trasport: " << num_transport;
    }
};

class elicoptere : public transport_aerian
{
public:
    void elicoptere_afisare()
    {
        cout << "\nNumarul de elicoptere este: " << num_elicoptere;
    }
};

int main()
{
    cout << "\nCrearea claselor si definirea: \n";
    elicoptere a1;
    a1.transport_aerian_afisare();
    a1.elicoptere_afisare();
    a1.transport1();

    cout << "\n\nConstructorul de copiere:\n";
    elicoptere a2(a1);
    a2.transport_aerian_afisare();
    a2.elicoptere_afisare();
    a2.transport1();

    cout << "\n\nSupraincarcarea operatorului de atribuire si constructor de copiere:\n";
    elicoptere a3 = a1;
    a3.transport_aerian_afisare();
    a3.elicoptere_afisare();
    a2.transport1();
}
