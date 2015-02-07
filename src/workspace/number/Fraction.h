#ifndef _FRACTION_H_INCLUDED
#define _FRACTION_H_INCLUDED

#include <stdexcept>

/**
 * This class represents a Fraction number a/b.
 * An exception is thrown if the denominator is zero.
 */
class Fraction
{
 private:
  int mNum; // Numerator
  int mDen; // Denominator

  /**
   * Simplifies the Fraction
   */
  void simplify();

 public:
  /**
   * Constructors
   */
  Fraction(const Fraction& f) : mNum{f.num()}, mDen{f.den()} {}
  Fraction(int num = 0, int den = 1) : mNum{num}, mDen{den} {
    if(den == 0) throw std::runtime_error("Denominator Zero.");
    simplify();
  }

  /**
   * Gets and sets the numerator and denominator.
   * Throwing and exception if the denominator is zero.
   */
  int num() const { return mNum; }
  void num(int n) { mNum = n; }
  int den() const { return mDen; }
  void den(int d) { if(d == 0) throw std::runtime_error("Denominator Zero."); mDen = d; }
  void setValues(int n, int d) { num(n); den(d); simplify(); }
  
  /**
   * Gets the double value of this Fraction
   */
  double dbl() const { return (double) mNum / (double) mDen; }

  /**
   * Operations over the Fractions
   */
  Fraction& operator=(const Fraction& f);
  Fraction& operator+=(const Fraction& f);
  Fraction& operator-=(const Fraction& f);
  Fraction& operator*=(const Fraction& f);
  Fraction& operator/=(const Fraction& f);

  friend Fraction operator+(const Fraction& a, const Fraction& b);
  friend Fraction operator-(const Fraction& a, const Fraction& b);
  friend Fraction operator*(const Fraction& a, const Fraction& b);
  friend Fraction operator/(const Fraction& a, const Fraction& b);

  friend bool operator==(const Fraction& a, const Fraction& b);
  friend bool operator!=(const Fraction& a, const Fraction& b);
  friend bool operator<(const Fraction& a, const Fraction& b);
  friend bool operator>(const Fraction& a, const Fraction& b);
  friend bool operator<=(const Fraction& a, const Fraction& b);
  friend bool operator>=(const Fraction& a, const Fraction& b);
    
  friend Fraction operator+(const Fraction& f);
  friend Fraction operator-(const Fraction& f);

  friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
  friend std::istream& operator>>(std::istream& os, Fraction& f);
  
};

#endif // _FRACTION_H_INCLUDED
