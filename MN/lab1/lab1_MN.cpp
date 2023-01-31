#include <iostream>
#include <conio.h>
#include <math.h>


using namespace std;
double (*f)(double), (*fn)(double), (*fd)(double);
double f1(double x)
{
    return pow(x, 3) + 9 * x - 3;
}
double f2(double x)
{
    return pow(2.71, -x) * sin(x) + 1;
}
double fd1(double x)
{
    return 3 * pow(x, 2) + 9;
}
double fd2(double x)
{
    return ((-sin(x)+cos(x))/pow(2.71, x));
}
double f3(double x)
{
    return (pow(x, 3) - 3) / 9;
}
double f4(double x)
{
    return ((-sin(x)+cos(x))/pow(2.71, x));
}
void aproximatie()
{
    cout <<"\nMetoda aproximatiei: \n";
    int k = 0;
    double x0, x1, eps = 0.000001;
    cout << " Introduceti valoare initiala x0" << endl;
    cout << " x0 = ";
    cin >> x0;
    while (1)
    {
        x1 = fn(x0);
        k++;
        if (abs(x1 - x0) < eps)
        {
            cout << " Radacina este: " << x0 << endl
                 << " Numarul de iteratii " << k << endl;
            break;
        }
        x0 = x1;
    }
    _getch();
}
void injumatatire()
{
    cout <<"\nMetoda injumatatirii: \n";
    int k = 0;
    double a, b, c = 0, eps = 0.01;
    cout << " Introduceti intervalul " << endl;
    cout << " a = ";
    cin >> a;
    cout << " b = ";
    cin >> b;
    while ((b - a) > eps)
    {
        k++;
        c = (a + b) / 2;
        if (f(c) == 0)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    cout << " Radacina este: " << c << endl;
    cout << " Numarul de iteratii: " << k;
    _getch();
}
void newton()
{
    cout <<"\nMetoda Newton: \n";
    int k = 0;
    double x0, x1, eps = 0.000001;
    cout << " Introduceti valoare initiala x0" << endl;
    cout << " x0 = ";
    cin >> x0;
    while (1)
    {
        x1 = x0 - f(x0) / fd(x0);
        k++;
        if (abs(x1 - x0) < eps)
        {
            cout << " Radacina este: " << x0 << endl
                 << " Numarul de iteratii " << k << endl;
            break;
        }
        x0 = x1;
    }
    _getch();
}
void secante()
{
    cout <<"\nMetoda secantei: \n";
    double x2, x1, x3 = 0, y, eps = 0.000001;
    int n = 0;
    cout << " Introduceti intervalul " << endl;
    cout << " a = ";
    cin >> x1;
    cout << " b = ";
    cin >> x2;
    do
    {
        n++;
        y = x3;
        x3 = x2 - (f(x2) * (x2 - x1) / (f(x2) - f(x1)));
        x1 = x2;
        x2 = x3;
    } while (fabs(y - x3) >= eps);
    cout << " Radacina este: " << x3 << endl;
    cout << " Numarul de iteratii : " << n << endl;
    _getch();
}
void selectFunction()
{
    system("cls");
    cout << " 1. Functia f1(x) = x^3 + 9x - 3" << endl;
    cout << " 2. Functia f2(x) = (e^-x) * sin(x) + 1" << endl;

    int optiune;
    do
    {
        optiune = _getch();
    } while (optiune < '1' || optiune > '2');
    system("cls");
    switch (optiune)
    {
    case '1':
    {
        f = f1;
        fn = f3;
        fd = fd1;
        break;
    }
    case '2':
    {
        f = f2;
        fn = f4;
        fd = fd2;
        break;
    }
    }
}
int meniu()
{
    system("cls");
    if (f == f1)
        cout << "  Functia f1(x) = x^3 + 9x - 3" << endl;
    else
        cout << "  Functia f2(x) = (e^-x) * sin(x) + 1" << endl;

    cout << " 1. Selectarea functiei" << endl;
    cout << " 2. Metoda aproximatiei succesive : exactitatea 10^(-6)" << endl;
    cout << " 3. Metoda injumatatirii : exactitatea 10^(-2)" << endl;
    cout << " 4. Metoda Newton : exactitatea 10^(-6)" << endl;
    cout << " 5. Metoda secantelor : exactitatea 10^(-6)" << endl;
    cout << " 6. Iesire" << endl;

    int optiune;
    do
    {
        optiune = _getch();
    } while (optiune < '1' || optiune > '6');
    system("cls");
    return optiune - '0';
}
int main()
{
    int optiune;
    f = f1;
    fn = f3;
    fd = fd1;
    do
    {
        switch (optiune = meniu())
        {
        case 1:
        {
            selectFunction();
            break;
        }
        case 2:
        {
            aproximatie();
            break;
        }
        case 3:
        {
            injumatatire();
            break;
        }
        case 4:
        {
            newton();
            break;
        }
        case 5:
        {
            secante();
            break;
        }
        }
    } while (optiune != 6);
}