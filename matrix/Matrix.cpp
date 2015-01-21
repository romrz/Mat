#include <iostream>
#include "matrix/Matrix.h"
#include "number/Number.h"

using namespace std;

Matrix::Matrix(int rows, int cols)
{
  mR = rows;
  mC = cols;

  mData = new int[mR * mC];
}

Matrix::~Matrix()
{
  delete[] mData;
}

void Matrix::setRows(int rows)
{
  mR = rows;
}

int Matrix::getRows()
{
  return mR;
}

void Matrix::setColumns(int columns)
{
  mC = columns;
}

int Matrix::getColumns()
{
  return mC;
}

void Matrix::getData(int *data)
{
  data = mData;
}

Matrix Matrix::operator+(Matrix &m)
{
  Matrix result(mR, mC);
  
  int n = mR * mC;

  for(int i = 0; i < n; i++)
    result[i] = mData[i] + m[i];

  return result;
}
 
Matrix Matrix::operator-(Matrix &m)
{
  Matrix result(mR, mC);
  
  int n = mR * mC;

  for(int i = 0; i < n; i++)
    result.mData[i] = mData[i] - m.mData[i];

  return result;
}

int& Matrix::operator[](int i)
{
  return mData[i];
}

void Matrix::print()
{
  int n = mR * mC;

  for(int i = 0; i < n; i++)
    {
      if(i % mC == 0) cout << endl;
      else cout << " ";

      cout << mData[i];     
    }

  cout << endl;
}
