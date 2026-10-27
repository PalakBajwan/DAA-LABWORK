#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    // Check for negative-weight cycle
    for (auto e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.wt < dist[e.v]) {
            cout << "Negative weight cycle exists";
            return 0;
        }
    }

    for (int i = 0; i < V; i++) {
        cout << "Distance to " << i << " = ";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}