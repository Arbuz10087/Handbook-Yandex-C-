#include <string>
#include <iostream>
#include <stack>

class Serializer {
    public:
    virtual void BeginArray() =0;
    virtual void AddArrayItem(const std::string& item)=0;
    virtual void EndArray() =0;
    virtual ~Serializer()= default;

};

class JsonSerializer : public Serializer {
    private:
    bool first_item=true;
    int count =0;
    public: 

    void BeginArray() override {
        if (count>0  &&  !first_item) {
            std::cout<< ",";
        }
       std::cout << "[";
       first_item=true;
       count++;
    }

    void EndArray() override {
        std::cout << "]";
        first_item=false;
    }

    void AddArrayItem(const std::string& item) override {

        if (!first_item) {
            std::cout <<",";
        } else {
            first_item=false;

        }
          std::cout <<"\"" << item << "\"" ;

    }

};