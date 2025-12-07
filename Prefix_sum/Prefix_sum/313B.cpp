//
//  313B.cpp
//  Prefix_sum
//
//  Created by Nestor Dzadzamia on 12.09.25.
//

#include <iostream>
using namespace std;


string s;
int i, x, y, n, m, d[100005];
int main() {
    cin >> s;
    n = s.size();
    
    for (i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            d[i] = d[i - 1] + 1;
        } else {
            d[i] = d[i - 1];
        }
    }
    
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        cout << d[y - 1] - d[x - 1] << endl;
    }
}
