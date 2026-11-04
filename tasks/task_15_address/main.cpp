#include "address.h"
#include <iostream>
#include <string>
#include <memory>


int main() {
    std::string line;
    while (getline(std::cin, line)) {
        try {
        if (line.empty()) {
            continue;
        }
        auto address = std::make_unique<Address>();
        Parse(line, address.get());
        Unify(address.get());
        std::cout << Format(*address) <<std::endl;
    }
    catch (...) {
        std::cout << "exception\n";
    }
    }

    
}