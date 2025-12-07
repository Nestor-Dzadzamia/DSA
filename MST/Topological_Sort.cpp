//
// Created by Nestor Dzadzamia on 07.12.25.
//

// Topological Sort (DFS)

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<bool> used;
vector<int> ans;

void dfs(int v) {
    used[v] = true;

    for (size_t i = 0; i < g[v].size(); i++) {
        int neighbour = g[v][i];
        if (!used[neighbour]) {
            dfs(neighbour);
        }
    }
    ans.push_back(v);
}

void topological_sort() {
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    ans.clear();
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());

}

int main() {
    g.assign(n, vector<int>(n));
    used.assign(n, false);


    return 0;
}