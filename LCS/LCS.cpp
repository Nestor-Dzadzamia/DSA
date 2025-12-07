//
// Created by Nestor Dzadzamia on 02.12.25.
//

#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2, int m, int n) {
    int arr[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) arr[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) arr[i][j] = 1 + arr[i - 1][j - 1];
            else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }

    int index = arr[m][n], i = m, j = n;
    char lcs[index + 1];
    lcs[index] = '\0';

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1] = s1[i - 1];
            i--; j--; index--;
        } else if (arr[i - 1][j] > arr[i][j - 1]) i--;
        else j--;
    }

    cout << "S1: " << s1 << "\nS2: " << s2 << "\nLCS: " << lcs << "\n";
}

int main() {
    string str1 = "ACADB"; string str2 = "ACBDAB";
    int m = str1.size(); int n = str2.size();
    lcs(str1, str2, m, n)
    return 0;
}