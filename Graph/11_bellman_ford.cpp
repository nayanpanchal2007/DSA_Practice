#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) : v(v), wt(wt) {}
};

void add_edge(vector<vector<Edge>>& g, int u, int v, int wt) {
    g[u].push_back({v, wt});
}

void bellman_ford(int src, vector<vector<Edge>>& g, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Edge e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    cout << "Shortest distance from node " << src << ":\n";
    for (int x : dist) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<Edge>> g(V);

    add_edge(g, 0, 1, 5);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 2);
    add_edge(g, 2, 4, 1);
    add_edge(g, 4, 3, -1);
    
    bellman_ford(0, g, V);
    return 0;
}