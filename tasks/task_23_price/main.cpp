#include <vector> 
#include <iostream>

int main() {
    int n, x;
    std::cin >> n;
    std::vector<int> data;
   size_t i =0;
   while (i != n) {
       std::cin >> x;
       data.push_back(x);
       ++i;
   }
   int min_diff = data[0] - data[1];
   int max_diff = min_diff;
   size_t i_min =0, j_min=1,
  i_max=0, j_max=1, max_index=0, min_index=0;

   for (size_t i = 1; i != n; ++i) {
      if (data[min_index]-data[i] < min_diff){
         min_diff = data[min_index]-data[i];
         i_min= min_index;
         j_min= i;
      }
         if (data[max_index] - data[i] > max_diff) {
            max_diff = data[max_index]-data[i];
            i_max= max_index;
            j_max = i;
         }
      
      if (data[i] < data[min_index]) {
          min_index = i;
      }

      if (data[i] > data[max_index]) {
          max_index = i;
      }

   }

   std::cout <<++i_min << " " <<++j_min << std::endl;
   std::cout <<++i_max << " " << ++j_max<< std::endl;


}