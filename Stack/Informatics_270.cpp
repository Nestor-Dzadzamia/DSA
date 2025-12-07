//
// Created by Nestor Dzadzamia on 06.10.25.
//

#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty()) { st.push(s[i]); continue; }

        if (s[i] == '(' || s[i] == '[' || s[i] == '{') { st.push(s[i]); continue; }

        if (s[i] == ')' && st.top() == '(') { st.pop(); continue; }
        if (s[i] == ')' && st.top() != '(') { cout << "NO"; return 0; }
        if (s[i] == '}' && st.top() == '{') { st.pop(); continue; }
        if (s[i] == '}' && st.top() != '{') { cout << "NO"; return 0; }
        if (s[i] == ']' && st.top() == '[') { st.pop(); continue; }
        if (s[i] == ']' && st.top() != '[') { cout << "NO"; return 0; }
    }

    if (st.empty()) cout << "YES"; else cout << "NO";
}