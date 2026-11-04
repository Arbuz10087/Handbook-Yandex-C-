#include <iostream>
#include <forward_list>

int main() {
    size_t n, i=0;
    std::cin >> n;
    int x;
    std::forward_list<int> data;
    auto before_it = data.before_begin();

    while (i < n) {
        std::cin >>x;
        before_it = data.insert_after(before_it, x);
        ++i;
    }

    int max; 
    auto it_before_max = data.begin();

    if (!data.empty()) {
       max = *data.begin();
    }

    for (auto it = data.before_begin(); std::next(it) != data.end(); ++it){
        if (*std::next(it) >= max) {
            max = *std::next(it);
            it_before_max = it;
        }
    }

    data.erase_after(it_before_max);

    for (const auto& elem : data) {
        std::cout << elem << " ";
    }
}