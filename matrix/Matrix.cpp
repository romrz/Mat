#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using namespace std;

Matrix& Matrix :: operator=(const Matrix& m)
{
  mR = m.rows();
  mC = m.cols();
  
  delete[] mData;
  mData = new complex<Real>[mR * mC];

  for(int i = m.length() - 1; i >= 0; i--)
    mData[i] = m[i];
  
  return *this;
}

Matrix& Matrix :: operator=(Matrix&& m)
{
  mR = m.rows();
  mC = m.cols();

  delete[] mData;
  mData = m.mData;
  m.mData = nullptr;

  return *this;
}

void Matrix :: setDimensions(int rows, int cols)
{
  if(rows > 0 && cols > 0) {

    int oldR = mR;
    int oldC = mC;
    
    mR = rows;
    mC = cols;

    complex<Real> *oldData = mData;

    mData = new complex<Real>[rows * cols];

    for(int i = 0; i < rows && i < oldR; i++)
      for(int j = 0; j < cols && j < oldC; j++)
	mData[i * mC + j] = oldData[i * oldC + j];

    delete[] oldData;
    
  }  
}

Matrix& Matrix :: operator+=(const Matrix& m)
{
  if(rows() != m.rows() || cols() != m.cols())
    throw runtime_error("Dimension mismatch.");

  for(int i = length() - 1; i >= 0; i--)
    mData[i] += m[i];

  return *this;
}

Matrix& Matrix :: operator-=(const Matrix& m)
{
  if(rows() != m.rows() || cols() != m.cols())
    throw runtime_error("Dimension mismatch.");

  for(int i = length() - 1; i >= 0; i--)
    mData[i] -= m[i];

  return *this;
}

Matrix& Matrix :: operator*=(const Matrix& m)
{
  if (cols() != m.rows())
    throw runtime_error("Dimension mismatch.");

  int rows1 = rows();
  int cols1 = cols();
  int cols2 = m.cols();

  Matrix result(rows1, cols2);

  for (int k = 0; k < rows1; k++)
    for (int i = 0; i < cols2; i++)
      for (int j = 0; j < cols1; j++)
	result(k, i) += (*this)(k, j) * m(j, i);
  
  return ((*this) = move(result));
}

Matrix operator+(const Matrix& a, const Matrix& b) { return move(Matrix(a) += b); }
Matrix operator-(const Matrix& a, const Matrix& b) { return move(Matrix(a) -= b); }
Matrix operator*(const Matrix& a, const Matrix& b) { return move(Matrix(a) *= b); }

ostream& operator<<(ostream& os, const Matrix& m)
{
  int n = m.length();
  for(int i = 0; i < n; i++) {
    if(i % m.cols() == 0) os << endl;
    else os << " ";
    os << m[i];
  }

  return os << endl;
}

istream& operator>>(std::istream& is, Matrix& m)
{
  int rows, cols;
  cin >> rows;
  cin >> cols;

  m.setDimensions(rows, cols);

  for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
      is >> m(i, j);
    
  return is;
}
