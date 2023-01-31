#include <iostream>
using namespace std;

class Bool
{
    int x,y,check;


    public:
    Bool();
    Bool(int x2, int y2)
    {
        x = x2;
        y = y2;
    };

    void afisare();
    friend Bool operator + (Bool, Bool);
    friend Bool operator - (Bool, Bool);
    friend Bool operator ^ (Bool, Bool);
    Bool operator = (Bool);
    Bool operator !=(Bool);
    
};

Bool::Bool()
{
    x = 1;
    y = 2;
}

Bool operator + (Bool num1, Bool num2)
{
    Bool suma;
    suma.x = num1.x + num2.x;
    suma.y = num1.y + num2.y;

    return suma;
}

Bool operator - (Bool num1, Bool num2)
{
    Bool diferenta;
    diferenta.x = num1.x - num2.x;
    diferenta.y = num1.y - num2.y;

    return diferenta;
}

Bool operator ^ (Bool num1, Bool num2)
{
    Bool as;
    as.x = (num1.x + num2.x);
    as.y = (num1.y + num2.y);

    return as;
}

Bool Bool :: operator = (Bool num1)
{
    x = num1.x;
    y = num1.y;
}

Bool Bool :: operator !=(Bool num1)
{
    Bool re;
    if(num1.x != num1.x){
        re.x = num1.x + num1.y;
        return re;}
    else 
        {
            re.y  = num1.y + num1.x;
            return re;
        }
}
void Bool::afisare()
{
    cout << "\nValorile lui x: " <<x<< "\nValorile lui y: " << y<<endl;
}

int main()
{
    Bool A(2, 6);
    A.afisare();
    cout << "\n";
    Bool B(2, 8);
    B.afisare();

    cout << "\nAdunare: \n";
    Bool C;
    C = A+B;
    C.afisare();

    cout << "\nScaderea: \n";
    Bool D;
    D = A-B;
    D.afisare();

    cout << "\nOperatorul XOR: \n";
    
    Bool F(true, false);
    F.afisare();
    cout << "\n";
    Bool G(0, 1);
    G.afisare();
    Bool H;
    H = F ^ G;
    H.afisare();
    cout <<"\n";

    cout << "\nOperatorul =\n";
    Bool j,k;
    j = k;
    j.afisare();
    k.afisare();

    cout << "\nOperatorul !=\n";
    Bool i(true, false);
    cout << "\n";
    Bool l(0, 1);
    i != l;
    l.afisare();
    i.afisare();



}

