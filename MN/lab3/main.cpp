#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
using namespace std;

void Lagrange(int nr, float array_x[20], float array_y[20], float a)
{
    int i, j, k;
    float array_C[20], array_B[20], array_A[20], r, y1;
    --nr;

    array_C[0] = 1;
    for(i = 0; i<=nr; i++)
    {
        array_C[i+1] = array_C[i];
        for(j = i; j>=1; j--)
        {
            array_C[j] = array_C[j-1]-array_C[j]*array_x[i];
        }
        array_C[0] = -array_C[0]*array_x[i];
    }

    for(i = 0; i<=nr; i++)
    {
            array_A[i] = 0;
    }
    array_B[nr] = array_C[nr+1];

    for(i = 0; i <= nr; i++)
    {
        r = 1;
        for(j = 0; j <= nr; j++)
        {
            if(i != j)
            {
                r = r*(array_x[i]-array_x[j]);
            }
        }
        for(k = nr-1; k >= 0; k--)
        {
            array_B[k] = array_C[k+1]+array_x[i]*array_B[k+1];
        }
        for(k = 0; k <= nr; k++)
        {
            array_A[k] = array_A[k] + array_y[i]*array_B[k]/r;
        }
    }

    cout << "\n 1) Polinomul de interpolare Lagrance Ln este: \nLn(x) = " << array_A[nr] << "x^" << nr;
    i = nr-1;
    for(k = nr-1; k > 0; k--)
    {
        printf(" %+1.4fx^%d", array_A[k], i);
        if(k == nr-4) printf("\n\t");
        i--;
    }
    printf(" %+1.4f", array_A[0]);

    y1 = array_A[nr];
    for(i = 1; i<=nr; i++)
        y1 = a*y1 + array_A[nr-i];

    cout << "\n\n\n 2) Valoarea functiei f(x) in punctul x=" << a << " utilizind \n polinomul de interpolare Lagrange este: f(x) = " << y1;
}

int main()
{
    int numar_elemente=7;
    float array_x[numar_elemente]={-1.432, -0.675, 1.439, 2.567, 3.486, 4.910, 5.763};
    float array_y[numar_elemente]={7.67103, 5.45321, 3.76129, 0.56741, -1.5630, 0.76884, 2.56793};
    float a = -0.532;

    cout << "\nNumarul de elemente: ";
    cout << numar_elemente;

    cout << "\nValoarea x pentru a calcula valoarea functiei = ";
    cout << a;
    cout << "\n\nValorile introduse sunt: \n\n";

    cout << "[X]";
    for(int i=0; i<numar_elemente; i++)
    {
        cout << "\t" << array_x[i];
    }
    cout << endl;

    cout << "[Y]";
    for(int i=0; i<numar_elemente; i++)
    {
        cout << "\t" << array_y[i];
    }
    cout << endl;
    
    cout << "\nPunctul x1 = " << a;

    cout << "\n\n";
    Lagrange(numar_elemente, array_x, array_y, a);
    cout << "\n\n";

    return 0;
}