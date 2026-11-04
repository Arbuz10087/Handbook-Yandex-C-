#include <iostream>
#include <numeric>
#include <map>


int main() {
    int n, x, y;
    std::cin >> n;
    std::map <std::pair<int, int>, int> data;
    for (int i = 0; i != n; ++i) {
        std::cin >> x >> y;
        if (y != 0) {
            int nod = std::gcd(x,y);
            x/= nod;
            y/= nod;
        }
        ++data[{x, y}];
    }
    int max = data.begin()->second;
    std::pair<int, int> result = data.begin()->first;
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->second > max || (it->second == max && (static_cast<double>(it->first.first)/it->first.second < static_cast<double>(result.first)/result.second))) {
            max = it->second;
            result = it->first;
        }
    }
    std::cout << result.first <<" " <<result.second;


}