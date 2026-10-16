#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1000000007;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pref[i + 1][j + 1] = (a[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j]) % MOD;
            if (pref[i + 1][j + 1] < 0) pref[i + 1][j + 1] += MOD;
        }
    }
    
    long long total_even_r = 0, total_odd_r = 0;
    vector<long long> C_even(m + 1, 0), C_odd(m + 1, 0);
    
    for (int r1 = 0; r1 < n; ++r1) {
        for (int r2 = r1 + 1; r2 <= n; ++r2) {
            int len_r = r2 - r1;
            long long sum_c_even = 0, sum_c_odd = 0;
            for (int c = 1; c <= m; ++c) {
                long long val = (pref[r2][c] - pref[r1][c]) % MOD;
                if (val < 0) val += MOD;
                if (c % 2 == 0) {
                    sum_c_even = (sum_c_even + val) % MOD;
                } else {
                    sum_c_odd = (sum_c_odd + val) % MOD;
                }
            }
        }
    }
    
    long long ans = 0;
    for (int r1 = 0; r1 < n; ++r1) {
        for (int r2 = r1 + 1; r2 <= n; ++r2) {
            int len_r = r2 - r1;
            for (int c1 = 0; c1 < m; ++c1) {
                for (int c2 = c1 + 1; c2 <= m; ++c2) {
                    long long s = (pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1]) % MOD;
                    if (s < 0) s += MOD;
                    long long sq = (s * s) % MOD;
                    if ((len_r + (c2 - c1)) % 2 == 0) {
                        ans = (ans + sq) % MOD;
                    } else {
                        ans = (ans - sq + MOD) % MOD;
                    }
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
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}