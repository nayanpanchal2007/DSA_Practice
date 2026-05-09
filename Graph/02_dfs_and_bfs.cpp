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

    void dfs_helper(int src, vector<bool>& visited) {
        visited[src] = true;

        cout << src << " ";

        for (int v : l[src]) {
            if (!visited[v]) {
                dfs_helper(v, visited);
            }
        }
    }

    void dfs(int src) {
        vector<bool> visited(V, false);

        dfs_helper(src, visited);
        cout << endl;
    }

    void bfs(int src) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : l[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);

    cout << "DFS traversal: ";
    g.dfs(0);

    cout << "BFS traversal: ";
    g.bfs(0);
    return 0;
}