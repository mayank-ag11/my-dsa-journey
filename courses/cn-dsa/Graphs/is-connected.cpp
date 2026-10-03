/***
 * Given an undirected graph G(V,E), check if the graph G is connected graph or not.
 * 
 * Notes:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
 * 
 * Test Case:
    V = 4, E = 4
    Edges: 0 1, 0 3, 1 2, 2 3

    => true

    V = 4, E = 3
    Edges: 0 1, 1 3, 0 3

    => false
 ***/

// Using Adjacency Lists
// T: O(e), S: O(n)
#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(vector<list<int>> &adj, int v, int src, vector<bool> &visited) {
    if(visited[src]) return;

    visited[src] = true;

    for(auto neighbor : adj[src]) {
        dfs(adj, v, neighbor, visited);
    }
}

bool isConnected(vector<list<int>> &adj, int v) {
    // To handle the graph with no vertices
    if(v == 0) return true;

    vector<bool> visited(v, false);

    dfs(adj, v, 0, visited);

    for(int i = 0; i < v; i++) {
        if(!visited[i])
            return false;
    }

    return true;
}

int main() {
    int v, e;
    cin >> v >> e;

    // Making the adjacency list
    vector<list<int>> adj(v);

    for(int i = 0, a, b; i < e; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(isConnected(adj, v))
        cout << "true";
    else
        cout << "false";
}

// Coding Ninjas Solution, Using Adjacency Matrix
/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph
*/
#include <iostream>

using namespace std;
void DFS(bool ** graph, int v, bool * visited, int currentVertex) {
    visited[currentVertex] = true;
    for (int i = 0; i < v; ++i) {
        if (graph[currentVertex][i] && !visited[i]) {
            DFS(graph, v, visited, i);
        }
    }
}
bool isConnected(bool ** graph, int v) {
    bool * visited = new bool[v]();
    DFS(graph, v, visited, 0);
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    int v, e;
    cin >> v >> e;
    bool ** graph = new bool * [v];
    for (int i = 0; i < v; ++i) {
        graph[i] = new bool[v]();
    }
    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    cout << (isConnected(graph, v) ? "true" : "false");
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
}