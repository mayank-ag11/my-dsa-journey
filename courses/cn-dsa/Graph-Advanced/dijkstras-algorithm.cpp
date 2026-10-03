/***
 * Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
 * Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
 * 
 * Test Case:
    V = 4, E = 4
    Next E lines: v1 v2 w
    0 1 3
    0 3 5
    1 2 1
    2 3 8

    => 0 0
       1 3
       2 4
       3 5       
 ***/

// Using Adjacency Matrix
#include <iostream>
#include <climits>
using namespace std;

int minUnvisitedVertex(int *distances, bool *visited, int n) {
    int minV = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] and (minV == -1 or distances[i] < distances[minV]))
            minV = i;
    }
    return minV;
}

void DijkstraShortestPaths(int **graph, int n, int src) {
    bool *visited = new bool[n]();

    int *distances = new int[n]();
    for(int i = 0; i < n; i++)
        distances[i] = INT_MAX;
    
    distances[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        // Find the unvisited vertex with minimum distance from src
        int curr = minUnvisitedVertex(distances, visited, n);
        visited[curr] = true;

        // Explore the neighbors of curr vertex
        for(int j = 0; j < n; j++) {
            // TODO: Not sure why graph[curr][j] != -1 doesn't work
            if(!visited[j] and graph[curr][j] != 0) {
                int dist = distances[curr] + graph[curr][j];
                if(distances[j] > dist)
                    distances[j] = dist;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << i << ' ' << distances[i] << '\n';
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    // Making the adjacency matrix
    int **graph = new int*[n];
    for(int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
            // graph[i][j] = -1;
    }

    for(int i = 0, a, b, w; i < e; i++) {
        cin >> a >> b >> w;

        graph[a][b] = w;
        graph[b][a] = w;
    }

    DijkstraShortestPaths(graph, n, 0);

    // Delete all the memory
    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;
}

// Using Adjacency Lists
#include <iostream>
#include <climits>
#include <vector>
#include <list>
using namespace std;

class Edge {
   public:
    int dest;
    int pathlength;

    Edge(int d, int p) {
        this->dest = d;
        this->pathlength = p;
    }
};

int minUnvisitedVertex(int *distances, bool *visited, int n) {
    int minV = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] and (minV == -1 or distances[i] < distances[minV]))
            minV = i;
    }
    return minV;
}

void DijkstraShortestPaths(vector<list<Edge>> &adj, int n, int src) {
    bool *visited = new bool[n]();

    int *distances = new int[n]();
    for(int i = 0; i < n; i++)
        distances[i] = INT_MAX;
    
    distances[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        // Find the unvisited vertex with minimum distance from src
        int curr = minUnvisitedVertex(distances, visited, n);
        visited[curr] = true;

        // Explore the neighbors of curr vertex
        for(auto neighbor : adj[curr]) {
            // Not sure why neighbor.pathlength != 0 is required!
            if(!visited[neighbor.dest] and neighbor.pathlength != 0) {
                int dist = distances[curr] + neighbor.pathlength;
                if(distances[neighbor.dest] > dist)
                    distances[neighbor.dest] = dist;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << i << ' ' << distances[i] << '\n';
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    // Making the adjacency list
    vector<list<Edge>> adj(n);

    for(int i = 0, v1, v2, w; i < e; i++) {
        cin >> v1 >> v2 >> w;

        Edge e1(v2, w);
        Edge e2(v1, w);

        adj[v1].push_back(e1);
        adj[v2].push_back(e2);
    }

    DijkstraShortestPaths(adj, n, 0);
}