/***
 * Prim's Algorithm to find the MST of a graph:
 * 
 * Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
 * Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
 * For printing MST follow the steps -
    1. In one line, print an edge which is part of MST in the format -
    v1 v2 w
    where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w.
    And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
    2. Print V-1 edges in above format in different lines.
    3. Order of different edges doesn't matter.
 *
 * Test Case:
    V = 4, E = 4
    Next E lines: v1 v2 w
    0 1 3
    0 3 5
    1 2 1
    2 3 8

    => 0 1 3
       1 2 1
       0 3 5
 ***/

#include <iostream>
#include <climits>
using namespace std;

int minUnvisitedVertex(int *minWeight, bool *visited, int n) {
    int minV = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] and (minV == -1 or minWeight[i] < minWeight[minV]))
            minV = i;
    }
    return minV;
}

void Prim(int **graph, int n) {
    bool *visited = new bool[n]();

    int *minWeight = new int[n]();
    for(int i = 0; i < n; i++)
        minWeight[i] = INT_MAX;

    int *parent = new int[n]();
    
    // Taking vertex 0 as source
    minWeight[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n - 1; i++) {
        // Find the unvisited vertex with minimum weight
        int curr = minUnvisitedVertex(minWeight, visited, n);
        visited[curr] = true;

        // Explore the neighbors of curr vertex
        for(int j = 0; j < n; j++) {
            // TODO: Not sure why graph[curr][j] != -1 doesn't work
            if(!visited[j] and graph[curr][j] != 0) {
                if(graph[curr][j] < minWeight[j]) {
                    parent[j] = curr;
                    minWeight[j] = graph[curr][j];
                }
            }
        }
    }

    // Printing the MST
    for(int i = 1; i < n; i++) {
        if(parent[i] < i) {
            cout << parent[i] << ' ' << i;
        }
        else {
            cout << i << ' ' << parent[i];
        }
        cout << ' ' << minWeight[i] << '\n';
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

    Prim(graph, n);

    // Delete all the memory
    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;
}