#include <iostream>
#include <vector>
#include <list>
using namespace std;

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

    // list to check if a node is already visited
    vector<bool> visited(v, false);

    // The work starts here!
}