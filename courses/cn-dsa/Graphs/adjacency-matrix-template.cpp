#include <iostream>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    // Making the adjacency matrix
    bool **graph = new bool*[v];
    for(int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for(int i = 0, a, b; i < e; i++) {
        cin >> a >> b;

        graph[a][b] = true;
        graph[b][a] = true;
    }

    // list to check if a node is already visited
    bool *visited = new bool[v]();

    // The work starts here!

    // Delete all the memory
    for (int i = 0; i < v; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] visited;
}