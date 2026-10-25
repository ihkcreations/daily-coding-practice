#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int count = 0;
        int op2 = std::min(b, c / 2);
        count += op2 * 3;
        b -= op2;
        int op1 = std::min(a, b / 2);
        count += op1 * 3;
        std::cout << count << std::endl;
    }
    return 0;
}