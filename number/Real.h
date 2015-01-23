#include "Fraction.h"

class Real
{
 private:
  enum Type { DOUBLE, FRACTION } mType;
  union {
    Fraction mF;
    double mD;
  };
  
 public:
  Real(const Real& r) : mType{r.mType} { r.isFraction() ? mF = r.mF : mD = r.mD; }
  Real(int num = 0, int den = 1) : mType{FRACTION}, mF{Fraction(num, den)} {}
  Real(double n) : mType{DOUBLE}, mD{n} {}

  Real& operator=(const Real& r) { mType = r.mType; r.isFraction() ? mF = r.mF : mD = r.mD; }

  Type type() const { return mType; }
  bool isFraction() const { return mType == FRACTION; }
  bool isDouble() const { return mType == DOUBLE; }

  Real& operator+=(const Real& r);
  Real& operator-=(const Real& r);
  Real& operator*=(const Real& r);
  Real& operator/=(const Real& r);

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
