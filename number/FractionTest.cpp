#include <iostream>
#include <exception>
#include "Fraction.h"

using namespace std;

int main()
{
  Fraction f(1, -2);
  Fraction g(-9, -3);
  
  Fraction h = f;

  Fraction i(5);

  Fraction j = 7;

  Fraction k = g + f;

  Fraction n;

  cout << "n = " << n << endl;
  cout << "f = " << f << endl << "g = " << g << endl << "h = " << h << endl << "i = " << i << endl << "j = " << j << endl;
  cout << "f + g = " << f + g << endl << "f - g = " << f - g << endl << "f * g = " << f * g << endl << "f / g = " << f / g << endl;
  cout << "f + g - i * j = " << f + g - i * j << endl;

  cout << "Basic Types: " << endl;
  cout << "f + 1 = " << f + 1 << endl;
  cout << "f - 1 = " << f - 1 << endl;
  cout << "f * 1 = " << f * 1 << endl;
  cout << "f / 1 = " << f / 1 << endl;
  cout << "1 + f = " << 1 + f << endl;
  cout << "1 - f = " << 1 - f << endl;
  cout << "1 * f = " << 1 * f << endl;
  cout << "1 / f = " << 1 / f << endl;

  cout << "f * 1.0 = " << f * 1.0 << endl;
  
  cout << "Unary Operators: " << endl;
  cout << "-g = " << -g << endl << "+f = " << +f << endl;

  cout << "Logic Operators:" << endl;
  cout << "f == f : " << (f == f) << endl;
  cout << "f != f : " << (f != f) << endl;
  cout << "f < f : " << (f < f) << endl;
  cout << "f <= f : " << (f <= f) << endl;
  cout << "f > f : " << (f > f) << endl;
  cout << "f >= f : " << (f >= f) << endl;

  cout << "f == g : " << (f == g) << endl;
  cout << "f != h : " << (f != h) << endl;
  cout << "f < i : " << (f < i) << endl;
  cout << "f <= j : " << (f <= j) << endl;
  cout << "h > i : " << (h > i) << endl;
  cout << "g >= g : " << (g >= g) << endl;
  
  cout << "Exception :" << endl;
  cout << "l = Fraction(1, 0)" << endl; 
  try {
    Fraction l = Fraction(1, 0);
  }
  catch(std::exception& e) {
    cout << e.what() << endl;
  }

  cout << "Real: " << endl;
  cout << "f = " << f.real() << endl;
  cout << "g = " << g.real() << endl;
  
  return 0;
}
