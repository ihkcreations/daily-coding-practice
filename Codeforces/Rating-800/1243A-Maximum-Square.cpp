#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    if (!(std::cin >> k)) return 0;
    while (k--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end(), std::greater<int>());
        int max_side = 0;
        for (int i = 0; i < n; ++i) {
            int side = std::min(a[i], i + 1);
            if (side > max_side) {
                max_side = side;
            }
        }
        std::cout << max_side << "\n";
    }
    return 0;
}