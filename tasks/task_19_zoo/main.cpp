#include "animals.h"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;

    while (std::cin >> word) {
        if (word == "Tiger") {
          // auto ptr =  std::make_unique<Animal>(tiger);
            zoo.push_back(std::make_unique<Tiger>());

        } else if (word == "Wolf") {
          //  Wolf wolf;
          //  auto ptr = std::make_unique<Animal>(wolf);
            zoo.push_back(std::make_unique<Wolf>());

        } else if (word == "Fox") {
          //  Fox fox;
         //   auto ptr = std::make_unique<Animal>(fox);
            zoo.push_back(std::make_unique<Fox>());

        } else {
            throw std::invalid_argument("такого животного нет");
        }
    }

 return zoo;
}




void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal->Voice() <<std::endl;
    }
}