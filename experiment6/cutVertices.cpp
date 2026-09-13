//PALAK BAJWAN
//25/DA/049

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    vector<int> disc, low, parent;
    vector<bool> visited, articulation;

    int timer;

    void DFS(int u) {
        visited[u] = true;
        disc[u] = low[u] = ++timer;

        int children = 0;

        for (int v : adj[u]) {
            // If v is not visited, it's a DFS tree edge
            if (!visited[v]) {
                parent[v] = u;
                children++;

                DFS(v);

                // Update low value of u
                low[u] = min(low[u], low[v]);

                // Case 1: u is root of DFS tree
                if (parent[u] == -1 && children > 1)
                    articulation[u] = true;

                // Case 2: u is not root
                if (parent[u] != -1 && low[v] >= disc[u])
                    articulation[u] = true;
            }
            // Back edge
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);

        disc.resize(V, -1);
        low.resize(V, -1);
        parent.resize(V, -1);

        visited.resize(V, false);
        articulation.resize(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {
        // Handle disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                DFS(i);
        }

        cout << "Articulation Points: ";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (articulation[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}

