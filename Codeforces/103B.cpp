//
// Created by Nestor Dzadzamia on 15.10.25.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int neighbour : graph[v]) {
        if (visited[neighbour] == false) dfs(neighbour);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) connected = false;
    }

    if (connected && m == n) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}