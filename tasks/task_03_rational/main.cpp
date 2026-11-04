#include <iostream>
#include <numeric>

class Rational {
   private:
   int numerator=0;
   int denominator=1;

   public:
   Rational() = default;

   Rational (int n, int d) {
       numerator = n;
       denominator = d;
   }

   int GetNumerator() const {
       return numerator;
   }

   int GetDenominator() const {
       return denominator;
   }

   int Numerator() const {
       return numerator/std::gcd(numerator, denominator);
   }

   int Denominator() const {
       return denominator/std::gcd(numerator,denominator);
   }

   Rational operator-() const {
       return Rational(-numerator, denominator);
   }

   Rational operator+() const {
       return Rational(numerator, denominator);
   }

   Rational& operator+= (const Rational& other) {
       int nod = std::gcd(Denominator(), other.Denominator());
        numerator = Numerator()*(other.Denominator()/nod) + other.Numerator()*(Denominator()/nod);
        denominator = Denominator()*(other.Denominator()/nod);
       return *this;
   }

   Rational& operator -= (const Rational& other) {
       int nod = std::gcd(Denominator(), other.Denominator());
       numerator = Numerator()*(other.Denominator()/nod)-other.Numerator()*(Denominator()/nod);
       denominator = Denominator()*(other.Denominator()/nod);
       return *this;
   }

   Rational& operator /= (const Rational& other) {
       numerator = Numerator()*other.Denominator();
       denominator = Denominator()*other.Numerator();
       return *this;
   }

   Rational& operator *= (const Rational& other) {
       numerator = Numerator()*other.Numerator();
       denominator = Denominator()*other.Denominator();
       return *this;
   }

   bool operator != (const Rational& other) {
       return (Numerator()!= other.Numerator()) ||(Denominator()!= other.Denominator());
   }

   bool operator == (const Rational& other) {
       return (Numerator()==other.Numerator()) && (Denominator()==other.Denominator());
   }
};

   Rational operator* (int n, const Rational& r) {
    return Rational(n*r.Numerator(), r.Denominator());
   }

   Rational operator* (const Rational& r, int n) {
       return Rational(r.Numerator()*n, r.Denominator());
   }

   Rational operator/ (const Rational& r, int n) {
       return Rational(r.Numerator(), r.Denominator()*n);
   }

   Rational operator + (const Rational& r, int n) {
       return Rational(r.Numerator()+ n*r.Denominator(), r.Denominator());
   }

   Rational operator- (const Rational& r, int n) {
       return Rational(r.Numerator()- n*r.Denominator(), r.Denominator());
   }

   Rational operator+ (Rational r, Rational other) {
       return r+=other;
   }

   Rational operator- (Rational r, Rational other) {
       return r-=other;
   }

   Rational operator* (Rational r, Rational other) {
       return r*=other;
   }

   Rational operator/ (Rational r, Rational other) {
       return r/=other;
   }

   
  
