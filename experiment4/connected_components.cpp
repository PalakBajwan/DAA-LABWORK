#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int vertex)
{
    visited[vertex] = 1;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize graph and visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        // Since graph is undirected
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "\nConnected Components:\n";

    int component = 1;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cout << "Component " << component << ": ";
            DFS(i);
            cout << endl;

            component++;
        }
    }

    return 0;
}