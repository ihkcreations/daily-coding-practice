#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int q;
    if (!(std::cin >> q)) return 0;
    while (q--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        bool has_adjacent = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i + 1] - a[i] == 1) {
                has_adjacent = true;
                break;
            }
        }
        if (has_adjacent) std::cout << 2 << "\n";
        else std::cout << 1 << "\n";
    }
    return 0;
}