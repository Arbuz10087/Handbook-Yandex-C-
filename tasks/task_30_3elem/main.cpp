#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >>n;
    std::map<int, int> data;
    for (int i = 0; i != n; ++i) {
        std::cin >> x;
        ++data[x];
    }
    int max1 = 0, max2= 0, max3= 0;
    int key1=1, key2=1, key3=1;
     for (auto it = data.begin(); it != data.end(); ++it) {
         if (it->second > max3) {
             max1=max2;
             key1=key2;
             max2=max3;
             key2=key3;
             max3 = it->second;
             key3 = it->first;
         } else if (it->second > max2) {
             max1=max2;
             key1=key2;
            max2 = it->second;
            key2 = it->first;
         } else if (it->second > max1) {
             max1 = it->second;
             key1 = it->first;
         }
     }

     std::vector<int> sorted_data = {key1, key2, key3};
     std::sort(sorted_data.begin(), sorted_data.end());

     std::cout << sorted_data[0] << " " << sorted_data[1] << " " << sorted_data[2];
    

}