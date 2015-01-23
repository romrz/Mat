#include <iostream>
#include "Real.h"

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
