#include <iostream>
#include <string>
#include "Workspace.h"

using namespace std;

Matrix* Workspace :: newMatrix(string name, int rows, int cols)
{
  if(matrixExists(name)) throw runtime_error("Matrix exists.");

  return ( mMatricesMap[name] = new Matrix(rows, cols) );
}

Matrix* Workspace :: newMatrix(std::string name, Matrix& src)
{
  if(matrixExists(name)) throw runtime_error("Matrix exists.");
  
  return ( mMatricesMap[name] = new Matrix(src) );
}

bool Workspace :: matrixExists(std::string name)
{
  bool r = true;
  try { mMatricesMap.at(name); }
  catch(out_of_range e) { r = false; }
  return r;
}

void Workspace ::  deleteMatrix(string name)
{
  if(matrixExists(name)) {
    delete mMatricesMap[name];
    mMatricesMap.erase(name);
  }
}

Matrix* Workspace :: findMatrix(string name)
{
  if(matrixExists(name)) return mMatricesMap[name];
  else return nullptr;
}

void Workspace :: changeMatrixName(string oldName, string newName)
{
  if(matrixExists(oldName)) {
    mMatricesMap[newName] = mMatricesMap[oldName];
    mMatricesMap.erase(oldName);
  }
}

Matrix* Workspace :: resolveExpression(string expr)
{
  Matrix *r = new Matrix(Expression(this, expr).resolve());

  mMatricesMap["R"] = r;

  return r;
}
