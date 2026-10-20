#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> a(4);
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    int target = sum / 2;
    std::sort(a.begin(), a.end());
    bool possible = false;
    if (a[0] + a[1] + a[2] == a[3] || a[0] + a[3] == a[1] + a[2] || a[0] + a[1] == a[2] + a[3]) {
        possible = true;
    }
    if (possible) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    return 0;
}