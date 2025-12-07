//
// Created by Nestor Dzadzamia on 11.10.25.
//

#include <ios>
#include <iosfwd>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct Fenwick {
    vector<ll> bit;
    int n;
    Fenwick(int n) : n(n) {
        bit.assign(n+1, 0);
    }

    // add val to index i
    void update(int i, ll val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    // sum from 1..i
    ll query(int i) {
        ll sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<Fenwick> tree(k + 1, Fenwick(n));

    for (int i = 0; i < n; i++) {
        tree[0].update(a[i], 1);

        for (int len = 1; len <= k; len++) {
            ll cnt = tree[len - 1].query(a[i] - 1);
            tree[len].update(a[i], cnt);
        }
    }

    ll answ = tree[k].query(n);
    cout << answ << endl;

    return 0;
}