#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix& Matrix::operator=(const Matrix& m)
{
  mR = m.rows();
  mC = m.cols();
  
  delete[] mData;
  mData = new complex<Real>[mR * mC];
  
  return *this;
}

Matrix& Matrix::operator+=(const Matrix& m){}
Matrix& Matrix::operator-=(const Matrix& m){}
Matrix& Matrix::operator*=(const Matrix& m){}

complex<Real>& Matrix::operator[](int i)
{
  return mData[i];
}

ostream& operator<<(ostream& os, const Matrix& m)
{
  int n = m.rows() * m.cols();
  for(int i = 0; i < n; i++) {
    if(i % m.cols() == 0) os << endl;
    else os << " ";
    
    os << m.mData[i];     
  }

  os << endl;
}
