/***
 * Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
 * 
 * Notes:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
    3. You need to take input in main and create a function which should return all the connected components.
    And then print them in the main, not inside function.
 *
 * Print different components in new line.
 * And each component should be printed in increasing order (separated by space).
 * Order of different components doesn't matter.
 * 
 * Test Cases:
    V = 4, E = 3
    Edges: 0 1, 1 3, 0 3

    => 0 1 3
       2
 ***/

// Using Adjacency Matrix
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(bool **graph, int v, int src, vector<bool> &visited, vector<int> &list) {
    list.push_back(src);
    visited[src] = true;

    for(int i = 0; i < v; i++) {
        if(graph[src][i] == 1 and !visited[i])
            dfs(graph, v, i, visited, list);
    }
}

vector<vector<int>> allConnectedComponents(bool **graph, int v) {
    vector<vector<int>> lists;
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            vector<int> list;
            dfs(graph, v, i, visited, list);
            lists.push_back(list);
        }
    }

    return lists;
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

    vector<vector<int>> lists = allConnectedComponents(graph, v);
    for(int i = 0; i < lists.size(); i++) {
        sort(lists[i].begin(), lists[i].end());
        for(int j = 0; j < lists[i].size(); j++) {
            cout << lists[i][j] << ' ';
        }
        cout << '\n';
    }

    // Delete all the memory
    for (int i = 0; i < v; i++)
        delete[] graph[i];
    delete[] graph;
}

// Using Adjacency Lists
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void dfs(vector<list<int>> &adj, int v, int src, vector<bool> &visited, vector<int> &list) {
    if(visited[src]) return;

    list.push_back(src);
    visited[src] = true;

    for(auto neighbor : adj[src]) {
        dfs(adj, v, neighbor, visited, list);
    }
}

vector<vector<int>> allConnectedComponents(vector<list<int>> &adj, int v) {
    vector<vector<int>> lists;
    vector<bool> visited(v, false);

    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            vector<int> list;
            dfs(adj, v, i, visited, list);
            lists.push_back(list);
        }
    }

    return lists;
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

    vector<vector<int>> lists = allConnectedComponents(adj, v);
    for(int i = 0; i < lists.size(); i++) {
        sort(lists[i].begin(), lists[i].end());
        for(int j = 0; j < lists[i].size(); j++) {
            cout << lists[i][j] << ' ';
        }
        cout << '\n';
    }
}

// Coding Ninjas Solution, using Breadth First Traversal
/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> getOneComponent(bool **graph, int startingVertex, int v, bool *visited) {
    vector<int> component;
    queue<int> pendingNodes;
    pendingNodes.push(startingVertex);
    visited[startingVertex] = true;
    while (!pendingNodes.empty()) {
        int current = pendingNodes.front();
        pendingNodes.pop();
        component.push_back(current);
        for (int i = 0; i < v; ++i) {
            if (graph[current][i] && !visited[i]) {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return component;
}
vector<vector<int>> getAllComponents(bool ** graph, int v) {
    vector<vector<int>> result;
    bool * visited = new bool[v]();
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            vector<int> component = getOneComponent(graph, i, v, visited);
            result.push_back(component);
        }
    }
    delete[] visited;
    return result;
}
int main() {
    int v, e;
    cin >> v >> e;
    bool ** graph = new bool * [v];
    for (int i = 0; i < v; i++) {
        graph[i] = new bool[v]();
    }
    for (int i = 0, a, b; i < e; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vector<vector<int>> connectedComponenents = getAllComponents(graph, v);
    for (int i = 0; i < connectedComponenents.size(); i++) {
        sort(connectedComponenents[i].begin(), connectedComponenents[i].end());
        for (int j = 0; j < connectedComponenents[i].size(); j++) {
            cout << connectedComponenents[i][j] << " ";
        }
        cout << "\n";
    }
}