
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int size1 = 5;
int size2 = 5;
class Set
{

private:
    int *p;
    // int arr[5];
    int k = 0;

public:
    Set();
    Set(int size)
    {
        p = new int[size];
    }
    ~Set();

    void afisare1();
    void afisare2();

    friend Set operator+(Set arr1, Set arr2);
    friend Set operator*(Set arr1, Set arr2);
    friend Set operator-(Set arr1, Set arr2);
    friend Set operator==(Set arr1, Set arr2);
    friend Set operator+=(Set arr1, Set arr2);
    friend ostream &operator<<(ostream &out, const Set &n1)
    {
        for (int i = 0; i < size1; i++)
        {
            out << n1.p[i] << " ";
        }
    }
    friend istream &operator>>(istream &in, Set &arr1)
    {
        Set t;
        for (int i = 0; i < size1; i++)
        {
            t.p[i] = arr1.p[i];
        }
        cout << "\nDati un element: \n";
        in >> arr1.p[size1];
        return in;
    }
    //Set &operator+=(const Set &);
};

Set operator==(Set arr1, Set arr2)
{
    int n;
    for (int i = 0; i < size1; i++)
    {
        if (arr1.p[i] == arr2.p[i])
        {
            n = 1;
            // cout << "\nMultimile sunt egale\n";
        }
        else
        {
            n = 2;
            // cout << "\nMultimile nu sunt egale\n";
        }
    }

    if (n == 1)
    {
        cout << "Multimile sunt egale\n";
    }
    else if (n == 2)
    {
        cout << "Multimile nu sunt egale\n";
    }
}

Set operator+(Set arr1, Set arr2)
{

    Set t(size1 + size2);
    int i;
    int k = 0;
    for (i = 0; i < size1; i++)
    {
        t.p[i] = arr1.p[i];
    }
    k = i;

    for (i = 0; i < size2; i++)
    {
        if (arr2.p[i] != arr1.p[i])
        {
            t.p[k] = arr2.p[i];
            k++;
        }
    }

    return t;
}

Set operator*(Set arr1, Set arr2)
{
    Set t(size1);
    int i = 0, count;

    for (int i = 0; i < size1; i++)
        if (arr1.p[i] == arr2.p[i])
        {
            t.p[i] = arr1.p[i];
            count = 1;
        }
        else
        {
            i = 5;
            count = 2;
        }

    if (count == 1)
    {
        cout << "Multimile au valori comune!\n";
    }
    else if (count == 2)
    {
        cout << "Multimile nu au valori comune!\n";
    }

    return t;
}

Set operator+=(Set arr1, Set arr2)
{
    for(int i=0; i < size1; i++)
        {
            arr2.p[i] = arr1.p[i];
        }
    return arr2;
}

Set operator-(Set arr1, Set arr2)
{
    Set t;
    for (int i = 0; i < size1; i++)
    {
        t.p[i] = arr1.p[i] - arr2.p[i];
    }
    return t;
}

Set ::Set()
{
   //srand(time(0));
    p = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        p[i] = rand() % 100;
    }
}

Set ::~Set()
{
    // cout<< "\nElementul a fost distrus!\n";
    delete[] p;
}

void Set::afisare1()
{
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
}

void Set::afisare2()
{
    for (int i = 0; i < 6; i++)
    {
        cout << p[i] << " ";
    }
}

int main()
{

    cout << "\n-----------Prima multime------------\n";
    Set ar1;
    cout << ar1;

    cout << "\n------------A doua multime-----------\n";
    Set ar2;
    cout << ar2;

    cout << "\n------------Reuniunea-----------\n";
    Set ar3(10);
    ar3 = ar1 + ar2;
    ar3.afisare1();

    cout << "\n------------Intersectia-----------\n";
    Set ar4 = ar1 * ar2;
    cout << ar4;

    cout << "\n------------Scaderea-----------\n";
    Set ar5 = ar1 - ar2;
    cout << ar5;

    cout << "\n------------Inserarea unui elelement-----------\n";
    cin >> ar1;
    ar1.afisare2();

    cout << "\n------------Verificare la egalitate-----------\n";
    ar1 == ar2;

    cout << "\n------------Copierea unei multimi-----------\n";
    cout << "\nMultimiea 1 s-a copiat in multimea 2\n";
    ar1 += ar2;
    cout << ar2;
    
}