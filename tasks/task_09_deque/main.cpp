#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
    private:
    std::vector<T> head, tail;

    public:

    bool Empty() const {
        return head.empty() && tail.empty();
    }

    size_t Size() const {
        return head.size() + tail.size();
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator [] (size_t i) const {
        if (i < head.size()) {
            return head[head.size()-1-i];
        } else {
            return tail[i - head.size()];
        }
    }

    T& operator [] (size_t i) {
        if (i < head.size()) {
            return head[head.size()-1-i];
        } else {
            return tail[i- head.size()];
        }
    }

    const T& At(size_t i) const {
      if (i >= head.size()+ tail.size()) {
       throw std::out_of_range("Индекс выходит за границы");
       } else {
           if (i < head.size()) {
               return head[head.size()-1-i];
           } else {
               return tail[i-head.size()];
           }
        
       }
    }

    T& At(size_t i) {
        if (i >= head.size()+ tail.size()) {
            throw std::out_of_range("Индекс выходит за границы массива");
        } else {
            if (i < head.size()) {
                return head[head.size()-1-i];
            } else {
                return tail[i - head.size()];
            }
        }
    }

    const T& Front() const {
        if (Empty()) {
            throw std::out_of_range("Очередь пустая");
        }
        if (head.empty()) {
            return tail[0];
        }
        return head[head.size()-1];
    }

    T& Front() {
        if (Empty()) {
            throw std::out_of_range("Очередь пустая");
        }
        if (head.empty()) {
            return tail[0];
        }
        return head[head.size()-1];
    }

    const T& Back() const {
        if (Empty()) {
            throw std::out_of_range("Очередь пустая");
        }
        if (tail.empty()){
            return head[0];
        }
        return tail[tail.size()-1];
    }

    T& Back() {
        if (Empty()) {
            throw std::out_of_range("Очередь пустая");
        }
        if (tail.empty()) {
            return head[0];
        }
        return tail[tail.size()-1];
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
 
};