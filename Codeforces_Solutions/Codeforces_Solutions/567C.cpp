//
//  main.cpp
//  Codeforces_Solutions
//
//  Created by Nestor Dzadzamia on 30.09.25.
//

#include <iostream>
#include "map"
using namespace std;

int main() {
    int n, k;
    long long sol = 0, a[200005];
    map<long long, long long> leftmap, rightmap;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        rightmap[a[i]]++;
    }
    leftmap[a[1]]++; rightmap[a[1]]--;
    
    for (int i = 2; i < n; i++) {
        rightmap[a[i]]--;
        
        if (a[i] % k == 0 ) sol+=leftmap[a[i]/k]*rightmap[a[i] * k];
        leftmap[a[i]]++;
    }
    
    cout << sol;
}
