#include <iostream>
#include "Fraction.h"

/**
 * Simplifies the fraction using the GCD and dividing both
 * the numarator and denominator by it.
 */
void Fraction :: simplify()
{
  // calculates the GCD of a & b
  int a = mNum, b = mDen, r;
  while(b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  mNum /= a;
  mDen /= a;

  // Simplifies the signs
  if(mDen < 0) { mNum *= -1; mDen *= -1; }
}

Fraction& Fraction :: operator=(const Fraction& f)
{
  num(f.num());
  den(f.den());
  simplify();

  return *this;
}

Fraction& Fraction :: operator+=(const Fraction& f)
{
  num(num() * f.den() + den() * f.num());
  den(den() * f.den());

  simplify();

  return *this;
}

Fraction& Fraction :: operator-=(const Fraction& f)
{
  num(num() * f.den() - den() * f.num());
  den(den() * f.den());

  simplify();

  return *this;
}

Fraction& Fraction :: operator*=(const Fraction& f)
{
  num(num() * f.num());
  den(den() * f.den());

  simplify();

  return *this;
}

Fraction& Fraction :: operator/=(const Fraction& f)
{
  num(num() * f.den());
  den(den() * f.num());

  simplify();

  return *this;
}

Fraction operator+(const Fraction& a, const Fraction& b) { return Fraction(a) += b; }
Fraction operator-(const Fraction& a, const Fraction& b) { return Fraction(a) -= b; }
Fraction operator*(const Fraction& a, const Fraction& b) { return Fraction(a) *= b; }
Fraction operator/(const Fraction& a, const Fraction& b) { return Fraction(a) /= b; }

bool operator==(const Fraction& a, const Fraction& b)
{
  return a.num() == b.num() && a.den() == b.den();
}
bool operator<(const Fraction& a, const Fraction& b)
{
  return a.den() > b.den() || (a.den() == b.den()) && a.num() < b.num();
}
bool operator!=(const Fraction& a, const Fraction& b) { return !(a == b); }
bool operator>(const Fraction& a, const Fraction& b) { return b < a; }
bool operator<=(const Fraction& a, const Fraction& b) { return !(a > b); }
bool operator>=(const Fraction& a, const Fraction& b) { return !(a < b); }

Fraction operator+(const Fraction& f) { return Fraction(f); }
Fraction operator-(const Fraction& f) { return Fraction(-f.num(), f.den()); }

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
  os << f.num();

  if(f.den() != 1)
    os << "/" << f.den();
  
  return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
  int num, den = 1;
  is >> num;
  if(is.peek() == '/') {
    is.ignore();
    is >> den;
  }

  f.setValues(num, den);
  
  return is;
}
