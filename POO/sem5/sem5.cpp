#include <iostream>
using namespace std;
#define M_PI 3.14159265358979323846 /* pi */

class figura
{
    double suprafata;
    double perimetrul;

public:
    // void create_triunghi()
    // {
    //     latura_isoscel = 10;
    //     h_isoscel = 16;
    // }

    void afisare_triunghi()
    {
        cout << "\nLungimea latruii triunghiului isoscel este: \n"
             << latura_isoscel << endl;
        cout << "\nInaltimea triunghiului isoscel este: \n"
             << h_isoscel << endl;
    }

    // void create_cerc()
    // {
    //     raza = 20;
    //     diametrul_cercului = 10;
    // }

    void afisare_cerc()
    {
        cout << "\n Raza  cercului este: \n"
             << raza << endl;
        cout << "\n Diametrul cercului este: \n"
             << diametrul_cercului << endl;
    }

protected:
    int latura_isoscel = 10;
    int h_isoscel = 16;
    int raza = 20;
    int diametrul_cercului = 10;
};

class cerc : public figura
{

public:
    // void create_cerc()
    // {
    //     raza = 20;
    //     diametrul_cercului = 10;
    // }

    void afisare_cerc()
    {
        cout << "\n Raza  cercului este: \n"
             << raza << endl;
        cout << "\n Diametrul cercului este: \n"
             << diametrul_cercului << endl;
    }

    double get_perimetru_cerc()
    {
        return ((2 * raza * M_PI) / 2);
    }

    double get_aria_cerc()
    {
        return ((M_PI * raza * raza) / 2);
    }
};

class triunghi_isoscel : public figura
{

public:
    // void create_triunghi()
    // {
    //     latura_isoscel = 10;
    //     h_isoscel = 16;
    // }

    void afisare_triunghi()
    {
        cout << "\nLungimea latruii triunghiului isoscel este: \n"
             << latura_isoscel << endl;
        cout << "\nInaltimea triunghiului isoscel este: \n"
             << h_isoscel << endl;
    }
    double get_perimetru_triunghi()
    {
        return (2 * latura_isoscel + diametrul_cercului);
    }

    double get_aria_triunghi()
    {
        return ((h_isoscel + latura_isoscel) / 2);
    }
};

int main()
{
    cerc c1;
    c1.afisare_cerc();
    cout << "\nPerimetrul cercului: \n"
         << c1.get_perimetru_cerc();
    cout << "\nAria cercului: \n"
         << c1.get_aria_cerc();
    cout << "\n";

    triunghi_isoscel t1;
    t1.afisare_triunghi();
    cout << "\nAria triunghiului: \n" << t1.get_aria_triunghi();
    cout << "\nPerimetrul triunghiului: \n" << t1.get_perimetru_triunghi();


    cout << "\nAria figurii este: \n"<<t1.get_aria_triunghi()+c1.get_aria_cerc();
    cout << "\nPerimetrul figurii este: \n"<<t1.get_perimetru_triunghi()+c1.get_perimetru_cerc();
    // cout << "\nPerimetrul figurei este: \n" << a1.get_perimetru
}