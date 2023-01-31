// #include <iostream>

// using namespace std;

// class Container
// {
// public:
//     int *array;
//     int position;

//     virtual void push(int i) = 0;
//     virtual int pop() = 0;
// };

// class Stack : public Container
// {

// public:
//     Stack(int size)
//     {
//         array = new int[size];
//         position = 0;
//     }

//     void push(int item)
//     {
//         array[position++] = item;
//     }

//     int pop()
//     {
//         return array[--position];
//     }
// };

// int main()
// {
//     int *a = new int[10];
//     a = new int[3];
//     a[1] = 2;

//     Stack p(100);
//     Container *c = &p;

//     c->push(3);
//     cout << c->pop() << endl;

//     // c->push(5);
//     // cout<<c->pop()<<endl;

//     return 1;
// }




///////////////////////////////////////////////

class Figure
{
public:
    virtual void arie(){};
};

class patrat : public Figure
{
    double l; // lungimea laturei
public:
    patrat() : l(0){};
    patrat(double l) : l(l){};
    ~patrat() { l = 0; };
    void arie()
    {
        double temp;
        temp = l * 4;
        cout << "Aria patratului este= " << temp;
        return;
    };
};

class cerc : public Figure
{
    double r; // raza cercului
public:
    cerc() : r(0){};
    cerc(double r) : r(r){};
    ~cerc() { r = 0; };
    void arie()
    {
        double temp;
        temp = PI * (pow(r, 2));
        cout << "Aria cercului este= " << temp;
        return;
    };
};

class triunghi : public Figure
{
    double a, b, c;

public:
    triunghi() : a(0), b(0), c(0){};
    triunghi(double a, double b, double c) : a(a), b(b), c(c){};
    ~triunghi()
    {
        a = 0;
        b = 0;
        c = 0;
    };
    void arie();
};

void triunghi::arie()
{
    double p, A;
    p = (a + b + c) / 2;
    A = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Aria Triunghiului este= " << A;
    return;
};

class trapez : public Figure
{
    double B, b, h;

public:
    trapez()
    {
        B = 0;
        b = 0;
        h = 0;
    };
    trapez(double B, double b, double h) : B(B), b(b), h(h){};
    ~trapez()
    {
        B = 0;
        b = 0;
        h = 0;
    };
    void arie();
};
void trapez::arie()
{
    double temp;
    temp = (h * (b + B)) / 2;
    cout << "Aria Trapezului este= " << temp;
    return;
};
int main()
{
    Figure *x[4];
sus:
    clrscr();
    cout << "1 - Patrat" << endl;
    cout << "2 - Cerc" << endl;
    cout << "3 - Triunghi" << endl;
    cout << "4 - Trapez" << endl;
    cout << "Esc - Iesire" << endl;
    switch (getch())
    {
    case '1':
    {
        clrscr();
        double l;
        cout << "Introdu latura patratului: ";
        cin >> l;
        patrat P(l);
        x[0] = &P;
        x[0]->arie();
        break;
    };
    case '2':
    {
        clrscr();
        double r;
        cout << "Introdu raza cercului: ";
        cin >> r;
        cerc C(r);
        x[1] = &C;
        x[1]->arie();
        break;
    };
    case '3':
    {
        clrscr();
        double a, b, c;
        cout << "Introdu laturile triunghiului..." << endl;
        cout << "A= ";
        cin >> a;
        cout << "B= ";
        cin >> b;
        cout << "C= ";
        cin >> c;
        triunghi T(a, b, c);
        x[2] = &T;
        x[2]->arie();
        break;
    };
    case '4':
    {
        clrscr();
        double B, b, h;
        cout << "Introdu Baza mare: ";
        cin >> B;
        cout << "Introdu Baza mica: ";
        cin >> b;
        cout << "Introdu h= ";
        cin >> h;
        trapez Tr(B, b, h);
        x[3] = &Tr;
        x[3]->arie();
        break;
    };
    case 27:
    {
        for (int i = 0; i < 5; i++)
        {
            if (x[i] == NULL)
                delete x[i];
        }
        exit(1);
    };
    }
    getch();
    goto sus;
}