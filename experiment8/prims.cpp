//Palak Bajwan
//25/DA/049

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100];

void prims(int n) {

    vector<bool> visited(n, false);

    // {weight, vertex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, 0});

    int mstWeight = 0;

    while (!pq.empty()) {

        pair<int, int> p = pq.top();
        pq.pop();

        int weight = p.first;
        int u = p.second;

        if (visited[u])
            continue;

        visited[u] = true;
        mstWeight += weight;

        cout << "Vertex added: " << u
             << " with edge weight " << weight << endl;

        for (auto p : adj[u]) {

            int v = p.first;
            int w = p.second;

            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "MST weight = " << mstWeight << endl;
}

int main() {

    int n = 4;

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 3});
    adj[2].push_back({0, 3});

    adj[1].push_back({3, 1});
    adj[3].push_back({1, 1});

    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    prims(n);
}