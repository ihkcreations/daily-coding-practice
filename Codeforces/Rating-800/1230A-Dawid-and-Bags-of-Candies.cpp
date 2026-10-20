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
    std::sort(a.begin(), a.end());
    if (sum % 2 != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    int target = sum / 2;
    if (a[0] + a[1] + a[2] == target || a[3] == target || a[0] + a[3] == target || a[1] + a[2] == target) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}