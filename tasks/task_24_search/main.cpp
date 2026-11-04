#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    size_t n, q, i=0;
    std::cin >> n >> q;

    int a, x;

    std::unordered_map<int, size_t> data;
    while (i < n) {
        std::cin >> x;
        data.insert({x,i});
        ++i;
    }

    while (q > 0) {
        std::cin >> a;
        auto it = data.find(a);
        if (it!= data.end()) {
           std::cout << it->second + 1 << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }


        q--;
}
}