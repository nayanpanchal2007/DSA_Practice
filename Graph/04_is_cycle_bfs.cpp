#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    ~Graph() {
        delete[] l;
    }
    
    void add_edge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print_list() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int x : l[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    bool is_cycle_undirected_bfs(int src, vector<bool>& visited) {
        queue<pair<int, int>> q;

        q.push({src, -1});
        visited[src] = true;

        while (!q.empty()) {
            int u = q.front().first;
            int parent = q.front().second;

            q.pop();

            for (int v : l[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                } else if (v != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool is_cycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (is_cycle_undirected_bfs(i, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(3, 4);

    if (g.is_cycle()) {
        cout << "Cycle Exists." << endl;
    } else {
        cout << "Cycle Not Exists." << endl;
    }

    return 0;
}