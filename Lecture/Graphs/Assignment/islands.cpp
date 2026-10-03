/***
 * Problem: No. of Connected Components
 * An island is a small piece of land surrounded by water.
 * A group of islands is said to be connected if we can reach from any given island to any other island in the same group.
 * Given V islands (numbered from 1 to V) and E connections or edges between islands.
 * Can you count the number of connected groups of islands.
 * 
 * Test Case:
    V = 5, E = 8
    Edges: 0 1, 0 4, 1 2, 2 0, 2 4, 3 0, 3 2, 4 3

    => 1
 ***/

// Using Adjacency Lists
#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool exploreDFS(vector<list<int>> &adj, int v, int src, bool *visited) {
    if(visited[src]) return false;

    visited[src] = true;

    for(auto neighbor : adj[src]) {
        exploreDFS(adj, v, neighbor, visited);
    }

    return true;
}

int countConnectedComponents(vector<list<int>> &adj, int v) {
    bool *visited = new bool[v]();

    int count = 0;
    for(int i = 0; i < v; i++) {
        if(!visited[i] and exploreDFS(adj, v, i, visited))
            count++;
    }

    delete[] visited;
    return count;
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

    cout << countConnectedComponents(adj, v);
}

// Coding Ninjas Solution in Java
// Using Adjacency Matrix
/*
Time complexity: O(N^2)
Space complexity: O(N^2)
where N is the number of vertex in the graph
*/
public class Solution {
    public static int numConnected(int[][] edges, int n) {
        boolean[] visited = new boolean[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(edges, i, visited, n);
                count++;
            }
        }
        return count;
    }
    private static void dfs(int[][] edges, int v1, boolean[] visited, int n) {
        visited[v1] = true;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false && edges[v1][i] == 1) {
                dfs(edges, i, visited, n);
            }
        }
    }
}