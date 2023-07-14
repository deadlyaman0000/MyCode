#include<vector>
#include<list>
#include<unordered_map>
#include<stack>
#include<climits>
#include<iostream>


using namespace std;

// crating graph class

class graph
{
public:
    // adj list for weighted DAG
    unordered_map<int, list<pair<int, int>>> adj;

    // addEdge function
    void addEdge(int u, int v, int weight)
    {
        // making pair
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    // printing adj list to check if we are doing correct or not

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "} ";
            }
            cout << endl;
        }
    }

    // topological sort
    // uses adjList from class
    void topologicalSort(unordered_map<int, bool> &visited, stack<int> &s, int node)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                topologicalSort(visited, s, i.first);
            }
        }
        s.push(node); // pushing node to stack after function call
    }
    // shortest path

    void shortestPath(vector<int> &shortDis, stack<int> &s, int src)
    {
        shortDis[src] = 0; // self distance 0

        while (!s.empty())
        {
            int top = s.top(); // stack top  // top is not distance shortDis[top] gives distance
            s.pop();

            if (shortDis[top]!= INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if (shortDis[top] + i.second < shortDis[i.first])
                    {
                        shortDis[i.first] = shortDis[top] + i.second; // if value in vector is greater then update
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;

    // creating DAG
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // print adj list
    cout << "adj List " << endl;
    g.printAdjList();
    cout << endl;

    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    int n = 6; // number of nodes

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topologicalSort(visited, s, i); // calling topological Sort
        }
    }

    // shortest path
    vector<int> shortDis(n);

    // intialise vector with infinity distance
    for (int i = 0; i < n; i++)
    {
        shortDis[i] = INT_MAX;
    }

    int src = 1; // source node

    g.shortestPath(shortDis, s, src); // function call for shortest path

    // printing ans
    cout << " shortes distance of nodes from 1 " << endl;
    for (auto i : shortDis)
    {
        cout << i << " ";
    }

    return 0;
}