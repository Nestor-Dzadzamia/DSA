//
//  main.cpp
//  Sorting_Algorithms
//
//  Created by Nestor Dzadzamia on 29.09.25.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, i, j, mx, idx;
    cin >> n;
    
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (i = 0; i <= n - 1; i++) {
        for (j = 1; j <= n-1; j++) {
            if (a[j-1] > a[j]) swap(a[j-1], a[j]);
        }
        
        for (j=n-1; j >= 1; j--) {
            if (a[j] < a[j-1]) swap(a[j-1], a[j]);
        }
    }
    
    for (i=0; i<n; i++) {
        cout << a[i] << " ";
    }
}
