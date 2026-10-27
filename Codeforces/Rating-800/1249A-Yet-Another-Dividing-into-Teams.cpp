#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        bool has_adjacent = false;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; ++i) {
            if (a[i + 1] - a[i] == 1) {
                has_adjacent = true;
                break;
            }
        }
        if (has_adjacent) std::cout << 2 << std::endl;
        else std::cout << 1 << std::endl;
    }
    return 0;
}