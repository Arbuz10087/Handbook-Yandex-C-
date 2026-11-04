#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    int n;
    size_t s;
    std::string word;
    std::map<std::string, int> data;
   std::map<std::string, int> same_data;
    std::cin >> n;
    for (int i = 0; i != n; ++i) {
      std::cin >> word;
      s = word.size();
     ++same_data[word];
      for (size_t i = 0; i != word.size(); ++i) {
        std::string duble = word;
        duble[i] = '*';
        ++data[duble];
      }
    }
    long long int k = 0,  same_k = 0;

    for (const auto& elem : same_data) {
        if (elem.second> 1) {
            same_k += elem.second*(elem.second-1)/2;
        }
    }
  for (const auto& elem : data) {
    k += elem.second*(elem.second-1)/2;
  }
    std::cout << k - s*same_k;


    
}