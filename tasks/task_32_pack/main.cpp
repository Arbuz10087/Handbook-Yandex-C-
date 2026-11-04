#include <iostream> 
#include <queue>
#include <functional>
#include <vector>

int main() {
    int n, k, x, y;
    std::cin >> n >> k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> data;

    for (int i= 0; i != k; ++i) {
        data.push(0);
    }

    int new_y;
    for (int i = 0; i != n; ++i) {
        std::cin >> x >> y;
        if (data.top() > x) {
            new_y = data.top() + y;
         } else {
             new_y = x+y;
         }
             data.pop();
             data.push(new_y);
        std::cout << new_y << " ";
        }
    }