#include "number/Number.h"

/**
 * A Matrix
 */
class Matrix {

 public:

  /**
   * Creates a Matrix of dimensions rows X cols
   */
  Matrix(int rows, int cols);

  /**
   * Creates a Matrix with the given values
   */
  Matrix(Number data[]);

  /**
   * Destroy a Matrix and frees the resources
   */
  ~Matrix();

  //  void setRows(int rows);

  /**
   * Gets the rows of the matrix
   */
  int getRows();

  //  void setColumns(int columns);

  /**
   * Gets the columns of the matrix
   */
  int getColumns();

  /**
   * Changes the Matrix dimensions.
   * If the new dimensions are greater than he old ones
   * the new values are filled with zeros.
   * If the new dimensions are lower than the old ones
   * the values are deleted from right to left and from the
   * bottom to the top.
   */
  void setDimensions(int rows, int columns);

  void print();

  /**
   * Gets the matrix's transpose.
   * The original matrix remains the same.
   */
  Matrix transpose();

  /**
   * Gets the matrix's determinant.
   * The original matrix remains the same.
   */
  Matrix determinant();

  /**
   * Gets the matrix's inverse.
   * The original matrix remains the same.
   */
  Matrix inverse();

  /**
   * Gets the solution matrix to the system Ax = b
   * where x is the solution matrix b is the given matrix
   * and A is this Matrix.
   */
  Matrix solve(const Matrix &b);

  /**
   * Gets the matrix's LU decomposition.
   * The matrix L and U are stored in the parameters l and u.
   */
  void LUDecompose(Matrix &l, Matrix &u);

  /**
   * Gets the sum of this Matrix with the given Matrix
   */
  Matrix operator+(const Matrix &m);

  /**
   * Gets the subtraction of this Matrix with the given Matrix
   */
  Matrix operator-(const Matrix &m);

  /**
   * Gets the product of this Matrix with the given Matrix
   */
  Matrix operator*(const Matrix &m);

  /**
   * Gets the number at the specified index of the matrix
   */
  Number &operator[](int i);

 private:
  Number *mData;
  int mR;
  int mC;

};
