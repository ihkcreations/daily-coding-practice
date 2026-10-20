#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (!(std::cin >> n)) return 0;
    while (n--) {
        std::string s;
        std::cin >> s;
        if (s.length() > 10) {
            std::cout << s.front() << (s.length() - 2) << s.back() << "\n";
        } else {
            std::cout << s << "\n";
        }
    }
    return 0;
}