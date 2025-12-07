//
// Created by Nestor Dzadzamia on 06.10.25.
//
#include <bits/stdc++.h>
using namespace std;

int i, n;
stack < pair<int, int> > st;
pair<int, int> p;
int main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        if (st.empty() || (p.first != st.top().first) &&
                           p.second != st.top().second) {
            st.push(p);
        } else {
            st.pop();
        }
    }

    cout << st.size();
}