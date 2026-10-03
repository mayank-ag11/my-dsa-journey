/***
 * Kruskal's Algorithm to find the MST of a graph:
 * 
 * Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
 * Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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

    => 1 2 1
       0 1 3
       0 3 5
 ***/

// T: O(ElogE + EV), S: O(V + E)
#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
   public:
    int source;
    int dest;
    int weight;

    void set(int v1, int v2, int w) {
        this->source = v1;
        this->dest = v2;
        this->weight = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int v, int *parent) {
    if(parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

Edge* Kruskal(Edge *graph, int n, int e) {
    Edge *mst = new Edge[n - 1];

    // Sort the graph in ascending order by weight
    sort(graph, graph + e, cmp);

    // Parent array
    int *parent = new int[n];
    for(int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0;
    int i = 0;

    while(count != n - 1) {
        Edge curr = graph[i];

        int sourceParent = findParent(curr.source, parent);
        int destParent = findParent(curr.dest, parent);

        // If the parents are not same, it means that they are not from the same component
        // Add the edge to the MST, as it won't create a cycle
        if(sourceParent != destParent) {
            if(curr.source > curr.dest)
                swap(curr.source, curr.dest);
            
            mst[count] = curr;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    return mst;
}

int main() {
    int n, e;
    cin >> n >> e;

    Edge *graph = new Edge[e];

    for(int i = 0; i < e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        
        graph[i].set(v1, v2, w);
    }

    Edge *mst = Kruskal(graph, n, e);

    for(int i = 0; i < n - 1; i++) {
        cout << mst[i].source << ' ' << mst[i].dest << ' ' << mst[i].weight << '\n';
    }
}

// First Try
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
   public:
    int source;
    int dest;
    int weight;
    
    Edge() {}

    Edge(int v1, int v2, int w) {
        source = v1;
        dest = v2;
        weight = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

vector<Edge> MST(vector<Edge> &graph, int v, int e) {
    vector<Edge> mst(v-1);

    // Sort the graph in ascending order by weight
    sort(graph.begin(), graph.end(), cmp);

    // Parent array
    int *p = new int[v];
    for(int i = 0; i < v; i++)
        p[i] = i;

    for(int i = 0, j = 0; i < v - 1; j++) {
        Edge curr = graph[j];

        int p1 = p[curr.source];
        int p2 = p[curr.dest];

        while(p[p1] != p1) {
            p1 = p[p1];
        }

        while(p[p2] != p2) {
            p2 = p[p2];
        }

        // If the parents are not same, it means that they are not from the same component
        // Add the edge to the MST, as it won't create a cycle
        if(p1 != p2) {
            if(curr.source > curr.dest)
                swap(curr.source, curr.dest);
            
            mst[i] = curr;
            i++;
            p[p1] = p2;
        }
    }
    return mst;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<Edge> graph(e);

    for(int i = 0; i < e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        Edge e(v1, v2, w);
        graph[i] = e;
    }

    vector<Edge> mst = MST(graph, v, e);

    for(int i = 0; i < mst.size(); i++) {
        cout << mst[i].source << ' ' << mst[i].dest << ' ' << mst[i].weight << '\n';
    }
}