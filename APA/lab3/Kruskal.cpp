// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INF 9999
#define edge pair<int, int>

long int it = 0;
class Graph
{
private:
    vector<pair<int, edge>> G; 
    vector<pair<int, edge>> T; 
    int *parent;
    int V; 
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();

};
Graph::Graph(int V)
{
    parent = new int[V];
    it++;

    for (int i = 0; i < V; i++)
        parent[i] = i;
    it += 4;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
    it += 4;
}
int Graph::find_set(int i)
{
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
    it++;
}
void Graph::kruskal()
{
    int i, uRep, vRep;
    sort(G.begin(), G.end()); 
    it += 2;
    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        it += 5;
        if (uRep != vRep)
        {
            T.push_back(G[i]); 
            union_set(uRep, vRep);
            it += 3;
        }
    }
}
void Graph::print()
{
    int cost_min = 0;
    it++;
    cout << "Varful :"
         << " Cost" << endl;
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first;
        cost_min += T[i].first;
        it += 4;
        cout << endl;
    }

}

void defavorabil_case(int V)
{
    Graph g(V);
    // Defavorabil
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                g.AddWeightedEdge(i, j, 0);
            }
            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;
                g.AddWeightedEdge(i, j, val);
            }
        }
    }

    g.kruskal();
    //g.print();
    cout << "\nNr de iteratii: " << it;
}

void random_case(int V)
{
    Graph g(V);

    // Random
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                g.AddWeightedEdge(i, j, 0);
            }

            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;

                if (val < 500)
                {
                    g.AddWeightedEdge(i, j, 0);
                    g.AddWeightedEdge(j, i, 0);
                }
                else
                {
                    g.AddWeightedEdge(i, j, val);
                    g.AddWeightedEdge(j, i, val);
                }
            }
        }
    }

    g.kruskal();
    //g.print();
    cout << "\nNr de iteratii: " << it;
}

void favorabil_case(int V)
{
    Graph g(V);

    // favorabil
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                g.AddWeightedEdge(i, j, 0);
                g.AddWeightedEdge(j, i, 0);
            }
            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;
                g.AddWeightedEdge(i, j, val);
                g.AddWeightedEdge(j, i, val);
            }
        }
    }

    g.kruskal();
    //g.print();
    cout << "\nNr de iteratii: " << it;
}
int main()
{
    // int V;
    // cout << "\nIntroduceti numarul de varfuri: ";
    // cin >> V;
    int arr[] = {5,25,45,65,85,100};

    for(int i = 0; i < 6;i++)
        {
            cout<<"\nNumarul de varfuri: " << arr[i]<<endl;
            defavorabil_case(arr[i]);
            cout <<"\n";
        }
    // defavorabil_case(V);
    // cout <<"\n";
    // random_case(V);
    // cout <<"\n";
    // favorabil_case(V);


    return 0;
}
    