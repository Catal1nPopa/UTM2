///Popa Catalin TI-211

#include <iostream>
using namespace std;


class numar
{
    double durata,pretul;

    public:
    numar(){durata = pretul = 0;}
    numar(double a, double b) //cons cu par
    {
        durata = a;
        pretul = b;
    }
    numar(numar&);

    void citire();
    void afisare();
    double cost();
    ~numar(){cout << "Obiectul a fost distrus!!!" <<endl;}
};

numar :: numar(numar &c)
{
    durata = c.durata;
    pretul = c.pretul;
}

void numar :: citire()
{
    cout << "Dati durata epelului telefonic: \n";
    cin >> durata;
    cout << " Dati pretul in lei a unui minut: \n";
    cin >> pretul;
}

void numar :: afisare()
{
    cout << " \nDurata : "<<durata<< "\n Pretul/min: "<<pretul<<"\n Costul: "<<cost()<<endl; 
}

double numar :: cost(){return ((durata/60)*pretul);}

int main()
{
    numar a;
    a.citire();
    a.afisare();

    numar b(100, 7.50);
    b.afisare();

    numar c(a);
    c.afisare();

    numar *p;

    p = new numar;
    p->afisare();
    delete p;

    p = new numar(80, 2);
    p->afisare();
    delete p;

    p = new numar(b);
    p->afisare();
    delete p; 
}


