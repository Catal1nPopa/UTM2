#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f 

long int it = 0;

typedef pair<int, int> iPair;
class Graph 
{
    int V;                     
    list<pair<int, int>> *adj; 
public:
    Graph(int V) 
    {
        this->V = V; 
        it++;
        adj = new list<iPair>[V]; 
        it++;
    }
    void addEdge(int u, int v, int w);
    void shortestPathingraph(int s); 
};
void Graph::addEdge(int u, int v, int w) 
{
    adj[u].push_back(make_pair(v, w)); 
    it++;
    adj[v].push_back(make_pair(u, w)); 
    it++;
}

void Graph::shortestPathingraph(int src) 
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);   
    pq.push(make_pair(0, src)); 
    dist[src] = 0;              
    it++;
    while (!pq.empty())
    { 
        int u = pq.top().second;
        it++;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            it += 3;
            int v = (*i).first;
            int weight = (*i).second;
            it += 2;
            if (dist[v] > dist[u] + weight)
            {
                it++;
                dist[v] = dist[u] + weight;
                it++;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    // cout << "\nVertex \tDistance from source\n";
    // for (int i = 0; i < V; ++i)
    // {
    //     cout << i << "------------- " << dist[i] << endl; 
    // }
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
                g.addEdge(i, j, 0);
            }
            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;
                g.addEdge(i, j, val);
            }
        }
    }
    g.shortestPathingraph(0);

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
                g.addEdge(i, j, 0);
            }

            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;

                if (val < 500)
                {
                    g.addEdge(i, j, 0);
                    g.addEdge(j, i, 0);
                }
                else
                {
                    g.addEdge(i, j, val);
                    g.addEdge(j, i, val);
                }
            }
        }
    }

    g.shortestPathingraph(0);
    cout << "\nNr de iteratii: " << it;
}

void favorabil_case(int V)
{
    Graph g(V);
    it++;

    // favorabil
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            if (i == j)
            {
                g.addEdge(i, j, 0);
                g.addEdge(j, i, 0);
            }
            else
            {
                int r = rand() % 10000;
                int val = (r == V) ? INF : r;
                g.addEdge(i, j, val);
                g.addEdge(j, i, val);
            }
        }
    }

    g.shortestPathingraph(0);
    cout << "\nNr de iteratii: " << it;
}

int main()
{

    int arr[] = {5, 25, 45, 65, 85, 100};

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << "\nNumarul de varfuri: " << arr[i] << endl;
    //     defavorabil_case(arr[i]);
    //     cout << "\n";
    // }
    defavorabil_case(arr[5]);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << "\nNumarul de varfuri: " << arr[i] << endl;
    //     random_case(arr[i]);
    //     cout << "\n";
    // }

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << "\nNumarul de varfuri: " << arr[i] << endl;
    //     defavorabil_case(arr[i]);
    //     cout << "\n";
    // }

    // g.shortestPathingraph(0); // call the function to find shortest path of graph
    return 0;
}