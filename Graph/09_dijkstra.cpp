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
    g[u].push_back(Edge(v, wt)); // directed graph
}

vector<int> dijkstra(int src, vector<vector<Edge>> g, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({dist[src], src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (Edge e : g[u]) {
            if (dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    vector<vector<Edge>> g(V);

    add_edge(g, 0, 1, 2);
    add_edge(g, 0, 2, 4);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 7);
    add_edge(g, 2, 4, 3);
    add_edge(g, 3, 5, 1);
    add_edge(g, 4, 3, 2);
    add_edge(g, 4, 5, 5);
    
    vector<int> dist = dijkstra(0, g, V);

    for (int x : dist) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}