#include <iostream>
#include <time.h>
#include <conio.h>
#include <math.h>

#define num 4
using namespace std;

long int iteratii1 = 0;
long int iteratii2 = 0;
long int iteratii3 = 0;
long int iteratii4 = 0;

float mat_A[4][4] = {11.2, 1.5, -1.3, 0.2,
                     1.5, 12.1, -0.9, 0.4,
                     -1.3, -0.9, 11.7, 1.2,
                     0.2, 0.4, 1.2, 14.2};

float mat_B[4] = {-11.4,
                  9.7,
                  8.3,
                  1.2};

void print_matrix()
{
    cout << "\n Matricea A: \n";
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << "   " << mat_A[i][j];
        }
        cout << "   \n";
    }

    cout << "\n Matricea B: \n";
    for (int i = 0; i < num; i++)
    {
        cout << " \n"
             << mat_B[i];
    }
}

void Gauss()
{

    float t, array_c[num], array_a[num][num], array_b[num];
    int i, j, l;

    for (i = 0; i < num; i++)
    {
        iteratii1 += 3;
        array_b[i] = mat_B[i];
        iteratii1++;
        for (j = 0; j < num; j++)
        {
            iteratii1 += 3;
            array_a[i][j] = mat_A[i][j];
            iteratii1++;
        }
    }
    l = 0;
    while (l < num)
    {
        iteratii1++;
        for (i = l + 1; i < num; i++)
        {
            iteratii1 += 4;
            t = array_a[i][l] / array_a[l][l];
            iteratii1++;
            for (j = l; j < num; j++)
            {
                iteratii1 += 3;
                array_a[i][j] -= t * array_a[l][j];
                iteratii1++;
            }
            array_b[i] -= t * array_b[l];
            iteratii1++;
        }
        l++;
    }
    for (i = num - 1; i >= 0; i--)
    {
        iteratii1 += 4;
        t = 0;
        iteratii1++;
        for (j = num - 1; j > i; j--)
        {
            iteratii1 += 4;
            t += array_a[i][j] * array_c[j];
            iteratii1++;
        }
        t = array_b[i] - t;
        array_c[i] = t / array_a[i][i];
        iteratii1 += 2;
    }

    for (i = 0; i < num; i++)
        printf("%7.3f ", array_c[i]);
    cout << "\nNumarul de iteratii: " << iteratii1 << endl;
}

void Cholesky()

{
    float t, array_x[num], array_l[num][num], array_y[num];
    int i, j, k;

    array_l[0][0] = sqrt(mat_A[0][0]);
    for (i = 1; i < num; i++)
    {
        array_l[i][0] = mat_A[i][0] / array_l[0][0];
        iteratii3 += 5;
    }
    for (k = 1; k < num; k++)
    {
        iteratii3 += 3;
        t = 0;
        for (j = 0; j < k - 1; j++)
        {
            t += array_l[k][j] * array_l[k][j];
            iteratii3 += 5;
        }
        array_l[k][k] = sqrt(mat_A[k][k] - t);
        iteratii3++;
        for (i = k + 1; i < num; i++)
        {
            t = 0;
            iteratii3 += 4;
            for (j = 0; j < k - 1; j++)
            {
                t += array_l[i][j] * array_l[k][j];
                iteratii3 += 6;
            }
            array_l[i][k] = (mat_A[i][k] - t) / array_l[k][k];
            iteratii3 += 3;
        }
    }
    for (i = 0; i < num; i++)
    {
        iteratii3 += 3;
        for (j = i + 1; j < num; j++)
        {
            array_l[i][j] = array_l[j][i];
            iteratii3 += 4;
        }
    }
    for (i = 0; i < num; i++)
    {
        t = 0;
        iteratii3++;
        for (j = 0; j < i; j++)
        {
            t += array_l[i][j] * array_y[j];
            iteratii3 += 5;
        }
        t = mat_B[i] - t;
        iteratii3++;
        array_y[i] = t / array_l[i][i];
        iteratii3 += 2;
    }
    for (i = num - 1; i >= 0; i--)
    {
        t = 0;
        iteratii3 += 5;
        for (j = num - 1; j > i; j--)
        {
            t += array_l[i][j] * array_x[j];
            iteratii3 += 5;
        }
        t = array_y[i] - t;
        array_x[i] = t / array_l[i][i];
        iteratii3 += 4;
    }

    for (i = 0; i < num; i++)
        printf("%7.3f ", array_x[i]);
    cout << "\nNumarul de iteratii: " << iteratii3 << endl;
}

