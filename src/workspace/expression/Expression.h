#ifndef _EXPRESSION_H_INCLUDED
#define _EXPRESSION_H_INCLUDED

class Workspace;

#include "Workspace.h"

using namespace std;

/**
 * The use of an Expression is to resolve an infix Expression
 * and return the result Matrix.
 *
 * To represent a Matrix in an Expression, the namtrix name must be enclosed
 * by square brackets: [matrix_name].
 *
 * Each operator or matrix must be separate by spaces.
 *
 * To resolve the Expression, it is first converted to a postfix
 * expression and then it is evaluated.
 * 
 */
class Expression
{

 private:
  /**
   * The Workspace, it is used to retrieve the Matrices.
   */
  Workspace* mWorkspace;

  /**
   * Expression in infix.
   */
  string mExpression;

  /**
   * Expression in postfix.
   */
  string mPostfix;

  /**
   * Gets a integer representing the precedence of the operator.
   * A higher value represents a higher precendence.
   */
  int priority(string op);
  bool hasHigherPrecedence(string op1, string op2) { return priority(op1) > priority(op2); }

  /**
   * Gets the name of the matrix from the token.
   * The token has the format [matrix_name] so the
   * returned string is matrix_name.
   */
  string getNameFromToken(string token);

  /**
   * Converts mExpression to postfix and stores it in mPostfix.
   *
   * throws an exception if there is an error.
   */
  void toPostfix();

  /**
   * Evaluates mPosfix expression.
   * 
   * Throws an exception if there is some error.
   *
   * Returns the result Matrix.
   */
  Matrix evaluate();
  
  
 public:

  Expression(Workspace* ws, string expr) : mWorkspace(ws), mExpression(expr) {}

  /**
   * Resolves this expression.
   * Converts the infix expression to a postfix expression and
   * then evaluetes that expression.
   *
   * Returns the result Matrix.
   */
  Matrix resolve();
  
};

#endif // _EXPRESSION_H_INCLUDED
