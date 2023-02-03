#include <bits/stdc++.h>
    using namespace std;

const int N = 1e6 + 10;
long long pre[N];

int main() {
    int n, x, q, l, r;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        pre[i] = x + pre[i-1];
    }

    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }

    return 0;
}