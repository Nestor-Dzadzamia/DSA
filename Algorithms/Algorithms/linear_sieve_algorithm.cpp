//
//  linear_sieve_algorithm.cpp
//  Algorithms
//
//  Created by Nestor Dzadzamia on 12.09.25.
//

#include <iostream>
using namespace std;

int num[1000001], pnum[100000];
int main() {
    int k = 0, n, j, i;
    cin >> n;
    
    for (i = 2; i <= n; i++) {
        if (num[i] == 0) {
            num[i] = i;
            pnum[k++] = i;
        }
        
        for (j = 0; ; j++) {
            if ( (j == k) || (i * pnum[j] > n) || (pnum[j] > num[i])) break;
            
            num[i * pnum[j]] = pnum[j];
        }
    }
    
    for (i = 2; i <= n; i++) {
        if (i == num[i]) cout << num[i] << " ";
    }
}
