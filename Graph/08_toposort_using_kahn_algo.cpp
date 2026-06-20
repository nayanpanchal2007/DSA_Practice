#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> l;

    Graph(int V) : V(V), l(V) {}

    void add_edge(int u, int v) {
        l[u].push_back(v); // directed edge
    }

    void add_edges(vector<vector<int>>& edges) {
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            add_edge(u, v);
        }
    }
    
    void topo_sort() {
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

            cout << curr << " ";

            for (int v : l[curr]) {
                indeg[v]--;

                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 1}, {5, 2}};
    g.add_edges(edges);
    
    g.topo_sort();
    
    return 0;
}