#include <iostream>
#include <list>
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
};

int main() {
    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);

    g.print_list();
    return 0;
}