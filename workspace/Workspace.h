#ifndef _WORKSPACE_H_INCLUDED
#define _WORKSPACE_H_INCLUDED

#include <iostream>
#include <string>
#include <unordered_map>
#include "matrix/Matrix.h"
#include "expression/Expression.h"

/**
 * The Workspace is in charge of handling all the Matrices and Expression solving.
 * This is, if you want to create a matrix, you must call the newMatrix method  of
 * the Workspace, the same way if you want to delete a Matrix.
 * 
 * This is done this way for that the Workspace be the only one which handles everything
 * (Matrix creation and destruction).
 *
 * The Matrices are stored in an unordered_map where the key is the Matrix's name.
 */
class Workspace
{

 private:
  /**
   * Unordered_map storing the matrices.
   * The key is the Matrix's name.
   * The value is a pointer to the Matrix.
   */
  std::unordered_map<std::string, Matrix*> mMatricesMap;

 public:

  Workspace() {}

  /**
   * Destructor.
   * Destroys all the matrices and clears the Matrix Map;
   */
  ~Workspace() { for(auto& x : mMatricesMap) delete x.second; mMatricesMap.clear(); }

  /**
   * Creates and a new Matrix of the specified name and dimensions.
   *
   * Throws an exception if the matrix already exists.
   *
   * Returns a pointer to the Matrix.
   */
  Matrix* newMatrix(std::string name, int rows, int cols);

  /**
   * Creates and a new Matrix, copy of the given Matrix, with the specified name.
   *
   * Throws an exception if the matrix already exists.
   *
   * Returns a pointer to the Matrix.
   */
  Matrix* newMatrix(std::string name, Matrix& m);

  /**
   * Destroy and deletes the Matrix with the specified name.
   */
  void deleteMatrix(std::string name);

  /**
   * Checks whether a Matrix with the given name exists.
   */
  bool matrixExists(std::string name);

  /**
   * Returns the Matrix with the given name or nullptr if none Matrix exists.
   */
  Matrix* findMatrix(std::string name);

  /**
   * Change the name of the matrix.
   */
  void changeMatrixName(std::string oldName, std::string newName);
  
  /**
   * Resolve the expression expr and returns a pointer to the
   * result Matrix.
   *
   * In the expression, the Matrix must be in the following format:
   * [matrix_name]
   * For example, suppose there are two Matrices A and B,
   * valid expressions could be:
   *
   * [A] + [B]
   * [A] * ( [B] + [A] )
   * ...
   *
   * Notice that each operator or Matrix MUST be separate with a space.
   *
   * The name of the result Matrix is set to an internal value,
   * not colliding with any existing name.
   * But the name can be changed any time. 
   * 
   */
  Matrix* resolveExpression(std::string expr);

  void print()
  {
    std::cout << "Workspace Matrices: " << std::endl;
    for(auto& x : mMatricesMap) {
      std::cout << x.first << std::endl;
      std::cout << *x.second <<  std::endl;
    }
  }
    
};

#endif // _WORKSPACE_H_INCLUDED
