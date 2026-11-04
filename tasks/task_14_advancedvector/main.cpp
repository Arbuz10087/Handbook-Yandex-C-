#include <vector>
#include <cmath>
#include <stdexcept>

template <typename T>
class AdvancedVector {
private:
  std::vector<T> data;

  public:
   
   AdvancedVector() = default;

   template <typename Iter>
   AdvancedVector (Iter begin, Iter end) {
       for (auto it = begin; it != end; ++it) {
           data.push_back(*it);
       }
   }

   AdvancedVector(const AdvancedVector& other) {
       data = other.data;
   }


   AdvancedVector& operator= (const AdvancedVector& other) {
       data= other.data;
       return *this;
   }


   bool empty() const {
      return data.empty();
   }

   size_t size() const {
       return data.size();
   }

   void pop_back() {
       data.pop_back();
   }

   void push_back(const T& elem) {
       data.push_back(elem);
   }

   bool operator == (const AdvancedVector& other) const {
       return data == other.data;
   }

   bool operator != (const AdvancedVector& other) const {
       return !(data == other.data);
   }

   const T& operator[] (int i) const {
     if (i >= 0) {
         if (i < static_cast<int>(size())) {
             return data[i];
         } else {
             throw std::out_of_range("выход за границы массива");
         }
     } else {
         if (i + static_cast<int>(size()) >= 0) {
             return data[i+static_cast<int>(size())];
         } else {
             throw std::out_of_range("выход за границы массива");
         }
     }
   }

   ~AdvancedVector() = default;


};