#include <iostream>

int main() {
    int w;
    if (!(std::cin >> w)) return 0;
    if (w > 2 && w % 2 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}