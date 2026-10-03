/***
 * Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges. 
 * Then count the distinct 3-cycles in the graph.
 * A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
 * Test Cases:
    1. N = 3, M = 3
       Edges: 0 1, 1 2, 2 0

       => 1

    2. N = 6, M = 9
       Edges: 4 3, 4 0, 0 3, 3 1, 5 1, 5 3, 0 5, 0 2, 5 2

       => 4
 * Help: Check the notes or the hint video.
 ***/

// T: O(N^3), S: O(N^2)
#include <iostream>
using namespace std;

int find3CycleBetter(bool **graph, int v) {
    int count = 0;

    for(int i = 0; i < v - 2; i++) {
        for(int j = i + 1; j < v - 1; j++) {
            for(int k = j + 1; k < v; k++) {
                if(graph[i][j] and graph[j][k] and graph[k][i])
                    count++;
            }
        }
    }
    return count;
}

int find3Cycle(bool **graph, int v) {
    int count = 0;

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(graph[i][j]) {
                for(int k = 0; k < v; k++) {
                    if(graph[j][k] and graph[k][i])
                        count++;
                }
            }
        }
    }
    return count / 6;
}

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

    cout << find3Cycle(graph, v);

    // Delete all the memory
    for (int i = 0; i < v; i++)
        delete[] graph[i];
    delete[] graph;
}