
#include <iostream>
#include <string>
#include <deque>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::string result;
    std::cin >> s;
    std::deque<char> data;

    for (const char& elem : s) {
        data.push_back(elem);
    }

    for (int i = 0; i != n; ++i) {
        if (data.front() > data.back()) {
            result += data.back();
            data.pop_back();
        } else {
            result += data.front();
            data.pop_front();
        }
    }
    std::cout << result;




}
