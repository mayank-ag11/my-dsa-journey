/***
 * Given an undirected graph G(V, E) and two vertices v1 and v2(as integers)
 * find and print the path from v1 to v2 (if exists).
 * Print nothing if there is no path between v1 and v2.
 * Find the path using DFS and print the first path that you encountered.
 * 
 * Notes:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
    3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
    4. Save the input graph in Adjacency Matrix.

 * Test Cases:
    V = 4, E = 4
    Edges: 0 1, 0 3, 1 2, 2 3
    v1 = 1, v2 = 3

    => 3 0 1
 ***/

// T: O(V + E), S: O(V^2)
#include <iostream>
#include <vector>
using namespace std;

vector<int>* getPathDFS(bool **graph, int v, int src, int dst, bool *visited) {
    if(src == dst) {
        vector<int> *path = new vector<int>();
        path->push_back(src);
        return path;
    }

    if(visited[src]) return NULL;

    visited[src] = true;
    vector<int> *path = NULL;

    for(int i = 0; i < v; i++) {
        if(graph[src][i] == 1 and !visited[i]) {
            path = getPathDFS(graph, v, i, dst, visited);
            if(path != NULL) {
                path->push_back(src);
                return path;
            }
        }
    }

    return path;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool **graph = new bool*[v];
    for(int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }

    for(int i = 0, a, b; i < e; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    bool *visited = new bool[v]();
    int v1, v2;
    cin >> v1 >> v2;

    vector<int> *path = getPathDFS(graph, v, v1, v2, visited);
    if(path != NULL) {
        for(int i = 0; i < path->size(); i++) {
            cout << path->at(i) << ' ';
        }

        delete path;
    }

    // Delete all the memory
    for (int i = 0; i < v; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] visited;
}