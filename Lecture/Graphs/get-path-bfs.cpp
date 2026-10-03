/***
 * Given an undirected graph G(V, E) and two vertices v1 and v2(as integers)
 * find and print the path from v1 to v2 (if exists).
 * Print nothing if there is no path between v1 and v2.
 * Find the path using BFS and print the shortest path available.
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
#include <unordered_map>
#include <queue>
using namespace std;

vector<int>* getPathBFS(bool **graph, int v, int src, int dst, bool *visited) {
    vector<int> *path = NULL;
    unordered_map<int, int> map;
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        if(front == dst) {
            path = new vector<int>();
            break;
        }

        for(int i = 0; i < v; i++) {
            if(!visited[i] and graph[front][i] == 1) {
                q.push(i);
                visited[i] = true;
                map[i] = front;
            }
        }
    }

    if(path != NULL) {
        int curr = dst;
        while(curr != src) {
            path->push_back(curr);
            curr = map[curr];
        }
        path->push_back(src);
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

    vector<int> *path = getPathBFS(graph, v, v1, v2, visited);
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

// Coding Ninjas Solution
/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector < int > * getBFSPath(bool ** graph, int v, int start, int end) {
    queue < int > pendingVertices;
    bool * visited = new bool[v]();
    pendingVertices.push(start);
    visited[start] = true;
    bool pathFound = false;
    vector < int > parent(v, -1);
    while (!pendingVertices.empty() && !pathFound) {
        int front = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < v; i++) {
            if (graph[front][i] && !visited[i]) {
                parent[i] = front;
                pendingVertices.push(i);
                visited[i] = true;
                if (i == end) {
                    pathFound = true;
                    break;
                }
            }
        }
    }
    delete[] visited;
    if (!pathFound) {
        return NULL;
    }
    vector < int > * output = new vector < int > ();
    int current = end;
    output -> push_back(end);
    while (current != start) {
        current = parent[current];
        output -> push_back(current);
    }
    return output;
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
    int start, end;
    cin >> start >> end;
    vector < int > * output = getBFSPath(graph, v, start, end);
    if (output != NULL) {
        for (int i = 0; i < output -> size(); ++i) {
            cout << output -> at(i) << " ";
        }
        delete output;
    }
    for (int i = 0; i < v; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
}