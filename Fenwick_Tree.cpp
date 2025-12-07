//
// Created by Nestor Dzadzamia on 11.10.25.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> make(vector<int> arr) {
    vector<int> fenwick_tree = arr;

    for (int i = 0; i < arr.size(); i++) {
        int p = i + (i & -i); // index to parent
        if (p < arr.size()) {
            fenwick_tree[p] += fenwick_tree[i];
        }
    }
    return fenwick_tree;
}
int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5};
    vector<int> fenwick_tree = make(arr);

    for (int i : fenwick_tree) {
        cout << i << " ";
    }
    return 0;
}