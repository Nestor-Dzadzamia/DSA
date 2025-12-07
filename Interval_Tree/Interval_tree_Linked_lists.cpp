//
// Created by Nestor Dzadzamia on 30.10.25.
//

#include <bits/stdc++.h>
using namespace std;
int a,s,d,f,g,h,j,k,l,i,n,m;

struct tree {
    tree *left, *right;
    int jami;

    tree() {
        left = nullptr; right = nullptr;
        jami = 0;
    }
};

void update(tree* &t, int val, int idx, int lf = 0, int rg = n) {
    if (t == nullptr) t = new tree();
    t->jami += val;
    if (rg - lf == 1) return;

    if (idx < (lf + rg) / 2) update(t->left, val, lf, (lf + rg) / 2);
    else update(t->right, val, (lf + rg) / 2, rg);
}

int ans(tree* &t, int lf, int rg) {
    if (t == nullptr) return 0;

    if (lf >= a && rg <= s) {
        return t->jami;
    }
    if (lf >= s || rg <= a) return 0;

    return ans(t->left, lf, (rg + lf) / 2) + ans(t->right, (rg + lf)  / 2 , rg);
}

int main() {
    cin >> n >> m;

    tree *root = nullptr;
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        update(root, a, i);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &s);
        a--; s--;

        printf("%d\n", ans(root, 0, n));
    }
    return 0;
}