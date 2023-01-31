#include <iostream>
using namespace std;

class data
{
    private:
    int an, luna, zi; // 2010:11:18

public:
    data();
    data(int, int, int);
    void operator ++ () 
    {
        ++zi;
    }
    void operator -- () 
    {
        --zi;
    }
    void creare();
    void afisare();
};

data::data()
{
    an = 2010;
    luna = 11;
    zi = 18;
}

data::data(int an1, int luna1, int zi1)
{
    this->an = an1;
    this->luna = luna1;
    this->zi = zi1;
}

void data::afisare()
{
    cout << "\nAnul este: " << an << endl;
    cout << "\nLuna este: " << luna << endl;
    cout << "\nZiua este: " << zi << endl;
}

// data operator+(data& data1)
// {
//     data suma1;
//     suma1.an = this->luna + data1.
// }

int main()
{
   // supraincarcarae incrimentare
    cout << "\nIncrimentarea: \n";
    data incrementare;
    ++incrementare;
    incrementare.afisare();

    cout << "\nDecrementarea: \n";
    //supraincarcarae decrementare
    data decrementarea;
    --decrementarea;
    decrementarea.afisare();

    //operatorul ==
    

}

