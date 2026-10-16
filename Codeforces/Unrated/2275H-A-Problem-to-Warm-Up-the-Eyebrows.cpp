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
        }
    }
    long long total = 0;
    for (int r1 = 0; r1 < n; ++r1) {
        for (int r2 = r1 + 1; r2 <= n; ++r2) {
            for (int c1 = 0; c1 < m; ++c1) {
                for (int c2 = c1 + 1; c2 <= m; ++c2) {
                    long long s = (pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1]) % MOD;
                    long long sq = (s * s) % MOD;
                    if (((r2 - r1) + (c2 - c1)) % 2 == 0) {
                        total = (total + sq) % MOD;
                    } else {
                        total = (total - sq + MOD) % MOD;
                    }
                }
            }
        }
    }
    cout << (total + MOD) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}