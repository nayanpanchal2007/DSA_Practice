#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, wt;

    Edge(int u, int v, int wt) : u(u), v(v), wt(wt) {}
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    vector<int> par;
    vector<int> rank;

    Graph(int V) : V(V) {
        for (int i = 0; i < V; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void add_edge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    int find(int x) {
        if (x == par[x]) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void union_by_rank(int a, int b) {
        int par_a = find(a);
        int par_b = find(b);

        if (par_a == par_b) return;

        if (rank[par_a] < rank[par_b]) {
            par[par_a] = par_b;
        } else if (rank[par_b] < rank[par_a]) {
            par[par_b] = par_a;
        } else {
            par[par_b] = par_a;
            rank[par_a]++;
        }
    }

    int kruskal() {
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.wt < b.wt; });
        int mst_cost = 0;
        int count = 0;

        for (int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];

            int par_u = find(e.u);
            int par_v = find(e.v);

            if (par_u != par_v) {
                union_by_rank(e.u, e.v);
                mst_cost += e.wt;
                count++;

                if (count >= V - 1) break;
            }
        }

        return mst_cost;
    }
};

int main() {
    Graph g(4);

    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 6);
    g.add_edge(0, 3, 5);
    g.add_edge(1, 3, 15);
    g.add_edge(2, 3, 4);

    cout << "MST cost = " << g.kruskal() << endl;

    
    return 0;
}