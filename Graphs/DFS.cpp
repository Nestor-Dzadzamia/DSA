//
// Created by Nestor Dzadzamia on 07.12.25.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> in, out; // enter and leave times for each vertice
int timer = 0;

void DFS(int v) {
    visited[v] = true;
    in[v] = ++timer;
    for (const int neighbour : graph[v]) {
        if (!visited[neighbour]) DFS(neighbour);
    }
    out[v] = ++timer;
}

int main() {
    int n = 6;
    graph = {
        {1, 2},
        {0, 3 , 4},
        {0, 5},
        {1},
        {1},
        {2}
    };

    visited.assign(n, false);
    in.assign(n, 0);
    out.assign(n, 0);

    DFS(0);

    for (int v = 0; v < n; v++) {
        cout << v << "       " << in[v] << "       " << out[v] << endl;
    }

    return 0;
}
