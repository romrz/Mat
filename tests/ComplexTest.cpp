#include <iostream>
#include <complex>
#include "../matrix/Real.h"

using namespace std;

int main()
{
  complex<Real> a(1.2, 1.3);
  complex<Real> b(3, 2);
  complex<Real> c(Real(2,3), Real(3,2));
  complex<Real> d(Real(2,3), Real(1.2));

  
  cout << "Complex Reals: " << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;

  cout << "Aritmethics operations: " << endl;
  cout << "a + b = " << (a + b) << endl;
  cout << "b + c = " << (b + c) << endl;
  cout << "c + d = " << (c + d) << endl;

  cout << "a - b = " << (a - b) << endl;
  cout << "b - c = " << (b - c) << endl;
  cout << "c - d = " << (c - d) << endl;

  cout << "a * b = " << (a * b) << endl;
  cout << "b * c = " << (b * c) << endl;
  cout << "c * d = " << (c * d) << endl;

  cout << "a / b = " << (a / b) << endl;
  cout << "b / c = " << (b / c) << endl;
  cout << "c / d = " << (c / d) << endl;


  return 0;
}
