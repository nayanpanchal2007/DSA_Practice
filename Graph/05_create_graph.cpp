#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> create_graph(int V, vector<vector<int>>& edges) {
    vector<vector<int>> mat(V, vector<int>(V));

    for (vector<int> it : edges) {
        int u = it[0];
        int v = it[1];
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    return mat;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
    int V = 4;
    vector<vector<int>> mat = create_graph(V, edges);

    cout << "Matrix representation:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }
    
    return 0;
}