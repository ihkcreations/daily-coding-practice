#include <iostream>
#include <algorithm>

int main() {
    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int total = 0;
        int op2 = std::min(b, c / 2);
        total += op2 * 3;
        b -= op2;
        int op1 = std::min(a, b / 2);
        total += op1 * 3;
        std::cout << total << std::endl;
    }
    return 0;
}