/***
 * Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers).
 * Check if there exists any path between them or not. Print true if the path exists and false otherwise.
 * Notes:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
 * 
 * Test Cases:
    V = 4, E = 4
    Edges: 0 1, 0 3, 1 2, 2 3
    v1 = 1, v2 = 3

    => true

    V = 6, E = 3
    Edges: 5 3, 0 1, 3 4
    v1 = 0, v2 = 3

    => false    
 ***/

// Using Adjacency Matrix
// T: O(V + E), S: O(V^2)
#include <iostream>
using namespace std;

bool hasPath(bool **graph, int n, int src, int dst, bool *visited) {
    if(src == dst) return true;
    if(visited[src]) return false;

    visited[src] = true;

    for(int i = 0; i < n; i++) {
        if(graph[src][i] == 1 and !visited[i]) {
            if(hasPath(graph, n, i, dst, visited))
                return true;
        }
    }

    return false;
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

    if(hasPath(graph, v, v1, v2, visited))
        cout << "true";
    else
        cout << "false";

    // Delete all the memory
    for (int i = 0; i < v; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] visited;
}

// Adjacency List code, without Graph class
// Resolved the doubt via TA
// Still not sure, what's the problem in previous code
#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> adj;

void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool hasPath(int src, int dst, vector<bool> visited) {
    if(src == dst) return true;
    // if(visited[src] == true) return false;

    visited[src] = true;

    for(auto neighbor : adj[src]) {
        if(!visited[neighbor]&&hasPath(neighbor, dst, visited))
            return true;
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    // Graph g(V);
    adj=vector<list<int>>(V);
    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        addEdge(a, b);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<bool> visited(V, false);

    if(hasPath(v1, v2, visited))
        cout << "true";
    else
        cout << "false";
}

// Using Adjacency List
// T: O(V + E), S: O(V)
// TLE on 2/12 test cases, not sure what's wrong!
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
   public:
    int V; // No. of vertices
    // Pointer to an array containing adjacency lists
    vector<list<int>> adj;
   
    Graph(int V); // Constructor

    // add an edge to graph
    void addEdge(int a, int b);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool hasPath(Graph g, int src, int dst, vector<bool> visited) {
    if(src == dst) return true;
    if(visited[src] == true) return false;

    visited[src] = true;

    for(auto neighbor : g.adj[src]) {
        if(hasPath(g, neighbor, dst, visited))
            return true;
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);
    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        g.addEdge(a, b);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<bool> visited(V, false);

    if(hasPath(g, v1, v2, visited))
        cout << "true";
    else
        cout << "false";
}