#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include <complex>
#include <string>
#include "Real.h"

/**
 * A matrix of complex<Real>
 */
class Matrix {

 private:

  // Matrix Name
  std::string mName;

  // Matrix Data
  std::complex<Real> *mData;

  // Matrix Rows
  int mR;
  // Matrix Cols
  int mC;
  
 public:
  /**
   * Copy Constructor.
   * Creates a new Matrix copy of m.
   */
  Matrix(const Matrix& m) : mR{m.rows()}, mC{m.cols()}, mData{new std::complex<Real>[m.rows() * m.cols()]}
  {
    for(int i = 0; i < mR * mC; i++)
      mData[i] = m[i];
  }

  /**
   * Move Constuctor.
   * Creates a new Matrix copy of m. Leaving m with no Data
   */
  Matrix(Matrix&& m) : mR(m.rows()), mC(m.cols()), mData(m.mData) { m.mData = nullptr; }

  /**
   * Creates a new matrix of the specified rows and cols
   */
  Matrix(int rows, int cols) : mR{rows}, mC{cols}, mData{new std::complex<Real>[rows * cols]} {}

  /**
   * Creates a new empty and with no length Matrix
   */
  Matrix() : mR{0}, mC{0}, mData{nullptr} {}

  /**
   * Destructor
   */
  ~Matrix() { delete[] mData; }

  /* Copy Assignment */
  Matrix& operator=(const Matrix& m);
  /* Move Assignment */
  Matrix& operator=(Matrix&& m);

  /**
   * Gets the rows of the matrix
   */
  int rows() const { return mR; }

  /**
   * Gets the columns of the matrix
   */
  int cols() const { return mC; }

  /**
   * Gets the number of iteems in the matrix
   */
  int length() const { return mR * mC; }

  /**
   * Changes the Matrix dimensions.
   * If the new dimensions are greater than he old ones
   * the new values are filled with zeros.
   * If the new dimensions are lower than the old ones
   * the values are deleted from right to left and from the
   * bottom to the top.
   */
  void setDimensions(int rows, int cols);

  
  /**
   * Arithmetic operations.
   *
   * Throws an exception if the dimensions do not match.
   */
  
  Matrix& operator+=(const Matrix& m);
  Matrix& operator-=(const Matrix& m);
  Matrix& operator*=(const Matrix& m);

  friend Matrix operator+(const Matrix& a, const Matrix& b);
  friend Matrix operator-(const Matrix& a, const Matrix& b);
  friend Matrix operator*(const Matrix& a, const Matrix& b);

  /**
   * Returns the number at the specified position.
   * i = rows
   * j = columns
   */
  std::complex<Real>& operator()(int i, int j) const { return mData[i * mC + j]; }

  /**
   * Gets the number at the specified index in the Matrix.
   */
  std::complex<Real>& operator[](int i) const { return mData[i]; }

  friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
  
  /*

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


#endif // _MATRIX_H_INCLUDED
