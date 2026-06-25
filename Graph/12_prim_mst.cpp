#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

void add_edges(vector<vector<pair<int, int>>>& adj, vector<vector<int>> edges) {
    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        add_edge(adj, u, v, wt);
    }
}

int prims_algo(vector<vector<pair<int, int>>>& adj, int V) {
    vector<bool> mst_set(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mst_wt = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if (mst_set[u]) {
            continue;
        }

        mst_set[u] = true;
        mst_wt += wt;

        for (auto pv : adj[u]) {
            int v = pv.first;
            int weight = pv.second;

            if (!mst_set[v]) {
                pq.push({weight, v});
            }
        }
    }   

    return mst_wt;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    vector<vector<int>> edges = {{0, 1, 30}, {0, 2, 10}, {0, 3, 15}, {1, 2, 45}, {2, 3, 20}};

    add_edges(adj, edges);

    int mst_wt = prims_algo(adj, V);

    cout << "MST weight = " << mst_wt << endl;

    return 0;
}