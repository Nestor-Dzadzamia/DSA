//
// Created by Nestor Dzadzamia on 11.10.25.
//

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n+1, 0) {}

    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query (int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    int range_sum(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<Fenwick> fenwicks(26, Fenwick(n));

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        fenwicks[c].update(i + 1, 1);
    }

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 2) {
            int l, r;
            cin >> l >> r;
            int distinct = 0;
            for (int c = 0; c < 26; c++) {
                if (fenwicks[c].range_sum(l, r) > 0) {
                    distinct++;
                }
            }

            cout << distinct << endl;
        } else {
            int pos;
            char ch;
            cin >> pos >> ch;

            int old_c = s[pos - 1] - 'a';
            int new_c = ch - 'a';

            if (old_c != new_c) {
                fenwicks[old_c].update(pos, -1);
                fenwicks[new_c].update(pos, +1);
                s[pos - 1] = ch;
            }
        }
    }
}