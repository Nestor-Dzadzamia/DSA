//
// Created by Nestor Dzadzamia on 06.10.25.
//
#include <bits/stdc++.h>
using namespace std;

int c, n, k, i, a[100001];
stack<int> s;
int main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> c;
        a[c] = 1;

        while (s.size() > 0 && c > s.top()) {
            a[c] = max(a[c], a[s.top()] + 1);
            s.pop();
        }
        if (s.size() == 0) a[c] = 0;
        s.push(c);
        k = max(k, a[c]);
    }

    cout << k;
}