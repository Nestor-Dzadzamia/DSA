//
// Created by Nestor Dzadzamia on 07.12.25.
//
#include <bits/stdc++.h>
using namespace std;

// BFS on Undirected graph

void readGraph(vector<vector<int>> &graph) {
    while (true) {
        int from, to;
        cin >> from >> to;
        if (from == -1 || to == -1) break;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

int main() {
    int n, s; // n : number of vertices. s : starting vertice
    cin >> n >> s;
    queue<int> q;
    vector<vector<int>> graph(n);

    readGraph(graph);

    q.push(s);
    vector<bool> used(n);
    vector<int> d(n), p(n); // d for distances and p for parents
    used[s] = true;
    p[s] = -1;
    d[s] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (size_t i = 0; i < graph[v].size(); i++) {
            int neighbour = graph[v][i];

            if (!used[neighbour]) {
                used[neighbour] = true;
                q.push(neighbour);
                d[neighbour] = d[v] + 1;
                p[neighbour] = v;
            }
        }
    }

    // finding path
    int vertice;
    cin >> vertice; // find path from vertice to s (starting vertice)

    if (!used[vertice]) cout << "NO path" << endl;
    else {
        vector<int> path;
        while (true) {
            if (p[vertice] == -1) break;
            else {
                path.push_back(p[vertice]);
                vertice = p[vertice];

            }
        }
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i]  << " ";
        }
    }
}