#include <stdexcept>
#include <optional>
#include <map>
#include <memory>


template <typename Key1, typename Key2, typename Value>
class BiMap {
private:
std::map<std::pair<std::optional<Key1>, std::optional<Key2>>, std::shared_ptr<Value>> data;
std::map<std::optional<Key1>, std::shared_ptr<Value>> number;
std::map<std::optional<Key2>, std::shared_ptr<Value>> login;

public:
 
void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value) {
  if (key1 == std::nullopt && key2 == std::nullopt) {
      throw std::invalid_argument("оба ключа пустые");
  }
  if ((key1 != std::nullopt && number.find(key1) != number.end()) || (key2 != std::nullopt && login.find(key2) != login.end())) {
      throw std::invalid_argument("таклй элемент уже есть в карте");
  } else {
  auto value_ptr = std::make_shared<Value>(value);
  data[{key1, key2}] = value_ptr;
  number[key1] = value_ptr;
  login[key2] = value_ptr;
  }
}

Value& GetByPrimaryKey(const std::optional<Key1>& key1) {
    if (key1!=std::nullopt && number.find(key1)!= number.end()) {
            return *number[key1];
    } else {
    throw std::out_of_range("нет такого ключа"); 
    }
}

const Value& GetByPrimaryKey(const std::optional<Key1>& key1) const {
    if (key1 != std::nullopt && number.find(key1) != number.end()) {
       return *number[key1];
    } else {
    throw std::out_of_range("нет такого элемента");
    }
}

Value& GetBySecondaryKey(const std::optional<Key2>& key2) {
    if (key2 != std::nullopt && login.find(key2) != login.end()) {
        return *login[key2];
    } else {
    throw std::out_of_range("нет такого элемента");
    }
}

const Value& GetBySecondaryKey(const std::optional<Key2>& key2) const {
    if (key2 != std::nullopt && login.find(key2) != login.end()) {
        return *login[key2];
    } else {
    throw std::out_of_range("нет такого элемента");
    }
}
};