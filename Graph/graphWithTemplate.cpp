#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

//creating template
template<typename T >
class graph
{
public:
    unordered_map<T, list<T>> adj; // adjacency list

    void addEdge(T u, T v, bool direction)
    {
        // direction 0->undirected
        // direction 1 ->directed
        adj[u].push_back(v); // create an edge from u to v

        if (direction == 0)
        {
            // we need to create edge for v to u
            adj[v].push_back(u);
        }
    }

    void prTAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph <int>g; // creating graph

    int n;
    cout << "Enter number of nodes " << endl;
    cin >> n;

    int m;
    cout << "Enter number of edges" << endl;
    cin >> m;

    // making edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // undirected graph
                            // all degree are saved in list
    }

    cout << "PrTing Graph " << endl;
    g.prTAdjList();

    return 0;
}