

// Elaboraţi un program prin intermediul căruia vor fi gestionate
// filmele de la  un cinematograf .
// Despre un film se cunosc următoarele date: numele filmului,
// anul ediţiei, actorul principal, regizorul,
//  bugetul filmului, ora de difuzare a filmului în cinematograf.

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;

class TFilme
{
    public:
    char *nume, *actor_principal, *regizor;
    int anul_editiei, ora, num;
    double buget;

    TFilme *next;
    TFilme()

    {
        nume = new char[20];
        actor_principal = new char[20];
        regizor = new char[20];
        anul_editiei = 0;
        ora = 0;
        buget = 0;
        next = NULL;
    }

    friend istream &operator>>(istream &, TFilme *&);
    friend ostream &operator<<(ostream &, TFilme *);
};

istream &operator>>(istream &is, TFilme *&t)
{
    cout << "Dati datele despre film" << endl;
    cout << "Numarul: ";
    is >> t->num;

    cout << "Nume: ";
    is >> t->nume;

    cout << " Anul editie: ";
    is >> t->anul_editiei;

    cout << " Actorul principal: ";
    is >> t->actor_principal;

    cout << " Regizorul:  ";
    is >> t->regizor;

    cout << " Bugetul filmului: ";
    is >> t->buget;

    cout << " Ora de difuzare a filmului in cinematograf: ";
    is >> t->ora;
    return is;
}

ostream &operator<<(ostream &os, TFilme *t)
{
    os << setw(3) << t->num << setw(20) << t->nume << setw(10) << t->actor_principal << setw(10) << t->regizor << setw(10);
    os << t->anul_editiei << setw(6) << t->buget << setw(10) << t->ora << setw(10);
    return os;
}

// int schimb(TFilme *a, TFilme *b)
// {
//     TFilme *an,*bn
//     an = a->next;
//     bn = b->next;
//}

class lista
{
    TFilme *prim;
    int n;

    public
    : lista()
    {
        prim = NULL;
        n = 0;
    } 
    void creare();
    void afisare(); 
    void inserare();
    void exclude();
    void cauta(char*);
    void cauta(double, int);
    ~lista();

};
    void lista ::creare()
{
    TFilme *p;
    ifstream f("f.txt");
    f >> n;
    for (int i = 0; i < n; i++)
    {
        p = new TFilme;
        f >> p->num >> p->nume >> p->anul_editiei >> p->actor_principal >> p->regizor >> p->buget >> p->ora;
        p->next = prim;
        prim = p;
    }
    f.close();
}

void lista ::afisare()
{
    cout << "Lista filmelor" << endl;
    cout << setw(6) << "Numarul" << setw(20) << "Nume" << setw(10) << "Anul editiei";
    cout << setw(20) << "Actor principal" << setw(20) << "Regizor " << setw(20) << "Bugetul" << setw(6) << "Ora" << endl;
    TFilme *p;
    p = prim;
    while (p != NULL)
    {
        cout << p;
        p = p->next;
    }
}

void lista ::inserare()
{
    TFilme *q;
    q = new TFilme;
    cin >> q;
    q->next = prim;
    prim = q;
    n++;
}

void lista::exclude()
{
    TFilme *p, *q;
    int c;
    cout << "Introdu numarul filmului care va fi exclus";
    cin >> c;
    p = prim;
    if (p->num == c)
    {
        prim = p->next;
        delete p;
        n--;
    }
    else
    {
        while (p->next->num != c && p != NULL)
            p = p->next;
        if (p != NULL)
        {
            q = p->next;
            p->next = q->next;
            delete q;
            n--;
        }
    }
}

void lista::cauta(char *nume)
{
    TFilme *p;
    p = prim;
    while (p != NULL)
    {
        if (stricmp(p->nume, nume) == 0)
            cout << p;
        p = p->next;
    }
}
void lista::cauta(double bugetul, int anul)
{
    TFilme *p;
    p = prim;
    while (p != NULL)
    {
        if (p->buget >= bugetul && p->anul_editiei == anul)
            cout << p;
        p = p->next;
    }
}

lista::~lista()
{
    TFilme *p, *q;
    do
    {
        p = prim;
        prim = prim->next;
        delete p;
    } while (prim != NULL);
}

int main()
{
    char c;
    lista g;
    g.creare();


    g.afisare();
    g.creare();
    // do
    // {
    //     //clrscr();
    //     cout << "Tastati" << endl
    //          << "1-afisare" << endl
    //          << "2-excludere";
    //     cout << endl
    //          << "3-inserare" << endl
    //          << "4-Filmele cu numele Obsidian";
    //     cout << endl
    //          << "5-Studentii cu bugetul>20000, din anul > 2010";
    //     cout << endl
    //          << "0-iesire" << endl;
    //     c = getch();
    //    // clrscr();
    //     switch (c)
    //     {
    //     case '1':
    //         g.afisare();
    //         getch();
    //         break;
    //     case '2':
    //         g.exclude();
    //         break;
    //     case '3':
    //         g.inserare();
    //         break;
    //     case '4':
    //         g.cauta("Obsidian");
    //         getch();
    //         break;
    //     case '5':
    //         g.cauta(20000, 2010);
    //         getch();
    //         break;
    //     }
    // } while (c != '0');
}
