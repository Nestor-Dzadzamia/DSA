//
// Created by Nestor Dzadzamia on 07.12.25.
//

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m; cin >> n >> m;
    int mst_cost = 0;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected
    }

    vector<bool> used(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); // weight - vertexx

    while (!pq.empty()) {
        auto [weight, v] = pq.top();
        pq.pop();

        if (used[v]) continue;
        used[v] = true;

        mst_cost += weight;

        for (auto [to, w] : graph[v]) {
            if (!used[to]) {
                pq.push({w, to});
            }
        }
    }

    cout << "MST cost : " << mst_cost << endl;
    return 0;
}