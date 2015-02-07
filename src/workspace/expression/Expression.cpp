#include <cstring>
#include <stdexcept>
#include <regex>
#include <string>
#include <stack>
#include "Expression.h"

using namespace std;

int Expression ::  priority(string op)
{
  if (op == "(" || op == ")")
    return 0;
  else if (op == "+" || op == "-")
    return 1;
  else if (op == "*")
    return 2;
  else if (op == "^-1" || op == "'")
    return 3;
  else
    return 0;
}

string Expression :: getNameFromToken(string token)
{
  string name(token);
  name.erase(0, 1);
  name.erase(name.length() - 1, 1);
  return name;  
}

Matrix Expression :: resolve()
{
  toPostfix();
  return evaluate();
}

void Expression :: toPostfix()
{
  stack<string> tempStack;

  char* expr = new char[mExpression.length() + 1];
  strcpy(expr, mExpression.c_str());

  string token = strtok(expr, " ");
  
  while(token != "") {

    if(token == "+" || token == "-" || token == "*" || token == "^-1" || token == "'") {

      while (!tempStack.empty() && !hasHigherPrecedence(token, tempStack.top())) {
	if (mPostfix.length() > 0)
	  mPostfix += " ";

	mPostfix += tempStack.top(); tempStack.pop();
      }

      tempStack.push(token);

    } else if(token == "(") {

      tempStack.push(token);

    } else if(token == ")") {

      while (!tempStack.empty()) {
	string op = tempStack.top(); tempStack.pop();

	if (op == "(")
	  break;
	else if (tempStack.empty())
	  throw runtime_error("Error in toPosfix() 1");
	else
	  mPostfix += " " + op;
      }

    }
    
    // The matrices are represented in string format as "[matrix_name]"
    // therefore it checks if the token is a matrix and if so, add it to the mPostfix expression
    else {

      if(mPostfix.length() > 0)
	mPostfix += " ";

      mPostfix += token;

    }
    //    else
    //      throw runtime_error("Error in toPosfix() 2");

    char *t = strtok(NULL, " ");
    token = t == 0 ? "" : t;
  }

  delete[] expr;
  
  while(!tempStack.empty()) {
    string op = tempStack.top(); tempStack.pop();
    if(op == "(")
      throw runtime_error("Error in toPosfix() 3");

    mPostfix += " " + op;
  }

}

Matrix Expression :: evaluate()
{
  if(mPostfix == "") throw runtime_error("Error in evaluate. 1");

  stack<Matrix*> tempStack;

  char* expr = new char[mPostfix.length() + 1];
  strcpy(expr, mPostfix.c_str());
  string token = strtok(expr, " ");
  
  while(token != "") {

    Matrix* m;

    if(token == "+")

      if (tempStack.size() >= 2) {
	Matrix* b = tempStack.top(); tempStack.pop();
	Matrix* a = tempStack.top(); tempStack.pop();
	m = new Matrix(*a + *b);
	delete a;
	delete b;
      }
      else
	throw runtime_error("Error in evaluate. 2");
    
    else if(token == "-")

      if(tempStack.size() >= 2) {
	Matrix* b = tempStack.top(); tempStack.pop();
	Matrix* a = tempStack.top(); tempStack.pop();
	m = new Matrix(*a - *b);
	delete a;
	delete b;
      }
      else
	throw runtime_error("Error in evaluate. 3");
    
    else if(token == "*")

      if(tempStack.size() >= 2) {
	Matrix* b = tempStack.top(); tempStack.pop();
	Matrix* a = tempStack.top(); tempStack.pop();
	m = new Matrix(*a * *b);
	delete a;
	delete b;
      }
      else
	throw runtime_error("Error in evaluate. 4");
    
    // The matrices are represented in string format as "[matrix_id]"
    // therefore it checks if the token is a matrix and if so, finds the matrix with the id given by the token
    //    else if(regex_match(token, regex ("\\x5B\\d+\\x5D")))
    //      m = new Matrix(*mWorkspace->findMatrix(getNameFromToken(token)));
    else
      if((m = new Matrix(*mWorkspace->findMatrix(getNameFromToken(token)))) == nullptr)
	 throw runtime_error("Error in evaluate. 5");

    tempStack.push(m);

    char* t = strtok(NULL, " ");
    token = t == 0 ? "" : t;
  }

  delete[] expr;
  
  if(tempStack.size() != 1)
    throw runtime_error("Error in evaluate. 6");

  Matrix *a = tempStack.top(); tempStack.pop();
  Matrix r = *a;

  delete a;  
  
  return r;
}
