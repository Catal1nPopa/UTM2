#include <iostream>
using namespace std;

class Matrix
{
    long int **p;
    int randuri;
    int coloane;
    bool error;

public:
    Matrix();
    Matrix(int randuri);
    Matrix(int randuri, int coloane);
    ~Matrix();

    void insert();
    void afisare();
    void suma(Matrix first_matrix);
    void diferenta(Matrix first_matrix);
    void multiply_with_num(int num);
    void multiply(Matrix a);
};

void Matrix::insert()
{
    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            cin >> p[i][j];
        }
    }
}

void Matrix::afisare()
{
    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < randuri; i++)
    {
        delete[] * (p + i);
    }
    delete[] p;

    randuri = 0;
    coloane = 0;
    error = 1;
    cout << "\n Matricea a fost eliberata!!\n";
}

Matrix::Matrix()
{
    randuri = 0;
    coloane = 0;
    p = NULL;
    error = 1;
}

Matrix::Matrix(int num)
{
    if (num > 0)
    {
        randuri = num;
        coloane = num;
        p = new long int *[num];
        for (int i = 0; i < num; i++)
        {
            p[i] = new long int[num];
        }
        error = 0;
    }
    else
    {
        error = 1;
    }
}

Matrix::Matrix(int randuri1, int coloane1)
{
    if (randuri > 0 && coloane > 0)
    {
        randuri = randuri1;
        coloane = coloane1;

        p = new long int *[randuri1];

        for (int i = 0; i < randuri1; i++)
        {
            p[i] = new long int[coloane1];
        }
        error = 0;
    }
    else
    {
        error = 1;
    }
}

void Matrix::suma(Matrix first_matrix)
{
    if (randuri == first_matrix.randuri && coloane == first_matrix.coloane)
    {
        for (int i = 0; i < randuri; i++)
        {
            for (int j = 0; j < coloane; j++)
            {
                p[i][j] = p[i][j] + first_matrix.p[i][j];
            }
        }
    }
    else
    {
        cout << "\nAdunarea nu poate fi efectuata!!!\n"<< endl;
    }
}

void Matrix::diferenta(Matrix first_matrix)
{
    if (first_matrix.randuri == randuri && first_matrix.coloane == coloane)
    {
        for (int i = 0; i < first_matrix.randuri; i++)
        {
            for (int j = 0; j < first_matrix.coloane; j++)
            {
                p[i][j] = p[i][j] - first_matrix.p[i][j];
            }
        }
    }
    else
    {
        cout << "\nScaderea nu poate fi efectuata!!!\n"
             << endl;
    }
}

void Matrix::multiply_with_num(int n)
{
    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            p[i][j] = p[i][j] * n;
        }
    }
}


void Matrix::multiply(Matrix M2)
{
    int M[randuri][coloane];
    for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            M[i][j] = p[i][j];
        }
    }
    


    if (coloane == M2.coloane && randuri == M2.randuri)
    {

        for (int i = 0; i < randuri; i++)
        {
            for (int j = 0; j < M2.coloane; j++)
            {
                p[i][j] = 0;
                for (int k = 0; k < coloane; k++)
                {
                    p[i][j] += ((M[i][k]) * (M2.p[k][j]));
                }
            }
        }
    }
    else if (coloane != M2.coloane && randuri != M2.randuri)
    {
        for (int i = 0; i < randuri; i++)
        {
            for (int j = 0; j < M2.coloane; j++)
            {
                p[i][j] = 0;
                for (int k = 0; k < coloane; k++)
                {
                    p[i][j] += ((M[i][k]) * (M2.p[k][j]));
                }
            }
        }

        coloane = M2.coloane;

        for (int i = 0; i < randuri; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }

    }
}

    ////////////////////////////////////////////////////////////////////////////////////////

    int main()
    {
        int count;

        cout << "\n1.Adunarea a doua matrice: \n";
        cout << "\n2.Scaderea a doua matrice: \n";
        cout << "\n3.Inmultirea a doua matrice: \n";
        cout << "\n4.Inmultirea cu un numar a unei matrice: \n";

        cout << "\nIntroduceti o optiune: \n";
        cin >> count;

        if (count == 1)
        {
            cout << "\nIntroduceti valorile primei matrice(2x2): \n";
            Matrix first_matrix(2, 2);
            first_matrix.insert();

            cout << "\nIntroduceti valorile altei matrice(2x2): \n";
            Matrix second_matrix(2, 2);
            second_matrix.insert();

            cout << "\nSuma matricelor 2x2 este: \n";
            first_matrix.suma(second_matrix);
            first_matrix.afisare();
        }
        else if (count == 2)
        {
            cout << "\nIntroduceti valorile primei matrice(2x2): \n";
            Matrix first_matrix(2, 2);
            first_matrix.insert();

            cout << "\nIntroduceti valorile altei matrice(2x2): \n";
            Matrix second_matrix(2, 2);
            second_matrix.insert();

            cout << "\nDiferenta matricelor 4x4 este: \n";
            first_matrix.diferenta(second_matrix);
            first_matrix.afisare();
        }
        else if (count == 3)
        {
            cout << "\nIntroduceti valorile primei matrice(2x2): \n";
            Matrix first_matrix(3, 2);
            first_matrix.insert();

            cout << "\nIntroduceti valorile altei matrice(2x2): \n";
            Matrix second_matrix(2, 3);
            second_matrix.insert();

            cout << "\nProdusul matricelor 2x2 este: \n";
            first_matrix.multiply(second_matrix);
            first_matrix.afisare();
            cout << "\nttttttttttttttttt";
        }
        else if (count == 4)
        {
            cout << "\nIntroduceti valorile matricei: \n";
            Matrix first_matrix(2);
            first_matrix.insert();

            int number;
            cout << "\n\nIntroduceti un numar: \n";
            cin >> number;
            cout << "\n";
            first_matrix.multiply_with_num(number);
            first_matrix.afisare();
        }
    }