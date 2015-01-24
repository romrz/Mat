#include "Fraction.h"

/**
 * This class implements the functionality of a real number.
 * A Real number can be a Fraction or a double. Hence, when the its type is
 * DOUBLE, a double is taken as its value and when its type is FRACTION, a
 * Fraction is taken as its value.
 * 
 * The operations on Real values give a Real Fraction only if the operands
 * are all Real Fractions, and give Real Doubles otherwise.
 * 
 */
class Real
{
 private:
  /**
   * Type of Real Number
   */
  enum Type { DOUBLE, FRACTION } mType;

  /**
   * The value of this Real Number.
   * If the type of this Real number is DOUBLE, its value is treated as double.
   * If the type is FRACTION, its value is treated as a Fraction.
   */
  union {
    Fraction mF;
    double mD;
  };
  
 public:
  /**
   * Constructors
   */
  Real(const Real& r) : mType{r.mType} { r.isFraction() ? mF = r.mF : mD = r.mD; }
  Real(int num = 0, int den = 1) : mType{FRACTION}, mF{Fraction(num, den)} {}
  Real(double n) : mType{DOUBLE}, mD{n} {}

  /**
   * Gets the type of this Real number
   */
  Type type() const { return mType; }
  bool isFraction() const { return mType == FRACTION; }
  bool isDouble() const { return mType == DOUBLE; }

  /**
   * Aritmethic Operations with Real numbers.
   */

  /**
   * The behavior of the operations +=, -=, *=, /= are as following:
   *
   * a (+= , -= , *= , /=) b
   * 
   * If b is a Real Double then a will become a Real Double,
   * if b is a Real Fraction then a will remain the same type as it was.
   *
   */
  Real& operator=(const Real& r) { mType = r.mType; r.isFraction() ? mF = r.mF : mD = r.mD; }
  Real& operator+=(const Real& r);
  Real& operator-=(const Real& r);
  Real& operator*=(const Real& r);
  Real& operator/=(const Real& r);

  /**
   * The behavior of the operations +, -, *, / are as following:
   * 
   * a (+, -, *, /) b = c
   *
   * c will be a Real Fraction only if a and b are both Real Fractions
   * otherwise c will be a Real Double.
   *
   */
  friend Real operator+(const Real& a, const Real& b);
  friend Real operator-(const Real& a, const Real& b);
  friend Real operator*(const Real& a, const Real& b);
  friend Real operator/(const Real& a, const Real& b);

  friend bool operator==(const Real& a, const Real& b);
  friend bool operator!=(const Real& a, const Real& b);
  friend bool operator<(const Real& a, const Real& b);
  friend bool operator>(const Real& a, const Real& b);
  friend bool operator<=(const Real& a, const Real& b);
  friend bool operator>=(const Real& a, const Real& b);

  friend Real operator-(const Real& f);
  
  friend std::ostream& operator<<(std::ostream& os, const Real& r);

};
