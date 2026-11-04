#include <vector>
#include <iostream>
#include <cmath>

template <typename T>
class Polynomial {

   private:
   std::vector<T> data;

  /* T power(const T& elem, size_t n) const {
       if (n== 0) {
           return 1;
       }
       T result=1;
       while (n != 0) {
        result*=elem;
        n--;
       }
       return result;
   }*/


    void Normalize() {
    while (!data.empty() && data.back() == T{0}) {
        data.pop_back();
    }
}
  std::vector<T>& GetCoefficients() {
    return data;
}
   
   public:
    

   Polynomial(const T& scalyar = {}) {
       if (scalyar != T(0)) {
       data.push_back(scalyar);
       }
   }

   Polynomial(std::vector<T> coeff) {
       data=coeff;
       Normalize();
   }

   const std::vector<T>& GetCoefficients() const {
       return data;
   }

   std::vector<T>::iterator begin() {
       return data.begin();
   }

   std::vector<T>::iterator end() {
       return data.end();
   }


   std::vector<T>::const_iterator begin() const {
       return data.cbegin();
   }

   std::vector<T>::const_iterator end() const  {
       return data.cend();
   }

   template <typename Iter>
   Polynomial(Iter first, Iter last) {
       for (Iter it = first; it != last; ++it) {
           data.push_back(*it);
       }
       Normalize();
   }


  

   /*bool operator == (const T& scalyar) const {
       return data.size()==1 && data[0] == scalyar;
   }

   bool operator != (const T& scalyar) const {
       return !(*this == scalyar);
   }*/


   T operator () (const T& x) const {
       T result = T{};
       for (int i = Degree(); i >=0; --i) {
           result *= x;
           result += data[i];
         // result+=data[i]*power(x,i);
       }
       return result;
   }

   const T& operator [] (size_t i) const {
       if (static_cast<int>(i) > Degree()) {
           static const T zero{0};
           return zero;
       }
       return data[i];
   }

 /* T& operator [] (size_t i) {
    if (i > static_cast<size_t>(Degree())) {
        static T zero{0};
        return zero;
     }
     return data[i];
  }*/

   int Degree() const {
           return static_cast<int>(data.size())-1;
   }

   size_t Size() const {
       return data.size();
   }

   void Resize(const Polynomial& other){
       if (other.Size() > Size()) {
           data.resize(other.Size());
       }
   }
   
Polynomial<T>& operator += (const Polynomial<T>& other) {
    Resize(other);
   for (size_t i = 0; i != other.Size(); ++i) {
       data[i] += other.data[i];
   }
   Normalize();
   return *this;
}

Polynomial<T>& operator -= (const Polynomial<T>& other) {
    Resize(other);
    for (size_t i = 0; i != other.Size(); ++ i) {
        data[i] -= other.data[i];
    }
    Normalize();
    return *this;
}

Polynomial<T>& operator *= (const Polynomial<T>& other) {
    if (Size()==0 || other.Size()==0) {
        Resize(Polynomial<T>(0));
        return *this;
    }
    std::vector<T> tmp(Size()+other.Size()-1);
    for (size_t i = 0; i != Size(); ++ i) {
        for (size_t j=0; j!= other.Size(); ++j) {
            tmp[i+j] +=data[i]*other.data[j];
        }
    }
    data = std::move(tmp);
    Normalize();
    return *this;
}

 friend bool operator == (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
     return lhs.GetCoefficients()==rhs.GetCoefficients();
   }

   friend bool operator != (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
       return !(lhs == rhs);
   } 

};




template <typename T>
std::ostream& operator << (std::ostream& out, const Polynomial<T>& p) {
    for (int i = p.Degree(); i >=0; --i) {
        out <<p[static_cast<size_t>(i)];
         if (i !=0) {
        out <<' ';
    }
    }
   
    return out;
}


template<typename T>
Polynomial<T> operator + (Polynomial<T> p1, const Polynomial<T>& p2) {
    return p1 += p2;
}
/*
template <typename T>
Polynomial<T>& operator += (Polynomial<T>& p, const T& scalyar) {
    p[0] += scalyar;
    p.Normalize();
    return p;
}

template <typename T>
Polynomial<T> operator + (const Polynomial<T>& p, const T& scalyar) {
    auto tmp(p);
    tmp += scalyar;
    return tmp;
}

template <typename T>
Polynomial<T> operator + (const T& scalyar, const Polynomial<T>& p){ 
return p + scalyar;
}

*/
template <typename T>
Polynomial<T> operator - (Polynomial<T> p1, const Polynomial<T>& p2) {
    return p1 -= p2;
}
/*
template <typename T>
Polynomial<T>& operator -= (Polynomial<T>& p, const T& scalyar) {
    p[0] -= scalyar;
    p.Normalize();
    return p;
}

template <typename T>
Polynomial<T> operator - (const Polynomial<T>& p, const T& scalyar) {
    auto tmp(p);
    tmp-=scalyar;
    return tmp;
}

template <typename T>
Polynomial<T> operator - (const T& scalyar, const Polynomial<T>& p) {
    Polynomial<T> tmp(scalyar);
    return tmp-p;
}
*/

template <typename T>
Polynomial<T> operator * (Polynomial<T> p1, const Polynomial<T>& p2) {
    return p1 *= p2;
}
/*
template <typename T>
Polynomial<T> operator * (const Polynomial<T>& p, const T& scalyar) {
    auto tmp(p);
    for (T& elem : tmp) {
        elem *= scalyar;
    }
    tmp.Normalize();
    return tmp;
}

template <typename T>
Polynomial<T> operator * (const T& scalyar, const Polynomial<T>& p1) {
    auto tmp(p1);
    return tmp*scalyar;
}
*/

