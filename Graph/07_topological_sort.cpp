#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> l;

public:
    Graph(int V) : V(V), l(V) {}

    void add_edge(int u, int v) {
        l[u].push_back(v);
    }

    void add_edges(vector<vector<int>>& edges) {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            add_edge(u, v);
        }
    }

    void dfs(int u, vector<bool>& visited, stack<int>& s) {
        visited[u] = true;

        for (int v : l[u]) {
            if (!visited[v]) {
                dfs(v, visited, s);
            }
        }

        s.push(u);
    }

    void topological_sort() {
        stack<int> s;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && !l[i].empty()) {
                dfs(i, visited, s);
            }
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        
        cout << endl;
    }
};

int main() {
    Graph g(10);
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 6}, {4, 5}, {6, 5}};
    g.add_edges(edges);

    g.topological_sort();

    return 0;
}