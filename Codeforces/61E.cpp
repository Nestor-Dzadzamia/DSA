#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, long long delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    long long range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // --- Coordinate compression ---
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    for (int &x : a)
        x = int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()) + 1;

    int maxVal = n; // because all are unique

    Fenwick bit1(maxVal), bit2(maxVal), bit3(maxVal);

    for (int x : a) {
        long long c1 = bit1.range_query(x + 1, maxVal    ]);
        long long c2 = bit2.range_query(x + 1, maxVal);

        bit1.update(x, 1);
        bit2.update(x, c1);
        bit3.update(x, c2);
    }

    cout << bit3.query(maxVal) << "\n";
}
