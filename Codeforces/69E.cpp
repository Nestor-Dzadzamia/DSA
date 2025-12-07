
#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
set<int> s;
int n, k, t, a[100005];
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[i] = t;

        if (++m[t]==1) s.insert(t);
        else s.erase(t);

        if (i<k-1) continue; // jer pirvel k shi vart

        t=a[i-k];
        if (--m[t]==1) s.insert(t);
        else s.erase(t);

        if (s.size()) cout << (*(--s.end())) << endl;
        else cout << "Nothing" << endl;
    }
}