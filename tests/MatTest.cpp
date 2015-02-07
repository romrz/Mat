#include <iostream>
#include "../Mat/mat.h"

using namespace std;

int main()
{

  Workspace ws;

  Matrix* m = ws.newMatrix("A", 2, 2);

  ws.print();
  
  return 0;
}
