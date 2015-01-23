#include <iostream>
#include "Real.h"

using namespace std;

int main()
{

  Real a(1, 2);
  Real b(1.2);
  Real c;
  Real d = a;
  Real e = b;
  Real f = 1;
  Real g = 1.345;
  Real h = Real(12, 4);
  Real i(1);
  Real j(3, 4);
  Real k = 23.45;
  
  cout << "Reals: " << endl;
  cout << "a = " << a << " (" << (a.isFraction() ? "F" : "D") << ")" << endl;
  cout << "b = " << b << " (" << (b.isFraction() ? "F" : "D") << ")" << endl;
  cout << "c = " << c << endl;
  cout << "d = " << d << endl;
  cout << "e = " << e << endl;
  d = b;
  cout << "d = b = " << d << endl;
  d = a;
  cout << "d = a = " << d << endl;
  cout << "f = " << f << endl;
  cout << "g = " << g << endl;
  cout << "h = " << h << endl;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "k = " << k << endl;

  Real ab = a / b;
  Real ba = b / a;
  Real aa = a / a;
  Real bb = b / b;
  
  cout << "Real Artimethic: " << endl;
  cout << "a / b = " << ab << " (" << (ab.isFraction() ? "F" : "D") << ")" << endl;
  cout << "b / a = " << ba << " (" << (ba.isFraction() ? "F" : "D") << ")" << endl;
  cout << "a / a = " << aa << " (" << (aa.isFraction() ? "F" : "D") << ")" << endl;
  cout << "b / b = " << bb << " (" << (bb.isFraction() ? "F" : "D") << ")" << endl;

  cout << "Logic Operators : " << endl;
  cout << "a == a : " << (a == a) << endl;
  cout << "a != a : " << (a != a) << endl;
  cout << "a < a : " << (a < a) << endl;  
  cout << "a <= a : " << (a <= a) << endl;
  cout << "a > a : " << (a > a) << endl;
  cout << "a >= a : " << (a >= a) << endl;

  cout << "b == b : " << (b == b) << endl;
  cout << "b != b : " << (b != b) << endl;
  cout << "b < b : " << (b < b) << endl;  
  cout << "b <= b : " << (b <= b) << endl;
  cout << "b > b : " << (b > b) << endl;
  cout << "b >= b : " << (b >= b) << endl;

  cout << "b == a : " << (b == a) << endl;
  cout << "b != a : " << (b != a) << endl;
  cout << "b < a : " << (b < a) << endl;  
  cout << "b <= a : " << (b <= a) << endl;
  cout << "b > a : " << (b > a) << endl;
  cout << "b >= a : " << (b >= a) << endl;

  cout << "Unary : " << endl;
  cout << "-a = " << -a << endl;
  cout << "-b = " << -b << endl;
  
  return 0;
}
