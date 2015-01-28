#include <complex>
#include "Real.h"

class Matrix {

 private:
  std::complex<Real> *mData;
  int mR;
  int mC;

 public:
  Matrix(const Matrix& m) : mR{m.rows()}, mC{m.cols()}, mData{new std::complex<Real>[m.rows() * m.cols()]}
  {
    for(int i = 0; i < mR * mC; i++)
      mData[i] = m[i];
  }
  Matrix(Matrix&& m) : mR(m.rows()), mC(m.cols()), mData(m.mData) { m.mData = nullptr; }
  Matrix(int rows, int cols) : mR{rows}, mC{cols}, mData{new std::complex<Real>[rows * cols]} {}
  Matrix() : mR{0}, mC{0}, mData{nullptr} {}
  
  ~Matrix() { delete[] mData; }

  Matrix& operator=(const Matrix& m);
  Matrix& operator=(Matrix&& m);
  
  int rows() const { return mR; }
  int cols() const { return mC; }
  int length() const { return mR * mC; }
  
  Matrix& operator+=(const Matrix& m);
  Matrix& operator-=(const Matrix& m);
  Matrix& operator*=(const Matrix& m);

  std::complex<Real>& operator()(int i, int j) const { return mData[i * mC + j]; }
  std::complex<Real>& operator[](int i) const { return mData[i]; }

  friend Matrix operator+(const Matrix& a, const Matrix& b);
  friend Matrix operator-(const Matrix& a, const Matrix& b);
  friend Matrix operator*(const Matrix& a, const Matrix& b);
  
  friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
  
  /*

  /**
   * Changes the Matrix dimensions.
   * If the new dimensions are greater than he old ones
   * the new values are filled with zeros.
   * If the new dimensions are lower than the old ones
   * the values are deleted from right to left and from the
   * bottom to the top.
   * /
  void setDimensions(int rows, int cols);

  void print();

  /**
   * Gets the matrix's transpose.
   * The original matrix remains the same.
   * /
  Matrix transpose();

  /**
   * Gets the matrix's determinant.
   * The original matrix remains the same.
   * /
  Matrix determinant();

  /**
   * Gets the matrix's inverse.
   * The original matrix remains the same.
   * /
  Matrix inverse();

  /**
   * Gets the solution matrix to the system Ax = b
   * where x is the solution matrix b is the given matrix
   * and A is this Matrix.
   * /
  Matrix solve(const Matrix &b);

  /**
   * Gets the matrix's LU decomposition.
   * The matrix L and U are stored in the parameters l and u.
   * /
  void LUDecompose(Matrix &l, Matrix &u);
*/
    
};
