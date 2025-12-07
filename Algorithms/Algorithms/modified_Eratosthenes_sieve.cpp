
#include <iostream>
using namespace std;

int i, n, j, num[10000001];

int main() {
    cin >> n;
    
    for (i = 2; i <= n; i++) {
        if (num[i] > 0) continue;
        
        for (j = i * i; j <= n; j = j + i) {
            if (num[j] == 0) {
                num[j] = i;
            }
        }
    }
    
    while (num[n] != 0) {
        cout << num[n] << " ";
        n = n / num[n];
    }
    
    cout << n;
}

void test() {
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        if (num[i] > 0) continue;
        
        for (j = i * i; j <= n; j = j + i) {
            if (num[j] == 0) num[j] = i;
        }
    }
    
    while (num[n] != 0) {
        cout << num[n] << " ";
        n = n / num[n];
    }
    
    cout << n;
    
    
}

