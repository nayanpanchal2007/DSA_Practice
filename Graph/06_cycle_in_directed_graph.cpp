#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> l;

    Graph(int V) : V(V), l(V) {}

    void add_edge(int u, int v) {
        // for directed only
        l[u].push_back(v);
    }

    void add_edges(vector<pair<int, int>> edges) {
        for (auto& p : edges) {
            int u = p.first;
            int v = p.second;
            add_edge(u, v);
        }
    }

    bool detect_cycle_directed_graph(int curr, vector<bool>& visited, vector<bool>& rec_path) {
        visited[curr] = true;
        rec_path[curr] = true;

        for (int v : l[curr]) {
            if (!visited[v]) {
                if (detect_cycle_directed_graph(v, visited, rec_path)) {
                    return true;
                }
            } else if (rec_path[v]) {
                return true;
            }
        }

        rec_path[curr] = false;
        return false;
    }

    bool is_cycle() {
        vector<bool> visited(V, false);
        vector<bool> rec_path(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && !l[i].empty()) {
                if (detect_cycle_directed_graph(i, visited, rec_path)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g(5);
    vector<pair<int, int>> edges = {{1, 0}, {0, 2}, {2, 3}, {3, 0}};
    g.add_edges(edges);

    if (g.is_cycle()) {
        cout << "Cycle exists.\n";
    } else {
        cout << "Cycle not exists.\n";
    }
    return 0;
}