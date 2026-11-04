#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
    private:
    Container data;

    public:

    Queue() = default;

    const T& front() const {
        return *data.begin();
    }

    T& front() {
        return *data.begin();
    }

    void pop() {
        if (!data.empty()) {
        data.erase(data.begin());
        }
    }

    void push(T elem) {
        data.push_back(elem);
    }

    size_t size() {
        return data.size();
    }

    bool empty() {
        return data.empty();
    }
   

    bool operator == (const Queue<T>& other) {
        size_t k = 0;
        for (size_t i=0; i != data.size(); ++i) {
         if (data[i]== other.data[i]) {
             k++;
         }
        }
        if (data.size()== other.data.size() && k == data.size()) {
            return true;
        } else {
            return false;
        }
    }

    bool operator != (const Queue<T>& other) {
        if (data == other.data) {
            return false;
        } else {
          return true;
        }
    }
};