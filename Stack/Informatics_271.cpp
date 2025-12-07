//
// Created by Nestor Dzadzamia on 06.10.25.
//

#include <iostream>
#include <stack>
using namespace std;
int n, m, x, y, k, i;
stack <int> st;
int main() {
    cin >> n >> m;
    st.push(0);
    for (i = 0; i < n; i++) {
        cin >> y >> x;
        if (st.top() < x) {
            st.push(x);
            continue;
        }

        while (st.top() > x) {
            st.pop();
            k++;
        }

        if (x > st.top()) st.push(x);
    }

    cout << k + st.size() - 1 << endl;
}