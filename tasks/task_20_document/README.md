
# Задача: Документы

## Суть задачи
Вам дан класс Document, от которого унаследованы два класса( PlainTextDocument и HTMLDocument), определён тип DocumentCollection, и написаны две функции (AddDocument и PrintCollection):
#include <iostream>
#include <string>
#include <vector>

class Document {
private:
    const std::string Content;
public:
    Document(const std::string& s): Content(s) {}
    void Save() const {
    }
};

class PlainTextDocument: public Document {
public:
    PlainTextDocument(const std::string& s): Document(s) {}
    virtual void Save() {
        std::cout << Content << "\n";
    }
};

class HTMLDocument: public Document {
public:
    HTMLDocument(const std::string& s): Document(s) {}
    virtual void Save() {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};

using DocumentCollection = std::vector<Document>;

void AddDocument(const std::string& content, const std::string& type, DocumentCollection& collection) {
    if (type == "plain") {
        collection.push_back(PlainTextDocument(content));
    } else if (type == "html") {
        collection.push_back(HTMLDocument(content));
    }
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection) {
        doc.Save();
    }
}
Однако этот код не компилируется, а если исправить ошибки компиляции, то эти функции почему-то работают совсем не так, как задумано. Вам надо исправить этот код. Требования к нему такие:

Иерархия классов должна сохраниться: PlainTextDocument и HTMLDocument должны быть наследникамии Document.

Функциия Save в классе Document должна вести себя полиморфно.

Тип DocumentCollection должен быть вектором (какого-то типа).

Сигнатуры функций AddDocument и PrintCollection должны сохраниться. Второй параметр функции AddDocument может принимать значения "plain" или "html".

Утечек памяти быть не должно.

## Статус
- [x] решено
- [ ] требует рефакторинга
- [ ] нужно добавить тесты

