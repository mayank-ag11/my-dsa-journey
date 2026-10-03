/***
 * Given an undirected and disconnected graph G(V, E), print its BFS traversal.
 * Notes:
    1. Here you need to consider that you need to print BFS path starting from vertex 0 only.
    2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
    3. E is the number of edges present in graph G.
    4. Take graph input in the adjacency matrix.
    5. Handle for Disconnected Graphs as well

 * Test Case:
    V=4 E=4
    Edges: 0 1, 0 3, 1 2, 2 3

    => 0 1 3 2
 ***/

// Breadth First Traversal - Adjacency Matrix
#include <iostream>
#include <queue>
using namespace std;

void print(int **edges, int n, int sv, bool *visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (!q.empty()) {
        int front = q.front();
        cout << front << ' ';
        q.pop();

        for (int i = 0; i < n; i++) {
            if (!visited[i] and edges[front][i] == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void print(int **edges, int n) {
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            print(edges, n, i, visited);
        }
    }

    delete[] visited;
}

int main() {
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    print(edges, n);

    // Delete all the memory
    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;

    return 0;
}

/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph
*/
#include <iostream>

#include <queue>

using namespace std;
void singleComponentBFS(bool ** graph, int v, bool * visited, int vertex) {
    queue < int > pendingVertices;
    pendingVertices.push(vertex);
    visited[vertex] = true;
    while (!pendingVertices.empty()) {
        int frontVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << frontVertex << " ";
        for (int i = 0; i < v; ++i) {
            if (graph[frontVertex][i] && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(bool ** graph, int v) {
    bool * visited = new bool[v]();
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            singleComponentBFS(graph, v, visited, i);
        }
    }
    delete[] visited;
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
    BFS(graph, v);
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
}