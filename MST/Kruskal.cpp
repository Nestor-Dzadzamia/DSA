//
// Created by Nestor Dzadzamia on 07.12.25.
//

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.reserve(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] =  find(parent[x]); // path compressing
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false; // already same
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

int main() {
    int n, m; cin >> n >> m;

    vector<tuple<int, int, int>> edges; // weight, v1, v2

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mst_cost = 0;
    vector<pair<int, int>> mst_edges;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst_cost += w;
            mst_edges.emplace_back(u, v);
        }
    }

    cout << "MST cost : " << mst_cost << endl;

    for (auto [u, v] : mst_edges) {
        cout << u << " - " << v << endl;
    }

    return 0;
}