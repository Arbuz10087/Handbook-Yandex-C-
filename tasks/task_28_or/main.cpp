#include <iostream> 
#include <set>
#include <vector>

int main() {
    size_t n;
    int x;
    std::cin >> n;
    std::vector<int> data;
    std::set<int> all_results;
    for (size_t i = 0; i != n; ++i) {
        std::cin >> x;
        data.push_back(x);
        all_results.insert(x);
    }
    std::set<int> cur;
    for (const int& x : data) {
        std::set<int> next;
           for (int v : cur) {
               next.insert(v|x);
           }
           next.insert(x);
           
           cur = std::move(next);
           
           for(const auto& elem :cur) {
               all_results.insert(elem);
           }
        }


    std::cout << all_results.size();

}
