#include <iostream>
#include <conio.h>
using namespace std;
#define INF 999
#define V 100
long int it = 0;

void floyds(int b[][V])
{
    for (int k = 0; k < V; k++)
    {
        it += 3;
        for (int i = 0; i < V; i++)
        {
            it += 3;
            for (int j = 0; j < V; j++)
            {
                it += 3;
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    it += 3;
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        it += 3;
                        b[i][j] = b[i][k] + b[k][j];
                        it += 2;
                    }
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << "\nMinimum Cost With Respect to Node:" << i << endl;
        for (int j = 0; j < V; j++)
        {
            cout << b[i][j] << "\t";
        }
    }
}

void defavorabil_case()
{
    // Defavorabil

    int b[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                b[i][j] = 0;
            }
            else
            {
                int r = rand() % 1000;
                int val = (r == V) ? INF : r;
                b[i][j] = val;
                b[j][i] = val;
            }
        }
    }

    cout << "\nMatricea: \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "  " << b[i][j];
        }
        cout << "\n";
    }
    floyds(b);

    cout << "\nNr de iteratii: " << it;
}

void random_case()
{
    // Random
    int b[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                b[i][j] = 0;
            }

            else
            {
                int r = rand() % 1000;
                int val = (r == V) ? 0 : r;

                if (val < 500)
                {
                    b[i][j] = 0;
                    b[j][i] = 0;
                }
                else
                {
                    b[i][j] = val;
                    b[j][i] = val;
                }
            }
        }
    }

    cout << "\nMatricea: \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "  " << b[i][j];
        }
        cout << "\n";
    }

    floyds(b);
    cout << "\nNr de iteratii: " << it;
}

void favorabil_case()
{
   int b[V][V];
    // favorabil
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                b[i][j] = 0;
                b[j][i] = 0;
            }
            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;
                b[i][j] = val;
                b[j][i] = val;
            }
        }
    }

    cout << "\nMatricea: \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "  " << b[i][j];
        }
        cout << "\n";
    }

    floyds(b);
    cout << "\nNr de iteratii: " << it;
}

int main()
{
   defavorabil_case();
    cout << "\n\n";
    //favorabil_case();
    cout << "\n\n";
    //random_case();
}