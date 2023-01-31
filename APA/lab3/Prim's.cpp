// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

#define INF 9999999
int main()
{
    long int it = 0;
    int V;
    cout << "\nIntroduceti numarul de varfuri: \n";
    cin >> V;
    int G[V][V];

    // favorabil
    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = i; j < V; j++)
    //     {
    //         if (i == j)
    //         {
    //             G[i][j] = 0;
    //             G[j][i] = 0;
    //         }
    //         else
    //         {
    //             int r = rand() % 1000;
    //             int val = (r == V) ? INF : r;
    //             G[i][j] = val;
    //             G[j][i] = val;
    //         }
    //     }
    // }

    // Random
    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = i; j < V; j++)
    //     {
    //         if (i == j)
    //         {
    //             G[i][j] = 0;
    //         }

    //         else
    //         {
    //             int r = rand() % 1000;
    //             int val = (r == V) ? INF : r;
    //             G[i][j] = val;
    //             G[j][i] = val;

    //             if(val < 500)
    //                 {
    //                     G[i][j] = 0;
    //                     G[j][i] = 0;

    //                 }
    //             else
    //                 {
    //                     G[i][j] = val;
    //                     G[j][i] = val;

    //                 }
    //         }
    //     }
    // }

    // Defavorabil
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                G[i][j] = 0;
            }

            else
            {
                int r = rand() % 1000;
                int val = (r == V) ? INF : r;
                G[i][j] = val;
                G[j][i] = val;
            }
        }
    }

    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < V; j++)
    //     {
    //         cout << "  " << G[i][j];
    //     }
    //     cout << "\n";
    //     it++;
    // }

    int no_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x; //  numarul de randuri
    int y; //  numarul de coloane

    cout << "Edge"
         << " : "
         << "Weight";
    cout << endl;
    int temp = 0;
    while (no_edge < V - 1)
    {
        it += 2;
        int min = INF;
        x = 0;
        y = 0;
        it += 3;

        for (int i = 0; i < V; i++)
        {
            it += 3;
            if (selected[i])
            {
                it++;
                for (int j = 0; j < V; j++)
                {
                    it += 3;
                    if (!selected[j] && G[i][j])
                    {
                        it++;
                        if (min > G[i][j])
                        {
                            it++;
                            min = G[i][j];
                            x = i;
                            y = j;
                            it += 3;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;

        // temp += G[x][y];
        // it++;
    }

    // cout << "\nCostul minim: " << temp;
    cout << "\nNumarul de iteratii: " << it;

    return 0;
}