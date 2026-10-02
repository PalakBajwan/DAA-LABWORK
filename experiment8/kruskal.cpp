//Palak Bajwan
//25/DA/049

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;

        if (rank[a] == rank[b])
            rank[a]++;
    }
};

struct Edge {
    int u, v, weight;
};

int main() {

    int n = 4;

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 3, 1},
        {2, 3, 4}
    };

    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
        [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

    DSU dsu(n);

    int mstWeight = 0;
    int edgesUsed = 0;

    for (auto edge : edges) {

        int u = edge.u;
        int v = edge.v;

        // If u and v are in different components,
        // adding this edge won't create a cycle.
        if (dsu.find(u) != dsu.find(v)) {

            dsu.unite(u, v);

            mstWeight += edge.weight;
            edgesUsed++;

            cout << u << " - " << v
                 << " : " << edge.weight << endl;

            if (edgesUsed == n - 1)
                break;
        }
    }

    cout << "MST weight = " << mstWeight << endl;
}