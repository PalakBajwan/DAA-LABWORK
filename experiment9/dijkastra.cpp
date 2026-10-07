//Palak Bajwan
//25/DA/049

#include <iostream>
#include <climits>
using namespace std;

#define V 5

// Find the vertex with minimum distance
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Dijkstra's Algorithm
void dijkstra(int graph[V][V], int source) {
    int dist[V];
    bool visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance from source to itself is 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, visited);

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display shortest distances
    cout << "\nShortest distances from source vertex "
         << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {

    // Graph represented using adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source;

    cout << "Enter source vertex (0-4): ";
    cin >> source;

    if (source < 0 || source >= V) {
        cout << "Invalid source vertex!" << endl;
        return 0;
    }

    dijkstra(graph, source);

    return 0;
}