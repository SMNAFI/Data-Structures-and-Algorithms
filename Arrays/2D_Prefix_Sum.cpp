#include <bits/stdc++.h>
    using namespace std;

const int N = 1e3 + 10;
long long pre[N][N];

int main() {
    int n, q, a, b, c, d;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            pre[i][j] = x + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    cin >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        cout << pre[c][d] - pre[c][b-1] - pre[a-1][d] + pre[a-1][b-1] << '\n';
    }

    return 0;
}