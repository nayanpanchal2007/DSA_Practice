#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> l;

    Graph(int V) : V(V), l(V) {}

    void add_edge(int u, int v) {
        l[u].push_back(v);
    }

    void add_edges(vector<pair<int, int>>& edges) {
        for (auto e : edges) {
            int u = e.first;
            int v = e.second;
            add_edge(u, v);
        }
    }

    bool is_cycle() {
        vector<int> indeg(V);
        for (int i = 0; i < V; i++) {
            for (int v : l[i]) {
                indeg[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int v : l[curr]) {
                indeg[v]--;

                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int x : indeg) {
            if (x != 0) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g(6);
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {2, 5}, {3, 4}, {4, 5}};
    g.add_edges(edges);

    if (g.is_cycle()) {
        cout << "Contains cycle.\n";
    } else {
        cout << "Not contains cycle.\n";
    }

    return 0;
}