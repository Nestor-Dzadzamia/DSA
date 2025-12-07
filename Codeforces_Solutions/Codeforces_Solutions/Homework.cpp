//
//  Homework.cpp
//  Codeforces_Solutions
//
//  Created by Nestor Dzadzamia on 30.09.25.
//

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int n, m;
int a[500000];
int eratos[MAXN];
int divs[MAXN];

void eratosthen() {
    for (int i = 2; i < MAXN; i++) {
        eratos[i] = i;
    }

    for (int i = 2; i * i < MAXN; i++) {
        if (eratos[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (eratos[j] == j) {
                    eratos[j] = i;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    int maxinput = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxinput = max(a[i], maxinput);
    }

    eratosthen();

    memset(divs, 0, sizeof(divs));

    for (int i = 0; i < n; i++) {
        int value = a[i];
        while (value > 1) {
            int divisor = eratos[value], cnt = 0;
            while (value % divisor == 0) {
                cnt++;
                value /= divisor;
            }
            divs[divisor] = max(divs[divisor], cnt);
        }
    }

    long long res = 1;
    for (int i = 2; i <= maxinput; i++) {
        if (divs[i] > 0) {
            res = (res * (divs[i] + 1)) % m;
        }
    }

    cout << ((res - n + m) % m) << endl;

    return 0;
}
