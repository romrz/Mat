#include <iostream>
#include "../Mat/Matrix.h"

using namespace std;

int main()
{
  Matrix a(2, 2);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;
  Matrix b(2, 3);
  b[0] = complex<Real>(Real(1, 2), 2.4);
  b[1] = complex<Real>(Real(1.45), 2.4);
  b[2] = complex<Real>(Real(3, 2), Real(3, 3));
  b[3] = complex<Real>(1.234, Real(3, 5));
  b[4] = complex<Real>(1, Real(1));
  b[5] = complex<Real>(Real(5, 6), Real(3, 5));
  Matrix c(b);
  Matrix d(2, 2);
  d[0] = complex<Real>(1, 1);
  d[1] = complex<Real>(2, 2);
  d[2] = complex<Real>(3, 3);
  d[3] = complex<Real>(4, 4);

  cout << "Matrices: " << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = b = " << c << endl;
  cout << "d = " << d << endl;

  a += a;
  b += b;
  d += d;
  c -= c;
  
  cout << "Arithmetic: " << endl;
  cout << "a += a = " << a << endl;
  cout << "b += b = " << b << endl;
  cout << "c -= c = " << c << endl;
  cout << "d += d = " << d << endl;

  a *= a;
  d *= d;
  
  cout << "a *= a = " << a << endl;
  cout << "d *= d = " << d << endl;

  cout << "a + a = " << (a + a) << endl;
  cout << "a + d = " << (a + d) << endl;
  cout << "b + b = " << (b + b) << endl;

  cout << "a - a = " << (a - a) << endl;
  cout << "a - d = " << (a - d) << endl;
  cout << "b - b = " << (b - b) << endl;

  Matrix e = a * a * a;

  cout << "e = " << e << endl;

  cout << "Matrix Redimensioning: " <<  endl;
  cout << "a = " << a << endl;
  a.setDimensions(3, 3);
  cout << "Redimension a to 3 x 3: " << endl << "a = " << a << endl;
  a.setDimensions(1, 1);
  cout << "Redimension a to 1 x 1: " << endl << "a = " << a << endl;
  a.setDimensions(10, 10);
  cout << "Redimension a to 10 x 10: " << endl << "a = " << a << endl; 

  Matrix in;
  cout << "Introduce a Matrix: " << endl;
  cin >> in;
  cout << "The Matrix is: " << in << endl;
  
  return 0;
}
