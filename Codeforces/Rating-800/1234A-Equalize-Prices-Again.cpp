#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    if (!(std::cin >> q)) return 0;
    while (q--) {
        int n;
        std::cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            std::cin >> a;
            sum += a;
        }
        long long ans = (sum + n - 1) / n;
        std::cout << ans << "\n";
    }
    return 0;
}