#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    int n;
    vector<int> rank;
    vector<int> par;

    DSU(int n) : n(n), rank(n, 0), par(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
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

    int find(int x) {
        if (x == par[x]) {
            return x;
        }

        return par[x] = find(par[x]);
    }
};

int number_of_connected_components(vector<vector<int>>& adj) {
    int n = adj.size();
    DSU dsu(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                dsu.union_by_rank(i, j);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (dsu.par[i] == i) {
            ans++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> adj = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    cout << "Connected components = " << number_of_connected_components(adj) << endl;
    
    return 0;
}