void Jacobi()
{
    float v, array_x[num], array_q[num][num], array_d[num];
    float array_s[num][num], array_t[num][num], array_x1[num], er;
    int i, j, m;

    for (i = 0; i < num; i++)
    {
        iteratii2 += 3;
        for (j = 0; j < num; j++)
        {
            iteratii2 += 3;
            if (i == j)
            {
                array_s[i][j] = 1 / mat_A[i][j];
                array_t[i][j] = 0;
                iteratii2 += 4;
            }
            else
            {
                array_s[i][j] = 0;
                array_t[i][j] = mat_A[i][j];
                iteratii2 += 2;
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        iteratii2 += 3;
        for (j = 0; j < num; j++)
        {
            iteratii2 += 3;
            v = 0;
            for (m = 0; m < num; m++)
            {
                v += array_s[i][m] * array_t[m][j];
                iteratii2 += 5;
            }
            array_q[i][j] = -v;
            iteratii2++;
        }
    }
    for (i = 0; i < num; i++)
    {
        iteratii2 += 3;
        v = 0;
        iteratii2++;
        for (m = 0; m < num; m++)
        {
            v += array_s[i][m] * mat_B[m];
            iteratii2 += 5;
        }
        array_d[i] = v;
        iteratii2++;
    }
    for (i = 0; i < num; i++)
    {
        array_x[i] = array_d[i];
        iteratii2 += 4;
    }
    do
    {
        for (i = 0; i < num; i++)
        {
            array_x1[i] = array_x[i];
            iteratii2 += 4;
        }
        for (i = 0; i < num; i++)
        {
            iteratii2 += 3;
            v = 0;
            for (m = 0; m < num; m++)
            {
                v += array_x1[m] * array_q[i][m];
                iteratii2 += 5;
            }
            array_x[i] = v + array_d[i];
            iteratii2++;
        }
        er = fabs(array_x1[0] - array_x[0]);
        iteratii2++;
        for (m = 0; m < num; m++)
        {
            iteratii2 += 3;
            if (er < fabs(array_x1[m] - array_x[m]))
            {
                er = fabs(array_x1[m] - array_x[m]);
                iteratii2 += 3;
            }
        }
    } while (er > 0.001);

    for (i = 0; i < num; i++)
        printf("%7.3f ", array_x[i]);
    cout << "\nNumarul de iteratii: " << iteratii2 << endl;
}

void gaussseidel()
{
    int i, j, m, k1 = 0, k;
    float v, array_x[num], array_q[num][num], array_d[num], array_s[num][num];
    float array_t[num][num], array_x1[num], er;

    for (i = 0; i < num; i++)
    {
        iteratii4 += 3;
        for (j = 0; j < num; j++)
        {
            iteratii4 += 3;
            if (i == j)
            {
                array_s[i][j] = 1 / mat_A[i][j];
                array_t[i][j] = 0;
                iteratii4 += 4;
            }
            else
            {
                array_s[i][j] = 0;
                array_t[i][j] = mat_A[i][j];
                iteratii4 += 2;
            }
        }
    };
    for (i = 0; i < num; i++)
    {
        iteratii4 += 3;
        for (j = 0; j < num; j++)
        {
            iteratii4 += 3;
            v = 0;
            for (m = 0; m < num; m++)
            {
                v += array_s[i][m] * array_t[m][j];
                iteratii4 += 5;
            }
            array_q[i][j] = -v;
            iteratii4++;
        }
    }
    for (i = 0; i < num; i++)
    {
        v = 0;
        iteratii4 += 4;
        for (m = 0; m < num; m++)
        {
            v += array_s[i][m] * mat_B[m];
            iteratii4 += 5;
        }
        array_d[i] = v;
        iteratii4++;
    }
    for (i = 0; i < num; i++)
    {
        array_x[i] = array_d[i];
        iteratii4 += 4;
    }
    do
    {
        k1++;
        iteratii4++;
        for (i = 0; i < num; i++)
        {
            array_x1[i] = array_x[i];
            iteratii4 += 4;
        }
        for (i = 0; i < num; i++)
        {
            v = 0;
            iteratii4 += 4;
            for (m = 0; m < num; m++)
            {
                v += array_x[m] * array_q[i][m];
                iteratii4 += 5;
            }
            array_x[i] = v + array_d[i];
            iteratii4 += 2;
        }
        er = fabs(array_x1[0] - array_x[0]);
        iteratii4++;
        for (m = 1; m < num; m++)
        {
            iteratii4 += 3;
            if (er < fabs(array_x1[m] - array_x[m]))
            {
                er = fabs(array_x1[m] - array_x[m]);
                iteratii4 + 4;
            }
        }
    } while (er > 0.001);

    for (i = 0; i < num; i++)
        printf("%7.3f ", array_x[i]);
    printf("\n");

    cout << "\nNumarul de iteratii: " << iteratii4 << endl;

    k1 = 0;
    for (i = 0; i < num; i++)
        array_x[i] = array_d[i];
    do
    {
        k1++;
        for (i = 0; i < num; i++)
            array_x1[i] = array_x[i];
        for (i = 0; i < num; i++)
        {
            v = 0;
            for (m = 0; m < num; m++)
                v += array_x[m] * array_q[i][m];
            array_x[i] = v + array_d[i];
        }
        er = fabs(array_x1[0] - array_x[0]);
        for (m = 1; m < num; m++)
            if (er < fabs(array_x1[m] - array_x[m]))
                er = fabs(array_x1[m] - array_x[m]);
    } while (er > 0.00001);
    cout << "\nMetoda prin Gauss-Seidel - eroare 0.00001\n" << endl;
    for (i = 0; i < num; i++)
        printf("%7.5f ", array_x[i]);
    cout << endl;
}

void comparare()
{
    if (iteratii1 < iteratii2 && iteratii1 < iteratii3 && iteratii1 < iteratii4)
    {
        cout << "\n\n Cel mai eficient algoritm este dupa metoda Gauss!!!" << endl;
    }
    else if (iteratii2 < iteratii1 && iteratii2 < iteratii3 && iteratii2 < iteratii4)
    {
        cout << "\n\n Cel mai eficient algoritm este dupa metoda Jacobi!!!" << endl;
    }
    else if (iteratii3 < iteratii1 && iteratii3 < iteratii2 && iteratii3 < iteratii4)
    {
        cout << "\n\n Cel mai eficient algoritm este dupa metoda Cholesky!!!" << endl;
    }
    else if (iteratii4 < iteratii1 && iteratii4 < iteratii3 && iteratii4 < iteratii2)
    {
        cout << "\n\n Cel mai eficient algoritm este dupa metoda Gauss-Seidel!!!" << endl;
    }

    if (iteratii1 > iteratii2 && iteratii1 > iteratii3 && iteratii1 > iteratii4)
    {
        cout << "\n Cel mai neeficient algoritm este dupa metoda Gauss!!!\n" << endl;
    }
    else if (iteratii2 > iteratii1 && iteratii2 > iteratii3 && iteratii2 > iteratii4)
    {
        cout << "\n Cel mai neeficient algoritm este dupa metoda Jacobi!!!\n" << endl;
    }
    else if (iteratii3 > iteratii1 && iteratii3 > iteratii2 && iteratii3 > iteratii4)
    {
        cout << "\n Cel mai neeficient algoritm este dupa metoda Cholesky!!!\n" << endl;
    }
    else if (iteratii4 > iteratii1 && iteratii4 > iteratii3 && iteratii4 > iteratii2)
    {
        cout << "\n Cel mai neeficient algoritm este dupa metoda Gauss-Seidel!!!\n" << endl;
    }
}

int main()
{

    cout << "\n         Laborator nr2 MN         \n";
    cout << "\n           Popa Catalin           \n";
    cout << "\n              TI-211              \n";
    cout << "\nMatricele initiale       \n";
    print_matrix();

    cout << "\n----------------------------------------------\n";
    cout << "\n";
    cout << "\nMetoda prin Gauss!\n" << endl;
    Gauss();
    cout << "\n----------------------------------------------\n";

    cout << "\n";
    cout << "\nMetoda prin Cholesky!\n" << endl;
    Cholesky();
    cout << "\n----------------------------------------------\n";

    cout << "\n";
    cout << "\nMetoda prin Jacobi!\n" << endl;
    Jacobi();
    cout << "\n----------------------------------------------\n";

    cout << "\n";
    cout << "\nMetoda prin Gauss-Seidel - eroare 0.001\n" << endl;
    gaussseidel();
    cout << "\n----------------------------------------------\n";

    comparare();

    return 0;
}