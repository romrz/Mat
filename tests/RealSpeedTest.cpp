#include <iostream>
#include <ctime>
#include "../matrix/Real.h"

using namespace std;

int main()
{
  int sums = 1000000;
  
  clock_t t = clock();
  for(int i = 0; i < sums; i++)
    Real a = Real(1.2) + Real(1.2);
  t = clock() - t;
  cout << "Real Double time (" << sums  << " sums): " << t << " = " << ((float) t) / CLOCKS_PER_SEC << endl;

  t = clock();
  for(int i = 0; i < sums; i++)
    Real b = Real(1,2) + Real(1,2);
  t = clock() - t;
  cout << "Real Fraction time (" << sums  << " sums): " << t << " = " << ((float) t) / CLOCKS_PER_SEC << endl;

  t = clock();
  for(int i = 0; i < sums; i++)
    double c = 1.2 + 1.2;
  t = clock() - t;
  cout << "double time (" << sums  << " sums): " << t << " = " << ((float) t) / CLOCKS_PER_SEC << endl;
  
  return 0;
}
