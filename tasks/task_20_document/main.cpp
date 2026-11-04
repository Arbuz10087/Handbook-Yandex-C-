#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Document {
private:
    const std::string Content;
public:
    Document(const std::string& s): Content(s) {}
    virtual void Save() const {
    }

    std::string GetContent() const {
        return Content;
    }
    virtual ~Document() = default;
};

class PlainTextDocument: public Document {
public:
    PlainTextDocument(const std::string& s): Document(s) {}
    void Save() const override {
        std::cout << GetContent() << "\n";
    }
};

class HTMLDocument: public Document {
public:
    HTMLDocument(const std::string& s): Document(s) {}
    void Save() const override {
        std::cout << "<HTML><BODY>" << GetContent() << "</BODY></HTML>\n";
    }
};

using DocumentCollection = std::vector<std::unique_ptr<Document>>;

void AddDocument(const std::string& content, const std::string& type, DocumentCollection& collection) {
    if (type == "plain") {
        collection.push_back(std::make_unique<PlainTextDocument>(content));
    } else if (type == "html") {
        collection.push_back(std::make_unique<HTMLDocument>(content));
    }
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection) {
        doc->Save();
    }
}