//
// Created by Nestor Dzadzamia on 14.10.25.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    priority_queue<pair<int, int>> pq; // {count, size}

    for (auto &[size, count] : freq) {
        pq.push({count, size});
    }



    vector<array<int, 3>> result;

    while (pq.size() >= 3) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        auto c = pq.top(); pq.pop();

        result.push_back({a.second, b.second, c.second});

        if (--a.first > 0) pq.push(a);
        if (--b.first > 0) pq.push(b);
        if (--c.first > 0) pq.push(c);
    }

    cout << result.size() << endl;

    for (auto &triple : result) {
        sort(triple.begin(), triple.end(), greater<int>());
        cout << triple[0] << " " << triple[1] << " " << triple[2] << endl;
    }
}