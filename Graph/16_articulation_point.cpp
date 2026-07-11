#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    vector<int> low;
    vector<int> dt;
    vector<bool> vis;
    int time;

public:
    Graph(int V) : V(V), adj(V), low(V, -1), dt(V, -1), vis(V, false) {
        time = 0;
    }

    void add_edges(vector<vector<int>>& edges) {
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfs(int u, int par_u, vector<bool>& isAP) {
        vis[u] = true;
        dt[u] = low[u] = time++;

        int children = 0;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                children++;
                dfs(v, u, isAP);

                low[u] = min(low[u], low[v]);

                // Non-root articulation point
                if (par_u != -1 && low[v] >= dt[u]) {
                    isAP[u] = true;
                }
            }
            else if (v != par_u) {
                // Back edge
                low[u] = min(low[u], dt[v]);
            }
        }

        // Root articulation point
        if (par_u == -1 && children > 1) {
            isAP[u] = true;
        }
    }

    vector<int> articulation_points() {
        vector<bool> isAP(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, isAP);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                ans.push_back(i);
            }
        }

        if (ans.empty())
            return {-1};

        return ans;
    }
};

int main() {
    Graph g(4);

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3}
    };

    g.add_edges(edges);

    cout << "Articulation points:\n";

    for (int p : g.articulation_points()) {
        cout << p << " ";
    }

    cout << endl;

    return 0;
}