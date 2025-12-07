//
// Created by Nestor Dzadzamia on 06.12.25.
//

#include <bits/stdc++.h>
using namespace std;

int i, n, x;
set <int> st;
set <int>::iterator it;
int main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x;

        it = st.lower_bound(x);
        if (it == st.end()) {
            st.insert(x);
        } else {
            st.erase(it);
            st.insert(x);
        }
    }

    cout << st.size() << endl;
}