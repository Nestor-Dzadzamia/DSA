//
//  main.cpp
//  Sorting_Algorithms
//
//  Created by Nestor Dzadzamia on 29.09.25.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, i, j, min, idx;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (i = 0; i < n; i++) {
        min = a[i]; idx = i;
        for (j = i + 1; j < n; j++) {
            if (min > a[j]) {
                min = a[j];
                idx = j;
            }
        }
        
        swap(a[i], a[idx]);
    }
    
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
 
