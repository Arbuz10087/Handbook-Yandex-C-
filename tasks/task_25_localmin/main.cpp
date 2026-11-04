#include <iostream>
#include <forward_list>
#include <iterator>

int main() {
    std::forward_list<int> data;
    
    size_t n, i = 0;
    int x;
    std::cin >> n;
    auto it = data.begin();
    auto it_before = data.before_begin();

    while (i < n) {
      std::cin >> x;
       it_before = data.insert_after(it_before, x);
      ++i; 
    }

    for (auto it = data.begin(); it!= data.end();) {
      auto elem = std::next(it);
      if (elem == data.end()) {break;}
      auto elem_next = std::next(it,2);
      if (elem_next == data.end()) {break;}
      if (*elem < *it && *elem < *elem_next) {
       it = data.erase_after(it);
       --n;

      } else {
        ++it;
      }
    }

    std::cout << n << std::endl;


    for (const auto& elem : data) {
      std::cout << elem << " ";
    }

    
    
}