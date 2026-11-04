
# Задача:  BiMap

## Суть задачи
Все вы знаете контейнер std::map, который сопоставляет уникальным ключам значение. Представим теперь, что мы работаем с данными, у которых бывает два типа ключей. Например, студента можно задать номером студенческого билета или логином в системе. При этом не обязательно заданы оба ключа: например, у студента может ещё не быть логина.

Вам надо написать класс BiMap, к которому можно обратиться за значением по одному из двух типов ключей. Вот заготовка для вашего класса:

#include <stdexcept>
#include <optional>

template <typename Key1, typename Key2, typename Value>
class BiMap {
public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value);

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key);
    const Value& GetByPrimaryKey(const Key1& key) const;

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key);
    const Value& GetBySecondaryKey(const Key2& key) const;
};


Функция Insert пытается вставить новое значение в хранилище. Ей могут быть указаны один или оба ключа (поэтому ключи передаются через std::optional). Если оба ключа не заданы, или если один из ключей уже есть в хранилище, функция должна сгенерировать исключение std::invalid_argument с каким-либо текстовым параметром.

Функции GetByPrimaryKey и GetBySecondaryKey должны вернуть значение по ключу соответствующего типа. Они очень похожи на функцию at в std::map: в случае отстутствия ключа должна генерироваться ошибка std::out_of_range.

Вот пример тестовой программы, демонстрирующей работу этих функций:


#include "bimap.h"

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string Surname, Name;
};

ostream& operator << (ostream& out, const Student& s) {
    return out << s.Surname << " " << s.Name;
}

int main() {
    BiMap<int, string, Student> bimap;  // студента можно определить либо по номеру, либо по логину
    bimap.Insert(42, {}, {"Ivanov", "Ivan"});
    bimap.Insert({}, "cshse-ami-512", {"Petrov", "Petr"});
    bimap.Insert(13, "cshse-ami-999", {"Fedorov", "Fedor"});

    cout << bimap.GetByPrimaryKey(42) << "\n";  // Ivanov Ivan

    cout << bimap.GetBySecondaryKey("cshse-ami-512") << "\n";  // Petrov Petr

    cout << bimap.GetByPrimaryKey(13) << "\n";  // Fedorov Fedor
    cout << bimap.GetBySecondaryKey("cshse-ami-999") << "\n";  // Fedorov Fedor

    // меняем значение по первичному ключу - по вторичному оно тоже должно измениться
    bimap.GetByPrimaryKey(13).Name = "Oleg";

    cout << bimap.GetByPrimaryKey(13) << "\n";  // Fedorov Oleg
    cout << bimap.GetBySecondaryKey("cshse-ami-999") << "\n";  // Fedorov Oleg
    return 0;
}
## Нюансы
Вы можете воспользоваться контейнером std::map для реализации класса (в частности, можно считать, что на ключах определён operator <).

Сдайте в систему только код класса BiMap без функции main. Подключите все необходимые для вашей реализации библиотеки.

## Статус
- [x] решено
- [ ] требует рефакторинга
- [ ] нужно добавить тесты


