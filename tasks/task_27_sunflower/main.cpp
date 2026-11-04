#include <set>
#include <iostream>
#include <vector>

int main() {
    size_t n, m, k =0;
    int x;
    std::cin >> n;
    std::multiset<int> multi_data;
    std::set<int> data;
    std::vector<size_t> mmm;

    for (size_t i = 0; i < n; ++i) {
      std::cin >> m;
      mmm.push_back(m);
      for (size_t j = 0; j < m; ++j) {
          std::cin >> x;
          data.insert(x);
          multi_data.insert(x);
      }
    }

    for (const int& elem : data) {
        if (multi_data.count(elem) == n) {
            ++k;
        }
    }

    if (k > 0 && (multi_data.size()- k*(n-1)== data.size())) {
        std::cout << "YES" << std::endl;
        std::cout <<k << std::endl;
        for (size_t m : mmm) {
            std::cout << m -k << " ";
        }
    } else {
        std::cout << "NO";
    }

}