#include <iostream>
#include <string>
#include "../workspace/Workspace.h"

using namespace std;

int main()
{

  Workspace ws;

  Matrix *a = ws.newMatrix("A", 2, 2);
  (*a)[0] = 1;
  (*a)[1] = 2;
  (*a)[2] = 3;
  (*a)[3] = 4;

  Matrix *b = ws.newMatrix("B", 2, 2);
  (*b)[0] = 2;
  (*b)[1] = 4;
  (*b)[2] = 6;
  (*b)[3] = 8;

  Matrix c(3, 3);
  c[0] = 1;  c[1] = 3;  c[2] = 6;
  c[3] = 9;  c[4] = 12;  c[5] = 15;
  c[6] = 18;  c[7] = 21;  c[8] = 24;

  Matrix *d = ws.newMatrix("C", c);

  cout << "Matrices: " << endl;
  cout << "A = " << *ws.findMatrix("A") << endl;
  cout << "B = " << *ws.findMatrix("B") << endl;
  cout << "C = " << *ws.findMatrix("C") << endl;

  Matrix *result = ws.resolveExpression("( [B] )");

  cout << "Expressions: " << endl;
  cout << "A + B = " << *result << endl;

  ws.print();

  cout << "Change name of A to AA: " << endl;
  ws.changeMatrixName("A", "AA");
  
  ws.print();
  
  return 0;
}
