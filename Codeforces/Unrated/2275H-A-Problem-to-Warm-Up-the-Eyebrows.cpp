#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    vector<vector<long long>> p(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p[i + 1][j + 1] = (a[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j]) % MOD;
            if (p[i + 1][j + 1] < 0) p[i + 1][j + 1] += MOD;
        }
    }
    long long ans = 0;
    for (int r1 = 0; r1 < n; ++r1) {
        for (int r2 = r1 + 1; r2 <= n; ++r2) {
            int dr = r2 - r1;
            long long s0 = 0, s1 = 0, s0sq = 0, s1sq = 0;
            for (int c = 0; c <= m; ++c) {
                long long s = (p[r2][c] - p[r1][c] + MOD) % MOD;
                if ((dr + c) % 2 == 0) {
                    ans = (ans + s * s % MOD * (m - c + 1) % MOD - 2 * s * s1 % MOD + s1sq) % MOD;
                    s0 = (s0 + s) % MOD;
                    s0sq = (s0sq + s * s) % MOD;
                } else {
                    ans = (ans - (s * s % MOD * (m - c + 1) % MOD - 2 * s * s0 % MOD + s0sq) % MOD + MOD) % MOD;
                    s1 = (s1 + s) % MOD;
                    s1sq = (s1sq + s * s) % MOD;
                }
            }
        }
    }
    cout << (ans + MOD) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}