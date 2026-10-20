#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;
    while (n--) {
        std::string s;
        std::cin >> s;
        if (s.length() > 10) {
            std::cout << s.front() << s.length() - 2 << s.back() << std::endl;
        } else {
            std::cout << s << std::endl;
        }
    }
    return 0;
}