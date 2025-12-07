//
// Created by Nestor Dzadzamia on 15.10.25.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> depths; // node count on each depth i

void dfs(int node, int depth) {
    if (depth >= depths.size()) {
        depths.resize(depth + 1, 0);
    }

    depths[depth]++;

    for (int child : tree[node]) {
        dfs(child, depth + 1); // visit children, depth + 1
    }
}


int main() {
    int n;
    cin >> n;

    tree.assign(n + 1, {});

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    dfs(1, 0); // start from root, depth = 0 node = 1

    int answer = 0;
    for (int depth : depths) {
        if (depth % 2 == 1) answer++;
    }

    cout << answer << endl;
}