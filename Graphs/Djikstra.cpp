//
// Created by Nestor Dzadzamia on 09.12.25.
//

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n); // graph[i] = vector of (i, weight)

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // since graph is directed, if not we remove this line
    }

    int start_vertex; cin >> start_vertex;
    vector<long long> distances(n, INF);
    distances[start_vertex] = 0;

    // min-heap - (distance, vertex)
    priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> pq;

    pq.push({0, start_vertex});

    while (!pq.empty()) {
        auto [distance, vertex] = pq.top(); pq.pop();

        if (distance > distances[vertex]) continue; // outdated entry, so we need to skip

        for (auto [neighbor_vertex, weight] : graph[vertex]) {
            if (distances[vertex] + weight < distances[neighbor_vertex]) { // check for relaxation
                distances[neighbor_vertex] = distances[vertex] + weight;
                pq.push({distances[neighbor_vertex], neighbor_vertex});
            }
        }
    }

    // print distances

    for (int i = 0; i < n; i++) {
        if (distances[i] == INF) cout << "INF ";
        else cout << distances[i] << " ";
    }

    cout << endl;

    return 0;
}
