
#include <iostream>
using namespace std;

bool num[1000001];

void optimizedSieve() {
    long long i, n, j;
    cin >> n;
    
    for (i = 2; i * i <= n; i++) {
        if (num[i] == 1) continue;
        
        cout << i << " ";
        
        for (j = i * i; j <= n; j = j + i) {
            num[j] = 1;
        }
    }
    
    for (i = 2; i <= n; i++) {
        if (num[i] != 1) cout << i << " ";
    }
}

int main1(int argc, const char * argv[]) {
    long long i, n, j;
    cin >> n;
    
    for (i = 2; i <= n; i++) {
        if (num[i] == 1) continue;
        
        cout << i << " ";
        
        for (j = i *  i; j <= n; j = j + i) {
            num[j] = 1;
        }
    }
    
    return 0;
}
