#include <iostream>
#include <sstream>
#include "Real.h"

using namespace std;

Real& Real :: operator+=(const Real& r)
{
  if(isFraction() && r.isFraction())
    mF += r.mF;
  else if(isDouble() && r.isDouble())
    mD += r.mD;
  else {
    mD = isFraction() ? mF.dbl() + r.mD : mD + r.mF.dbl();    
    mType = Real::DOUBLE;
  }

  return *this;
}

Real& Real :: operator-=(const Real& r)
{
  if(isFraction() && r.isFraction())
    mF -= r.mF;
  else if(isDouble() && r.isDouble())
    mD -= r.mD;
  else {
    mD = isFraction() ? mF.dbl() - r.mD : mD - r.mF.dbl();    
    mType = Real::DOUBLE;
  }

  return *this;
}

Real& Real :: operator*=(const Real& r)
{
  if(isFraction() && r.isFraction())
    mF *= r.mF;
  else if(isDouble() && r.isDouble())
    mD *= r.mD;
  else {
    mD = isFraction() ? mF.dbl() * r.mD : mD * r.mF.dbl();    
    mType = Real::DOUBLE;
  }

  return *this;
}

Real& Real :: operator/=(const Real& r)
{
  if(isFraction() && r.isFraction())
    mF /= r.mF;
  else if(isDouble() && r.isDouble())
    mD /= r.mD;
  else {
    mD = isFraction() ? mF.dbl() / r.mD : mD / r.mF.dbl();    
    mType = Real::DOUBLE;
  }

  return *this;
}

Real operator+(const Real& a, const Real& b) { return Real(a) += b; }
Real operator-(const Real& a, const Real& b) { return Real(a) -= b; }
Real operator*(const Real& a, const Real& b) { return Real(a) *= b; }
Real operator/(const Real& a, const Real& b) { return Real(a) /= b; }

bool operator==(const Real& a, const Real& b)
{
  if(a.isFraction() && b.isFraction())
    return a.mF == b.mF;
  else if(a.isDouble() && b.isDouble())
    return a.mD == b.mD;
  else
    return a.isFraction() ? a.mF.dbl() == b.mD : a.mD == b.mF.dbl();    
}
bool operator<(const Real& a, const Real& b)
{
  if(a.isFraction() && b.isFraction())
    return a.mF < b.mF;
  else if(a.isDouble() && b.isDouble())
    return a.mD < b.mD;
  else
    return a.isFraction() ? a.mF.dbl() < b.mD : a.mD < b.mF.dbl();    
}
bool operator!=(const Real& a, const Real& b) { return !(a == b); }
bool operator>(const Real& a, const Real& b) { return b < a; }
bool operator<=(const Real& a, const Real& b) { return !(a > b); }
bool operator>=(const Real& a, const Real& b) { return !(a < b); }

Real operator-(const Real& a)
{
  return a.isFraction() ? Real(-a.mF.num(), a.mF.den()) : Real(-a.mD);
}

std::ostream& operator<<(std::ostream& os, const Real& r)
{
  r.isFraction() ? os << r.mF : os << r.mD;
  return os;
}

std::istream& operator>>(std::istream& is, Real& r)
{
  string s;
  char c;
  bool isFraction = true;

  while((c = cin.get()) == ' ');
  
  while(c >= 45 && c <= 57 || c == '+') {
    if(c == '.') isFraction = false;
    s += c;
    c = cin.get();
  }
  cin.unget();
  
  if(isFraction) {
    Fraction f;
    (istringstream(s)) >> f;
    r.mType = Real::FRACTION;
    r.mF = f;
  }
  else {
    double d;
    (istringstream(s)) >> d;
    r.mType = Real::DOUBLE;
    r.mD = d;
  }  
  
  return is;
}
